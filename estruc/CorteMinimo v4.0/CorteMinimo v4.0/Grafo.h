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
	Grafo() {
		vec = new Vertice<tipo>*[201];
		//vec = new list<tipo>[201];
		inicializarVertices();
		tam = 0;
	}
	list<tipo> getLista() {
		return lista;
	}
	void listShuffle()
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(lista.begin(), lista.end());
		shuffle(V.begin(), V.end(), gen);
		lista.assign(V.begin(), V.end());
	}
	void inicializar() {
		for (int i = 1; i <= tam; i++) {
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
	void insertarArista(int v1, int v2) {
		if (vec[v1]->getExiste() == false) {
			vec[v1]->setExiste(true);
			tam++;
		}
		vec[v1]->insertar(v2);
	}
	void llenarDatos() {
		for (int i = 1; i <= tam; i++) {
			vec[i]->llenar();
		}
	}
	void recuperaDatos() {
		for (int i = 1; i <= tam; i++) {
			vec[i]->setExiste(true);
			vec[i]->inicializar();
			vec[i]->recupera();
		}
	}
	int minCut() {
		int v1 = 0, v2 = 0;
		int min = 0;
		int tmp = tam;
		while (tmp > 2) {
			v1 = lista.front();
			vec[v1]->listShuffle();
			v2 = vec[v1]->getLista2().front();
			reducir(v1, v2);
			eliminarAutoCiclos(v1);
			vec[v1]->setExiste(false);
			lista.pop_front();
			/*cout << endl;
			mostrarGrafo();*/
			tmp--;
		}
		/*int ver1;
		ver1 = lista.front();
		int ver2;
		ver2 = lista.back();*/
		min = vec[lista.front()]->getVec(lista.back());
		return min;
	}

	void reducir(int v1, int v2) {
		list <int> ::iterator it;
		for (it = vec[v1]->getLista2().begin(); it != vec[v1]->getLista2().end(); ++it) {
			if (*it != v2) {
				vec[v2]->getLista2().push_back(*it);
				vec[*it]->getLista2().push_back(v2);
				vec[v2]->setVec(*it, vec[v1]->getVec(*it) + vec[v2]->getVec(*it));
				vec[*it]->setVec(v2, vec[v2]->getVec(*it) /*+ vec[*it]->getVec(v2)*/);
			}
		}
		//cout << endl;
		//mostrarGrafo();
	}
	void eliminarAutoCiclos(int v1) {
		for (int i = 1; i <= tam; i++) {
			if (vec[i]->getVec(v1) != 0) {
				vec[i]->eliminar(v1);
			}
		}
		/*cout << endl;
		mostrarGrafo();*/
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
				//vec[i]->showlist();
				vec[i]->showVec();
				cout << endl;
			}
		}
	}
	void inicializarLista() {
		lista.clear();
		for (int i = 1; i <= tam; i++) {
			lista.push_back(i);
		}
		listShuffle();
	}
	~Grafo() {}
};

