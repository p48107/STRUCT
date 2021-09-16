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
		cont++;
	}
	void eliminarCabeza() {
		if (cabeza != NULL) {
			cabeza->~NodoL();
			ultimo->~NodoL();
			cabeza = NULL;
			ultimo = NULL;
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