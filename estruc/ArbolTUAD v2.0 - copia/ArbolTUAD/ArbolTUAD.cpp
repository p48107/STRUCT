// ArbolTUAD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "ArbolRN.h"
int main()
{
	bool c;
	char p, l;
	string palabra;
	ArbolRN<char> *a1 = new ArbolRN<char>();
	a1->insertarTrie("arbol");
	a1->insertarTrie("arma");
	a1->insertarTrie("armagedon");
	a1->insertarTrie("armario");
	a1->mostrar(a1->getRaiz());
	cout << endl;
	a1->mostrarArbol(a1->getRaiz(), 0);
	/*c = a1->insertarRN('A', a1->getRaiz(), p, l);
	c = a1->insertarRN('Y', a1->getRaiz(), p, l);
	c = a1->insertarRN('E', a1->getRaiz(), p, l);
	c = a1->insertarRN('B', a1->getRaiz(), p, l);
	a1->mostrarArbol(a1->getRaiz(), 0);*/
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
