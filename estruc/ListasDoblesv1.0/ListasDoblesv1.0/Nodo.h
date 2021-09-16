#pragma once
#include <iostream>
template <class t>
class Nodo
{
private:
	t valor;
	Nodo * sig;
	Nodo * ant;
public:
	void setValor(t v)
	{
		valor = v;
	}
	t getValor()
	{
		return valor;
	}
	void inline setSig(Nodo* n)
	{
		sig = n;
	}
	Nodo* getSig()
	{
		return sig;
	}
	void setAnt(Nodo* n)
	{
		ant = n;
	}
	Nodo* getAnt()
	{
		return ant;
	}
	Nodo()
	{
		sig = NULL;
		ant = NULL;
	}
	~Nodo() {}
};
