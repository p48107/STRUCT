#pragma once
#include "L8.h"
#include <vector>
template<class tipo>
class Tuad
{
private:
	int capacidad;
	L8<tipo> **vec;
	vector<int> tmp;
public:
	Tuad()
	{
		capacidad = 31;
		vec = new L8<tipo>*[capacidad];
	}
	int funcionTUAD(char s)
	{
		int pos = 0;
		pos = s - 97;
		if (pos > 25)
		{
			if (s == 130) pos = 26;
			if (s == 160) pos = 27;
			if (s == 161) pos = 28;
			if (s == 162) pos = 29;
			if (s == 163) pos = 30;
			if (s == 164) pos = 31;
		}	
		return pos;
	}
	NodoL<tipo> *buscar(tipo e)
	{
		NodoL<tipo> *tmp;
		int pos = funcionTUAD(e);
		tmp = vec[pos]->buscar(e);
		return tmp;
	}
	void insertarL8(tipo e) {
		int pos = funcionTUAD(e);
		NodoL<tipo> *tmp = buscar(e);
		if (tmp == NULL)
		{
			vec[pos]->insertarPrincipio(e);
		}
	}
	void eliminar(tipo e) {
		int pos = funcionTUAD(e);
		vec[pos]->eliminarCabeza();
	}
	void mostrar() {
		for (int i = 0; i < capacidad; i++) {
			if (vec[i]->getCabeza() != NULL) {
				vec[i]->mostrar();
			}
		}
	}
	void inicializar() {
		for (int i = 0; i < capacidad; i++) {
			vec[i] = new L8<tipo>();
		}
	}
	~Tuad() {}
};