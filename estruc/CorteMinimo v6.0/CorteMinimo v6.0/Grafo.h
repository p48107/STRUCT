#pragma once
#include "Vertice.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <list>
#include <iterator>
#include <vector>
#include <chrono>
#include <fstream>
#include <functional>
using namespace std;
template<class tipo>
class Grafo
{
private:
	Vertice<tipo> **vec;
	vector<tipo> lista;
	int tam;
public:
	Grafo(int t) {
		vec = new Vertice<tipo>*[201];
		tam = t;
		inicializar();

	}
	/*void listShuffle()
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(lista.begin(), lista.end());
		shuffle(V.begin(), V.end(), gen);
		lista.assign(V.begin(), V.end());
	}*/
	void inicializarLista() {
		for (int i = 1; i <= tam; i++) {
			lista.push_back(i);
		}
	}
	void listShuffle()
	{
		std::shuffle(lista.begin(), lista.end(), std::mt19937{ std::random_device{}() });
	}
	void insertarArista(int v1, int v2) {
		if (vec[v1]->getExiste() == false) {
			vec[v1]->setExiste(true);
		}
		vec[v1]->insertar(v2);
	}
	void inicializar() {
		for (int i = 1; i <= tam; i++) {
			vec[i] = new Vertice<tipo>();
		}
	}
	void inicializarVertices() {
		lista.clear();
		for (int i = 1; i <= tam; i++) {
			vec[i]->getLista2().clear();
		}
		listShuffle();
	}
	void recuperarDatos() {
		for (int i = 1; i <= tam; i++) {
			vec[i]->recuperar();
			vec[i]->setExiste(true);
		}
	}
	void llenarDatos() {
		for (int i = 1; i <= tam; i++) {
			vec[i]->llenar();
			vec[i]->setExiste(true);
		}
	}
	int minCut() {
		int v1 = 0, v2 = 0;
		int min = 0;
		int tmp = tam;
		int i = 0;
		int it = 0;
		while (tmp > 2) {
			/*cout << "ITERACION" << endl;*/
			v1 = lista[it];
			vec[v1]->listShuffle();
			v2 = vec[v1]->getLista2().front();
			//cout << "v1 = " << v1 << endl;//PRUEBA
			//cout << "v2 = " << v2 << endl;//PRUEBA
			copiarAristas(v1, v2);
			eliminarAutoCiclos(v1);
			vec[v1]->setExiste(false);
			
			//cout << endl;//PRUEBA
			//mostrarGrafo();//PRUEBA
			it++;
			tmp--;
		}
		return min;
	}

	void copiarAristas(int v1, int v2) {
		vector <int> ::iterator it;
		for (it = vec[v1]->getLista2().begin(); it != vec[v1]->getLista2().end(); ++it) {
			if (*it != v2) {
				vec[v2]->add(*it);
				vec[*it]->add(v2);
			}
		}
		//cout << endl;//PRUEBA
		//mostrarGrafo();//PRUEBA
	}
	void eliminarAutoCiclos(int v1) {
		for (int i = 1; i <= tam; i++) {
			vec[i]->eliminar(v1);
		}
		//cout << endl;//PRUEBA
		//mostrarGrafo();//PRUEBA
	}
	void showlist(list<int> g)
	{
		list <int> ::iterator it;
		for (it = g.begin(); it != g.end(); ++it)
			cout << *it << " |";
	}
	void leerArchivo(string texto) {
		ifstream archivo;
		int ady, i = 1;
		archivo.open(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		while (!archivo.eof())
		{
			archivo >> ady;
			if (ady != i) {
				if (ady == -1)
					i++;
				else
					insertarArista(i, ady);
			}
		}
		archivo.close();
	}
	void mostrarGrafo() {
		for (int i = 1; i <= tam; i++) {
			if (vec[i]->getExiste() == true) {
				cout << "vec[" << i << "]" << " --> ";
				vec[i]->showlist();
				cout << endl;
			}
		}
	}
	~Grafo() {}
};

