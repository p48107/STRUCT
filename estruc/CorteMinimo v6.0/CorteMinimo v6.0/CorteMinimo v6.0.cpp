// CorteMinimo v6.0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>


#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <list>
#include <iterator>
#include <vector>
#include <chrono>
#include <fstream>
#include <functional>

#include "Grafo.h"
using namespace std;
int main()
{
	/*vector<int> vec;
	vector<int> vec2;
	vec.resize(6);
	vec[0] = 6;
	vec[1] = 5;
	vec[2] = 1;
	vec[3] = 54;
	vec[4] = 3;
	vec[5] = 30;*/
	/*auto it = remove(vec.begin(), vec.end(), 30);
	vector <int> ::iterator it1;
	int i = 0;
	for (it1 = vec.begin(); it1 != it; ++it1)
		i++;
	vec.resize(i);*/
	/*vector <int> ::iterator it1;
	it1 = vec.begin() + 1;
	shuffle(it1, vec.end(), std::mt19937{ std::random_device{}() });
	int v1 = *it1;*/
	Grafo<int> *g1 = new Grafo<int>(200);
	g1->leerArchivo("datos.txt");
	/*g1->insertarArista(1, 2);//PRUEBA
	g1->insertarArista(1, 4);
	g1->insertarArista(1, 3);
	g1->insertarArista(2, 1);
	g1->insertarArista(2, 4);
	g1->insertarArista(3, 1);
	g1->insertarArista(3, 4);
	g1->insertarArista(4, 1);
	g1->insertarArista(4, 2);
	g1->insertarArista(4, 3);//PRUEBA*/
	g1->llenarDatos();
	//g1->mostrarGrafo();//PRUEBA
	g1->inicializarLista();
	//g1->listShuffle();//PRUEBA
	//g1->minCut();//PRUEBA
	//g1->mostrarGrafo();//PRUEBA
	for (int i = 0; i < 92041; i++) {
		g1->listShuffle();
		g1->recuperarDatos();
		g1->minCut();
		//g1->mostrarGrafo();

		//cout << i << endl;
		if (i == 500) {
			cout << "TERMINE";
		}
	}
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
