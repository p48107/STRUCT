// ARN.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "ArbolRN.h"
#include "Nodo.h"
int main()
{
	ArbolRN<int> *a1 = new ArbolRN<int>();
	char c, p, l;
	a1->insertarRN(10, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->insertarRN(5, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->insertarRN(1, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->insertarRN(4, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->insertarRN(20, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->insertarRN(15, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->insertarRN(30, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->insertarRN(27, a1->getRaiz(), c, p, l);
	a1->getRaiz()->setColor('N');
	/*c = '/0';
	p = '/0';
	l = '/0';*/
	a1->inOrden(a1->getRaiz());
	cout << endl;
	a1->preOrden(a1->getRaiz());
	cout << endl;
	a1->postOrden(a1->getRaiz());
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
