// Dijkstra.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Grafo.h"
int main()
{
	Grafo<int> *g1 = new Grafo<int>();
	bool b;
	int ini, fin, peso, op;
	do {
		printf("\n\t\t\t\t<<<<<   DIJKSTRA   >>>>>\n\n");
		printf("\t\t\t0.  Valores por DEFECTO.\n");
		printf("\t\t\t1.  Insertar.\n");
		printf("\t\t\t2.  Dijkstra.\n");
		printf("\t\t\t3.  .\n");
		printf("\t\t\t4.  .\n");
		printf("\t\t\t5.  .\n");
		printf("\t\t\t6.  Mostrar Grafo.\n");
		printf("\t\t\t7.  Leer archivo.\n");
		printf("\t\t\t8.  Vaciar Grafo.\n");
		printf("\t\t\t9.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-9]: ");
		cin >> op;
		switch (op)
		{
		case 0:
		{
			/*g1->leerArchivo("datos.txt");
			g1->dijkstra(1);
			g1->mostrarGrafo();
			cout << endl;
			g1->mostrarCamino(9);*/
			system("pause");
		} break;
		case 1:
		{
			cout << "INSERTAR ARISTA. " << endl;
			cout << "Ingrese un Origen: ";
			cin >> ini;
			cout << "Ingrese un Destino: ";
			cin >> fin;
			cout << "Ingrese Peso: ";
			cin >> peso;
			g1->insertarArista(ini, fin, peso);
			system("pause");
		} break;
		case 2:
		{
			cout << "DIJKSTRA. " << endl;
			cout << "Ingrese un Origen: ";
			cin >> ini;
			cout << "Ingrese un Destino: ";
			cin >> fin;
			g1->inicializarMPD();
			g1->dijkstra(ini);
			g1->mostrarGrafo();
			cout << endl;
			//g1->mostrarCamino(fin);
			for (int i = 0; i < 10; i++) {
				if (g1->getDistancia(i) != 400000000) {
					g1->mostrarCamino(i);
					cout << "Distancia: " << g1->getDistancia(i);
					cout << endl;
				}
			}
			cout << "Distancia: " << g1->getDistancia(fin) << endl;
			system("pause");
		} break;
		case 3:
		{
			cout << ". " << endl;

			system("pause");
		} break;
		case 4:
		{
			cout << ". " << endl;

			system("pause");
		} break;
		case 5:
		{
			cout << ". " << endl;

			system("pause");
		} break;
		case 6:
		{
			g1->mostrarGrafo();
			system("pause");
		} break;
		case 7:
		{
			g1->leerArchivo("datos.txt");
			g1->leerArchivoDep("datos2.txt");
			cout << "ARCHIVO CARGADO." << endl;
			system("pause");
		} break;
		case 8:
		{
			g1->inicializar();
			cout << "GRAFO VACIO. " << endl;
			system("pause");
		} break;
		case 9:
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
	} while (op != 9);

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
