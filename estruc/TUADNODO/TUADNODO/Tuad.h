#pragma once
#include "L8.h"
#include <vector>
template<class tipo>
class Tuad
{
private:
	int capacidad;
	L8<tipo> **vec;
	vector<int> tmp;
public:
	Tuad()
	{
		capacidad = 380;
		vec = new L8<tipo>*[capacidad];
	}
	int funcionTuad(int d, int m)
	{
		return (d - 1) + (m - 1) * 31;
	}
	Nodo<tipo> *buscar(int d, int m, tipo e)
	{
		Nodo<tipo> *tmp;
		int pos = funcionTuad(d, m);
		tmp = vec[pos]->buscar(e);
		return tmp;
	}
	void insertarL8(int d, int m, tipo e) {
		int pos = funcionTuad(d, m);
		Nodo<tipo> *tmp = buscar(d, m, e);
		if (tmp == NULL)
		{
			vec[pos]->insertarPrincipio(e);
			vec[pos]->setDia(d);
			vec[pos]->setMes(m);
		}
		else
		{
			if (e == tmp->getValor()) {
				cout << "La tarea ya existe" << endl;
			}
			else
			{
				vec[pos]->insertarFinal(e);
				vec[pos]->setDia(d);
				vec[pos]->setMes(m);
			}

		}
	}
	void eliminar(int d, int m, tipo e) {
		int pos = funcionTuad(d, m);
		vec[pos]->eliminar(e);
	}
	void mostrar() {
		for (int i = 0; i < capacidad; i++) {
			if (vec[i]->getCabeza() != NULL) {
				vec[i]->mostrar();
			}
		}
	}
	//DEFENSA
	void insertarFechas(tipo e) {
		fflush(stdin);
		for (int i = 0; i < capacidad; i++) {
			Nodo<tipo> *b = new Nodo<tipo>();
			b = vec[i]->buscar(e);
			if (b != NULL) 
			{
				if (b->getValor() == e)
					tmp.push_back(i);
			}
		}
		/*for (unsigned i = 0; i < tmp.size(); i++) {
			cout << vec[tmp[i]]->getDia() << " / " << vec[tmp[i]]->getMes() << endl;
		}*/
	}
	void mostrarFecha() {
		for (unsigned i = 0; i < tmp.size(); i++) {
			cout << vec[tmp[i]]->getDia() << " / " << vec[tmp[i]]->getMes() << endl;
		}
	}
	void inicializar() {
		for (int i = 0; i < capacidad; i++) {
			vec[i] = new L8<tipo>();
		}
	}
	~Tuad() {}
};