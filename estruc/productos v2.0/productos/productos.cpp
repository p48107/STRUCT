// ABB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Arbol.h"
#include "Nodo.h"
#include <string>
#include "string.h"
#include <fstream>
int main()
{
	int op, n;
	string valor,valor1;
	float precio;
	bool sw;
	Arbol<string> *a1 = new Arbol<string>();
	Nodo<string> *n1 = new Nodo<string>();
	do {
		printf("\n\t<<<<<   ARBOLES BINARIOS DE BUSQUEDA MEMORIA DINAMICA   >>>>>\n\n");
		printf("\t\t\t0.  Valores por DEFECTO.\n");
		printf("\t\t\t1.  Insertar un producto. //PRACTICA\n");//PRACTICA
		printf("\t\t\t2.  Insertar precio y pagina web. //PRACTICA\n");//PRACTICA
		printf("\t\t\t3.  Recorrer INORDEN.\n");
		printf("\t\t\t4.  Recorrer PREORDEN.\n");
		printf("\t\t\t5.  Recorrer POSTORDEN.\n");
		printf("\t\t\t6.  Contar Nodos.\n");
		printf("\t\t\t7.  Calcular altura.\n");
		printf("\t\t\t8.  Encontrar MENOR.\n");
		printf("\t\t\t9.  Encontrar MAYOR.\n");
		printf("\t\t\t10. ELiminar elemento ABB. //PRACTICA\n");//PRACTICA
		printf("\t\t\t11. Siguiente.\n");
		printf("\t\t\t12. Mostrar Arbol.\n");
		printf("\t\t\t13. Mostrar Arbol de Listas. //PRACTICA\n");//PRACTICA
		printf("\t\t\t14. Buscar Mejor Precio. //PRACTICA\n");//PRACTICA
		printf("\t\t\t15. Eliminar precio y pagina web.\n");
		printf("\t\t\t16.  Salir.\n\n");
		printf("\nQue opcion desea realizar!!! [0-16]: ");
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

			a1->insertarABB("Manzana", a1->getRaiz());
			a1->insertarABB("Rabano", a1->getRaiz());
			a1->insertarABB("Papaya", a1->getRaiz());
			a1->insertarABB("Higo", a1->getRaiz());
			a1->insertarABB("Locoto", a1->getRaiz());
			a1->insertarABB("Hortalizas", a1->getRaiz());
			a1->insertarABB("Coco", a1->getRaiz());
			a1->insertarABB("Camote", a1->getRaiz());
			a1->insertarABB("Aceite de Oliva", a1->getRaiz());

			n1 = a1->buscaYdevuelve("Aceite de Oliva", a1->getRaiz());
			n1->getLista()->insertarEnSuLugar("web2", 80);
			n1->getLista()->insertarEnSuLugar("web3", 150);
			n1->getLista()->insertarEnSuLugar("web4", 60);
			n1->getLista()->insertarEnSuLugar("web5", 100);
			n1->getLista()->insertarEnSuLugar("web6", 70);

			/*a1->insertaPrecioWeb("Arroz", "web1", 15);
			a1->insertaPrecioWeb("Aceite de Oliva", "web2", 80);
			a1->insertaPrecioWeb("Aceite de Oliva", "web3", 150);
			a1->insertaPrecioWeb("Aceite de Oliva", "web4", 60);
			a1->insertaPrecioWeb("Aceite de Oliva", "web5", 100);
			a1->insertaPrecioWeb("Aceite de Oliva", "web6", 70);*/
			//a1->niveles(a1->getRaiz(), 1);

			n = a1->contarHojas(a1->getRaiz());
			cout << "El arbol tiene " << n << " hojas." << endl;

			a1->mostrarArbol(a1->getRaiz(), 0);
			//a1->eliminar(a1->getRaiz(), "Aceite de Oliva");
			a1->eliminar(a1->getRaiz(), "Hortalizas");
			a1->eliminar(a1->getRaiz(), "Manzana");
			a1->eliminar(a1->getRaiz(), "Higo");
			a1->mostrarArbol(a1->getRaiz(), 0);
			system("pause");
		} break;
		case 1:
		{
			cout << "INSERTAR PRODUCTO. " << endl;
			cout << "Ingrese un producto: ";
			getline(cin, valor);
			getline(cin, valor);
			cout << endl;
			a1->insertarABB(valor, a1->getRaiz());
			system("pause");
		} break;
		case 2:
		{
			cout << "INSERTAR PRECIO Y PAGINA WEB. " << endl;
			cout << "Ingrese un producto: ";
			getline(cin, valor);
			getline(cin, valor);
			n1 = a1->buscaYdevuelve(valor, a1->getRaiz());
			if (n1 == NULL)
				cout << "Producto No Registrado" << endl;
			else
			{
				cout << "Ingrese una pagina Web: ";
				cin >> valor1;
				cout << "Ingrese un precio: ";
				cin >> precio;
				//a1->insertaPrecioWeb(valor, valor1, precio);
				n1->getLista()->insertarEnSuLugar(valor1, precio);
				cout << "\nREGISTRADO." << endl;
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
				std::cout << "El menor es: " << n1->getProducto() << endl;
			system("pause");
		} break;
		case 9:
		{
			cout << "MAYOR. " << endl;
			n1 = a1->mayor(a1->getRaiz());
			if (n1 == NULL)
				std::cout << "Arbol vacio" << endl;
			else
				std::cout << "El mayor es: " << n1->getProducto() << endl;
			system("pause");
		} break;
		case 10:
		{
			cout << "ELIMINAR. " << endl;
			cout << "Ingrese un producto: ";
			getline(cin, valor);
			getline(cin, valor);
			cout << endl;
			a1->eliminar(a1->getRaiz(), valor);
			system("pause");
		} break;
		case 11:
		{
			a1->sigNull();
			cout << "SIGUIENTE. " << endl;
			cout << "Ingrese un producto: ";
			getline(cin, valor);
			getline(cin, valor);
			cout << endl;
			a1->siguiente(a1->getRaiz(), valor);
			if (a1->getSig() == NULL) {
				cout << "El elemento no existe" << endl;
			}
			else
			{
				cout << "Elemento siguiente es " << a1->getSig()->getProducto() << endl;
			}
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
			cout << "BUSCAR MEJOR PRECIO. " << endl;
			cout << "Ingrese un producto: ";
			getline(cin, valor);
			getline(cin, valor);
			a1->mejorPrecio(valor);
			system("pause");
		} break;
		case 15:
		{
			cout << "ELIMINAR PRECIO Y PAGINA WEB. " << endl;
			cout << "Ingrese un producto: ";
			getline(cin, valor);
			getline(cin, valor);
			n1 = a1->buscaYdevuelve(valor, a1->getRaiz());
			if (n1 == NULL)
				cout << "Producto No Registrado" << endl;
			else
			{
				cout << "Ingrese una pagina Web: ";
				cin >> valor1;
				cout << "Ingrese un precio: ";
				cin >> precio;
				n1->getLista()->eliminar(valor1, precio);
				cout << "\nELIMINADO." << endl;
			}
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
