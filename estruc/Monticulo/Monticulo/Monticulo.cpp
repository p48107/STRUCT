// Monticulo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Nodo.h"
#include "ArbolHEAP.h"
int main()
{
	ArbolHEAP<int> *a1 = new ArbolHEAP<int>();
	a1->inicializar();
	
	/*a1->mostrar();
	a1->eliminarMB();
	a1->eliminarMB();
	a1->eliminarMB();
	a1->eliminarMB();*/

	int op, valor, alt;
	do {
		printf("\n\t\t<<<<<   MONTICULO BINARIO ARRAY (MAX HEAP)    >>>>>\n\n");
		printf("\t\t\t0.  Valores por Defecto.\n");
		printf("\t\t\t1.  Cargar Archivo.\n");
		printf("\t\t\t2.  Insertar HEAP.\n");
		printf("\t\t\t3.  Eliminar HEAP.\n");
		printf("\t\t\t4.  Mostrar Array.\n");
		printf("\t\t\t5.  Mostrar Arbol.\n");
		printf("\t\t\t6.  Destruir Arbol.\n");
		printf("\t\t\t7.  Contar.\n");
		printf("\t\t\t8.  .\n");
		printf("\t\t\t9.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-9]: ");
		cin >> op;
		switch (op)
		{
		case 0:
		{
			a1->insertarMB(30);
			a1->insertarMB(20);
			a1->insertarMB(1);
			a1->insertarMB(80);
			a1->insertarMB(50);
			a1->insertarMB(49);
			a1->insertarMB(100);

			a1->insertarMB(32);
			a1->insertarMB(12);
			a1->insertarMB(199);
			a1->insertarMB(200);
			a1->insertarMB(4);
			a1->insertarMB(1000);
			a1->insertarMB(99);
			a1->insertarMB(37);
			a1->insertarMB(6);
			a1->insertarMB(66);
			a1->insertarMB(77);
			a1->insertarMB(500);


			a1->mostrar();
			cout << endl;
			cout << endl;
			alt = a1->altura(1);
			cout << "La altura es: "<< alt << endl;
			a1->mostrarArbol(1,0);
			system("pause");
		} break;
		case 1:
		{
			/*a1->leerArchivo("datos.txt");
			cout << "ALTURA. " << endl;
			/*alt = a1->alturaNegraIzq(a1->getRaiz());
			cout << "La altura es " << alt <<endl;*/
			/*alt = a1->altura(a1->getRaiz()) - 1;
			cout << "La altura es " << alt << endl;
			c = a1->diferencia(a1->getRaiz());
			if (c == true)
				cout << "Todas las alturas estan correctas" << endl;
			else
				cout << "Existen algunas alturas incorrectas" << endl;
			system("pause");*/
		} break;
		case 2:
		{
			cout << "INSERTAR. " << endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			a1->insertarMB(valor);
			a1->mostrar();
			cout << endl;
			cout << endl;
			a1->mostrarArbol(1, 0);
			system("pause");
		} break;
		case 3:
		{
			cout << "ELIMINAR. " << endl;
			valor = a1->eliminarMB();
			cout << "Se elimino el elemento de la Raiz: " << valor << endl;
			a1->mostrar();
			cout << endl;
			cout << endl;
			a1->mostrarArbol(1, 0);
			system("pause");
		} break;
		case 4:
		{
			cout << "MOSTRAR ARRAY. " << endl;
			a1->mostrar();
			system("pause");
		} break;
		case 5:
		{
			cout << "MOSTRAR ARBOL. " << endl;
			a1->mostrarArbol(1,0);
			system("pause");
		} break;
		case 6:
		{
			cout << "BORRAR ARBOL. " << endl;
			a1->inicializar();
			system("pause");
		} break;
		case 7:
		{
			/*cout << "CONTAR NODOS. " << endl;
			valor = a1->contarNodos(a1->getRaiz());
			cout << "Son " << valor << " Nodos" << endl;*/
			system("pause");
		} break;
		case 8:
		{
			
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
