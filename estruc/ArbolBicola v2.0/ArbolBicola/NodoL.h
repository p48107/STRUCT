#pragma once
#include<iostream>
#include "Nodo.h"
using namespace std;
template<class tipo>
class NodoL
{
private:
	Nodo *valor;
	NodoL *sig;
	NodoL *ant;

public:
	NodoL() {
		sig = NULL;
		ant = NULL;
		//cant = 0;
	}
	void setValor(Nodo *v) {
		valor = v;
	}
	Nodo *&getValor() {
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


