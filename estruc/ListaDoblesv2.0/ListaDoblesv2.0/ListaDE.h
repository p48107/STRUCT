#pragma once
#include "Nodo.h"
template<class tipo>
class ListaDE
{
private:
	Nodo<tipo> *cabeza;
	Nodo<tipo> *cola;
	int cont;
public:
	ListaDE() {
		cabeza = NULL;
		cola = NULL;
		cont = 0;
	}
	void insertarPrincipio(tipo t) {
		if (cabeza == NULL) {
			cabeza = new Nodo<tipo>();
			cola = cabeza;
			cabeza->setValor(t);
		}
		else {
			Nodo<tipo> *tmp = new Nodo<tipo>();//ant,sig NULL
			tmp->setValor(t);
			tmp->setSig(cabeza);
			cabeza->setAnt(tmp);
			cabeza = tmp;
		}
		cont++;
	}
	void insertarFinal(tipo t) {
		if (cola == NULL) {
			insertarPrincipio(t);
		}
		else {
			Nodo<tipo> *tmp = new Nodo<tipo>();//ant,sig NULL
			tmp->setValor(t);
			tmp->setAnt(cola);
			cola->setSig(tmp);
			cola = tmp;
		}
		cont++;
	}
	void insertarSuLugar(tipo t) 
	{
		Nodo<tipo> *tmp = new Nodo<tipo>();
		Nodo<tipo> *nuevo = NULL;
		if (cabeza == NULL || cabeza->getValor() > t)
			insertarPrincipio(t);
		else
		{
			if (cola->getValor() < t)
				insertarFinal(t);
			else
			{
				tmp = cabeza;//tmp es TEMPORAL ACTUAL
				while (nuevo == NULL)
				{
					if (t < tmp->getValor())
					{
						nuevo = new Nodo<tipo>();//TEMPORAL A INSERTAR
						nuevo->setValor(t);
						nuevo->setSig(tmp);
						nuevo->setAnt(tmp->getSig());
						tmp->getAnt()->setSig(nuevo);
						tmp->setAnt(nuevo);
					}
					else
					{
						tmp = tmp->getSig();
					}
				}
			}
		}
		cont++;
	}
	void eliminarCabeza() {
		if (cabeza != NULL) {
			if (cont == 1) {
				cabeza->~Nodo();
				cola->~Nodo();
				cabeza = NULL;
				cola = NULL;
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
	void eliminarCola() {
		if (cola != NULL) {
			if (cont == 1) {
				cabeza->~Nodo();
				cola->~Nodo();
				cabeza = NULL;
				cola = NULL;
			}
			else
			{
				Nodo<tipo> *tmp;
				tmp = cola;
				tmp->getAnt()->setSig(NULL);
				cola->~Nodo();
				cola = tmp->getAnt();
			}
			cont--;
		}
	}
	void eliminarPorValor(tipo t) {
		Nodo<tipo> *tmp;
		if (cabeza != NULL) 
		{
			if (cabeza->getValor() == t) 
			{
				eliminarCabeza();
			}
			else
			{
				if (cola->getValor() == t)
				{
					eliminarCola();
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
	int candidadNodos() 
	{
		return cont;
	}
	void mostrar() {
		Nodo<tipo> *tmp = new Nodo<tipo>();
		tmp = cabeza;
		cout << "| ";
		while (tmp != NULL) {
			cout << tmp->getValor() << " | ";
			tmp = tmp->getSig();
		}
		cout << endl;
	}
	/*l1->insertarPrincipio(5);
	l1->insertarPrincipio(1);
	l1->insertarFinal(10);
	l1->insertarPrincipio(7);
	l1->insertarEnSuLugar(2);
	l1->eliminarPrincipio();
	l1->eliminarFinal();
	l1->eliminarPorValor(7);
	l1->mostrar();*/
};

