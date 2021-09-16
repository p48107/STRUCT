#pragma once
#include <list>
#include <iterator>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
using namespace std;
template<class tipo>
class Vertice
{
private:
	int vec[201];
	list<tipo> lista;
	list<tipo> lista2;
	bool existe;
public:
	Vertice(){
		inicializar();
	}
	void setExiste(bool e) {
		existe = e;
	}
	bool getExiste() {
		return existe;
	}
	list<tipo> getLista() {
		return lista;
	}
	list<tipo> &getLista2() {
		return lista2;
	}
	void setVec(int i, v) {
		vec[i] = v;
	}
	int getVec(int i) {
		return vec[i];
	}
	void inicializar() {
		for (int i = 0; i <= 200; i++) {
			vec[i] = 0;
		}
		lista2.clear();
	}
	void insertar(int i) {
		lista.push_back(i);
		vec[i] = 1;
	}
	void llenar() {
		list <int> ::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it) {
			vec[*it] = 1;
			lista2.push_back(*it);
		}
	}
	void listShuffle()
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(lista2.begin(), lista2.end());
		shuffle(V.begin(), V.end(), gen);
		lista2.assign(V.begin(), V.end());
	}
	void showlist()
	{
		list <int> ::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it)
			cout << *it << " |";
	}
	~Vertice(){}
};

