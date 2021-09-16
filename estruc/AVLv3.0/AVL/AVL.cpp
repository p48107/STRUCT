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
		printf("\n\t\t\t<<<<<   ARBOLES AVL   >>>>>\n\n");
		printf("\t\t\t0.  Valores por Defecto.\n");
		printf("\t\t\t1.  Cargar Archivo.\n");
		printf("\t\t\t2.  Insertar AVL.\n");
		printf("\t\t\t3.  Recorrer INORDEN.\n");
		printf("\t\t\t4.  Recorrer PREORDEN.\n");
		printf("\t\t\t5.  Recorrer POSTORDEN.\n");
		printf("\t\t\t6.  Eliminar AVL.\n");
		printf("\t\t\t7.  Contar AVL.\n");
		printf("\t\t\t8.  Destruir raiz AVL.\n");
		printf("\t\t\t9.  .\n");
		printf("\t\t\t10.  .\n");
		printf("\t\t\t11.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-11]: ");
		cin >> op;
		switch (op)
		{
		case 0:
		{
			/*c = a1->insertarAVL(10, a1->getRaiz());
			c = a1->insertarAVL(15, a1->getRaiz());
			c = a1->insertarAVL(20, a1->getRaiz());
			c = a1->insertarAVL(5, a1->getRaiz());
			c = a1->insertarAVL(1, a1->getRaiz());
			c = a1->insertarAVL(9, a1->getRaiz());*/
			//c = a1->insertarAVL(10, a1->getRaiz());
			//c = a1->insertarAVL(1, a1->getRaiz());
			/*c = a1->insertarAVL(4, a1->getRaiz());
			c = a1->insertarAVL(20, a1->getRaiz());
			c = a1->insertarAVL(15, a1->getRaiz());
			c = a1->insertarAVL(30, a1->getRaiz());
			c = a1->insertarAVL(27, a1->getRaiz());*/
			/*c = a1->insertarAVL(20, a1->getRaiz());
			c = a1->insertarAVL(7, a1->getRaiz());
			c = a1->insertarAVL(29, a1->getRaiz());
			c = a1->insertarAVL(3, a1->getRaiz());
			c = a1->insertarAVL(9, a1->getRaiz());
			c = a1->insertarAVL(24, a1->getRaiz());
			c = a1->insertarAVL(33, a1->getRaiz());
			c = a1->insertarAVL(1, a1->getRaiz());
			c = a1->insertarAVL(4, a1->getRaiz());
			c = a1->insertarAVL(12, a1->getRaiz());
			c = a1->insertarAVL(28, a1->getRaiz());
			c = a1->insertarAVL(31, a1->getRaiz());
			c = a1->insertarAVL(44, a1->getRaiz());
			c = a1->insertarAVL(63, a1->getRaiz());
			c = a1->insertarAVL(22, a1->getRaiz());
			c = a1->insertarAVL(21, a1->getRaiz());
			c = a1->insertarAVL(23, a1->getRaiz());*/
			//c = a1->insertarAVL(43, a1->getRaiz());
			//c = a1->insertarAVL(8, a1->getRaiz());
			/*c = a1->insertarAVL(3, a1->getRaiz());
			c = a1->insertarAVL(4, a1->getRaiz());
			c = a1->insertarAVL(5, a1->getRaiz());*/


			// GET IZQ EJEMPLOS
			/*c = a1->insertarAVL(6, a1->getRaiz());
			c = a1->insertarAVL(4, a1->getRaiz());
			c = a1->insertarAVL(2, a1->getRaiz());
			c = a1->insertarAVL(8, a1->getRaiz());
			c = a1->insertarAVL(10, a1->getRaiz());
			c = a1->insertarAVL(12, a1->getRaiz());
			c = a1->insertarAVL(1, a1->getRaiz());
			c = a1->insertarAVL(0, a1->getRaiz());*/

			// GET DER EJEMPLOS
			/*c = a1->insertarAVL(20, a1->getRaiz());
			c = a1->insertarAVL(17, a1->getRaiz());
			c = a1->insertarAVL(14, a1->getRaiz());
			c = a1->insertarAVL(12, a1->getRaiz());
			c = a1->insertarAVL(9, a1->getRaiz());
			c = a1->insertarAVL(6, a1->getRaiz());
			c = a1->insertarAVL(3, a1->getRaiz());
			c = a1->insertarAVL(4, a1->getRaiz());
			c = a1->insertarAVL(10, a1->getRaiz());
			c = a1->insertarAVL(11, a1->getRaiz());
			// GET DOBLE DERECHA NO NULL
			c = a1->insertarAVL(8, a1->getRaiz());*/
			
			//GET DOBLE DERECHA EN ALTURA 4
			/*c = a1->insertarAVL(50, a1->getRaiz());
			c = a1->insertarAVL(45, a1->getRaiz());
			c = a1->insertarAVL(40, a1->getRaiz());
			c = a1->insertarAVL(35, a1->getRaiz());
			c = a1->insertarAVL(30, a1->getRaiz());
			c = a1->insertarAVL(25, a1->getRaiz());
			c = a1->insertarAVL(20, a1->getRaiz());
			c = a1->insertarAVL(15, a1->getRaiz());
			c = a1->insertarAVL(28, a1->getRaiz());
			c = a1->insertarAVL(26, a1->getRaiz());
			c = a1->insertarAVL(29, a1->getRaiz());*/

			//GET DOBLE IZQUIERDA EN ALTURA 4
			c = a1->insertarAVL(50, a1->getRaiz());
			c = a1->insertarAVL(70, a1->getRaiz());
			c = a1->insertarAVL(90, a1->getRaiz());
			c = a1->insertarAVL(110, a1->getRaiz());
			c = a1->insertarAVL(150, a1->getRaiz());
			c = a1->insertarAVL(170, a1->getRaiz());
			c = a1->insertarAVL(160, a1->getRaiz());

			//GET DOBLE IZQUIERDA EN ALTURA 3
			/*c = a1->insertarAVL(28, a1->getRaiz());
			c = a1->insertarAVL(31, a1->getRaiz());
			c = a1->insertarAVL(55, a1->getRaiz());
			c = a1->insertarAVL(88, a1->getRaiz());
			c = a1->insertarAVL(96, a1->getRaiz());
			//c = a1->insertarAVL(40, a1->getRaiz());
			c = a1->insertarAVL(70, a1->getRaiz());
			//c = a1->insertarAVL(60, a1->getRaiz());
			*/
			//GET DOBLE DERECHA EN ALTURA 3
			/*c = a1->insertarAVL(200, a1->getRaiz());
			c = a1->insertarAVL(170, a1->getRaiz());
			c = a1->insertarAVL(100, a1->getRaiz());
			c = a1->insertarAVL(50, a1->getRaiz());
			c = a1->insertarAVL(150, a1->getRaiz());
			//c = a1->insertarAVL(130, a1->getRaiz());
			c = a1->insertarAVL(160, a1->getRaiz());*/
			alt = a1->altura(a1->getRaiz()) - 1;
			cout << "La altura es " << alt << endl;

			c = a1->diferencia(a1->getRaiz());
			if (c == true)
				cout << "Todas las alturas estan correctas" << endl;
			else
				cout << "Existen algunas alturas incorrectas" << endl;
			system("pause");
		} break;
		case 1:
		{
			a1->leerArchivo("datos.txt");
			cout << "ALTURA. " << endl;
			/*alt = a1->alturaNegraIzq(a1->getRaiz());
			cout << "La altura es " << alt <<endl;*/
			alt = a1->altura(a1->getRaiz()) - 1;
			cout << "La altura es " << alt << endl;
			c = a1->diferencia(a1->getRaiz());
			if (c == true)
				cout << "Todas las alturas estan correctas" << endl;
			else
				cout << "Existen algunas alturas incorrectas" << endl;
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
			cout << "CONTAR NODOS. " << endl;
			valor = a1->contarNodos(a1->getRaiz());
			cout << "Son " << valor << " Nodos" << endl;
			system("pause");
		} break;
		case 8:
		{
			cout << "DESTRUIR RAIZ. " << endl;
			a1->destruir(a1->getRaiz());
			cout << "Arbol Destruido. " << endl;
			system("pause");
		} break;
		case 9:
		{
			cout << ". " << endl;
			
			system("pause");
		} break;
		case 10:
		{
			cout << ". " << endl;
			
			system("pause");
		} break;
		case 11:
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
	} while (op != 11);
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
