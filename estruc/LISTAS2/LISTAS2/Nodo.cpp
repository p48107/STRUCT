#include "pch.h"
#include "Nodo.h"
#include <iostream>
template<class t>
Nodo<t>::Nodo()
{
	sig = NULL;
	ant = NULL;
}

template<class t>
void Nodo<t>::setValor(t v)
{
	valor = v;
}

template<class t>
t Nodo<t>::getValor()
{
	return valor;
}

template<class t>
void Nodo<t>::setSig(Nodo * s)
{
	sig = s;
}

template<class t>
Nodo<t> * Nodo<t>::getSig()
{
	return sig;
}

template<class t>
void Nodo<t>::setAnt(Nodo * s)
{
	ant = s;
}

template<class t>
Nodo<t> * Nodo<t>::getAnt()
{
	return ant;
}