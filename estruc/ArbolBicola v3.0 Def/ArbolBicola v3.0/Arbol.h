#pragma once
#include "Nodo.h"
#include "L8.h"
#include <fstream>
template<class tipo>
class Arbol
{
private:
	Nodo<tipo> *raiz;
	L8<tipo> *bicola;
	Nodo<tipo> *ultimo;
public:
	Arbol() {
		raiz = NULL;
		bicola = new L8<tipo>();
		ultimo = NULL;
	}
	~Arbol() {}
	Nodo<tipo> *&getRaiz() {
		return raiz;
	}
	Nodo<tipo> *&getUltimo() {
		return ultimo;
	}
	L8<tipo> *&getBicola()
	{
		return bicola;
	}
	Nodo<tipo> *insertarArbol(tipo el, Nodo<tipo> *&r) {
		Nodo<tipo> *tmp = NULL;
		if (r == NULL) 
		{
			//r = bicola->getCabeza()->getValor();
			r = new Nodo<tipo>();
			r->setValor(el);
			tmp = r;
		}
		else
		{
			if (r->getIzq() == NULL) {
				tmp = insertarArbol(el, r->getIzq());
				r->getIzq()->setPadre(r);
			}
			else
			{
				tmp = insertarArbol(el, r->getDer());
				r->getDer()->setPadre(r);
			}
		}
		return tmp;
	}
	void insertar(tipo el)
	{
		if (bicola->getCabeza() == NULL)
		{
			ultimo = insertarArbol(el, raiz);
			bicola->insertarPrincipio(ultimo);
		}
		else
		{
			Nodo<tipo> *tmp = bicola->getCabeza()->getValor();
			ultimo = insertarArbol(el, tmp);
			bicola->insertarFinal(ultimo);
			recuperaAbajoArriba(ultimo);
			if (tmp->getDer() != NULL && tmp->getIzq() != NULL)
				bicola->eliminarCabeza();
		}
	}
	void recuperaAbajoArriba(Nodo<tipo> *&r)
	{
		if (r->getPadre() != NULL)
		{
			if (r->getValor() > r->getPadre()->getValor())
			{
				tipo aux;
				aux = r->getPadre()->getValor();
				r->getPadre()->setValor(r->getValor());
				r->setValor(aux);
				recuperaAbajoArriba(r->getPadre());
			}
		}
	}
	int eliminar()
	{
		int mayor;
		if (raiz == NULL)
		{
			mayor = -1;
		}
		else
		{
			mayor = raiz->getValor();
			//act cabeza
			if (ultimo->getPadre() == NULL)
			{
				raiz = NULL;
				bicola->eliminarUltimo();
			}
			else
			{
				//preguntar si padre tiene hijos inserta cabeza 
				if (ultimo->getPadre()->getIzq() != NULL && ultimo->getPadre()->getDer() != NULL)
					bicola->insertarPrincipio(ultimo->getPadre());
				raiz->setValor(ultimo->getValor());
				if (ultimo->getPadre()->getIzq()->getValor() == ultimo->getValor())
					ultimo->getPadre()->setIzq(NULL);
				else
					ultimo->getPadre()->setDer(NULL);
				bicola->eliminarUltimo();
				ultimo = bicola->getUltimo()->getValor();
				recuperaArribaAbajo(raiz);
			}
		}
		return mayor;
	}
	void recuperaArribaAbajo(Nodo<tipo> *&r)
	{
		int aux;
		if (r->getIzq() == NULL && r->getDer() == NULL) {
			return;
		}
		else
		{
			Nodo<tipo> *tmp = hijoMayor(r);
			if (tmp->getValor() > r->getValor()) 
			{
				aux = r->getValor();
				r->setValor(tmp->getValor());
				tmp->setValor(aux);
			}
			recuperaArribaAbajo(tmp);
		}
	}
	Nodo<tipo> *hijoMayor(Nodo<tipo> *&r)
	{
		Nodo<tipo> *res = NULL;
		if (r->getDer() == NULL)
			res = r->getIzq();
		else
		{
			if (r->getIzq()->getValor() > r->getDer()->getValor())
				res = r->getIzq();
			else
				res = r->getDer();
		}
		return res;
	}
	void preOrden(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			cout << r->getValor() << "|";
			preOrden(r->getIzq());
			preOrden(r->getDer());
		}
	}
	void inOrden(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			inOrden(r->getIzq());
			cout << r->getValor() << "|";
			inOrden(r->getDer());
		}
	}
	void postOrden(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			postOrden(r->getIzq());
			postOrden(r->getDer());
			cout << r->getValor() << "|";
		}
	}
	int contar(Nodo<tipo> *r) {
		int cont = 0;
		if (r == NULL) {
			cont = 0;
		}
		else
		{
			cont = 1 + contar(r->getIzq()) + contar(r->getDer());
		}
		return cont;
	}
	int altura(Nodo<tipo> *r) {
		int a = 0;
		if (r == NULL) {
			a = 0;
		}
		else
		{
			if (r->getIzq() == NULL && r->getDer() == NULL)
				a = 0;
			else
				a = 1 + maximo(altura(r->getIzq()), altura(r->getDer()));
		}
		return a;
	}
	int maximo(int e1, int e2) {
		if (e1 > e2) {
			return e1;
		}
		else
		{
			return e2;
		}
	}

	void niveles(Nodo<tipo> *r, int n) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			cout << endl << r->getValor() << "(" << n << ") -";
			niveles(r->getIzq(), n + 1);
			niveles(r->getDer(), n + 1);
		}
	}
	int contarHojas(Nodo<tipo> *r) {
		int cont;
		if (r->getIzq() == NULL && r->getDer() == NULL)
		{
			cont = 1;
		}
		else
		{
			if (r->getIzq() == NULL && r->getDer() != NULL)
			{
				cont = contarHojas(r->getDer());
			}
			else
			{
				if (r->getIzq() != NULL && r->getDer() == NULL)
				{
					cont = contarHojas(r->getIzq());
				}
				else
				{
					cont = contarHojas(r->getIzq()) + contarHojas(r->getDer());
				}
			}
		}
		return cont;
	}
	void mostrarArbol(Nodo<tipo> *r, int spaces)
	{
		if (r != NULL)
		{
			mostrarArbol(r->getDer(), spaces + 5);
			for (int j = 0; j < spaces; j++)
				cout << ' ';
			cout << r->getValor() << endl;
			mostrarArbol(r->getIzq(), spaces + 5);
		}
	}
	void mostrarA(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			mostrarA(r->getIzq());
			cout << r->getValor() << endl;
			mostrarA(r->getDer());
		}
	}
	void leerArchivo(string texto)
	{
		int v;
		ifstream archivo(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		else
			while (!archivo.eof())
			{
				archivo >> v;
				insertar(v);
			}
		archivo.close();
	}
};