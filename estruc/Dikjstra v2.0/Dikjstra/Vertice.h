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
	int distancia;
	bool existe;
public:
	Vertice() {
		nombre = "v";
		existe = false;
		marca = false;
		lista = new L8();
		padre = -1;
		distancia = 400000000;
	}
	bool getExiste() {
		return existe;
	}
	void setExiste(bool e) {
		existe = e;
	}
	int getDistancia() {
		return distancia;
	}
	void setDistancia(int d) {
		distancia = d;
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

