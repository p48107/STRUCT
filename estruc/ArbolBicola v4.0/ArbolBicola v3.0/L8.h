#pragma once
#include "NodoL.h"
#include <string>
template<class tipo>
class L8
{
private:
	NodoL<tipo> *cabeza;
	NodoL<tipo> *ultimo;
	int cont;
public:
	L8() {
		cabeza = NULL;
		ultimo = NULL;
		cont = 0;
	}
	NodoL<tipo> *&getCabeza() {
		return cabeza;
	}
	NodoL<tipo> *&getUltimo() {
		return ultimo;
	}
	int getCont() {
		return cont;
	}
	void setCont(int c) {
		cont = c;
	}
	void insertarPrincipio(Nodo<tipo> *&v) {
		if (cabeza == NULL) {
			cabeza = new NodoL<tipo>();
			ultimo = cabeza;
			cabeza->setValor(v);
		}
		else
		{
			NodoL<tipo> *tmp = new NodoL<tipo>();//ant,sig NULL
			tmp->setValor(v);
			tmp->setSig(cabeza);
			cabeza->setAnt(tmp);
			cabeza = tmp;
		}
		cont++;
	}
	void insertarFinal(Nodo<tipo> *&v) {
		if (ultimo == NULL) {
			insertarPrincipio(v);
		}
		else {
			NodoL<tipo> *tmp = new NodoL<tipo>();//ant,sig NULL
			tmp->setValor(v);
			tmp->setAnt(ultimo);
			ultimo->setSig(tmp);
			ultimo = tmp;
		}
		cont++;
	}
	void eliminarCabeza() {
		if (cabeza != NULL) {
			if (cont == 1) {
				cabeza->~NodoL();
				ultimo->~NodoL();
				cabeza = NULL;
				ultimo = NULL;
			}
			else
			{
				NodoL<tipo> *tmp;
				tmp = cabeza;
				tmp->getSig()->setAnt(NULL);
				cabeza->~NodoL();
				cabeza = tmp->getSig();
			}
			cont--;
		}
	}
	void eliminarUltimo() {
		if (ultimo != NULL) {
			if (cont == 1) {
				eliminarCabeza();
			}
			else
			{
				NodoL<tipo> *tmp;
				tmp = ultimo;
				tmp->getAnt()->setSig(NULL);
				ultimo->~NodoL();
				ultimo = tmp->getAnt();
			}
			cont--;
		}
	}
	void eliminar(int v) {
		NodoL<tipo> *tmp;
		if (cabeza != NULL)
		{
			if (cabeza->getValor() == v)
			{
				eliminarCabeza();
			}
			else
			{
				if (ultimo->getValor() == v)
				{
					eliminarUltimo();
				}
				else
				{
					tmp = cabeza->getSig();
					while (tmp != NULL) {
						if (tmp->getValor() == v)
						{
							tmp->getAnt()->setSig(tmp->getSig());
							tmp->getSig()->setAnt(tmp->getAnt());
							tmp->~NodoL();
							tmp = NULL;
						}
						else
						{
							tmp = tmp->getSig();
						}
					}
				}
			}
			cont--;
		}
	}
	void mostrar() {
		NodoL<tipo> *tmp;
		tmp = cabeza;
		while (tmp != NULL) {
			cout << tmp->getValor()->getValor() << "| ";
			tmp = tmp->getSig();
		}
		cout << endl;
	}
	void mostrarCont() {
		cout << cont << endl;
	}
	~L8() {}
};