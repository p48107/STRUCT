// ABB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Arbol.h"
#include "Nodo.h"
int main()
{
	Arbol<char> *a1 = new Arbol<char>(100);
	a1->inicializar();
	a1->insertarABB('F', 1);
	a1->insertarABB('B', 2);
	a1->insertarABB('G', 3);
	a1->insertarABB('A', 4);
	a1->insertarABB('D', 5);
	a1->insertarABB('I', 7);
	a1->insertarABB('C', 10);
	a1->insertarABB('E', 11);
	a1->insertarABB('H', 14);
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
