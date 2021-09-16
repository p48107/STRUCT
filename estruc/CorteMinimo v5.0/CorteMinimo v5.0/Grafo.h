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
	list<tipo> lista;
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
	void listShuffle()
	{
		std::vector< std::reference_wrapper< const tipo > > vec(lista.begin(), lista.end());
		std::shuffle(vec.begin(), vec.end(), std::mt19937{ std::random_device{}() });
		std::list<tipo> shuffled_list{ vec.begin(), vec.end() };
		lista.swap(shuffled_list);
	}
	void insertarArista(int v1, int v2) {
		if (vec[v1]->getExiste() == false) {
			vec[v1]->setExiste(true);
		}
		vec[v1]->insertar(v2);
	}
	void inicializar() {
		lista.clear();
		for (int i = 1; i <= tam; i++) {
			lista.push_back(i);
			vec[i] = new Vertice<tipo>();
		}
		listShuffle();
	}
	void inicializarVertices() {
		lista.clear();
		for (int i = 1; i <= tam; i++) {
			lista.push_back(i);
			vec[i]->getLista2().clear();
		}
		listShuffle();
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
		while (tmp > 2) {
			/*cout << "ITERACION" << endl;*/
			v1 = lista.front();
			vec[v1]->listShuffle();
			v2 = vec[v1]->getLista2().front();
			/*cout << "v1 = " << v1 << endl;
			cout << "v2 = " << v2 << endl;*/
			copiarAristas(v1, v2);
			eliminarAutoCiclos(v1);
			vec[v1]->setExiste(false);
			lista.pop_front();
			/*cout << endl;
			mostrarGrafo();*/
			tmp--;
		}
		return min;
	}

	void copiarAristas(int v1, int v2) {
		list <int> ::iterator it;
		for (it = vec[v1]->getLista2().begin(); it != vec[v1]->getLista2().end(); ++it) {
			if (*it != v2) {
				vec[v2]->add(*it);
				vec[*it]->add(v2);
			}
		}
		/*cout << endl;
		mostrarGrafo();*/
	}
	void eliminarAutoCiclos(int v1) {
		for (int i = 1; i <= tam; i++) {
			vec[i]->eliminar(v1);
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
				vec[i]->showlist();
				cout << endl;
			}
		}
	}
	~Grafo() {}
};

