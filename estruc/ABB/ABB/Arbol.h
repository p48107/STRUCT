#pragma once
#include "Nodo.h"
#include<iostream>
using namespace std;
template<class tipo>
class Arbol
{
	int capacidad;
	Nodo<tipo> **vec;
	int raiz;
public:
	Arbol(int c){
		capacidad = c + 3;
		vec = new Nodo<tipo>*[capacidad];
		raiz = 1;
	}
	void insertarABB(tipo el, int i) {
		if (vec[i]->getExiste() == false) {
			vec[i]->setElem(el);
			raiz = 1;
		}
		else
		{
			if (el < vec[i]->getElem()) {
				if (vec[2 * i] != NULL)
					insertarABB(el, 2 * i);
				else
				{
					vec[2 * i]->setElem(el);
					vec[2 * i]->setExiste(true);
				}
			}
			else
			{
				if (vec[2 * i + 1] != NULL)
					insertarABB(el, 2 * i + 1);
				else
				{
					vec[2 * i + 1]->setElem(el);
					vec[2 * i + 1]->setExiste(true);
				}
			}
		}
	}
	void inicializar() {
		for (int i = 0; i < capacidad; i++) {
			vec[i] = new Nodo<tipo>();
		}
	}
	~Arbol(){}
};

