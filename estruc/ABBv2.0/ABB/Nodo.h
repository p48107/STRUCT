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
	//Nodo *ant;
public:
	Nodo() {
		izq = NULL;
		der = NULL;
		valor = 0;
		//ant = NULL;
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
	/*void setAnt(Nodo *a) {
		ant = a;
	}*/
	tipo getValor() {
		return valor;
	}
	Nodo *&getIzq() {
		return izq;
	}
	Nodo *&getDer() {
		return der;
	}
	/*Nodo *getAnt() {
		return ant;
	}*/
	~Nodo() {}
};

