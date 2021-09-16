// ListaDoblesv2.0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "ListaDE.h"
#include "conio.h"
#include <stdio.h>
#include <Windows.h>
#include "stdlib.h"
using namespace std;
int main()
{
	int op,n;
	ListaDE<int> *l1 = new ListaDE<int>();
	do {
		printf("\n\t\t\t\t\t*****LISTAS DOBLES*****\n\n");
		printf("\t\t\t1.  VALORES POR DEFECTO.\n");
		printf("\t\t\t2.  Insertar antes de la cabeza.\n");
		printf("\t\t\t3.  Insertar despues de la cola.\n");
		printf("\t\t\t4.  Insertar en su lugar.\n");
		printf("\t\t\t5.  Eliminar cabeza.\n");
		printf("\t\t\t6.  Eliminar cola.\n");
		printf("\t\t\t7.  Eliminar dado un valor.\n");
		printf("\t\t\t8.  Mostrar.\n");
		printf("\t\t\t9.  Cantidad de nodos.\n");
		printf("\t\t\t10. Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [1-10]: ");
		cin >> op;
		switch (op)
		{
		case 1:
		{
			l1->insertarPrincipio(18);
			l1->insertarPrincipio(12);
			l1->insertarPrincipio(9);
			l1->insertarFinal(25);
			l1->mostrar();
			system("pause");
		} break;
		case 2:
		{
			cout << "Ingrese un valor: ";
			cin >> n;
			l1->insertarPrincipio(n);
			l1->mostrar();
			system("pause");
		} break;
		case 3:
		{
			cout << "Ingrese un valor: ";
			cin >> n;
			l1->insertarFinal(n);
			l1->mostrar();
			system("pause");
		} break;
		case 4:
		{
			cout << "Ingrese un valor: ";
			cin >> n;
			l1->insertarSuLugar(n);
			l1->mostrar();
			system("pause");
		} break;
		case 5:
		{
			l1->eliminarCabeza();
			l1->mostrar();
			system("pause");
		} break;
		case 6:
		{
			l1->eliminarCola();
			l1->mostrar();
			system("pause");
		} break;
		case 7:
		{
			l1->mostrar();
			cout << "\nIngrese valor a eliminar: ";
			cin >> n;
			l1->eliminarPorValor(n);
			l1->mostrar();
			system("pause");
		} break;
		case 8:
		{
			l1->mostrar();
			system("pause");
		} break;
		case 9:
		{
			n = l1->candidadNodos();
			cout << "Son " << n << " Nodos." << endl;
			system("pause");
		} break;
		case 10:
		{
			printf("\nEL PROGRAMA HA TERMINADO... ");
			system("pause");
		} break;
		default:
			printf("LA OPCION ES INCORRECTA");
			system("pause");
			break;
		}
		system("cls");
	} while (op != 10);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
