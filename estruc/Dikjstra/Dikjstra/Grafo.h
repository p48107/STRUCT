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
	//L8 *cola;
public:
	Grafo() {
		capacidad = 201;
		vec = new Vertice*[capacidad];
		inicializar();
		monticulo = new ArbolHEAP<tipo>();
		//cola = new L8();
	}
	void insertarArista(int v1, int v2, int p) {
		vec[v1]->getLista()->insertarFinal(v2, p);
		vec[v1]->setExiste(true);
		vec[v2]->getLista()->insertarFinal(v1, p);
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
	void inicializarMP() {
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
	/*bool BFS(int ini, int fin)
	{
		bool encontre = false;
		vec[ini]->setMarca(true);
		cola->insertarPrincipio(ini);
		while (cola->getCabeza() != NULL && encontre == false)
		{
			int iesimo = 1;
			int vert = cola->getCabeza()->getValor();
			cola->eliminarCabeza();
			int adya = vec[vert]->getLista()->sacarSiguienteAdyacente(iesimo);
			while (adya != 0 && encontre == false)
			{
				if (vec[adya]->getMarca() == false)
				{
					vec[adya]->setPadre(vert);
					if (adya == fin)
					{
						encontre = true;
					}
					else
					{
						vec[adya]->setMarca(true);
						cola->insertarPrincipio(adya);
					}
				}
				iesimo++;
				adya = vec[vert]->getLista()->sacarSiguienteAdyacente(iesimo);
			}
		}
		return encontre;
	}
	bool DFS(int ini, int fin)
	{
		bool encontre = false;
		vec[ini]->setMarca(true);
		int iesimo = 1;
		int adya = vec[ini]->getLista()->sacarSiguienteAdyacente(iesimo);
		while (adya != 0)
		{
			if (encontre == false && vec[adya]->getMarca() == false)
			{
				vec[adya]->setPadre(ini);
				if (adya == fin)
				{
					encontre = true;
				}
				else
				{
					encontre = DFS(adya, fin);
				}
			}
			iesimo++;
			adya = vec[ini]->getLista()->sacarSiguienteAdyacente(iesimo);
		}
		return encontre;
	}*/
	void mostrarCamino(int fin) {
		int tmp = fin;
		cout << "| ";
		while (tmp != -1) {
			cout << tmp << " | ";
			tmp = vec[tmp]->getPadre();
		}
		cout << " Distancia = " << vec[fin]->getDistancia() << endl;
	}
	void mostrarGrafo() {
		int x = 0;
		int y = 12;
		for (int i = 0; i < capacidad; i++) {
			if (vec[i]->getExiste() == true) {
				gotoxy(x, y);
				cout << "vec[" << i << "] = "; //<< " --> ";
				gotoxy(x + 10, y);
				cout << "| " << vec[i]->getDistancia();
				gotoxy(x + 24, y);
				cout << "| " << vec[i]->getMarca();
				gotoxy(x + 32, y);
				cout << "| " << vec[i]->getPadre() ;
				gotoxy(x + 39, y);
				cout << " | --> ";
				vec[i]->getLista()->mostrar();
				y++;
			}
		}
	}
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
	//void vertices(int n) {
	//	for (int i = 1; i < 6; i++) {
	//		inicializarMP();
	//		if (BFS(n, i) == true) {
	//			//cout << i << " | ";
	//			mostrarDestinoOrigen(n, i, true);
	//		}
	//		cout << endl;
	//	}
	//	cout << "termino" << endl;
	//}
	~Grafo() {}
};

