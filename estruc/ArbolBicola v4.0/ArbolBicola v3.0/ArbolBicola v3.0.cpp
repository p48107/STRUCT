// ArbolBicola v3.0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Arbol.h"
#include "L8.h"
#include <vector>
#include "string.h"
#include <string>
using namespace std;
int main()
{
	int n, valor, op;
	Arbol<int> *a1 = new Arbol<int>();
	Nodo<int> *n1 = new Nodo<int>();
	do {
		printf("\n\t\t\t\t<<<<<   MONTICULO MEMORIA DINAMICA   >>>>>\n\n");
		printf("\t\t\t0.  Valores por DEFECTO.\n");
		printf("\t\t\t1.  Leer Archivo.\n");
		printf("\t\t\t2.  Insertar.\n");
		printf("\t\t\t3.  Recorrer INORDEN.\n");
		printf("\t\t\t4.  Recorrer PREORDEN.\n");
		printf("\t\t\t5.  Recorrer POSTORDEN.\n");
		printf("\t\t\t6.  Contar Nodos.\n");
		printf("\t\t\t7.  Calcular altura.\n");
		printf("\t\t\t8.  Eliminar.\n");
		printf("\t\t\t9.  HEAPSORT.\n");
		printf("\t\t\t10. .\n");
		printf("\t\t\t11. .\n");
		printf("\t\t\t12. Mostrar Arbol.\n");
		printf("\t\t\t13. Mostrar Arbol de Listas.\n");
		printf("\t\t\t14. .\n");
		printf("\t\t\t15. .\n");
		printf("\t\t\t16.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-16]: ");
		cin >> op;
		switch (op)
		{
		case 0:
		{
			a1->insertar(100);
			a1->insertar(50);
			a1->insertar(10);
			a1->insertar(70);
			a1->insertar(60);
			a1->insertar(9);
			a1->insertar(5);
			a1->insertar(80);
			a1->insertar(200);
			a1->insertar(500);
			a1->insertar(1);
			a1->insertar(165);
			a1->insertar(132);
			a1->insertar(11);
			a1->insertar(199);

			n = a1->contarHojas(a1->getRaiz());
			cout << "El arbol tiene " << n << " hojas." << endl;
			//a1->mostrarArbol(a1->getRaiz(), 0);
			cout << "\n\n\n";
			a1->eliminar();
			a1->eliminar();
			a1->eliminar();
			a1->eliminar();
			a1->eliminar();
			a1->eliminar();
			a1->eliminar();
			a1->mostrarArbol(a1->getRaiz(), 0);
			a1->getBicola()->mostrar();
			a1->eliminar();
			a1->mostrarArbol(a1->getRaiz(), 0);
			a1->getBicola()->mostrar();
			system("pause");
		} break;
		case 1:
		{
			a1->leerArchivo("datos.txt");
			//a1->inOrden(a1->getRaiz());
			system("pause");
		} break;
		case 2:
		{
			cout << "INSERTAR. " << endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			a1->insertar(valor);
			//a1->mostrarArbol(a1->getRaiz(), 0);
			system("pause");
		} break;
		case 3:
		{
			cout << "INORDEN. " << endl;
			a1->inOrden(a1->getRaiz());
			cout << endl;
			system("pause");
		} break;
		case 4:
		{
			cout << "PREORDEN. " << endl;
			a1->preOrden(a1->getRaiz());
			cout << endl;
			system("pause");
		} break;
		case 5:
		{
			cout << "POSTORDEN. " << endl;
			a1->postOrden(a1->getRaiz());
			cout << endl;
			system("pause");
		} break;
		case 6:
		{
			cout << "CONTAR. " << endl;
			int c = a1->contar(a1->getRaiz());
			std::cout << "Son " << c << " Elementos " << endl;
			system("pause");
		} break;
		case 7:
		{
			cout << "ALTURA. " << endl;
			int c = a1->altura(a1->getRaiz());
			std::cout << "La altura es " << c << endl;
			system("pause");
		} break;
		case 8:
		{
			int aux;
			cout << "ELIMINAR. " << endl;
			aux = a1->eliminar();
			cout << aux << endl;
			//a1->mostrarArbol(a1->getRaiz(), 0);
			//a1->getBicola()->mostrar();
			system("pause");
		} break;
		case 9:
		{
			cout << "HEAPSORT. " << endl;
			vector<int> vec;
			int cont = 0;
			int i = 0;
			while (i != -1)
			{
				i = a1->eliminar();
				if (i != -1) {
					vec.push_back(i);
					cout << vec[cont] << "| ";
					cont++;
				}
			}
			a1 = new Arbol<int>();
			system("pause");
		} break;
		case 10:
		{

			system("pause");
		} break;
		case 11:
		{

			system("pause");
		} break;
		case 12:
		{
			cout << "MOSTRAR ARBOL. " << endl;
			a1->mostrarArbol(a1->getRaiz(), 0);
			system("pause");
		} break;
		case 13:
		{
			cout << "MOSTRAR ARBOL DE LISTAS. " << endl;
			a1->mostrarA(a1->getRaiz());
			system("pause");
		} break;
		case 14:
		{

			system("pause");
		} break;
		case 15:
		{

			system("pause");
		} break;

		case 16:
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
	} while (op != 16);
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
