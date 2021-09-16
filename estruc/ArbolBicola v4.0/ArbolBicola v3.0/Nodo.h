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
	Nodo *padre;
public:
	Nodo() {
		izq = NULL;
		der = NULL;
		padre = NULL;
	}
	Nodo *setNull(Nodo *n) {
		return NULL;
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
	void setPadre(Nodo *a) {
		padre = a;
	}
	tipo getValor() {
		return valor;
	}
	Nodo *&getIzq() {
		return izq;
	}
	Nodo *&getDer() {
		return der;
	}
	Nodo *&getPadre() {
		return padre;
	}
	~Nodo() {}
};


