// TUADNODO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "L8.h"
#include "Tuad.h"
#include "Nodo.h"
#include <string>
#include "string.h"
#include <vector>
using namespace std;
int main()
{
	//vector<int> *tmp;
	Tuad<string> *t1 = new Tuad<string>();
	Nodo<string> *el;
	t1->inicializar();
	int op, d, m;
	string tarea;
	do {
		printf("\n\t\t\t\t\t<<<<<   AGENDA   >>>>>\n\n");
		printf("\t\t\t1.  VALORES POR DEFECTO.\n");
		printf("\t\t\t2.  Insertar Tarea.\n");
		printf("\t\t\t3.  Eliminar Tarea.\n");
		printf("\t\t\t4.  Buscar Tarea dada.\n");
		printf("\t\t\t5.  Buscar Tarea y retornar las fechas en las que se encuentra.\n");
		printf("\t\t\t6.  Mostrar TUAD de listas.\n");
		printf("\t\t\t7.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [1-7]: ");
		cin >> op;
		switch (op)
		{
		case 1:
		{
			t1->insertarL8(1, 1, "Examen Sorpresa");
			t1->insertarL8(2, 1, "Tarea Programacion");
			t1->insertarL8(3, 1, "Cita al Dentista");
			t1->insertarL8(4, 1, "Limpiar la casa");
			system("pause");
		} break;
		case 2:
		{
			cout << "Registro Tarea:" << endl;
			cout << "Dia: ";
			cin >> d;
			cout << "Mes: ";
			cin >> m;
			cout << "Ingrese una tarea: ";
			getline(cin, tarea);
			getline(cin, tarea);
			t1->insertarL8(d, m, tarea);
			system("pause");
		} break;
		case 3:
		{
			t1->mostrar();
			cout << "Eliminar Tarea:" << endl;
			cout << "Dia: ";
			cin >> d;
			cout << "Mes: ";
			cin >> m;
			cout << "Ingrese una tarea: ";
			getline(cin, tarea);
			getline(cin, tarea);
			t1->eliminar(d, m, tarea);
			system("pause");
		} break;
		case 4:
		{
			cout << "Buscar Tarea:" << endl;
			cout << "Dia: ";
			cin >> d;
			cout << "Mes: ";
			cin >> m;
			cout << "Ingrese una tarea: ";
			getline(cin, tarea);
			getline(cin, tarea);
			el = t1->buscar(d, m, tarea);
			if (el == NULL) {
				cout << "No se encontro la tarea a buscar..." << endl;
			}
			else {
				cout << "################ " << endl;
				cout << "TAREA ENCONTRADA" << endl;
				cout << d << " / " << m << endl;
				cout << "\t- " << tarea << endl;
				cout << "################ " << endl;
				cout << endl;
			}
			system("pause");
		} break;
		case 5:
		{
			cout << "Buscar Tarea + fechas:" << endl;
			cout << "Ingrese una tarea: ";
			getline(cin, tarea);
			getline(cin, tarea);
			t1->insertarFechas(tarea);
			t1->mostrarFecha();
			system("pause");
		} break;
		case 6:
		{
			t1->mostrar();
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
