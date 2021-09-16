#pragma once
#include<iostream>
#include "Nodo.h"
using namespace std;
template<class tipo>
class NodoL
{
private:
	Nodo<tipo> *valor;
	NodoL *sig;
	NodoL *ant;

public:
	NodoL() {
		sig = NULL;
		ant = NULL;
		valor = NULL;
	}
	void setValor(Nodo<tipo> *v) {
		valor = v;
	}
	Nodo<tipo> *&getValor() {
		return valor;
	}
	void setSig(NodoL *s) {
		sig = s;
	}
	void setAnt(NodoL *a) {
		ant = a;
	}
	NodoL *&getSig() {
		return sig;
	}
	NodoL *&getAnt() {
		return ant;
	}
	~NodoL() {}
};
