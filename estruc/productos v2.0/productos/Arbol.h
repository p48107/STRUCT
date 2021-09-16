#pragma once
#include "Nodo.h"
template<class tipo>
class Arbol
{
private:
	Nodo<tipo> *raiz;
	bool existe;
	bool tiene;
	Nodo<tipo> *sig;
public:
	Arbol() {
		raiz = NULL;
		existe = false;
		tiene = false;
		sig = NULL;
	}
	~Arbol() {}
	Nodo<tipo> *&getRaiz() {
		return raiz;
	}
	Nodo<tipo> *&getSig() {
		return sig;
	}
	void sigNull() {
		sig = NULL;
	}
	void insertarABB(tipo el, Nodo<tipo> *&r) {

		if (r == NULL) {
			r = new Nodo<tipo>();
			r->setProducto(el);
		}
		else
		{
			if (el < r->getProducto()) {
				insertarABB(el, r->getIzq());
			}
			else
			{
				if (el > r->getProducto()) {
					insertarABB(el, r->getDer());
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
			if (el == r->getProducto())
				sw = true;
			else
			{
				if (el > r->getProducto())
					sw = buscarABB(el, r->getDer());
				else
				{
					if (el < r->getProducto())
						sw = buscarABB(el, r->getIzq());
				}
			}

		}
		return sw;
	}
	Nodo<tipo> *buscaYdevuelve(tipo el, Nodo<tipo> *r) {
		Nodo<tipo> *tmp = NULL;
		if (r == NULL) {
			tmp = NULL;
		}
		else
		{
			if (el == r->getProducto())
				tmp = r;
			else
			{
				if (el > r->getProducto())
					tmp = buscaYdevuelve(el, r->getDer());
				else
				{
					if (el < r->getProducto())
						tmp = buscaYdevuelve(el, r->getIzq());
				}
			}

		}
		return tmp;
	}
	void mejorPrecio(tipo el)
	{
		Nodo<tipo> *tmp = buscaYdevuelve(el, raiz);
		cout << endl;
		if (tmp == NULL) {
			cout << "El producto no esta en el Arbol! " << endl;
		}
		else
		{
			cout << "Producto: " << tmp->getProducto() << endl;
			if (tmp->getLista()->getCabeza() == NULL)
				cout << "No se registraron Pagina Web ni Precio al Producto." << endl;
			else
			{
				cout << "\tPagina Web: " << tmp->getLista()->getCabeza()->getNombre() << endl;
				cout << "\tPrecio: " << tmp->getLista()->getCabeza()->getPrecio() << endl;
			}
		}
	}
	/*void insertaPrecioWeb(tipo el, string w, float p)
	{
		Nodo<tipo> *tmp = buscaYdevuelve(el,raiz);
		if (tmp == NULL)
		{
			cout << "Producto No Registrado." << endl;
		}
		else
		{
			tmp->getLista()->insertarEnSuLugar(w, p);
		}
	}*/
	/*void eliminarPrecioWeb(tipo el, string w, float p)
	{
		Nodo<tipo> *tmp = buscaYdevuelve(el, raiz);
		if (tmp == NULL)
		{
			cout << "Producto No Registrado." << endl;
		}
		else
		{
			cout << "Producto: " << tmp->getProducto() << endl;
			if (tmp->getLista()->getCabeza() == NULL)
				cout << "No se registraron Pagina Web ni Precio al Producto." << endl;
			else
			{
				tmp->getLista()->eliminar(w, p);
				cout << "Eliminado!" << endl;
			}
		}
	}*/
	void preOrden(Nodo<tipo> *r) {
		if (r == NULL) {
			cout << "";
		}
		else
		{
			cout << r->getProducto() << "|";
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
			cout << r->getProducto() << "|";
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
			cout << r->getProducto() << "|";
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
	int maximo(int e1, int e2) {
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
	void *eliminar(Nodo<tipo> *&r, tipo valor) {
		if (r == NULL)
		{
			return r;
		}
		else
		{
			if (r->getProducto() > valor)
			{
				eliminar(r->getIzq(), valor);
			}
			else
			{
				if (r->getProducto() < valor)
				{
					eliminar(r->getDer(), valor);
				}
				else
				{
					if (r->getIzq() == NULL && r->getDer() == NULL) {
						r = NULL;
						//r->~Nodo();
					}
					else
					{
						if (r->getDer() == NULL) {
							r = r->getIzq();
						}
						else
						{
							if (r->getIzq() == NULL) {
								r = r->getDer();
							}
							else
							{
								Nodo<tipo> *aux = menor(r->getDer());
								r->setProducto(aux->getProducto());
								eliminar(r->getDer(), r->getProducto());
							}
						}
					}
				}
			}
		}
	}
	void siguiente(Nodo<tipo> *&r, tipo el) {
		if (r == NULL)
		{
			tiene = false;
			existe = false;
		}
		else
		{
			if (el < r->getProducto())
			{
				siguiente(r->getIzq(), el);
				if (existe == true && tiene == false)
				{
					sig = r;
					tiene = true;
				}
			}
			else
			{
				if (el > r->getProducto())
				{
					siguiente(r->getDer(), el);
				}
				else {
					existe = true;
					if (r->getDer() != NULL) {
						sig = menor(r->getDer());
						tiene = true;
					}
					else
					{
						tiene = false;
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
			cout << endl << r->getProducto() << "(" << n << ") -";
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
			cout << r->getProducto() << endl;
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
			cout << "Producto: "<< r->getProducto() << endl;
			r->getLista()->mostrar();
			mostrarA(r->getDer());
		}
	}
};