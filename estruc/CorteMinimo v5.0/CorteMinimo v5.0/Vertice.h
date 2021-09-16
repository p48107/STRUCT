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
	list<tipo> lista;
	list<tipo> lista2;
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
	list<tipo> getLista() {
		return lista;
	}
	list<tipo> &getLista2() {
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
		std::vector< std::reference_wrapper< const tipo > > vec(lista2.begin(), lista2.end());
		std::shuffle(vec.begin(), vec.end(), std::mt19937{ std::random_device{}() });
		std::list<tipo> shuffled_list{ vec.begin(), vec.end() };
		lista2.swap(shuffled_list);
	}
	void insertar(int i) {
		lista.push_back(i);
		//vec.insert(it, 1);
	}
	void inicializar() {

	}
	void llenar() {
		list <int> ::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it) {
			lista2.push_back(*it);
		}
	}
	void eliminar(int i)
	{
		lista2.remove(i);
		//getVec(i) = NULL;
	}
	void showlist()
	{
		list <int> ::iterator it;
		for (it = lista2.begin(); it != lista2.end(); ++it)
			cout << *it << " |";
	}
	~Vertice() {}
};

