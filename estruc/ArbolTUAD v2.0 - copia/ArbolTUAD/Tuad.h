#pragma once
#include <iostream>
using namespace std;
template<class tipo>
class Tuad
{
private:
	int capacidad;
	tipo valor;
	Tuad<tipo> **vec;
public:
	Tuad()
	{
		capacidad = 36;
		vec = new Tuad<tipo>*[capacidad];
		inicializar();
	}
	void setValor(tipo v) {
		valor = v;
	}
	tipo getValor() {
		return valor;
	}
	void setVec(Tuad<tipo> *&v) {
		vec = v;
	}
	Tuad<tipo> *&getVec(int pos) {
		return vec[pos];
	}
	int funcionTUAD(char s)
	{
		int pos = 0;
		pos = s - 97;
		if (pos > 25)
		{
			if (s == 132) pos = 26;
			if (s == 137) pos = 27;
			if (s == 139) pos = 28;
			if (s == 148) pos = 29;
			if (s == 129) pos = 30;
			if (s == 130) pos = 31;
			if (s == 160) pos = 32;
			if (s == 161) pos = 33;
			if (s == 162) pos = 34;
			if (s == 163) pos = 35;
			if (s == 164) pos = 36;
		}
		return pos;
	}
	Tuad<tipo> *buscar(tipo e)
	{
		Tuad<tipo> *tmp;
		int pos = funcionTUAD(e);
		tmp = vec[pos];
		return tmp;
	}
	void insertarTuad(tipo el) {
		int pos = funcionTUAD(el);
		//Tuad<tipo> *tmp = buscar(el);
		if (vec[pos] == NULL)
		{
			vec[pos] = new Tuad<tipo>();
			vec[pos]->setValor(el);
		}
	}
	void eliminar(tipo e) {
		int pos = funcionTUAD(e);
		vec[pos]->eliminarCabeza();
	}
	void mostrar() {
		for (int i = 0; i < capacidad; i++) {
			if (vec[i] != NULL) {
				vec[i]->mostrar();
				cout << vec[i]->getValor();
			}
		}
	}
	void inicializar() {
		for (int i = 0; i < capacidad; i++) {
			vec[i] = NULL;
		}
	}
	~Tuad() {}
};