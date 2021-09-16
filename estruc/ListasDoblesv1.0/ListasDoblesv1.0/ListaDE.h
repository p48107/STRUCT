#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
template <class t>
class ListaDE
{
	Nodo<t> *primer;
	Nodo<t> *ultimo;
	int cont;
public:
	ListaDE() {
		primer = NULL;
		ultimo = NULL;
		cont = 0;
	}
	Nodo<t> * getPrimer()
	{
		return primer;
	}
	int getCont()
	{
		return cont;
	}
	void setCont(int c)
	{
		cont = c;
	}
	void insertarPrincipio(t el)
	{
		if (primer == NULL) {
			primer = new Nodo<t>();
			ultimo = primer;
			primer->setValor(el);
		}
		else {
			Nodo<t> *aux;
			aux = new Nodo<t>();
			aux->setSig(primer);
			primer->setAnt(aux);
			aux->setValor(el);
			primer = aux;
		}
		setCont(getCont() + 1);
	}
	void insertarFinal(t el)
	{
		if (primer == NULL) {
			primer = new Nodo<t>();
			ultimo = primer;
			primer->setValor(el);
		}
		else
		{
			Nodo<t> *aux;
			aux = new Nodo<t>();
			aux->setAnt(ultimo);
			ultimo->setSig(aux);
			aux->setValor(el);
			ultimo = aux;
		}
		setCont(getCont() + 1);
	}
	void insertarEnSuLugar(t el)
	{
		if (primer == NULL)
		{
			insertarPrincipio(el);
		}
		else
		{
			if (ultimo->getValor() < el)
			{
				insertarFinal(el);
			}
			if (primer->getValor() > el)
			{
				insertarPrincipio(el);
			}
			else
			{
				Nodo<t> *aux, *nuevo;
				nuevo = new Nodo<t>;
				aux = primer;
				while (aux->getSig() != ultimo)
				{
					if (el < aux->getValor())
					{
						nuevo->setValor(el);
						nuevo->setSig(aux);
						nuevo->setAnt(aux->getAnt());
						aux->getAnt()->setSig(nuevo);
						aux->setAnt(nuevo);
					}
					else
					{
						aux = aux->getSig();
					}
				}
			}
		}

		setCont(getCont() + 1);
	}
	void eliminarPrincipio()
	{
		if (primer != NULL)
		{
			if (cont > 1)
			{
				Nodo<t> *aux;
				aux = primer;
				aux->getSig()->setAnt(NULL);
				primer->~Nodo();
				primer = aux->getSig();
			}
			else
			{
				primer->~Nodo();
				primer = NULL;
				ultimo = NULL;
			}
		}
		setCont(getCont() - 1);
	}
	void eliminarFinal()
	{
		if (primer != NULL)
		{
			if (cont > 1)
			{
				Nodo<t> *aux;
				aux = ultimo;
				aux->getAnt()->setSig(NULL);
				ultimo->~Nodo();
				ultimo = aux->getAnt();
			}
			else
			{
				primer->~Nodo();
				primer = NULL;
				ultimo = NULL;
			}
		}
		setCont(getCont() - 1);
	}
	void eliminarPorValor(t el)
	{
		if (primer != NULL)
		{
			Nodo<t> *aux;
			aux = primer;
			if (primer->getValor() == el)
			{
				eliminarPrincipio();
			}
			else
			{
				while (aux->getSig() != ultimo)
				{
					if (aux->getValor() == el)
					{
						aux->getAnt()->setSig(aux->getSig());
						aux->getSig()->setAnt(aux->getAnt());
						aux->~Nodo();
					}
					else
					{
						aux = aux->getSig();
					}
				}
				setCont(getCont() - 1);
			}
			//if (ultimo->getValor() == el)
			//{
			//	eliminarFinal();
			//}
		}
	}

	void mostrar()
	{
		if (primer != NULL)
		{
			Nodo<t> *aux;
			aux = primer;
			while (aux != ultimo) {
				cout << aux->getValor() << endl;
				aux = aux->getSig();
			}
			aux = ultimo;
			cout << aux->getValor() << endl;
		}
	}
	~ListaDE() {}
};
