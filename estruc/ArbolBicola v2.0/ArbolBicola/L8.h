#pragma once
#include "NodoL.h"
#include <string>
template<class tipo>
class L8
{
private:
	NodoL<tipo> *cabeza;
	NodoL<tipo> *ultimo;
	int cont;
public:
	L8() {
		cabeza = NULL;
		ultimo = NULL;
		cont = 0;
	}
	NodoL<tipo> *&getCabeza() {
		return cabeza;
	}
	NodoL<tipo> *&getUltimo() {
		return ultimo;
	}
	int getCont() {
		return cont;
	}
	void setCont(int c) {
		cont = c;
	}
	void insertarPrincipio(int v) {
		if (cabeza == NULL) {
			cabeza = new NodoL();
			ultimo = cabeza;
			cabeza->setValor(v);
		}
		else 
		{
			NodoL *tmp = new NodoL();//ant,sig NULL
			tmp->setValor(v);
			tmp->setSig(cabeza);
			cabeza->setAnt(tmp);
			cabeza = tmp;
		}
		cont++;
	}
	void insertarFinal(int v) {
		if (ultimo == NULL) {
			insertarPrincipio(v);
		}
		else {
			NodoL *tmp = new NodoL();//ant,sig NULL
			tmp->setValor(v);
			tmp->setAnt(ultimo);
			ultimo->setSig(tmp);
			ultimo = tmp;
		}
		cont++;
	}
	void insertarEnSuLugar(int v)
	{
		NodoL *tmp = new NodoL();
		tmp->setValor(v);
		if (cabeza == NULL)
		{
			insertarPrincipio(v);
		}
		else
		{
			if (tmp->getValor() < cabeza->getValor())
			{
				insertarPrincipio(v);
			}
			else
			{
				if (tmp->getValor() > ultimo->getValor())
				{
					insertarFinal(v);
				}
				else
				{
					NodoL *aux = cabeza->getSig();
					while (aux->getValor() < tmp->getValor())
					{
						aux = aux->getSig();
					}
					aux->getAnt()->setSig(tmp);
					tmp->setAnt(aux->getAnt());
					aux->setAnt(tmp);
					tmp->setSig(aux);
				}
			}
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
	void mostrar() {
		NodoL *tmp;
		tmp = cabeza;
		while (tmp != NULL) {
			cout << tmp->getValor() << "| ";
			tmp = tmp->getSig();
		}
		cout << endl;
	}
	void mostrarCont() {
		cout << cont << endl;
	}
	~L8() {}
};