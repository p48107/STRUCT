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
	int fact;
	//Nodo *ant;
public:
	Nodo() {
		izq = NULL;
		der = NULL;
		fact = 0;
		//ant = NULL;
	}
	Nodo *setNull(Nodo *n) {
		return NULL;
	}
	void setValor(tipo v) {
		valor = v;
	}
	void setIzq(Nodo *&i) {
		izq = i;
	}
	void setDer(Nodo *&d) {
		der = d;
	}
	void setFact(int f) {
		fact = f;
	}
	/*void setContinuar(char c) {
		continuar = c;
	}
	void setParidad(char p) {
		paridad = p;
	}
	void setLado(char l) {
		lado = l;
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
	int getFact() {
		return fact;
	}
	/*char getContinuar() {
		return continuar;
	}
	char getParidad() {
		return paridad;
	}
	char getLado() {
		return lado;
	}
	/*Nodo *getAnt() {
		return ant;
	}*/
	~Nodo() {}
};
