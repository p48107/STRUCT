#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include<algorithm>
#include<random>
#include<list>
#include<vector>
#include<chrono>
using namespace std;
class Vertice
{
private:
	string nombre;
	Vertice **vec;
	int contador;
	bool existe;
	int capacidad;
	list<int> lista;
public:
	Vertice() {
		capacidad = 201;
		vec = new Vertice*[capacidad];
		contador = 0;
		existe = false;
		//lista.clear();
	}
	Vertice *&getVec(int pos) {
		return vec[pos];
	}
	list<int> &getLista() {
		return lista;
	}
	void setLista(list<int> L) {
		lista = L;
	}   
	void eliminar(int i)
	{
		getVec(i)->setCont(0);
		getVec(i)->setExiste(false);
		//getVec(i) = NULL;
	}
	void insertar(int i) {
		if (vec[i]->getExiste() != true) {
			vec[i]->setExiste(true);
			lista.push_back(i);
		}
		vec[i]->setCont(vec[i]->getCont() + 1);
		contador++;
	}
	void listShuffle()
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(lista.begin(), lista.end());
		shuffle(V.begin(), V.end(), gen);
		lista.assign(V.begin(), V.end());
	}
	void inicializar() {
		for (int i = 0; i < capacidad; i++) {
			vec[i] = new Vertice();
			vec[i]->getVec(i) = NULL;
		}
	}
	void inicializarCE() {
		for (int i = 0; i < capacidad; i++) {
			vec[i]->setCont(0);
			vec[i]->setExiste(false);
		}
	}
	void listShow()
	{
		for (auto& e : lista) cout << e << "| ";
		cout << endl;
	}
	bool getExiste() {
		return existe;
	}
	void setExiste(bool e) {
		existe = e;
	}
	string getNombre() {
		return nombre;
	}
	void setNombre(string n) {
		nombre = n;
	}
	int getCont() {
		return contador;
	}
	void setCont(int c) {
		contador = c;
	}
	void mostrar() {
		for (int i = 0; i < capacidad; i++) {
			if (vec[i]->getExiste() == true) {
				cout << i << "(" << vec[i]->getCont() << ")" << "| ";
			}
		}
	}
	~Vertice() {}
};


