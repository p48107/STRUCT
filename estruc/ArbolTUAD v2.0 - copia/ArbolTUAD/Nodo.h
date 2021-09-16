#pragma once
#include<iostream>
#include "Tuad.h"
using namespace std;
template<class tipo>
class Nodo
{
private:
	tipo valor;
	Tuad<tipo> *t1;
	Nodo *izq;
	Nodo *der;
	char color;// continuar, paridad, lado;// 'R' 'N' ROJO/NEGRO
	//Nodo *ant;
public:
	Nodo() {
		izq = NULL;
		der = NULL;
		color = 'N';
		t1 = new Tuad<tipo>();
		//ant = NULL;
	}
	void setT1(Tuad<tipo> *&t) {
		t1 = t;
	}
	Tuad<tipo> *&getT1() {
		return t1;
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
	void setColor(char c) {
		color = c;
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
	char getColor() {
		return color;
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
