// ListasDoblesv1.0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "ListaDE.h"
#include <iostream>
using namespace std;
int main()
{
	ListaDE<int> *l1 = new ListaDE<int>();
	int opc, el;
	do
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "1.-insertar al principio" << endl;
		cout << "2.-insertar al final" << endl;
		cout << "3.-insertar en su lugar" << endl;
		cout << "4.-eliminar al principio" << endl;
		cout << "5.-eliminar al final" << endl;
		cout << "6.-eliminar por valor" << endl;
		cout << "7.-mostrar" << endl;
		cout << "8.-cantidad de nodos" << endl;
		cout << "9.-Salir" << endl;
		cout << "elejir opcion:" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "ingrese dato:" << endl;
			cin >> el;
			l1->insertarPrincipio(el);
			break;
		case 2:
			cout << "ingrese dato:" << endl;
			cin >> el;
			l1->insertarFinal(el);
			break;
		case 3:
			cout << "ingrese dato:" << endl;
			cin >> el;
			l1->insertarEnSuLugar(el);
			break;
		case 4:
			l1->eliminarPrincipio();
			break;
		case 5:
			l1->eliminarFinal();
			break;
		case 6:
			if (l1->getPrimer() != NULL)
			{
				cout << "ingrese dato:" << endl;
				cin >> el;
				l1->eliminarPorValor(el);
			}
			break;
		case 7:
			l1->mostrar();
			system("pause");
			break;
		case 8:
			cout << "cantidad de nodos" << l1->getCont() << endl;
			break;
		}
	} while (opc != 9);

	/*l1->insertarPrincipio(5);
	l1->insertarPrincipio(1);
	l1->insertarFinal(10);
	l1->insertarPrincipio(7);
	l1->insertarEnSuLugar(2);
	l1->eliminarPrincipio();
	l1->eliminarFinal();
	l1->eliminarPorValor(7);
	l1->mostrar();*/
	return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
