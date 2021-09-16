#pragma once
#include "NodoL.h"
#include <string>
class L8
{
private:
	NodoL *cabeza;
	NodoL *ultimo;
	int cont;
public:
	L8() {
		//valor = NULL;
		cabeza = NULL;
		ultimo = NULL;
		cont = 0;
	}
	NodoL *&getCabeza() {
		return cabeza;
	}
	NodoL *&getUltimo() {
		return ultimo;
	}
	int getCont() {
		return cont;
	}
	void setCont(int c) {
		cont = c;
	}
	void insertarPrincipio(int v, int p) {
		if (cabeza == NULL) {
			cabeza = new NodoL();
			ultimo = cabeza;
			cabeza->setValor(v);
			cabeza->setPeso(p);
		}
		else
		{
			NodoL *tmp = new NodoL();//ant,sig NULL
			tmp->setValor(v);
			tmp->setPeso(p);
			tmp->setSig(cabeza);
			cabeza->setAnt(tmp);
			cabeza = tmp;
		}
		cont++;
	}
	void insertarFinal(int v, int p) {
		if (ultimo == NULL) {
			insertarPrincipio(v, p);
		}
		else {
			NodoL *tmp = new NodoL();//ant,sig NULL
			tmp->setValor(v);
			tmp->setPeso(p);
			tmp->setAnt(ultimo);
			ultimo->setSig(tmp);
			ultimo = tmp;
			cont++;
		}
	}
	void eliminarCabeza() {
		if (cabeza != NULL) {
			if (cont == 1) {
				cabeza->~NodoL();
				ultimo->~NodoL();
				cabeza = NULL;
				ultimo = NULL;
			}
			else
			{
				NodoL *tmp;
				tmp = cabeza;
				tmp->getSig()->setAnt(NULL);
				cabeza->~NodoL();
				cabeza = tmp->getSig();
			}
			cont--;
		}
	}
	void eliminarUltimo() {
		if (ultimo != NULL) {
			if (cont == 1) {
				eliminarCabeza();
			}
			else
			{
				NodoL *tmp;
				tmp = ultimo;
				tmp->getAnt()->setSig(NULL);
				ultimo->~NodoL();
				ultimo = tmp->getAnt();
			}
			cont--;
		}
	}
	void eliminar(int v) {
		NodoL *tmp;
		if (cabeza != NULL)
		{
			if (cabeza->getValor() == v)
			{
				eliminarCabeza();
			}
			else
			{
				if (ultimo->getValor() == v)
				{
					eliminarUltimo();
				}
				else
				{
					tmp = cabeza->getSig();
					while (tmp != NULL) {
						if (tmp->getValor() == v)
						{
							tmp->getAnt()->setSig(tmp->getSig());
							tmp->getSig()->setAnt(tmp->getAnt());
							tmp->~NodoL();
							tmp = NULL;
						}
						else
						{
							tmp = tmp->getSig();
						}
					}
				}
			}
			cont--;
		}
	}
	int sacarSiguienteAdyacente(int i) {
		int tmp = 0;
		NodoL *ind = cabeza;
		while (ind != NULL)
		{
			i--;
			if (i == 0)
			{
				tmp = ind->getValor();
			}
			ind = ind->getSig();
		}
		return tmp;
	}
	void mostrar() {
		NodoL *tmp;
		tmp = cabeza;
		while (tmp != NULL) {
			cout << "(" << tmp->getValor() << ", " << tmp->getPeso() << ")" << "| ";
			tmp = tmp->getSig();
		}
		cout << endl;
	}
	void mostrarCont() {
		cout << cont << endl;
	}
	~L8() {}
};