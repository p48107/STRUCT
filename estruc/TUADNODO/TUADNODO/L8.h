#pragma once
#include "Nodo.h"
template<class tipo>
class L8
{
private:
	Nodo<tipo> *cabeza;
	Nodo<tipo> *ultimo;
	int dia;
	int mes;
	int cont;
public:
	L8() {
		cabeza = NULL;
		ultimo = NULL;
		dia = 0;
		mes = 0;
		cont = 0;
	}
	Nodo<tipo> *getCabeza() {
		return cabeza;
	}
	void setDia(int d) {
		dia = d;
	}
	void setMes(int m) {
		mes = m;
	}
	int getDia() {
		return dia;
	}
	int getMes() {
		return mes;
	}
	void insertarPrincipio(tipo t) {
		if (cabeza == NULL) {
			cabeza = new Nodo<tipo>();
			ultimo = cabeza;
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
		if (ultimo == NULL) {
			insertarPrincipio(t);
		}
		else {
			Nodo<tipo> *tmp = new Nodo<tipo>();//ant,sig NULL
			tmp->setValor(t);
			tmp->setAnt(ultimo);
			ultimo->setSig(tmp);
			ultimo = tmp;
		}
		cont++;
	}
	Nodo<tipo> *buscar(tipo el) {
		Nodo<tipo> *ind = new Nodo<tipo>();
		//Nodo<tipo> *tmp = new Nodo<tipo>();
		Nodo<tipo> *tmp = NULL;
		/*if (cont == 0)
			tmp = NULL;
		else*/
		//{
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
				cabeza->~Nodo();
				ultimo->~Nodo();
				cabeza = NULL;
				ultimo = NULL;
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
	void eliminar(tipo t) {
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
		cout << "################ " << endl;
		cout << dia << " / " << mes << endl;
		while (tmp != NULL) {
			cout << "\t- " << tmp->getValor() << endl;
			tmp = tmp->getSig();
		}
		cout << "################ " << endl;
		cout << endl;
	}
	~L8(){}
};