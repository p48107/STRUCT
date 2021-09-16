#pragma once
#include<iostream>
using namespace std;
class NodoL
{
private:
	int valor;
	int peso;
	NodoL *sig;
	NodoL *ant;
public:
	NodoL() {
		sig = NULL;
		ant = NULL;
		valor = NULL;
		peso = NULL;
	}
	int getPeso() {
		return peso;
	}
	void setPeso(int p) {
		peso = p;
	}
	int getValor() {
		return valor;
	}
	void setValor(int v) {
		valor = v;
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
