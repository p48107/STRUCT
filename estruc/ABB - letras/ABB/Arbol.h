#pragma once
#include "Nodo.h"
template<class tipo>
class Arbol
{
private:
	Nodo<tipo> *raiz;
public:
	Arbol() {
		raiz = NULL;
	}
	~Arbol() {}
	Nodo<tipo> *getRaiz() {
		return raiz;
	}
	void insertarABB(tipo el, Nodo<tipo> *r){
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r == NULL) {
			r = new Nodo<tipo>();
			r->setValor(el);
			raiz = r;
		}
		else
		{
			if (el < r->getValor()) {
				if (r->getIzq() != NULL) {
					insertarABB(el, r->getIzq());
				}
				else
				{
					tmp->setValor(el);
					r->setIzq(tmp);//ASIGNAR A IZQUIERDA
					r->getIzq()->setAnt(r);//ASIGNAR PADRE DEL NODO
				}
			}
			else
			{
				if (el > r->getValor()) {
					if (r->getDer() != NULL) {
						insertarABB(el, r->getDer());
					}
					else
					{
						tmp->setValor(el);
						r->setDer(tmp);
						r->getDer()->setAnt(r);
					}
				}
			}

		}
	}
	bool buscarABB(tipo el, Nodo<tipo> *r) {
		bool sw = false;
		if (r == NULL) {
			sw = false;
		}
		else 
		{
			if (el == r->getValor())
				sw = true;
			else 
			{
				if (el > r->getValor())
					sw = buscarABB(el, r->getDer());
				else
				{
					if (el < r->getValor())
						sw = buscarABB(el, r->getIzq());
				}
			}
			
		}
		return sw;
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
				a = 1;
			else
				a = 1 + maximo(altura(r->getIzq()), altura(r->getDer()));
		}
		return a;
	}
	tipo maximo(tipo e1, tipo e2) {
		if (e1 > e2) {
			return e1;
		}
		else
		{
			return e2;
		}
	}
	Nodo<tipo> *menor(Nodo<tipo> *r) {
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r == NULL) {
			tmp = NULL;
		}
		else
		{
			if (r->getIzq() != NULL)
				tmp = menor(r->getIzq());
			else
				tmp = r;
		}
		return tmp;
	}
	Nodo<tipo> *mayor(Nodo<tipo> *r) {
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r == NULL) {
			tmp = NULL;
		}
		else
		{
			if (r->getDer() != NULL)
				tmp = mayor(r->getDer());
			else
				tmp = r;
		}
		return tmp;
	}
	void eliminar(tipo el, Nodo<tipo> *r) {
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r == NULL) {
			cout << "Arbol Vacio" << endl;
		}
		else
		{
			if (el > r->getValor())
				eliminar(el, r->getDer());
			else
			{
				if (el < r->getValor())
					eliminar(el, r->getIzq());
				else
					if (el == r->getValor())
						eliminarPadre(r);
			}
		}
	}
	void eliminarPadre(Nodo<tipo> *r) {
		Nodo<tipo> *tmp = new Nodo<tipo>();
		if (r->getIzq() != NULL && r->getDer() == NULL)
		{
			tmp = r->getIzq();
			r->setValor(tmp->getValor());
			r->setIzq(NULL);
			tmp = NULL;
			tmp->~Nodo();
		}
		else
		{
			if (r->getIzq() == NULL && r->getDer() != NULL)
			{
				tmp = r->getDer();
				r->setValor(tmp->getValor());
				r->setDer(NULL);
				tmp = NULL;
				tmp->~Nodo();
			}
			else
			{
				if (r->getIzq() == NULL && r->getIzq() == NULL && r->getAnt()->getIzq() == r)
				{
					r->getAnt()->setIzq(NULL);
					r = NULL;
					r->~Nodo();
				}
				else
				{
					if (r->getIzq() == NULL && r->getIzq() == NULL && r->getAnt()->getDer() == r)
					{
						r->getAnt()->setDer(NULL);
						r = NULL;
						r->~Nodo();
					}
					else
					{
						if (r->getAnt() != NULL)
						{
							Nodo<tipo> *min = menor(r->getDer());//buscar menor de la derecha
							r->setValor(min->getValor());//swap menor con el PADRE
							if(min->getAnt()->getIzq() == min)
								min->getAnt()->setIzq(NULL);
							else
							{
								min->getAnt()->setDer(NULL);
							}
							min = NULL;
							min->~Nodo();
						}
						else
						{
							Nodo<tipo> *min = menor(r->getDer());//buscar menor de la derecha
							raiz = min;
							min->setIzq(r->getIzq());
							r->getIzq()->setAnt(min);
							r = NULL;
							r->~Nodo();
						}
					}
				}
					
			}
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
};