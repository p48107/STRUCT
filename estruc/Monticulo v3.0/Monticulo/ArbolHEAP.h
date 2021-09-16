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
	void insertarMB(tipo el)
	{
		if (vec[raiz()] == NULL) 
		{
			tam = 2;
			vec[ultimaHoja()] = new Nodo<tipo>();
			vec[ultimaHoja()]->setValor(el);
			vec[ultimaHoja()]->setPresente(true);
		}
		else
		{
			tam++;
			vec[ultimaHoja()] = new Nodo<tipo>();
			vec[ultimaHoja()]->setValor(el);
			vec[ultimaHoja()]->setPresente(true);
			recuperaAbajoArriba(ultimaHoja());
		}
	}
	void recuperaAbajoArriba(int i)
	{
		if (vec[padre(i)] != NULL)
		{
			if (vec[i]->getValor() > vec[padre(i)]->getValor())
			{
				tipo aux;
				aux = vec[padre(i)]->getValor();
				vec[padre(i)]->setValor(vec[i]->getValor());
				vec[i]->setValor(aux);
				recuperaAbajoArriba(padre(i));
			}
		}
	}
	int eliminarMB()
	{
		int mayor;
		if (vec[raiz()] == NULL)
		{
			cout << "No existe elementos en el Arbol" << endl;
			mayor = -1;
		}
		else
		{
			mayor = vec[raiz()]->getValor();
			vec[raiz()]->setValor(vec[ultimaHoja()]->getValor());
			vec[ultimaHoja()] = NULL;
			tam--;
			recuperaArribaAbajo(raiz());
		}
		return mayor;
	}
	/*void recuperaArribaAbajo(int i)
	{
		tipo aux;
		if (vec[hijoIzq(i)] == NULL && vec[hijoDer(i)] == NULL)
		{
			cout << "" << endl;
		}
		else
		{
			if (vec[hijoIzq(i)] != NULL && vec[hijoDer(i)] == NULL && vec[i]->getValor() > vec[hijoIzq(i)]->getValor())
			{
				recuperaArribaAbajo(hijoIzq(i));
			}
			else
			{
				if (vec[hijoIzq(i)] != NULL && vec[hijoDer(i)] == NULL && vec[i]->getValor() < vec[hijoIzq(i)]->getValor())
				{
					aux = vec[hijoIzq(i)]->getValor();
					vec[hijoIzq(i)]->setValor(vec[i]->getValor());
					vec[i]->setValor(aux);
					recuperaArribaAbajo(hijoIzq(i));
				}
				else
				{
					if (vec[hijoIzq(i)]->getValor() < vec[hijoDer(i)]->getValor() && vec[i]->getValor() < vec[hijoDer(i)]->getValor())
					{
						aux = vec[hijoDer(i)]->getValor();
						vec[hijoDer(i)]->setValor(vec[i]->getValor());
						vec[i]->setValor(aux);
						recuperaArribaAbajo(hijoDer(i));
					}
					else
					{
						if (vec[hijoIzq(i)]->getValor() > vec[hijoDer(i)]->getValor() && vec[i]->getValor() < vec[hijoIzq(i)]->getValor())
						{
							aux = vec[hijoIzq(i)]->getValor();
							vec[hijoIzq(i)]->setValor(vec[i]->getValor());
							vec[i]->setValor(aux);
							recuperaArribaAbajo(hijoIzq(i));
						}
					}
				}
			}

		}
	}*/
	void recuperaArribaAbajo(int i)
	{
		int tmp, aux;
		if (vec[hijoIzq(i)] == NULL && vec[hijoDer(i)] == NULL)
		{
			return;
		}
		else
		{
			tmp = hijoMayor(i);
			if (vec[tmp]->getValor() > vec[i]->getValor())
			{
				aux = vec[i]->getValor();
				vec[i]->setValor(vec[tmp]->getValor());
				vec[tmp]->setValor(aux);
			}
			recuperaArribaAbajo(tmp);
		}
	}
	int hijoMayor(int i)
	{
		int res;
		if (vec[hijoDer(i)] == NULL)
			res = hijoIzq(i);
		else
		{
			if (vec[hijoIzq(i)]->getValor() > vec[hijoDer(i)]->getValor())
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
	/*void mostrarArbol(int i, int space)
	{
		// Base case  
		if (vec[i] == NULL)
			cout << "" << endl;

		// Increase distance between levels  
		space += COUNT;

		// Process right child first  
		mostrarArbol(hijoDer(i), space);

		// Print current node after space  
		// count  
		cout << endl;
		for (int j = COUNT; j < space; j++)
			cout << " ";
		cout << vec[i]->getValor() << "\n";

		// Process left child  
		mostrarArbol(hijoIzq(i), space);
	}*/
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
	vector<int> heapSort()
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
	}
	/*void mostrarArbol(int i)
	{
		int h = altura(raiz());
		int spaces = h;
		for (int j = 1; j <= h; j++)
		{
			for (int k = 0; k < (spaces * 8); k++)
				cout << " ";
			imprimirValor(i, j);
			cout << endl;
			spaces--;
		}
	}

	void imprimirValor(int i, int level)
	{
		if (vec[i] == NULL)
			return;
		if (level == 1)
			cout << vec[i]->getValor() << "          ";
		else if (level > 1)
		{
			imprimirValor(hijoIzq(i), level - 1);
			imprimirValor(hijoDer(i), level - 1);
		}
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

