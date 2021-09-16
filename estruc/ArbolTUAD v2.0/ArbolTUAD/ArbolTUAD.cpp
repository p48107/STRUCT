// ArbolTUAD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "ArbolRN.h"
int main()
{
	bool b;
	char p, l;
	string palabra;
	ArbolRN<char> *a1 = new ArbolRN<char>();
	int n, op;
	do {
		printf("\n\t\t\t\t<<<<<   ARBOLES TRIE (DICCIONARIO)   >>>>>\n\n");
		printf("\t\t\t0.  Valores por DEFECTO.//TAREA\n");
		printf("\t\t\t1.  .\n");
		printf("\t\t\t2.  Insertar.//TAREA\n");
		printf("\t\t\t3.  Recorrer INORDEN.\n");
		printf("\t\t\t4.  Recorrer PREORDEN.\n");
		printf("\t\t\t5.  Recorrer POSTORDEN.\n");
		printf("\t\t\t6.  Contar Nodos.\n");
		printf("\t\t\t7.  Calcular altura.\n");
		printf("\t\t\t8.  .\n");
		printf("\t\t\t9.  Buscar.//TAREA\n");
		printf("\t\t\t10. Mostrar DICCIONARIO.//TAREA\n");
		printf("\t\t\t11. .\n");
		printf("\t\t\t12. Mostrar Arbol.\n");
		printf("\t\t\t13. .\n");
		printf("\t\t\t14. .\n");
		printf("\t\t\t15. .\n");
		printf("\t\t\t16.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-16]: ");
		cin >> op;
		switch (op)
		{
		case 0:
		{
			a1->insertarTrie("arbol");
			a1->insertarTrie("arma");
			a1->insertarTrie("armario");
			a1->insertarTrie("armagedon");
			a1->insertarTrie("zapato");
			a1->insertarTrie("salario");
			a1->insertarTrie("capa");
			a1->insertarTrie("caporales");
			a1->insertarTrie("cebra");
			a1->insertarTrie("cebada");
			a1->insertarTrie("zero");

			system("pause");
		} break;
		case 1:
		{
			//a1->leerArchivo("datos.txt");
			//a1->inOrden(a1->getRaiz());
			system("pause");
		} break;
		case 2:
		{
			cout << "INSERTAR. " << endl;
			cout << "Ingrese un palabra: ";
			cin >> palabra;
			a1->insertarTrie(palabra);
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
			//a1->mostrarArbol(a1->getRaiz(), 0);
			//a1->getBicola()->mostrar();
			system("pause");
		} break;
		case 9:
		{
			cout << "BUSCAR. " << endl;
			cout << "Ingrese una palabra: ";
			cin >> palabra;
			b = a1->buscarTrie(palabra);
			if (b == false)
			{
				cout << "La palabra que buscas no se encuentra en el Diccionario." << endl;
			}
			else
			{
				cout << "Se encontro la palabra." << endl;
			}
			system("pause");
		} break;
		case 10:
		{
			/*Nodo<char> *tmp = a1->buscaDevuelve('a', a1->getRaiz());
			a1->mostrarTrie(tmp->getT1());*/
			a1->mostrar(a1->getRaiz());
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
			cout << ". " << endl;
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
