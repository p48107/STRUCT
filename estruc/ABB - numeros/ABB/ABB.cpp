// ABB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Arbol.h"
#include "Nodo.h"
int main()
{
	Arbol<int> *a1 = new Arbol<int>();
	Nodo<int> *n1 = new Nodo<int>();
	n1->setValor(50);
	a1->setRaiz(n1);
	a1->insertar(3);
	a1->insertar(19);
	a1->insertar(20);
	a1->insertar(1);
	a1->inOrden(a1->getRaiz());
	std::cout << "INORDEN\n";
	a1->postOrden(a1->getRaiz());
	std::cout << "POSTORDEN\n";
	a1->preOrden(a1->getRaiz());
    std::cout << "PREORDEN\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
