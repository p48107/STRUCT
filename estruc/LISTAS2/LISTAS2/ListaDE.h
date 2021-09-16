#pragma once
#include "Nodo.h"
#include <iostream>
template<class t>
class ListaDE
{
	Nodo<t> *primer;
	Nodo<t> *ultimo;
	int cont;
public:
	void insertarPrincipio(int el):
	void insertarFinal();
	void insertarSuLugar();
	void eliminarPrincipio();
	void eliminarFinal();
	void eliminarPos();
	void mostrar();
	void tamaño();
	ListaDE();
	~ListaDE();
};
template<class t>
inline void ListaDE<t>::insertarFinal()
{

}
