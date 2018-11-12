#include "stdafx.h"
#include "Sistema.h"


Sistema::Sistema()
{
  this->administradores = new ListaPersona(1000);
  this->clientes = new ListaPersona(1000);
  this->eventos = new ListaEvento(1000);
  this->correlativoAdmn = 0;
  this->correlativoCliente = 0;
  this->correlativoEvento = 0;
}

bool Sistema::LeerArchivos()
{
	return false;
}

bool Sistema::GuardarArchivos()
{
	return false;
}

bool Sistema::AgregarEvento()
{
	cout << "Ingrese nombre" << endl;
	string nombre = NULL;
	cin >> nombre;
	cout << "Ingrese ciudad" << endl;
	string ciudad = NULL;
	cin >> ciudad;
	cout << "Ingrese idCliente" << endl;
	string idCliente = NULL;
	cin >> idCliente;
	cout << "ingrese tipo de evento" << endl;
	string tipo = NULL;
	cin >> tipo;
	cout << "Ingrese cantidad de personas esperadas" << endl;
	int personasEsperadas = 0;
	cin >> personasEsperadas;
	string idAdmin = NULL;
	int min = 99999;
	Administrador* adminAux = nullptr;

	for (int i = 0; i < this->administradores->getN(); i++) {
		if (this->administradores->getPosAdmin(i)->getEventosAdministrados()->getN() < min && this->administradores->getPosAdmin(i)->getCiudad().compare(ciudad) == 0) {
			min = this->administradores->getPosAdmin(i)->getEventosAdministrados()->getN();
			adminAux = this->administradores->getPosAdmin(i);
		}
	}
	if (adminAux == nullptr) {
		cout << "No hay administrador disponible en la ciudad, por favor agregue uno." << endl;
		return false;
	}
	else {
		idAdmin = adminAux->getId();
	}
	Evento* evento = new Evento(nombre, ciudad, idCliente, tipo, personasEsperadas, idAdmin);
	administradores->buscarAdmin(idAdmin)->getEventosAdministrados()->addEvento(*evento);
	eventos->addEvento(*evento);
}

bool Sistema::AgregarAdministrador()
{
	cout << "Ingrese nombre" << endl;
	string nombre = NULL;
	cin >> nombre;
	cout << "Ingrese apellido" << endl;
	string apellido = NULL;
	cin >> apellido;
	cout << "Ingrese ciudad" << endl;
	string ciudad = NULL;
	cin >> ciudad;
	Administrador* admin = new Administrador(nombre, apellido, ciudad, 7000, NULL);
	administradores->addAdmin(*admin);
}

bool Sistema::AgregarCliente()
{
	cout << "Ingrese nombre" << endl;
	string nombre = NULL;
	cin >> nombre;
	cout << "Ingrese apellido" << endl;
	string apellido = NULL;
	cin >> apellido;
	cout << "Ingrese ciudad" << endl;
	string ciudad = NULL;
	cin >> ciudad;
	cout << "Ingrese telefono" << endl;
	int telefono = NULL;
	cin >> telefono;
	Cliente* cliente = new Cliente(nombre, apellido, ciudad, telefono, "");
	clientes->addCliente(*cliente);
}

bool Sistema::EventoRealizado(string id, int cantidadAsistentes)
{
	Evento* evento;
	evento = eventos->buscarEvento(id);
	if (evento == nullptr) {
		cout << "No se encuentra el evento." << endl;
		return false;
	}
	else {
		if (evento->getPersonasAsistentes() > evento->getPersonasEsperadas()) {
			cout << "No válido, las personas asistentes no deben superar a las esperadas." << endl;
			return false;
		}
		else {
			cout << "Utilidad:  ";
			cout << evento->utilidad();
			cout << "  dólares." << endl;
			Administrador* admin = administradores->buscarAdmin(evento->getIdAdministrador());
			admin->setMonto(admin->getMonto() + (evento->utilidad()*0.5));
			if (admin->getMonto() <= 0) {
				cout << "El administrador: ";
				cout << admin->toString();
				cout << "  fue despedido." << endl;
				administradores->eliminarPersona(admin->getId());
			}
			return true;
		}
	}
}

bool Sistema::CancelarEvento(string id)
{
	Evento* evento;
	evento = eventos->buscarEvento(id);
	if (evento == nullptr) {
		cout << "No se encuentra el evento." << endl;
		return false;
	}
	else {
		Administrador* admin = administradores->buscarAdmin(evento->getIdAdministrador());
		admin->setMonto(admin->getMonto() + (evento->coste()*0.25));
		evento->setCancelado();
		cout << "Evento: ";
		cout << evento->getNombre();
		cout << " cancelado" << endl;
		if (admin->getMonto() <= 0) {
			cout << "El administrador: ";
			cout << admin->toString();
			cout << "  fue despedido." << endl;
			administradores->eliminarPersona(admin->getId());		
			return true;
		}
	}
}

void Sistema::EventosTipo(string tipo)
{
	eventos->buscarEventoTipo(tipo);
}

void Sistema::ClientesCiudad(string ciudad)
{
	clientes->toString(ciudad);
}

void Sistema::Administradores()
{
	administradores->toString();
}


Sistema::~Sistema()
{
}
