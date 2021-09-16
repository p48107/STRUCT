#pragma once
#include<iostream>
using namespace std;
class NodoL
{
private:
	string nombre;
	NodoL *sig;
	NodoL *ant;
	//int cant;
	float precio;
public:
	NodoL() {
		sig = NULL;
		ant = NULL;
		//cant = 0;
		precio = 0;
	}
	void setPrecio(float p) {
		precio = p;
	}
	float getPrecio() {
		return precio;
	}
	void setNombre(string n) {
		nombre = n;
	}
	void setSig(NodoL *s) {
		sig = s;
	}
	void setAnt(NodoL *a) {
		ant = a;
	}
	string getNombre() {
		return nombre;
	}
	NodoL *&getSig() {
		return sig;
	}
	NodoL *&getAnt() {
		return ant;
	}
	~NodoL() {}
};


