#pragma once
#include<iostream>
using namespace std;
template<class tipo>
class Nodo
{
	tipo valor;
	Nodo *sig;
	Nodo *ant;
public:
	Nodo() {
		sig = NULL;
		ant = NULL;
	}
	void setValor(tipo v){
		valor = v;
	}
	void setSig(Nodo *s) {
		sig = s;
	}
	void setAnt(Nodo *a) {
		ant = a;
	}
	tipo getValor(){
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

