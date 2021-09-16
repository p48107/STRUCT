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
	vector<tipo> vec;
	list<tipo> lista;
	list<tipo> lista2;
	bool existe;
public:
	Vertice() {
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
	int getVec(int i) {
		return vec[i];
	}
	void setVec(int i, int v) {
		vec[i] = v;
	}
	void listShuffle()
	{
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		vector<int> V(lista2.begin(), lista2.end());
		shuffle(V.begin(), V.end(), gen);
		lista2.assign(V.begin(), V.end());
	}
	void inicializar() {
		vec.clear();
		for (int i = 0; i <= 200; i++) {
			vec.push_back(0);
		}
		lista2.clear();
	}
	void insertar(int i) {
		lista.push_back(i);
		//vec.insert(it, 1);
		vec[i] = 1;
	}
	void llenar() {
		list <int> ::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it) {
			/*auto it1 = vec.begin() + *it;
			vec.insert(it1, 1);*/
			//vec[*it] = 3;
			lista2.push_back(*it);
		}
	}
	void recupera() {
		list <int> ::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it) {
			/*auto it1 = vec.begin() + *it;
			vec.insert(it1, 1);*/
			//vec[*it] = 1;
			vec[*it] = 1;
			lista2.push_back(*it);
		}
	}
	void eliminar(int i)
	{
		vec[i] = 0;
		lista2.remove(i);
		//getVec(i) = NULL;
	}
	void showlist()
	{
		list <int> ::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it)
			cout << *it << " |";
	}
	void showVec()
	{
		/*for (auto it = vec.begin() + 1; it != vec.end(); ++it)
			if(*it != 0)
				cout << *it << " |";*/
		for (int it = 1; it < vec.size(); it++) {
			if(vec[it] != 0)
				cout << "(" << it << "," << vec[it] << ")" << " |";
		}
	}
	~Vertice() {}
};

