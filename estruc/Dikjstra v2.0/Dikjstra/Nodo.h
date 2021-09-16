#pragma once
#include <iostream>
using namespace std;
template<class tipo>
class Nodo
{
private:
	tipo valor;
	tipo vertice;
	bool presente;
public:
	Nodo() {
		presente = false;
	}
	tipo getValor()
	{
		return valor;
	}
	tipo getVertice()
	{
		return vertice;
	}
	bool getPresente()
	{
		return presente;
	}
	void setValor(tipo v)
	{
		valor = v;
	}
	void setVertice(tipo v)
	{
		vertice = v;
	}
	void setPresente(bool p)
	{
		presente = p;
	}
	~Nodo() {}
};

