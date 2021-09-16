#pragma once
#include "Vertice.h"
#include "L8.h"
#include "ArbolHEAP.h"
#include <fstream>
#include <Windows.h>
template<class tipo>
class Grafo
{
private:
	Vertice **vec;
	int capacidad;
	ArbolHEAP<tipo> *monticulo;
public:
	Grafo() {
		capacidad = 201;
		vec = new Vertice*[capacidad];
		inicializar();
		monticulo = new ArbolHEAP<tipo>();
	}
	void insertarArista(int v1, int v2, int p) {
		vec[v1]->getLista()->insertarFinal(v2, p);
		vec[v2]->getLista()->insertarFinal(v1, p);
		vec[v1]->setExiste(true);
		vec[v2]->setExiste(true);
	}
	void gotoxy(int x, int y)  // funcion que posiciona el cursos en la coordenada (x,y)
	{
		HANDLE hCon;
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hCon, dwPos);
	}
	void inicializar() {
		for (int i = 0; i < capacidad; i++) {
			vec[i] = new Vertice();
			//vec[i] = NULL;
		}
	}
	int getDistancia(int d) {
		return vec[d]->getDistancia();
	}
	void inicializarMPD() {
		for (int i = 0; i < capacidad; i++) {
			vec[i]->setMarca(false);
			vec[i]->setPadre(-1);
			vec[i]->setDistancia(400000000);
		}
	}
	void dijkstra(int ini) {
		Nodo<tipo> *duo;
		int vi;
		NodoL *ady;
		vec[ini]->setDistancia(0);
		monticulo->insertarMB(vec[ini]->getDistancia(), ini);
		while (monticulo->getTam() != 1)
		{
			duo = monticulo->eliminarMB();
			vi = duo->getVertice();
			if (vec[vi]->getMarca() == false) 
			{
				vec[vi]->setMarca(true);
				ady = vec[vi]->getLista()->getCabeza();
				while (ady != NULL)
				{
					if (vec[ady->getValor()]->getMarca() == false && ady->getPeso() > 0)
					{
						if (vec[vi]->getDistancia() + ady->getPeso() < vec[ady->getValor()]->getDistancia()) 
						{
							vec[ady->getValor()]->setDistancia(vec[vi]->getDistancia() + ady->getPeso());
							vec[ady->getValor()]->setPadre(vi);
							monticulo->insertarMB(vec[ady->getValor()]->getDistancia(), ady->getValor());
						}
					}
					ady = ady->getSig();
				}
			}
		}
	}
	void mostrarCamino(int fin) {
		if(fin == -1)
			cout << "| ";
		else
		{
			mostrarCamino(vec[fin]->getPadre());
			cout << fin << " - " << vec[fin]->getNombre() << " | ";
		}
	}
	void mostrarGrafo() {
		int x = 0;
		int y = 19;
		gotoxy(x, y);
		cout << " vec[pos] |  DISTANCIA  | MARCA | PADRE |     ARISTAS";
		y = y + 2;
		for (int i = 0; i < capacidad; i++) {
			if (vec[i]->getExiste() == true) {
				gotoxy(x, y);
				cout << "vec[" << i << "] = "; //<< " --> ";
				gotoxy(x + 10, y);
				cout << "|  " << vec[i]->getDistancia();
				gotoxy(x + 24, y);
				cout << "|   " << vec[i]->getMarca();
				gotoxy(x + 32, y);
				cout << "|   " << vec[i]->getPadre();
				gotoxy(x + 40, y);
				cout << "|   " << vec[i]->getNombre();
				gotoxy(x + 52, y);
				cout << " | --> ";
				vec[i]->getLista()->mostrar();
				y++;
			}
		}
	}
	/*void mostrarPorDepartamentos(int dep) {
		for (int i = 1; i < 10; i++) {
			if (i < dep)
				mostrarCamino(i);
			else

		}
	}*/
	
	void leerArchivo(string texto) {
		ifstream archivo;
		int ini, fin, peso;
		archivo.open(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		while (!archivo.eof())
		{
			archivo >> ini;
			archivo >> fin;
			archivo >> peso;
			insertarArista(ini, fin, peso);
		}
		archivo.close();
	}
	void leerArchivoDep(string texto) {
		ifstream archivo;
		int pos;
		string dep;
		archivo.open(texto);
		if (archivo.fail())
			cerr << "Error al abrir el archivo de datos" << endl;
		while (!archivo.eof())
		{
			archivo >> pos;
			archivo >> dep;
			vec[pos]->setNombre(dep);
		}
		archivo.close();
	}
	~Grafo() {}
};

