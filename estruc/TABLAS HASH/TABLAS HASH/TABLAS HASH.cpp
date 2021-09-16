// TABLAS HASH.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "string.h"
#include "HASH.h"
#include "L8.h"

#include <vector>
#define TAM_VECTOR 1009
int main()
{
	//vector<int> *tmp;
	Hash<string> *h1 = new Hash<string>(TAM_VECTOR);
	Nodo<string> *el;
	h1->inicializar();
	int op, c;
	float p;
	string producto;
	do {
		printf("\n\t\t\t\t<<<<<   FERRETERIA   >>>>>\n\n");
		printf("\t\t\t1.  Leer Archivo e insertar en la HASH.\n");
		printf("\t\t\t2.  Insertar.\n");
		printf("\t\t\t3.  Eliminar.\n");
		printf("\t\t\t4.  Buscar.\n");
		printf("\t\t\t5.  Comprar.\n");
		printf("\t\t\t6.  Vender.\n");
		printf("\t\t\t7.  Mostrar.\n");
		printf("\t\t\t8.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [1-8]: ");
		cin >> op;
		switch (op)
		{
		case 1:
		{
			h1->leerArchivo("datos.txt");
			system("pause");
		} break;
		case 2:
		{
			cout << "Registro Producto:" << endl;
			cout << "Nombre Producto: ";
			getline(cin, producto);
			getline(cin, producto);
			cout << "Precio: ";
			cin >> p;
			cout << "Cantidad: ";
			cin >> c;
			h1->insertarL8(producto, p, c);
			system("pause");
		} break;
		case 3:
		{
			h1->mostrar();
			cout << "Registro Producto:" << endl;
			cout << "Nombre Producto: ";
			getline(cin, producto);
			getline(cin, producto);
			cout << "Precio: ";
			cin >> p;
			cout << "Cantidad: ";
			cin >> c;
			h1->eliminar(producto);
			system("pause");
		} break;
		case 4:
		{
			cout << "Registro Producto:" << endl;
			cout << "Nombre Producto: ";
			getline(cin, producto);
			getline(cin, producto);
			cout << "Precio: ";
			cin >> p;
			cout << "Cantidad: ";
			cin >> c;
			el = h1->buscar(producto);
			if (el == NULL) {
				cout << "No se encontro el producto a buscar..." << endl;
			}
			else {
				cout << "################ " << endl;
				cout << "\tProducto: " << producto << endl;
				cout << "\tPrecio: " << p << endl;
				cout << "\tCantidad: " << c << endl;
				cout << "################ " << endl;
				cout << endl;
			}
			system("pause");
		} break;
		case 5:
		{
			
			system("pause");
		} break;
		case 6:
		{
			
			system("pause");
		} break;
		case 7:
		{
			h1->mostrar();
			system("pause");
		} break;
		case 8:
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
	} while (op != 8);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
