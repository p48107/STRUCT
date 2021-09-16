#pragma once
#include "Nodo.h"
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
		vec = new Nodo<tipo>*[100];
	}
	int ultimaHoja()
	{
		return tam - 1;
	}
	void inicializar()
	{
		for (int i = 0; i < 100; i++)
		{
			vec[i] = NULL;
		}
	}
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
	void eliminarMB()
	{
		if (vec[raiz()] == NULL)
		{
			cout << "No existe elementos en el Arbol" << endl;
		}
		else
		{
			vec[raiz()]->setValor(vec[ultimaHoja()]->getValor());
			vec[ultimaHoja()] = NULL;
			tam--;
			recuperaArribaAbajo(raiz());
		}
	}
	void recuperaArribaAbajo(int i)
	{
		tipo aux;
		if (vec[hijoIzq(i)] == NULL && vec[hijoDer(i)] == NULL)
		{
			cout << "" << endl;
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
	void mostrar()
	{
		for (int i = 1; i < tam; i++)
		{
			cout << vec[i]->getValor() << " | ";
		}
	}
	~ArbolHEAP() {}
};

