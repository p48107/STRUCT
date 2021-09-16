#pragma once
#include <iostream>
using namespace std;
template<class tipo>
class Nodo
{
private:
	tipo valor;
	bool presente;
	int izq;
	int der;
	int padre;
	int index;
public:
	Nodo(){
		presente = false;
	}
	tipo getValor() 
	{
		return valor;
	}
	bool getPresente()
	{
		return presente;
	}
	void setValor(tipo v) 
	{
		valor = v;
	}
	void setPresente(bool p) 
	{
		presente = p;
	}
	~Nodo(){}
};

