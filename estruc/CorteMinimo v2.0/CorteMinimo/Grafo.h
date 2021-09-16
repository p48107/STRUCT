#pragma once
#include "Vertice.h"
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<random>
#include<list>
#include<vector>
#include<chrono>
#include<string>
#include"string.h"
using namespace std;
template<class tipo>
class Grafo
{
private:
	Vertice **vec;
	int capacidad;
	list<int> lista;
	int total;
public:
	Grafo() {
		capacidad = 201;
		vec = new Vertice*[capacidad];
		//inicializar();
		total = 0;
		//llenarLista();
	}
	int getTotal() {
		return total;
	}
	void setTotal(int t) {
		total = t;
	}
	Vertice *&getVec(int pos) {
		return vec[pos];
	}
	list<int> getLista() {
		return lista;
	}
	void insertarArista(int v1, int v2) {
		vec[v1]->insertar(v2);
		if (vec[v1]->getExiste() != true)
		{
			total++;
		}
		vec[v1]->setExiste(true);
	}
	void llenarLista()
	{
		for (int i = 1; i <= total; i++)
		{
			lista.push_front(i);
		}
		listShuffle(lista);
	}
	void listShuffle(list<int>& L)
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(L.begin(), L.end());
		shuffle(V.begin(), V.end(), gen);
		L.assign(V.begin(), V.end());
	}
	int minCut() {
		int v1 = 0, v2 = 0;
		int min = 0;
		int tmp = total;
		while (tmp > 2) {
			v1 = lista.front();
			//cout << "ITERACION" << endl;
			vec[v1]->listShuffle();
			v2 = vec[v1]->getLista().front();
			reducir(v1, v2);

			/*cout << endl;
			mostrarGrafo();*/
			eliminarAutociclos(v1);

			/*cout << endl;
			mostrarGrafo();*/
			eliminarVertice(v1);
			lista.pop_front();

			/*cout << endl;
			mostrarGrafo();*/
			tmp--;
		}
		min = vec[v2]->getVec(vec[v2]->getLista().front())->getCont();
		return min;
	}
	void reducir(int v1, int v2) {
		for (auto e : vec[v1]->getLista()) {
			if (e != v2) {
				vec[v2]->insertar(e);
				vec[e]->insertar(v2);
				vec[v2]->setCont(vec[e]->getCont());
				vec[e]->setCont(vec[v2]->getCont());
				/*vec[v2]->setExiste(true);
				vec[v2]->setCont(vec[e]->getCont());
				vec[e]->setExiste(true);
				vec[e]->setCont(vec[v2]->getCont());*/
			}
		}
	}
	void eliminarAutociclos(int v1) {
		for (int i = 1; i <= total; i++) {
			if (vec[i]->getVec(v1)->getExiste() == true) {
				vec[i]->eliminar(v1);
				vec[i]->getLista().remove(v1);
			}
		}
	}
	/*void azarArista()
	{
		int num;
		num = lista.front();
		vec[num]->buscarRand();
		lista.pop_front();
	}*/
	void mostrarLista()
	{
		//lista->mostrar();
	}
	void listShow()
	{
		for (auto& e : lista) cout << e << " ";
		cout << endl;
	}
	void gotoxy(int x, int y)  // funcion que posiciona el cursos en la coordenada (x,y)
	{
		HANDLE hCon;
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hCon, dwPos);
	}
	void inicializar() {
		for (int i = 0; i <= capacidad; i++) {
			vec[i] = new Vertice();
			vec[i]->inicializar();
			//vec[i]->setCont(0);
		}
	}
	void inicializarCE() {
		for (int i = 0; i <= capacidad; i++) {
			vec[i]->setCont(0);
			vec[i]->setExiste(false);
		}
	}
	/*void mostrarGrafo() {
		int x = 0;
		int y = 17;
		gotoxy(x, y);
		cout << " vec[pos] | PADRE |     ARISTAS";
		y = y + 2;
		for (int i = 0; i < capacidad; i++) {
			if (vec[i]->getExiste() == true) {
				gotoxy(x, y);
				cout << "vec[" << i << "] = ";
				gotoxy(x + 10, y);
				cout << "|   " << vec[i]->getPadre();
				gotoxy(x + 18, y);
				cout << "| --> ";
				vec[i]->getLista()->mostrar();
				y++;
			}
		}
	}*/
	Grafo<int> *copiar(Grafo<int> *g1) {
		Grafo<int> *tmp = new Grafo<int>();
		memcpy(tmp, g1, sizeof(Grafo<int> *));
		return tmp;
	}
	void eliminarVertice(int i)
	{
		//getVec(i) = NULL;
		vec[i]->setCont(0);
		vec[i]->setExiste(false);
	}
	void mostrarGrafo() {
		for (int i = 0; i <= capacidad; i++) {
			if (vec[i]->getExiste() == true) {
				cout << "vec[" << i << "]" << " --> ";
				vec[i]->mostrar();
				//vec[i]->listShow();
				cout << endl;
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

	~Grafo() {}
};

