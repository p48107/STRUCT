// CorteMinimo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Grafo.h"
#include <list>
#include "Vertice.h"
int main()
{
	Grafo<int> *g1 = new Grafo<int>();
	Grafo<int> *g2 = new Grafo<int>();
	Vertice *v1 = new Vertice();

	//Arbol<int> *a1 = new Arbol<int>()

	/*g1->inicializar();
	g1->leerArchivo("datos.txt");
	g1->llenarLista();*/
	memcpy(g2, g1, sizeof(Grafo<int> *));
	
	/*for (int i = 1; i <= 200; i++) {
		v1->getVec(i)->setLista(g1->getVec(i)->getLista());
	}*/
	//POR DEFECTO
	/*g1->insertarArista(1, 2);
	g1->insertarArista(1, 4);
	g1->insertarArista(1, 3);
	g1->insertarArista(2, 1);
	g1->insertarArista(2, 4);
	g1->insertarArista(3, 1);
	g1->insertarArista(3, 4);
	g1->insertarArista(4, 1);
	g1->insertarArista(4, 2);
	g1->insertarArista(4, 3);
	g1->mostrarGrafo();
	g1->llenarLista();
	int h = g1->minCut();*/

	for (int i = 0; i < 92041; i++) {
		/*g1 = new Grafo<int>();
		g1->inicializar();
		g1->leerArchivo("datos.txt");
		g1->llenarLista();
		int h = g1->minCut();*/
		cout << "";
		//cout << i << endl;

		//cout << i << endl;
	}
	cout << "End";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
