#pragma once
#include "Nodo.h"
#include <fstream>
#include <string>
#include "string.h"
template<class tipo>
class ArboAVL
{
private:
	Nodo<tipo> *raiz;
	//continuar 'S' 'n'--> SI/NO
public:
	ArboAVL() {
		raiz = NULL;
	}
	~ArboAVL() {}
	Nodo<tipo> *&getRaiz() {
		return raiz;
	}
	void setNull(Nodo<tipo> *&r)
	{
		r = NULL;
	}
	void preOrden(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			cout << r->getValor() << "|";
			preOrden(r->getIzq());
			preOrden(r->getDer());
		}
	}
	void inOrden(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			inOrden(r->getIzq());
			cout << r->getValor() << "|";
			inOrden(r->getDer());
		}
	}
	void postOrden(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			postOrden(r->getIzq());
			postOrden(r->getDer());
			cout << r->getValor() << "|";
		}
	}
	Nodo<tipo> *menor(Nodo<tipo> *r) 
	{
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r == NULL) {
			tmp = NULL;
		}
		else
		{
			if (r->getIzq() != NULL)
				tmp = menor(r->getIzq());
			else
				tmp = r;
		}
		return tmp;
	}
	Nodo<tipo> *mayor(Nodo<tipo> *r) 
	{
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r == NULL) {
			tmp = NULL;
		}
		else
		{
			if (r->getDer() != NULL)
				tmp = mayor(r->getDer());
			else
				tmp = r;
		}
		return tmp;
	}
	void rotarIzq(Nodo<tipo> *&n) {
		Nodo<tipo> *flotante;
		Nodo<tipo> *tmp = n->getDer();
		if (n->getIzq() != NULL)
			flotante = tmp->getIzq();
		else
			flotante = NULL;
		tmp->setFact(0);
		tmp->setIzq(n);
		n->setDer(flotante);
		n = tmp;
	}
	void rotarDer(Nodo<tipo> *&n) {
		Nodo<tipo> *flotante;
		Nodo<tipo> *tmp = n->getIzq();
		if (tmp->getDer() != NULL)
			flotante = tmp->getDer();
		else
			flotante = NULL;
		tmp->setFact(0);
		tmp->setDer(n);
		n->setIzq(flotante);
		n = tmp;
	}
	int cFactor(Nodo<tipo> *&r)
	{
		return altura(r->getIzq()) - altura(r->getDer());
	}
	void rotarIzqCompuesto(Nodo<tipo> *&r)
	{
		Nodo<tipo> *tmp;
		Nodo<tipo> *flotanteDer;
		Nodo<tipo> *flotanteIzq;
		tmp = r->getDer()->getIzq();
		tmp->setFact(0);
		r->setFact(0);
		r->getDer()->setFact(0);
		flotanteIzq = tmp->getIzq();
		flotanteDer = tmp->getDer();
		if (tmp->getFact() == 1)
		{
			r->setFact(-1);
			tmp->setFact(0);
		}
		if (tmp->getFact() == -1)
		{
			r->getDer()->setFact(1);
			tmp->setFact(0);
		}
		tmp->getIzq() = r;
		tmp->getDer() = r->getDer();
		tmp->getDer()->getIzq() = flotanteDer;
		tmp->getIzq()->getDer() = flotanteIzq;
		r = tmp;
	}
	void rotarDerCompuesto(Nodo<tipo> *&r)
	{
		Nodo<tipo> *tmp;
		Nodo<tipo> *flotanteDer;
		Nodo<tipo> *flotanteIzq;
		tmp = r->getIzq()->getDer();
		tmp->setFact(0);
		r->setFact(0);
		r->getIzq()->setFact(0);
		flotanteIzq = tmp->getIzq();
		flotanteDer = tmp->getDer();
		if (tmp->getFact() == 1)
		{
			r->setFact(-1);
			tmp->setFact(0);
		}
		if (tmp->getFact() == -1)
		{
			r->getIzq()->setFact(1);
			tmp->setFact(0);
		}
		tmp->getDer() = r;
		tmp->getIzq() = r->getIzq();
		tmp->getIzq()->getDer() = flotanteIzq;
		tmp->getDer()->getIzq() = flotanteDer;
		r = tmp;
	}
	bool insertarAVL(tipo el, Nodo<tipo> *&r)
	{
		bool continuar = false;
		if (r == NULL) 
		{
			r = new Nodo<tipo>;
			r->setValor(el);
			r->setFact(0);
			continuar = true;
		}
		else
		{
			if (el < r->getValor())
			{
				continuar = insertarAVL(el, r->getIzq());
				//r->setFact(cFactor(r));
				if (continuar == true)
				{
					r->setFact(r->getFact() + 1);
					if (r->getFact() == 0) {
						continuar = false;
					}
					else
					{
						if (r->getFact() == 2)
						{
							continuar = false;
							if (r->getIzq()->getFact() == 1)
							{
								rotarDer(r);
								cout << "ROTACION DERECHA - " << r->getValor() << endl;
							}
							else
							{
								rotarDerCompuesto(r);
								cout << "ROTACION COMPUESTA DERECHA - " << r->getValor() << endl;
							}
								
						}
					}
				}
			}
			else
			{
				if (el >= r->getValor())
				{
					continuar = insertarAVL(el, r->getDer());
					//r->setFact(cFactor(r));
					if (continuar == true)
					{
						r->setFact(r->getFact() - 1);
						if (r->getFact() == 0) {
							continuar = false;
						}
						else
						{
							if (r->getFact() == -2)
							{
								continuar = false;
								if (r->getDer()->getFact() == -1)
								{
									cout << "ROTACION IZQUIERDA - " << r->getValor() << endl;
									rotarIzq(r);
								}
								else
								{
									cout << "ROTACION DOBLE IZQUIERDA - " << r->getValor() << endl;
									rotarIzqCompuesto(r);
								}
							}
						}
					}
				}
			}
		}
		return continuar;
	}
	bool eliminarAVL(Nodo<tipo> *&r, tipo valor) 
	{
		bool continuar = false;
		if (r == NULL)
		{
			continuar = false;
		}
		else
		{
			if (r->getValor() > valor)
			{
				continuar = eliminarAVL(r->getIzq(), valor);
				r->setFact(cFactor(r));
				if (continuar == true)
				{
					if (r->getFact() == 0) {
						continuar = false;
					}
					else
					{
						if (r->getFact() == 2)
						{
							continuar = false;
							if (r->getIzq()->getFact() == 1)
								rotarDer(r);
							else
								rotarDerCompuesto(r);
						}
						else
						{
							if (r->getFact() == -2)
							{
								continuar = false;
								if (r->getDer()->getFact() == -1)
									rotarIzq(r);
								else
									rotarIzqCompuesto(r);
							}
						}
					}
				}
			}
			else
			{
				if (r->getValor() < valor)
				{
					continuar = eliminarAVL(r->getDer(), valor);
					r->setFact(cFactor(r));
					if (continuar == true)
					{
						if (r->getFact() == 0) {
							continuar = false;
						}
						else
						{
							if (r->getFact() == -2)
							{
								continuar = false;
								if (r->getDer()->getFact() == -1)
									rotarIzq(r);
								else
									rotarIzqCompuesto(r);
							}
							else
							{
								if (r->getFact() == 2)
								{
									continuar = false;
									if (r->getIzq()->getFact() == 1)
										rotarDer(r);
									else
										rotarDerCompuesto(r);
								}
							}
						}
					}
				}
				else
				{
					if (r->getIzq() == NULL && r->getDer() == NULL) {
						tipo a = NULL;
						r->setValor(a);
						r = NULL;
						r->~Nodo();
						continuar = true;
					}
					else
					{
						if (r->getDer() == NULL) 
						{
							r->setValor(r->getIzq()->getValor());
							r->getIzq() = NULL;
							r->setFact(cFactor(r));
							continuar = true;
						}
						else
						{
							if (r->getIzq() == NULL) 
							{
								r->setValor(r->getDer()->getValor());
								r->getDer() = NULL;
								r->setFact(cFactor(r));
								continuar = true;
							}
							else
							{
								Nodo<tipo> *aux = mayor(r->getIzq());
								r->setValor(aux->getValor());
								r->setFact(cFactor(r));
								continuar = eliminarAVL(r->getIzq(), r->getValor());
								r->setFact(cFactor(r));
								continuar = true;
								aux = NULL;
							}
						}
					}
					//return r;
				}
			}
		}
		//return r;
		return continuar;
	}
	void leerArchivo(string texto)
	{
		int num;
		bool c;
		ifstream archivo(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		else
			while (!archivo.eof())
			{
				archivo >> num;
				/*fflush(stdin);
				cout << "NUM = " << num << endl;
				if(num == 3130)
					num = 3130;*/
				c = insertarAVL(num, raiz);
			}
		archivo.close();
	}
	tipo maximo(tipo e1, tipo e2) 
	{
		if (e1 > e2) {
			return e1;
		}
		else
		{
			return e2;
		}
	}
	int altura(Nodo<tipo> *&r) 
	{
		int a = 0;
		if (r == NULL) {
			a = 0;
		}
		else
		{
			if (r->getIzq() == NULL && r->getDer() == NULL)
				a = 1;
			else
				a = 1 + maximo(altura(r->getIzq()), altura(r->getDer()));
		}
		return a;
	}
	bool diferencia(Nodo<tipo> *&r)
	{
		if (r == NULL)
		{
			return false;
		}
		else
		{
			if (r->getFact() < 2 && r->getFact() > -2)
				return true;
			else
				return false;
			return diferencia(r->getIzq()) && diferencia(r->getDer());
			//return diferencia(r->getDer());
		}
	}
	void destruir(Nodo<tipo> *&r)
	{
		if (r != NULL)
		{
			destruir(r->getIzq());
			destruir(r->getDer());
			delete r;
			r = NULL;
		}
	}
	int contarNodos(Nodo<tipo> *r) {
		int cont = 0;
		if (r == NULL) {
			cont = 0;
		}
		else
		{
			cont = 1 + contarNodos(r->getIzq()) + contarNodos(r->getDer());
		}
		return cont;
	}
};