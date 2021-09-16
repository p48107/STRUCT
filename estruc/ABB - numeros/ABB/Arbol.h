#pragma once
#include "Nodo.h"
template<class tipo>
class Arbol
{
private:
	Nodo<tipo> *raiz;
public:
	Arbol() {
		raiz = NULL;
	}
	~Arbol() {}
	void setRaiz(Nodo<tipo> *r) {
		raiz = r;
	}
	Nodo<tipo> *getRaiz() {
		return raiz;
	}
	void insertar(tipo el) {
		insertarABB(el, raiz);
	}
	void insertarABB(tipo el, Nodo<tipo> *r){
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r == NULL) { 
			r->setValor(el);
			//tmp = r;
		}
		else
		{
			if (el < r->getValor()) {
				if (r->getIzq() != NULL) {
					insertarABB(el, r->getIzq());
				}
				else
				{
					tmp->setValor(el);
					r->setIzq(tmp);
				}
			}
			else
			{
				if (el > r->getValor()) {
					if (r->getDer() != NULL) {
						insertarABB(el, r->getDer());
					}
					else
					{
						tmp->setValor(el);
						r->setDer(tmp);
					}
				}
			}

		}
	}
	bool *buscar(tipo el, Nodo<tipo> *r) {
		bool sw;
		if (r == NULL) {
			sw = false;
		}
		else 
		{
			if (el == r->getValor())
			{
				sw = true;
			}
			else 
			{
				if (el < r.getValor())
					buscar(el, r.getIzq());
				else
					buscar(el, r.getDer());
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
			postOrden(r->getDer());
			postOrden(r->getIzq());
			cout << r->getValor() << "|";
		}
	}
	
};