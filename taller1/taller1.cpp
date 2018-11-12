#include "stdafx.h"
#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;
 
int main() {
	Sistema* sistema = new Sistema();
	int command = 0;
	while (command != 4) {

		string id = "";
		cout << "Menú: " << endl;
		cout << "1.- Agregar" << endl;
		cout << "2.- Administrar eventos" << endl;
		cout << "3.- Buscar" << endl;
		cout << "4.- Salir" << endl;
		cin >> command;
		switch (command) {
		case 1:
			int command2 = 0;
			while (command2!=4) {
				cout << "Agregar: " << endl;
				cout << "1.- Agregar Evento" << endl;
				cout << "2.- Agregar Administrador" << endl;
				cout << "3.- Agregar Cliente" << endl;
				cout << "4.- Volver" << endl;
				cin >> command2;
				switch (command2) {
				case 1:
					sistema->AgregarEvento();
					break;

				case 2:
					sistema->AgregarAdministrador();
					break;

				case 3:
					sistema->AgregarCliente();
					break;

				case 4:
					break;

				default:
					cout << "Opción no válida" << endl;
					break;
				}
			}
			break;

		case 2:
			int command3 = 0;
			while (command3!=3) {
				cout << "Administrar Eventos: " << endl;
				cout << "1.- Marcar evento realizado" << endl;
				cout << "2.- Marcar evento cancelado" << endl;
				cout << "3.- Volver" << endl;
				cin >> command3;
				switch (command3) {
				case 1:
					cout << "Ingrese la id del evento" << endl;
					cin >> id;
					cout << "Ingrese cantidad de asistentes" << endl;
					int cantidadAsistentes = 0;
					cin >> cantidadAsistentes;
					sistema->EventoRealizado(id, cantidadAsistentes);
					break;

				case 2:
					sistema->AgregarAdministrador();
					break;

				case 3:
					break;

				default:
					cout << "Opción no válida" << endl;
					break;
				}
			}
			break;

		case 3:
			int command4 = 0;
			while (command4 != 4) {
				cout << "Buscar: " << endl;
				cout << "1.- Eventos por tipo" << endl;
				cout << "2.- Clientes por ciudad" << endl;
				cout << "3.- Administradores" << endl;
				cout << "4.- Volver" << endl;
				cin >> command4;
				switch (command4) {
				case 1:
					cout << "Ingrese el tipo de evento:" << endl;
					cin >> id;
					sistema->EventosTipo(id);
					break;

				case 2:
					cout << "Ingrese la ciudad" << endl;
					cin >> id;
					sistema->ClientesCiudad(id);
					break;

				case 3:
					sistema->Administradores();
					break;

				case 4:
					break;

				default:
					cout << "Opción no válida" << endl;
					break;
				}
			}
			break;

		case 4:
			cout << "Gracias por usar este programa" << endl;
			break;

		default:
			break;
		}
	}
}
 
 
 
 
