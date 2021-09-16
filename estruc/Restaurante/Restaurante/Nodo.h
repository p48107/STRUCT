#pragma once
#include<iostream>
using namespace std;
template<class tipo>
class Nodo
{
private:
	tipo valor;
	Nodo *sig;
	Nodo *ant;
public:
	Nodo() {
		sig = NULL;
		ant = NULL;
		//cant = 0;
		//precio = 0;
	}
	void setValor(tipo v) {
		valor = v;
	}
	void setSig(Nodo *s) {
		sig = s;
	}
	void setAnt(Nodo *a) {
		ant = a;
	}
	tipo getValor() {
		return valor;
	}
	Nodo *getSig() {
		return sig;
	}
	Nodo *getAnt() {
		return ant;
	}
	~Nodo() {}
};

