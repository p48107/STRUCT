#pragma once
#include<iostream>
#include "Nodo.h"
#include "TUAD.h"
using namespace std;
template<class tipo>
class NodoL
{
private:
	Tuad<tipo> *vec;
	tipo valor;
	NodoL *sig;
	NodoL *ant;
public:
	NodoL() {
		sig = NULL;
		ant = NULL;
		vec = NULL;
	}
	void setVec(Tuad<tipo> *&v) {
		vec = v;
	}
	Tuad<tipo> *&getVec() {
		return vec;
	}
	void setValor(tipo v) {
		valor = v;
	}
	tipo getValor() {
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
