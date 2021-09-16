#pragma once
#include<iostream>
using namespace std;
template<class tipo>
class Nodo
{
private:
	tipo valor;
	Tuad<tipo> *vec;
	Nodo *izq;
	Nodo *der;
	char color;// continuar, paridad, lado;// 'R' 'N' ROJO/NEGRO
	//Nodo *ant;
public:
	Nodo() {
		izq = NULL;
		der = NULL;
		color = 'N';
		//ant = NULL;
	}
	void setVec(Tuad<tipo> *&v) {
		vec = v;
	}
	Tuad<tipo> *&getVec() {
		return vec;
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
