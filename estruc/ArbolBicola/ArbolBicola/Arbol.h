#pragma once
#include "Nodo.h"
#include "L8.h"
#include <fstream>
template<class tipo>
class Arbol
{
private:
	Nodo<tipo> *raiz;
	bool existe;
	bool tiene;
	Nodo<int> *sig;
	L8 *bicola;
	Nodo<tipo> *tmp;
	Nodo<tipo> *ultimo;
public:
	Arbol() {
		raiz = NULL;
		existe = false;
		tiene = false;
		sig = NULL;
		bicola = new L8();
		tmp = NULL;
		ultimo = NULL;
	}
	~Arbol() {}
	Nodo<tipo> *&getRaiz() {
		return raiz;
	}
	Nodo<tipo> *&getSig() {
		return sig;
	}
	Nodo<tipo> *&getUltimo() {
		return ultimo;
	}
	void sigNull() {
		sig = NULL;
	}
	Nodo<tipo> *insertarArbol(tipo el, Nodo<tipo> *&r) {
		Nodo<tipo> *tmp = NULL;
		if (r == NULL) {
			r = new Nodo<tipo>();
			r->setValor(el);
			tmp = r;
		}
		else
		{
			if ( r->getIzq() == NULL ) {
				tmp = insertarArbol(el, r->getIzq());
				r->getIzq()->setAnt(r);
			}
			else
			{
				tmp = insertarArbol(el, r->getDer());
				r->getDer()->setAnt(r);
			}
		}
		return tmp;
	}
	void insertar(tipo el)
	{
		Nodo<tipo> *sw;
		if (bicola->getCabeza() == NULL) 
		{
			bicola->insertarPrincipio(el);
			ultimo = insertarArbol(el, raiz);
		}
		else
		{
			cabezaBicola(bicola->getCabeza()->getValor(), raiz);
			bicola->insertarFinal(el);
			ultimo = insertarArbol(el, tmp);
			recuperaAbajoArriba(ultimo);
			if (tmp->getDer() != NULL && tmp->getIzq() != NULL)
				bicola->eliminarCabeza();
			else
			{
				bicola->getCabeza()->setValor(ultimo->getAnt()->getValor());
				bicola->getUltimo()->setValor(ultimo->getValor());
			}
		}
	}
	void recuperaAbajoArriba(Nodo<tipo> *&r)
	{
		if (r->getAnt() != NULL)
		{
			if (r->getValor() > r->getAnt()->getValor())
			{
				tipo aux;
				aux = r->getAnt()->getValor();
				r->getAnt()->setValor(r->getValor());
				r->setValor(aux);
				recuperaAbajoArriba(r->getAnt());
			}
		}
	}
	void cabezaBicola(tipo el, Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			if (el == r->getValor())
			{
				tmp = r;
			}
			cabezaBicola(el, r->getIzq());
			cabezaBicola(el, r->getDer());
		}
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