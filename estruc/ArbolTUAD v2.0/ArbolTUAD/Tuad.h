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
	bool ultimo;
	string acum;
public:
	Tuad()
	{
		capacidad = 36;
		vec = new Tuad<tipo>*[capacidad];
		inicializar();
		ultimo = false;
	}
	string getAcum() {
		return acum;
	}
	void setAcum(string a) {
		acum = a;
	}
	void setUltimo(bool u) {
		ultimo = u;
	}
	bool getUltimo() {
		return ultimo;
	}
	void setValor(tipo v) {
		valor = v;
	}
	tipo getValor() {
		return valor;
	}
	void setVec(int pos, char l) {
		vec[pos] = new Tuad<tipo>();
		vec[pos]->setValor(l);
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
		
	}
	void insertarTuad(tipo el) 
	{
		
	}
	void eliminar(tipo e) 
	{
		
	}
	void mostrar() 
	{
		
	}
	void inicializar() {
		for (int i = 0; i < capacidad; i++) {
			vec[i] = NULL;
		}
	}
	~Tuad() {}
};