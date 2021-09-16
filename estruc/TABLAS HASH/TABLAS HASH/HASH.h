#pragma once
#include "L8.h"
#include <math.h>
#include <fstream>
template<class tipo>
class Hash
{
private:
	int capacidad;
	L8<tipo> **vec;
public:
	Hash(int c) 
	{
		capacidad = c;
		vec = new L8<tipo>*[capacidad];
	}
	int funcionHashResiduo(string s) 
	{
		int pos = 0;
		for (int i = 0; i < s.size(); i++) {
			pos = pos + (s[i] * 2 ^ i);
		}
		pos = pos % capacidad;
		return pos;
	}
	/*int funcionHashMultiplicacion(string s)
	{
		int mult, piso, fraccion, pos, tmp;
		tmp = 0;
		for (int i = 0; i < s.size(); i++) {
			tmp = tmp + (s[i] * 2 ^ i);
		}
		mult = (tmp * (sqrt(5) - 1) / 2);
		piso = floor(mult);
		fraccion = mult - floor;
		pos = floor(fraccion * capacidad);
		return pos;
	}*/
	void insertarL8(tipo e, float p, int c) 
	{
		int pos = funcionHashResiduo(e);
		Nodo<tipo> *tmp = buscar(e);
		if (tmp == NULL && vec[pos]->getCont() < 8)//CONTROLA QUE NO SOBREPASE
		{
			vec[pos]->insertarPrincipio(e,p,c);
		}
		else
		{
			vec[pos]->insertarFinal(e,p,c);
		}
	}
	void eliminar(tipo e) 
	{
		int pos = funcionHashResiduo(e);
		vec[pos]->eliminarProducto(e);
	}
	Nodo<tipo> *buscar(tipo e)
	{
		Nodo<tipo> *tmp;
		int pos = funcionHashResiduo(e);
		tmp = vec[pos]->buscar(e);
		return tmp;
	}
	void leerArchivo(string texto) 
	{
		char linea[128];
		string tmp;
		ifstream archivo(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		else
			while (!archivo.eof())
			{
				archivo.getline(linea, sizeof(linea));
				tmp = linea;
				insertarL8(tmp, 0, 0);
			}
		archivo.close();
	}
	/*
	void compra(tipo e, int c) 
	{
		Nodo<tipo> *tmp = buscar(e);
		int pos = funcionHashResiduo(e);
		if (tmp != NULL) {
			tmp->setCant(tmp->getCant() + c);
		}
		else
		{
			insertarL8(e);
			vec[pos]->
		}
	}*/
	void venta(tipo e, int cant) 
	{

	}
	void mostrar() 
	{
		for (int i = 0; i < capacidad; i++) {
			if (vec[i]->getCabeza() != NULL) {
				vec[i]->mostrar();
			}
		}
	}
	void inicializar() 
	{
		for (int i = 0; i < capacidad; i++) {
			vec[i] = new L8<tipo>();
		}
	}
	~Hash(){
	}
};