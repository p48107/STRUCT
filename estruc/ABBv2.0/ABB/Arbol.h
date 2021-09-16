#pragma once
#include "Nodo.h"
template<class tipo>
class Arbol
{
private:
	Nodo<tipo> *raiz;
	bool existe;
	bool tiene;
	Nodo<tipo> *sig;
public:
	Arbol() {
		raiz = NULL;
		existe = false;
		tiene = false;
		sig = NULL;
	}
	~Arbol() {}
	Nodo<tipo> *&getRaiz() {
		return raiz;
	}
	Nodo<tipo> *&getSig() {
		return sig;
	}
	void sigNull() {
		sig = NULL;
	}
	void insertarABB(tipo el, Nodo<tipo> *&r){
		
		if (r == NULL) {
			r = new Nodo<tipo>();
			r->setValor(el);
		}
		else
		{
			if (el < r->getValor()) {
					insertarABB(el, r->getIzq());
			}
			else
			{
				if (el > r->getValor()) {
						insertarABB(el, r->getDer());
				}
			}
		}
	}

	bool buscarABB(tipo el, Nodo<tipo> *r) {
		bool sw = false;
		if (r == NULL) {
			sw = false;
		}
		else 
		{
			if (el == r->getValor())
				sw = true;
			else 
			{
				if (el > r->getValor())
					sw = buscarABB(el, r->getDer());
				else
				{
					if (el < r->getValor())
						sw = buscarABB(el, r->getIzq());
				}
			}
			
		}
		return sw;
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
	int contar(Nodo<tipo> *r) {
		int cont = 0;
		if (r == NULL) {
			cont = 0;
		}
		else
		{
			cont = 1 + contar(r->getIzq()) + contar(r->getDer());
		}
		return cont;
	}
	int altura(Nodo<tipo> *r) {
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
	tipo maximo(tipo e1, tipo e2) {
		if (e1 > e2) {
			return e1;
		}
		else
		{
			return e2;
		}
	}
	Nodo<tipo> *menor(Nodo<tipo> *r) {
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
	Nodo<tipo> *mayor(Nodo<tipo> *r) {
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
	void *eliminar(Nodo<tipo> *&r, tipo valor) {
		if (r == NULL) 
		{
			return r;
		}
		else 
		{
			if (r->getValor() > valor) 
			{
				eliminar(r->getIzq(), valor);
			}
			else
			{
				if (r->getValor() < valor)
				{
					eliminar(r->getDer(), valor);
				}
				else
				{
					if (r->getIzq() == NULL && r->getDer() == NULL) {
						tipo a = NULL;
						r->setValor(a);
						r = NULL;
						r->~Nodo();
						//r = r->setNull(r);
					}
					else
					{
						if (r->getDer() == NULL) {
							r->setValor(r->getIzq()->getValor());
							r->setIzq(NULL);
						}
						else
						{
							if (r->getIzq() == NULL) {
								r->setValor(r->getDer()->getValor());
								r->setDer(NULL);
							}
							else
							{
								Nodo<tipo> *aux = menor(r->getDer());
								r->setValor(aux->getValor());
								eliminar(r->getDer(), r->getValor());
							}
						}
					}
					//return r;
				}
			}
		}
		//return r;
	}
	void siguiente(Nodo<tipo> *&r, tipo el) {
		if(r == NULL)
		{
			tiene = false;
			existe = false;
		}
		else
		{
			if(el < r->getValor())
			{
				siguiente(r->getIzq(), el);
				if(existe == true && tiene == false)
				{
					sig = r;
					tiene = true;
				}
			}
			else 
			{
				if (el > r->getValor())
				{
					siguiente(r->getDer(), el);
				}
				else {
					existe = true;
					if (r->getDer() != NULL) {
						sig = menor(r->getDer());
						tiene = true;
					}
					else
					{
						tiene = false;
					}
				}
			}
		}
	}
	void niveles(Nodo<tipo> *r, int n) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			cout << endl << r->getValor() << "(" << n << ") -";
			niveles(r->getIzq(), n + 1);
			niveles(r->getDer(), n + 1);
		}
	}
	int contarHojas(Nodo<tipo> *r) {
		int cont;
		if (r->getIzq() == NULL && r->getDer() == NULL) 
		{
			cont = 1;
		}
		else
		{
			if (r->getIzq() == NULL && r->getDer() != NULL) 
			{
				cont = contarHojas(r->getDer());
			}
			else
			{
				if (r->getIzq() != NULL && r->getDer() == NULL)
				{
					cont = contarHojas(r->getIzq());
				}
				else
				{
					cont = contarHojas(r->getIzq()) + contarHojas(r->getDer());
				}
			}
		}
		return cont;
	}
	void mostrarArbol(Nodo<tipo> *r, int spaces)
	{
		if (r != NULL)
		{
			mostrarArbol(r->getDer(), spaces + 5);
			for (int j = 0; j < spaces; j++)
				cout << ' ';
			cout << r->getValor() << endl;
			mostrarArbol(r->getIzq(), spaces + 5);
		}
	}
	void espejo(Nodo<tipo> *&r, Nodo<tipo> *&tmp) {
		if (r == NULL) {
			tmp = NULL;
		}
		else
		{
			tmp = new Nodo<tipo>();
			tmp->setValor(r->getValor());
			espejo(r->getIzq(), tmp->getDer());
			espejo(r->getDer(), tmp->getIzq());
		}
	}
};