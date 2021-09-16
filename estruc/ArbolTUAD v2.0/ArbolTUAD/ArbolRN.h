#pragma once
#include "Nodo.h"
#include <fstream>
#include <string>
#include "string.h"
#include "TUAD.h"
template<class tipo>
class ArbolRN
{
private:
	Nodo<tipo> *raiz;
	//bool b;
	//continuar 'S' 'n'--> SI/NO
public:
	ArbolRN() {
		raiz = NULL;
		//b = false;
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
	bool insertarRN(tipo el, Nodo<tipo> *&r, char &paridad, char &lado)
	{
		bool continuar = false;
		if (r == NULL)
		{
			r = new Nodo<tipo>;
			r->setValor(el);
			r->setColor('R');
			continuar = true;
			paridad = 'P';
		}
		else
		{
			if (el < r->getValor())
			{
				continuar = insertarRN(el, r->getIzq(), paridad, lado);
				if (continuar == true)
				{
					if (paridad == 'P')
					{
						if (r->getColor() == 'N')
						{
							continuar = false;
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
								continuar = false;
								if (lado == 'D')
								{
									rotarIzq(r->getIzq()); //rotar Izquierda
								}
								r->getIzq()->setColor('N');
								r->setColor('R');
								rotarDer(r); //rotar Derecha
							}
						}
					}
				}
			}
			if (el > r->getValor())
			{
				continuar = insertarRN(el, r->getDer(), paridad, lado);
				if (continuar == true)
				{
					if (paridad == 'P')
					{
						if (r->getColor() == 'N')
						{
							continuar = false;
						}
						else
						{
							paridad = 'I';
							lado = 'D';
						}
					}
					else
					{
						if (paridad == 'I')
						{
							if (r->getIzq() != NULL && r->getIzq()->getColor() == 'R')
							{
								r->getIzq()->setColor('N');
								r->getDer()->setColor('N');
								r->setColor('R');
								paridad = 'P';
							}
							else
							{
								continuar = false;
								if (lado == 'I')
								{
									rotarDer(r->getDer());  //rotar derecha
								}
								r->getDer()->setColor('N');
								r->setColor('R');
								rotarIzq(r); //rotar izquierda
							}
						}
					}
				}
			}
		}
		return continuar;
	}
	bool buscar(tipo el, Nodo<tipo> *r) {
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
					sw = buscar(el, r->getDer());
				else
				{
					if (el < r->getValor())
						sw = buscar(el, r->getIzq());
				}
			}

		}
		return sw;
	}
	Nodo<tipo> *buscaDevuelve(tipo el, Nodo<tipo> *r) {
		Nodo<tipo> *tmp = NULL;
		if (r == NULL) {
			tmp = NULL;
		}
		else
		{
			if (el == r->getValor())
				tmp = r;
			else
			{
				if (el > r->getValor())
					tmp = buscaDevuelve(el, r->getDer());
				else
				{
					if (el < r->getValor())
						tmp = buscaDevuelve(el, r->getIzq());
				}
			}
		}
		return tmp;
	}
	void insertarTrie(string palabra)
	{
		char p, l;
		if(buscar(palabra[0],raiz) == false)
			insertarRN(palabra[0], raiz, p, l);
		Nodo<tipo> *tmp = buscaDevuelve(palabra[0], raiz);
		if (tmp->getT1() == NULL) {
			tmp->getT1() = new Tuad<tipo>();
			tmp->getT1()->setValor(palabra[0]);
		}
		if(palabra[1] != '\0')
			insertarTuad(palabra, tmp->getT1(), 0);
	}
	void insertarTuad(string palabra, Tuad<tipo> *&t, int pos)
	{
		char letra;
		int pos2;
		letra = palabra[pos];
		pos2 = t->funcionTUAD(letra);
		if (pos == palabra.size()) {
			t->setUltimo(true);
			t->setAcum(t->getAcum() + letra);
		}
		if (pos < palabra.size())
		{
			if (t->getVec(pos2) == NULL)
			{
				t->setVec(pos2, letra);
				t->getVec(pos2)->setAcum(t->getAcum() + letra);
			}
			insertarTuad(palabra, t->getVec(pos2), pos + 1);
		}
	}
	bool buscarTrie(string palabra)
	{
		bool b = false;
		Nodo<tipo> *tmp = buscaDevuelve(palabra[0], raiz);
		if (palabra[1] != '\0' && tmp != NULL)
			b = buscarTuad(palabra, tmp->getT1(), 0);
		return b;
	}
	bool buscarTuad(string palabra, Tuad<tipo> *&t, int pos)
	{
		char letra, pos2;
		bool b = false;
		letra = palabra[pos];
		pos2 = t->funcionTUAD(letra);
		if (pos == palabra.size() && t->getUltimo() == true)
			b = true;
		else
		{
			if (t->getVec(pos2) == NULL)
				b = false;
			else
			{
				if (pos < palabra.size())
				{
					b = buscarTuad(palabra, t->getVec(pos2), pos + 1);
				}
			}
		}
		return b;
	}
	void mostrarTrie(Tuad<char> *&t) {
		/*char letra, pos2;
		letra = palabra[pos];
		pos2 = t->funcionTUAD(letra);*/
		for (int i = 0; i < 31; i++) {
			if (t->getVec(i) != NULL) {
				if (t->getVec(i)->getUltimo() == true) {
					cout << t->getVec(i)->getAcum() << endl;
				}
				mostrarTrie(t->getVec(i));
			}
		}
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
	int altura(Nodo<tipo> *&r) {
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
	int alturaNegra(Nodo<tipo> *&r) {
		int a = 0;
		if (r == NULL) {
			a = 0;
		}
		else
		{
			if (r->getIzq() == NULL && r->getDer() == NULL)
			{
				if (r->getColor() == 'N')
					a = 1;
				else
					a = 0;
			}
			else
			{
				if (r->getColor() == 'N')
					a = 1 + maximo(alturaNegra(r->getIzq()), alturaNegra(r->getDer()));
				else
					a = maximo(alturaNegra(r->getIzq()), alturaNegra(r->getDer()));
			}
		}
		return a;
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
	void mostrar(Nodo<tipo> *r)
	{
		if (r != NULL)
		{
			mostrar(r->getIzq());
			mostrarTrie(r->getT1());
			mostrar(r->getDer());
		}
	}
	/*void leerArchivo(string texto)
	{
		string p;
		ifstream archivo(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		else
			while (!archivo.eof())
			{
				archivo >> p;
				insertarTrie(p);
			}
		archivo.close();
	}*/
};