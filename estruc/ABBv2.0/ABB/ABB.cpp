// ABB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Arbol.h"
#include "Nodo.h"
int main()
{
	int op, n;
	int valor;
	bool sw;
	Arbol<int> *a1 = new Arbol<int>();
	Nodo<int> *n1 = new Nodo<int>();
	do {
		printf("\n\t\t<<<<<   ARBOLES BINARIOS MEMORIA DINAMICA   >>>>>\n\n");
		printf("\t\t\t0.  Valores por DEFECTO.\n");
		printf("\t\t\t1.  Insertar ABB.\n");
		printf("\t\t\t2.  Buscar ABB.\n");
		printf("\t\t\t3.  Recorrer INORDEN.\n");
		printf("\t\t\t4.  Recorrer PREORDEN.\n");
		printf("\t\t\t5.  Recorrer POSTORDEN.\n");
		printf("\t\t\t6.  Contar Nodos.\n");
		printf("\t\t\t7.  Calcular altura.\n");
		printf("\t\t\t8.  Encontrar MENOR.\n");
		printf("\t\t\t9.  Encontrar MAYOR.\n");
		printf("\t\t\t10. ELiminar elemento ABB.\n");
		printf("\t\t\t11. Siguiente.\n");
		printf("\t\t\t12. Mostrar.\n");
		printf("\t\t\t13. ESPEJO.\n");
		printf("\t\t\t14.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-14]: ");
		cin >> op;
		switch (op)
		{
		case 0:
		{
			/*a1->insertarABB('F', a1->getRaiz());
			a1->insertarABB('B', a1->getRaiz());
			a1->insertarABB('A', a1->getRaiz());
			a1->insertarABB('D', a1->getRaiz());
			a1->insertarABB('C', a1->getRaiz());
			a1->insertarABB('E', a1->getRaiz());
			a1->insertarABB('G', a1->getRaiz());
			a1->insertarABB('I', a1->getRaiz());
			a1->insertarABB('H', a1->getRaiz());*/

			a1->insertarABB(10, a1->getRaiz());
			a1->insertarABB(5, a1->getRaiz());
			a1->insertarABB(1, a1->getRaiz());
			a1->insertarABB(4, a1->getRaiz());
			a1->insertarABB(20, a1->getRaiz());
			a1->insertarABB(15, a1->getRaiz());
			a1->insertarABB(30, a1->getRaiz());
			a1->insertarABB(27, a1->getRaiz());
			//a1->niveles(a1->getRaiz(), 1);

			n = a1->contarHojas(a1->getRaiz());
			cout << "El arbol tiene " << n << " hojas." << endl;

			a1->mostrarArbol(a1->getRaiz(), 0);
			system("pause");
		} break;
		case 1:
		{
			cout << "INSERTAR. " <<endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			a1->insertarABB(valor, a1->getRaiz());
			system("pause");
		} break;
		case 2:
		{
			cout << "BUSCAR. " << endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			sw = a1->buscarABB(valor, a1->getRaiz());
			if (sw == 0) {
				cout << "El elemento no esta en el Arbol! " << endl;
			}
			else
			{
				cout << "El elemento esta en el Arbol! " << endl;
			}
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
			cout << "MENOR. " << endl;
			n1 = a1->menor(a1->getRaiz());
			if (n1 == NULL)
				std::cout << "Arbol vacio" << endl;
			else
				std::cout << "El menor es: " << n1->getValor() << endl;
			system("pause");
		} break;
		case 9:
		{
			cout << "MAYOR. " << endl;
			n1 = a1->mayor(a1->getRaiz());
			if (n1 == NULL)
				std::cout << "Arbol vacio" << endl;
			else
				std::cout << "El mayor es: " << n1->getValor() << endl;
			system("pause");
		} break;
		case 10:
		{
			cout << "ELIMINAR. " << endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			a1->eliminar(a1->getRaiz(), valor);
			system("pause");
		} break;
		case 11:
		{
			a1->sigNull();
			cout << "SIGUIENTE. " << endl;
			cout << "Ingrese un valor: ";
			cin >> valor;
			a1->siguiente(a1->getRaiz(), valor);
			if (a1->getSig() == NULL) {
				cout << "El elemento no existe" << endl;
			}
			else
			{
				cout << "Elemeno siguiente es " << a1->getSig()->getValor() << endl;
			}
			system("pause");
		} break;
		case 12:
		{
			cout << "ELIMINAR. " << endl;
			a1->mostrarArbol(a1->getRaiz(), 0);
			system("pause");
		} break;
		case 13:
		{
			cout << "ESPEJO. " << endl;
			a1->mostrarArbol(a1->getRaiz(), 0);
			cout << endl;
			Arbol<int> *a2 = new Arbol<int>();
			a1->espejo(a1->getRaiz(), a2->getRaiz());
			a2->mostrarArbol(a2->getRaiz(), 0);
			system("pause");
		} break;
		case 14:
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
	} while (op != 14);
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
