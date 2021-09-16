#pragma once
#include "Nodo.h"
#include <fstream>
#include <vector>
#define COUNT 10
template<class tipo>
class ArbolHEAP
{
private:
	Nodo<tipo> **vec;
	int tam;
public:
	ArbolHEAP()
	{
		tam = 1;
		vec = new Nodo<tipo>*[35000];
		inicializar();
	}
	int getTam() 
	{
		return tam;
	}
	int ultimaHoja()
	{
		return tam - 1;
	}
	void inicializar()
	{
		for (int i = 0; i < 35000; i++)
		{
			vec[i] = NULL;
		}
	}
	int raiz()
	{
		return 1;
	}
	void insertarMB(tipo el, tipo v)
	{
		if (vec[raiz()] == NULL)
		{
			tam = 2;
			vec[ultimaHoja()] = new Nodo<tipo>();
			vec[ultimaHoja()]->setValor(el);
			vec[ultimaHoja()]->setVertice(v);
			vec[ultimaHoja()]->setPresente(true);
		}
		else
		{
			tam++;
			vec[ultimaHoja()] = new Nodo<tipo>();
			vec[ultimaHoja()]->setValor(el);
			vec[ultimaHoja()]->setVertice(v);
			vec[ultimaHoja()]->setPresente(true);
			recuperaAbajoArriba(ultimaHoja());
		}
	}
	void recuperaAbajoArriba(int i)
	{
		if (vec[padre(i)] != NULL)
		{
			if (vec[i]->getValor() < vec[padre(i)]->getValor())
			{
				tipo aux;
				aux = vec[padre(i)]->getValor();
				vec[padre(i)]->setValor(vec[i]->getValor());
				vec[i]->setValor(aux);
				recuperaAbajoArriba(padre(i));
			}
		}
	}
	Nodo<tipo> *eliminarMB()
	{
		Nodo<tipo> *menor = new Nodo<tipo>();
		if (vec[raiz()] == NULL)
		{
			cout << "No existe elementos en el Arbol" << endl;
			menor = NULL;
		}
		else
		{
			menor->setValor(vec[raiz()]->getValor());
			menor->setVertice(vec[raiz()]->getVertice());
			vec[raiz()]->setValor(vec[ultimaHoja()]->getValor());
			vec[raiz()]->setVertice(vec[ultimaHoja()]->getVertice());
			vec[ultimaHoja()] = NULL;
			tam--;
			recuperaArribaAbajo(raiz());
		}
		return menor;
	}
	void recuperaArribaAbajo(int i)
	{
		int tmp, aux;
		if (vec[hijoIzq(i)] == NULL && vec[hijoDer(i)] == NULL)
		{
			return;
		}
		else
		{
			tmp = hijoMenor(i);
			if (vec[tmp]->getValor() < vec[i]->getValor())
			{
				aux = vec[i]->getValor();
				vec[i]->setValor(vec[tmp]->getValor());
				vec[tmp]->setValor(aux);
			}
			recuperaArribaAbajo(tmp);
		}
	}
	int hijoMenor(int i)
	{
		int res;
		if (vec[hijoDer(i)] == NULL)
			res = hijoIzq(i);
		else
		{
			if (vec[hijoIzq(i)]->getValor() < vec[hijoDer(i)]->getValor())
				res = hijoIzq(i);
			else
				res = hijoDer(i);
		}
		return res;
	}
	void mostrar()
	{
		for (int i = 1; i < tam; i++)
		{
			cout << vec[i]->getValor() << " | ";
		}
	}
	void mostrarArbol(int i, int spaces)
	{
		if (vec[i] != NULL)
		{
			mostrarArbol(hijoDer(i), spaces + 5);
			for (int j = 0; j < spaces; j++)
				cout << ' ';
			cout << vec[i]->getValor() << endl;
			mostrarArbol(hijoIzq(i), spaces + 5);
		}
	}
	/* Function to line by line print level order traversal a tree*/
	int maximo(int e1, int e2)
	{
		if (e1 > e2) {
			return e1;
		}
		else
		{
			return e2;
		}
	}
	int altura(int i)
	{
		int a = 0;
		if (vec[i] == NULL) {
			a = 0;
		}
		else
		{
			if (vec[hijoIzq(i)] == NULL && vec[hijoDer(i)] == NULL)
				a = 0;
			else
				a = 1 + maximo(altura(hijoIzq(i)), altura(hijoDer(i)));
		}
		return a;
	}
	void leerArchivo(string texto)
	{
		int num;
		ifstream archivo(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		else
			archivo >> num;
		insertarMB(num);
		while (!archivo.eof())
		{
			archivo >> num;
			insertarMB(num);
		}
		archivo.close();
	}
	/*vector<int> heapSort()
	{
		vector<int> vec;
		int cont = 0;
		int i = 0;
		while (i != -1)
		{
			i = eliminarMB();
			if (i != -1) {
				vec.push_back(i);
				cout << vec[cont] << "| ";
				cont++;
			}
		}
		return vec;
	}*/
	int padre(int i)
	{
		return i / 2;
	}
	int hijoIzq(int i)
	{
		return i * 2;
	}
	int hijoDer(int i)
	{
		return i * 2 + 1;
	}
	~ArbolHEAP() {}
};

