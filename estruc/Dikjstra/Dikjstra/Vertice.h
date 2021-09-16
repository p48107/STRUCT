#pragma once
#include <iostream>
#include "L8.h"
using namespace std;
class Vertice
{
private:
	string nombre;
	bool marca;
	L8 *lista;
	int padre;
	bool existe;
	int distancia;
public:
	Vertice() {
		marca = false;
		lista = new L8();
		padre = -1;
		existe = false;
		distancia = 400000000;
	}
	int getDistancia() {
		return distancia;
	}
	void setDistancia(int d) {
		distancia = d;
	}
	bool getExiste() {
		return existe;
	}
	void setExiste(bool e) {
		existe = e;
	}
	string getNombre() {
		return nombre;
	}
	void setNombre(string n) {
		nombre = n;
	}
	bool getMarca() {
		return marca;
	}
	void setMarca(bool m) {
		marca = m;
	}
	L8 *&getLista() {
		return lista;
	}
	void setLista(L8 *&l) {
		lista = l;
	}
	int getPadre() {
		return padre;
	}
	void setPadre(int p) {
		padre = p;
	}
	~Vertice() {}
};

