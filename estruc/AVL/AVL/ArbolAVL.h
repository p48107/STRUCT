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
	void rotarIzq(Nodo<tipo> *&n) {
		Nodo<tipo> *flotante;
		Nodo<tipo> *tmp = n->getDer();
		if (n->getIzq() != NULL)
			flotante = tmp->getIzq();
		else
			flotante = NULL;
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
		tmp->setDer(n);
		tmp->getDer()->setFact((cFactor(tmp->getDer())));
		n->setIzq(flotante);
		n->getIzq()->setFact((cFactor(n->getIzq())));
		n = tmp;
		n->setFact(cFactor(n));
	}
	/*void rotarDoble(Nodo<tipo> *&r) 
	{
		if (r->getFact() == 2)
		{
			if (r->getDer()->getFact() < 0)
				rotarDer(r->getDer());
			else
				rotarIzq(r);
		}
		if (r->getFact() == -2)
		{
			if (r->getIzq()->getFact() > 0)
				rotarIzq(r->getIzq());
			else
				rotarDer(r);
		}
	}*/
	int cFactor(Nodo<tipo> *&r)
	{
		if (r == NULL) {
			return 0;
		}
		else
		{
			if (r->getDer() == NULL && r->getIzq() == NULL)
				return 0;
			else 
				return altura(r->getIzq()) - altura(r->getDer());
		}
	}
	void rotarIzqCompuesto(Nodo<tipo> *&r)
	{
		Nodo<tipo> *tmp;
		Nodo<tipo> *flotanteIzq;
		Nodo<tipo> *flotanteDer;
		tmp = r->getDer()->getIzq();
		tmp->setFact(cFactor(tmp));
		r->setFact(cFactor(r));
		r->getDer()->setFact(cFactor(r->getDer()));
		if (tmp->getIzq() != NULL) 
		{
			flotanteIzq = tmp->getIzq();
			r->getDer()->setFact(cFactor(r->getDer()));
		}
		else
		{
			flotanteIzq = NULL;
		}
		if (tmp->getDer() != NULL)
		{
			flotanteDer = tmp->getDer();
			r->setFact(cFactor(r));
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
		tmp->setFact(cFactor(tmp));
		r->setFact(cFactor(r));
		r->getIzq()->setFact(cFactor(r->getIzq()));
		if (tmp->getDer() != NULL)
		{
			flotanteDer = tmp->getDer();
			r->getIzq()->setFact(cFactor(r->getIzq()));
		}
		else
		{
			flotanteDer = NULL;
		}
		if (tmp->getIzq() != NULL)
		{
			flotanteIzq = tmp->getIzq();
			r->setFact(cFactor(r));
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
					r->setFact(cFactor(r));
					//r->setFact(r->getFact() + 1);
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
					if (continuar == true)
					{
						r->setFact(cFactor(r));
						//r->setFact(r->getFact() - 1);
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