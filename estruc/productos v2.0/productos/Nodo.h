#pragma once
#include<iostream>
#include "L8.h"
using namespace std;
template<class tipo>
class Nodo
{
private:
	tipo producto;
	Nodo *izq;
	Nodo *der;
	L8 *lista;
	//Nodo *ant;
public:
	Nodo() {
		izq = NULL;
		der = NULL;
		lista = new L8();
		//ant = NULL;
	}
	Nodo *setNull(Nodo *n) {
		return NULL;
	}
	void setProducto(tipo v) {
		producto = v;
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
	tipo getProducto() {
		return producto;
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
	L8 *&getLista(){
		return lista;
	}
	~Nodo() {
		//lista = NULL;
		//izq = NULL;
		//der = NULL;
		//producto = NULL;
	}
};

