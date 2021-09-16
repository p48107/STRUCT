#pragma once
#include<iostream>
using namespace std;
class NodoL
{
private:
	int valor;
	NodoL *sig;
	NodoL *ant;

public:
	NodoL() {
		sig = NULL;
		ant = NULL;
		//cant = 0;
	}
	void setValor(int v) {
		valor = v;
	}
	int getValor() {
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


