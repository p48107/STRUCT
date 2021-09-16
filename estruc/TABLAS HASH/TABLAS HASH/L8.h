#pragma once
#include "Nodo.h"
template<class tipo>
class L8
{
private:
	Nodo<tipo> *cabeza;
	Nodo<tipo> *ultimo;
	int cont;
public:
	L8() {
		cabeza = NULL;
		ultimo = NULL;
		cont = 0;
	}
	Nodo<tipo> *getCabeza() {
		return cabeza;
	}
	int getCont() {
		return cont;
	}
	void insertarPrincipio(tipo t, float p, int c) {
		if (cabeza == NULL) {
			cabeza = new Nodo<tipo>();
			ultimo = cabeza;
			cabeza->setValor(t);
		}
		else {
			Nodo<tipo> *tmp = new Nodo<tipo>();//ant,sig NULL
			tmp->setValor(t);
			tmp->setPrecio(p);
			tmp->setCant(c);
			tmp->setSig(cabeza);
			cabeza->setAnt(tmp);
			cabeza = tmp;
		}
		cont++;
	}
	void insertarFinal(tipo t, float p, int c) {
		if (ultimo == NULL) {
			insertarPrincipio(t,p,c);
		}
		else {
			Nodo<tipo> *tmp = new Nodo<tipo>();//ant,sig NULL
			tmp->setValor(t);
			tmp->setPrecio(p);
			tmp->setCant(c);
			tmp->setAnt(ultimo);
			ultimo->setSig(tmp);
			ultimo = tmp;
		}
		cont++;
	}
	Nodo<tipo> *buscar(tipo el) {
		Nodo<tipo> *ind = new Nodo<tipo>();
		Nodo<tipo> *tmp = NULL;
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
	}
	void eliminarCabeza() {
		if (cabeza != NULL) {
			if (cont == 1) {
				cabeza->~Nodo();
				ultimo->~Nodo();
				cabeza = NULL;
				ultimo = NULL;
			}
			else
			{
				Nodo<tipo> *tmp;
				tmp = cabeza;
				tmp->getSig()->setAnt(NULL);
				cabeza->~Nodo();
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
				Nodo<tipo> *tmp;
				tmp = ultimo;
				tmp->getAnt()->setSig(NULL);
				ultimo->~Nodo();
				ultimo = tmp->getAnt();
			}
			cont--;
		}
	}
	void eliminarProducto(tipo t) {
		Nodo<tipo> *tmp;
		if (cabeza != NULL)
		{
			if (cabeza->getValor() == t)
			{
				eliminarCabeza();
			}
			else
			{
				if (ultimo->getValor() == t)
				{
					eliminarUltimo();
				}
				else
				{
					tmp = cabeza->getSig();
					while (tmp != NULL) {
						if (tmp->getValor() == t)
						{
							tmp->getAnt()->setSig(tmp->getSig());
							tmp->getSig()->setAnt(tmp->getAnt());
							tmp->~Nodo();
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
		Nodo<tipo> *tmp = new Nodo<tipo>();
		tmp = cabeza;
		while (tmp != NULL) {
			cout << "################ " << endl;
			cout << "\tProducto: " << tmp->getValor() << endl;
			cout << "\tPrecio: " << tmp->getPrecio() << endl;
			cout << "\tCantidad: " << tmp->getCant() << endl;
			cout << "################ " << endl;
			tmp = tmp->getSig();
		}
		cout << endl;
	}
	~L8() {}
};