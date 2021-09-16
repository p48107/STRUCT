#pragma once
#include<iostream>
using namespace std;
template<class tipo>
class Nodo
{
private:
	tipo valor;
	Nodo *izq;
	Nodo *der;
public:
	Nodo() {
		izq = NULL;
		der = NULL;
	}

	void setValor(tipo v) {
		valor = v;
	}
	void setIzq(Nodo *i) {
		izq = i;
	}
	void setDer(Nodo *d) {
		der = d;
	}
	tipo getValor() {
		return valor;
	}
	Nodo *getIzq() {
		return izq;
	}
	Nodo *getDer() {
		return der;
	}
	~Nodo() {}
};

