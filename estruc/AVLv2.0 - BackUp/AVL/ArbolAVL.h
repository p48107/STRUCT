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
	void rotarIzq(Nodo<tipo> *&r) {
		Nodo<tipo> *flotante;
		Nodo<tipo> *tmp = r->getDer();
		if (r->getIzq() != NULL)
			flotante = tmp->getIzq();
		else
			flotante = NULL;
		tmp->setIzq(r);
		r->setDer(flotante);
		r = tmp;
		r->setFact(cFactor(r));
		r->getDer()->setFact(cFactor(r->getDer()));
		r->getIzq()->setFact(cFactor(r->getIzq()));
	}
	void rotarDer(Nodo<tipo> *&r) {
		Nodo<tipo> *flotante;
		Nodo<tipo> *tmp = r->getIzq();
		if (tmp->getDer() != NULL)
			flotante = tmp->getDer();
		else
			flotante = NULL;
		tmp->setDer(r);
		r->setIzq(flotante);
		r = tmp;
		r->setFact(cFactor(r));
		r->getDer()->setFact(cFactor(r->getDer()));
		r->getIzq()->setFact(cFactor(r->getIzq()));
	}
	int cFactor(Nodo<tipo> *&r)
	{
		return altura(r->getIzq()) - altura(r->getDer());
	}
	void rotarIzqCompuesto(Nodo<tipo> *&r)
	{
		Nodo<tipo> *tmp;
		Nodo<tipo> *flotanteIzq;
		Nodo<tipo> *flotanteDer;
		tmp = r->getDer()->getIzq();
		tmp->setFact(0);
		r->setFact(0);
		r->getDer()->setFact(0);
		if (tmp->getIzq() != NULL) 
		{
			flotanteIzq = tmp->getIzq();
			r->getDer()->setFact(-1);
		}
		else
		{
			flotanteIzq = NULL;
		}
		if (tmp->getDer() != NULL)
		{
			flotanteDer = tmp->getDer();
			r->setFact(1);
		}
		else
		{
			flotanteDer = NULL;
		}
		tmp->getIzq() = r;
		tmp->getDer() = r->getDer();
		tmp->getDer()->getIzq() = flotanteDer;
		tmp->getIzq()->getDer() = flotanteIzq;
		r = tmp;
	}
	void rotarDerCompuesto(Nodo<tipo> *&r)
	{
		Nodo<tipo> *tmp = new Nodo<tipo>();
		Nodo<tipo> *flotanteDer;
		Nodo<tipo> *flotanteIzq;
		tmp = r->getIzq()->getDer();
		tmp->setFact(0);
		r->setFact(0);
		r->getIzq()->setFact(0);
		if (tmp->getDer() != NULL)
		{
			flotanteDer = tmp->getDer();
			r->getIzq()->setFact(1);
		}
		else
		{
			flotanteDer = NULL;
		}
		if (tmp->getIzq() != NULL)
		{
			flotanteIzq = tmp->getIzq();
			r->setFact(-1);
		}
		else
		{
			flotanteIzq = NULL;
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
					}
				}
			}
			else
			{
				if (el > r->getValor())
				{
					continuar = insertarAVL(el, r->getDer());
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
						}
					}
				}
			}
		}
		return continuar;
	}
	/*void eliminarAVL(tipo el, Nodo<tipo> *r)
	{
		if (r == NULL)
		{
			cout << "No hay elementos en el arbol";
		}
		else
		{
			if (el < r->getEle())
			{
				eliminarAVL(el, r->getIzquierda());
			}
			if (el > r->getEle())
			{
				eliminarAVL(el, r->getDerecha());
			}
			if (el == r->getEle())
			{

				if (r->getIzquierda() != NULL)
				{
					Nodo<T>* mayor;
					mayor = encontrarMayor(r->getIzquierda());
					r->setElemento(mayor->getEle());
					eliminarABB(mayor->getEle(), r->getIzquierda());
					if (esHoja(r->getIzquierda()))
					{
						r->setIzquierda(NULL);
					}
				}
				else
				{
					if (r->getDerecha() != NULL)
					{
						Nodo<T>* menor;
						menor = encontrarMenor(r->getDerecha());
						r->setElemento(menor->getEle());
						eliminarABB(menor->getEle(), r->getDerecha());
						if (esHoja(r->getDerecha()))
						{
							r->setDerecha(NULL);
						}
					}
				}
				if (esHoja(r))
				{
					//setRaiz(NULL);
					delete r;
				}
			}
		}
	}
	*/
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
						continuar = false;
						//r = r->setNull(r);
					}
					else
					{
						if (r->getDer() == NULL) 
						{
							continuar = true;
							r->setValor(r->getIzq()->getValor());
							r->getIzq() = NULL;
							//r->setIzq(NULL);
							r->setFact(cFactor(r));
						}
						else
						{
							if (r->getIzq() == NULL) 
							{
								continuar = true;
								r->setValor(r->getDer()->getValor());
								r->getDer() = NULL;
								//r->setDer(NULL);
								r->setFact(cFactor(r));
							}
							else
							{
								if (r->getIzq() != NULL)
								{
									Nodo<tipo> *aux = mayor(r->getIzq());
									r->setValor(aux->getValor());
									r->setFact(cFactor(r));
									continuar = eliminarAVL(r->getIzq(), r->getValor());
									r->setFact(cFactor(r));
									continuar = true;
									aux = NULL;
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
				c = insertarAVL(num, raiz);
			}
		archivo.close();
	}
	tipo maximo(tipo e1, tipo e2) {
		if (e1 > e2) {
			return e1;
		}
		else
		{
			return e2;
		}
	}
	int altura(Nodo<tipo> *&r) {
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
};