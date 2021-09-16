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
		cabeza = NULL;
		ultimo = NULL;
		cont = 0;
	}
	NodoL *getCabeza() {
		return cabeza;
	}
	int getCont() {
		return cont;
	}
	void setCont(int c) {
		cont = c;
	}
	void insertarPrincipio(string n, float p) {
		if (cabeza == NULL) {
			cabeza = new NodoL();
			ultimo = cabeza;
			cabeza->setNombre(n);
			cabeza->setPrecio(p);
		}
		else {
			NodoL *tmp = new NodoL();//ant,sig NULL
			tmp->setNombre(n);
			tmp->setPrecio(p);
			tmp->setSig(cabeza);
			cabeza->setAnt(tmp);
			cabeza = tmp;
		}
		cont++;
	}
	void insertarFinal(string n, float p) {
		if (ultimo == NULL) {
			insertarPrincipio(n, p);
		}
		else {
			NodoL *tmp = new NodoL();//ant,sig NULL
			tmp->setNombre(n);
			tmp->setPrecio(p);
			tmp->setAnt(ultimo);
			ultimo->setSig(tmp);
			ultimo = tmp;
		}
		cont++;
	}
	void insertarEnSuLugar(string n, float p)
	{
		NodoL *tmp = new NodoL();
		tmp->setPrecio(p);
		tmp->setNombre(n);
		if (cabeza == NULL)
		{
			insertarPrincipio(n, p);
		}
		else
		{
			if (tmp->getPrecio() < cabeza->getPrecio())
			{
				insertarPrincipio(n, p);
			}
			else
			{
				if (tmp->getPrecio() > ultimo->getPrecio())
				{
					insertarFinal(n, p);
				}
				else
				{
					NodoL *aux = cabeza->getSig();
					while (aux->getPrecio() < tmp->getPrecio())
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
	/*NodoL *buscar(tipo el) {
		NodoL<tipo> *ind = new NodoL<tipo>();
		NodoL<tipo> *tmp = NULL;
		ind = cabeza;
		while (ind != NULL && tmp == NULL)
		{
			if (el == ind->getValor())
			{
				tmp = ind;
			}
			ind = ind->getSig();
		}
		//}
		return tmp;
	}*/
	
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
	void eliminar(string n, float p) {
		NodoL *tmp;
		if (cabeza != NULL)
		{
			if (cabeza->getNombre() == n && cabeza->getPrecio() == p)
			{
				eliminarCabeza();
			}
			else
			{
				if (ultimo->getNombre() == n && ultimo->getPrecio() == p)
				{
					eliminarUltimo();
				}
				else
				{
					tmp = cabeza->getSig();
					while (tmp != NULL) {
						if (tmp->getNombre() == n && tmp->getPrecio() == p)
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
		while (tmp != NULL){
			cout << "\tPagina Web: " << tmp->getNombre() << "| ";
			cout << "Precio: " << tmp->getPrecio() << endl;
			tmp = tmp->getSig();
		}
	}
	void mostrarCont() {
		cout << cont << endl;
	}
	~L8() {}
};