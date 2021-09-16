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
using namespace std;
template<class tipo>
class Grafo
{
private:
	Vertice<tipo> **vec;
	//list<tipo> *vec;
	list<tipo> lista;
	int tam;
public:
	Grafo(){
		vec = new Vertice<tipo>*[201];
		//vec = new list<tipo>[201];
		inicializarVertices();
		tam = 0;
	}
	void inicializar() {
		for (int i = 1; i <= 200; i++) {
			vec[i]->inicializar();
			vec[i]->setExiste(false);
			lista.push_back(i);
		}
		listShuffle();
	}
	void inicializarVertices() {
		for (int i = 1; i <= 200; i++) {
			vec[i] = new Vertice<tipo>();
			vec[i]->setExiste(false);
			lista.push_back(i);
		}
		listShuffle();
	}
	void llenarDatos() {
		for (int i = 1; i <= 200; i++) {
			vec[i]->llenar();
		}
	}
	void listShuffle()
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(lista.begin(), lista.end());
		shuffle(V.begin(), V.end(), gen);
		lista.assign(V.begin(), V.end());
	}
	list<tipo> getLista() {
		return lista;
	}
	void showlist(list<int> g)
	{
		list <int> ::iterator it;
		for (it = g.begin(); it != g.end(); ++it)
			cout << *it << " |";
	}
	void mostrarGrafo() {
		for (int i = 1; i <= 200; i++) {
			if (vec[i]->getExiste() == true) {
				cout << "vec[" << i << "]" << " --> ";
				vec[i]->showlist();
				//vec[i]->listShow();
				cout << endl;
			}
		}
	}
	void insertarArista(int v1, int v2) {
		vec[v1]->insertar(v2);
		vec[v1]->setExiste(true);
	}
	int minCut() {
		int v1 = 0, v2 = 0;
		int min = 0;
		int tmp = 200;
		while (tmp > 2) {
			v1 = lista.pop_front();
			vec[v1]->listShuffle();
			v2 = vec[v1]->getLista2().front();
		}
	}
	void reducir(int v1, int v2) {
		list <int> ::iterator it;
		for (it = vec[v1]->getLista2().begin(); it != vec[v1]->getLista2().end(); ++it) {
			if (*it != v2) {
				if (vec[v2]->getVec(it) == 0) {
					vec[v2]->insertar(it);
				}
				else
				{
					vec[v2]->setVec(it, vec[v1]->getVec(it) + vec[v2]->getVec(it));
					vec[v2]->getLista2().push_back(it);
				}
			}
		}
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
	~Grafo(){}
};

