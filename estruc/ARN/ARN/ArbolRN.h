#pragma once
#include "Nodo.h"
template<class tipo>
class ArbolRN
{
private:
	Nodo<tipo> *raiz;
	//continuar 'S' 'n'--> SI/NO
public:
	ArbolRN() {
		raiz = NULL;
	}
	~ArbolRN() {}
	Nodo<tipo> *&getRaiz() {
		return raiz;
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
	void rotarIzq(Nodo<tipo> *&n) {
		Nodo<tipo> *flotante;
		Nodo<tipo> *tmp = n->getDer();
		if (n->getIzq() != NULL)
			flotante = tmp->getIzq();
		else
			flotante = NULL;
		tmp->setIzq(n);
		n->setDer(flotante);
		n = tmp;
	}
	void rotarDer(Nodo<tipo> *&n) {
		Nodo<tipo> *flotante;
		Nodo<tipo> *tmp = n->getIzq();
		if (tmp->getDer() != NULL)
			flotante = tmp->getDer();
		else
			flotante = NULL;
		tmp->setDer(n);
		n->setIzq(flotante);
		n = tmp;
	}
	void insertarRN(tipo el, Nodo<tipo> *&r, char &continuar, char &paridad, char &lado) {
		if (r == NULL) {
			Nodo<tipo> *tmp = new Nodo<tipo>();
			tmp->setValor(el);
			tmp->setColor('R');
			r = tmp;
			continuar = 'S';
			paridad = 'P';
		}
		else
		{
			if (el < r->getValor())
			{
				insertarRN(el, r->getIzq(), continuar, paridad, lado);
				if (continuar == 'S')
				{					
					if (paridad == 'P')
					{
						if (r->getColor() == 'N')
						{
							continuar = 'N';
						}
						else
						{
							paridad = 'I';
							lado = 'I';
						}
					}
					else
					{
						if (paridad == 'I')
						{
							if (r->getDer() != NULL && r->getDer()->getColor() == 'R')
							{
								r->getIzq()->setColor('N');
								r->getDer()->setColor('N');
								r->setColor('R');
								paridad = 'P';
							}
							else
							{
								continuar = 'S';
								if (lado == 'D')
									rotarIzq(r->getIzq());
								r->getIzq()->setColor('N');
								r->setColor('R');
								rotarDer(r);
							}
						}
					}
				}
			}
			else
			{
				insertarRN(el, r->getDer(), continuar, paridad, lado);
				if (continuar == 'S')
				{
					if (paridad == 'P')
					{
						if (r->getColor() == 'N') {
							continuar = 'N';
						}
						else
						{
							paridad = 'I';
							lado = 'D';
						}
					}
					else
					{
						if (paridad == 'I') {
							if (r->getIzq() != NULL && r->getIzq()->getColor() == 'R')
							{
								r->getIzq()->setColor('N');
								r->getDer()->setColor('N');
								r->setColor('R');
								paridad = 'P';
							}
							else
							{
								continuar = 'N';
								if (lado == 'I')
									rotarDer(r->getDer());
								r->getDer()->setColor('N');
								r->setColor('R');
								rotarIzq(r);
							}
						}
					}
				}
			}
		}
	}
};