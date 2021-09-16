// AVL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "ArbolAVL.h"
#include "Nodo.h"
int main()
{
	int op, valor, alt;
	bool c;
	ArboAVL<int> *a1 = new ArboAVL<int>();
	do {
		printf("\n\t\t\t<<<<<   ARBOLES ALV   >>>>>\n\n");
		printf("\t\t\t0.  Valores por Defecto.\n");
		printf("\t\t\t1.  Cargar Archivo.\n");
		printf("\t\t\t2.  Insertar AVL.\n");
		printf("\t\t\t3.  Recorrer INORDEN.\n");
		printf("\t\t\t4.  Recorrer PREORDEN.\n");
		printf("\t\t\t5.  Recorrer POSTORDEN.\n");
		printf("\t\t\t6.  Eliminar AVL.\n");
		printf("\t\t\t7.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-7]: ");
		cin >> op;
		switch (op)
		{
		case 0:
		{
			c = a1->insertarAVL(10, a1->getRaiz());
			c = a1->insertarAVL(15, a1->getRaiz());
			c = a1->insertarAVL(20, a1->getRaiz());
			c = a1->insertarAVL(5, a1->getRaiz());
			c = a1->insertarAVL(1, a1->getRaiz());
			c = a1->insertarAVL(9, a1->getRaiz());
			//c = a1->insertarAVL(10, a1->getRaiz());
			//c = a1->insertarAVL(1, a1->getRaiz());
			/*c = a1->insertarAVL(4, a1->getRaiz());
			c = a1->insertarAVL(20, a1->getRaiz());
			c = a1->insertarAVL(15, a1->getRaiz());
			c = a1->insertarAVL(30, a1->getRaiz());
			c = a1->insertarAVL(27, a1->getRaiz());*/
			alt = a1->altura(a1->getRaiz());
			cout << "La altura es " << alt << endl;
			system("pause");
		} break;
		case 1:
		{
			a1->leerArchivo("datos.txt");
			cout << "ALTURA. " << endl;
			/*alt = a1->alturaNegraIzq(a1->getRaiz());
			cout << "La altura es " << alt <<endl;*/
			alt = a1->altura(a1->getRaiz());
			cout << "La altura es " << alt << endl;
			system("pause");
		} break;
		case 2:
		{
			cout << "INSERTAR. " << endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			c = a1->insertarAVL(valor, a1->getRaiz());
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
			cout << "ELIMINAR. " << endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			c = a1->eliminarAVL(a1->getRaiz(), valor);
			system("pause");
		} break;
		case 7:
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
	} while (op != 7);
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
