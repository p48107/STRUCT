#pragma once
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
	vector<tipo> lista;
	vector<tipo> lista2;
	bool existe;
public:
	Vertice() {
		lista2.clear();
		existe = false;
	}
	void setExiste(bool e) {
		existe = e;
	}
	bool getExiste() {
		return existe;
	}
	vector<tipo> getLista() {
		return lista;
	}
	vector<tipo> &getLista2() {
		return lista2;
	}
	void add(int v) {
		lista2.push_back(v);
	}
	/*void listShuffle()
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(lista2.begin(), lista2.end());
		shuffle(V.begin(), V.end(), gen);
		lista2.assign(V.begin(), V.end());
	}*/
	void listShuffle()
	{
		std::shuffle(lista2.begin(), lista2.end(), std::mt19937{ std::random_device{}() });
	}
	void insertar(int i) {
		lista.push_back(i);
		//vec.insert(it, 1);
	}
	void recuperar() {
		lista2.resize(lista.size());
		for (int it = 0; it != lista2.size() ; it++) {
			lista2[it] = lista[it];
		}
	}
	void llenar() {
		vector <int> ::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it) {
			lista2.push_back(*it);
		}
	}
	void eliminar(int v)
	{
		int i = 0;
		auto it = remove(lista2.begin(), lista2.end(), v);
		//vector <int> ::iterator it1;
		/*for (it1 = lista2.begin(); it1 != it; ++it1)
			i++;*/
		//int s = it - lista2.begin();
		lista2.resize(it - lista2.begin());
	}
	void showlist()
	{
		vector <int> ::iterator it;
		for (it = lista2.begin(); it != lista2.end(); ++it)
			cout << *it << " |";
	}
	~Vertice() {}
};

