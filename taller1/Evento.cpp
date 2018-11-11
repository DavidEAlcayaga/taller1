#include "stdafx.h"
#include "Evento.h"


Evento::Evento()
{
}

Evento::Evento(string nombre, string ciudad, string idCliente, string tipo, int personasEsperadas, ListaPersona* listaAdministrador)
{
	this->nombre = nombre;
	this->ciudad = ciudad;
	this->idCliente = idCliente;
	this->tipo = tipo;
	this->personasEsperadas = personasEsperadas;
	this->estado = nullptr;
	this->personasAsistentes = 0;
	this->idAdministrador = verifyAdmin(listaAdministrador, ciudad);
}

string Evento::getIdEvento()
{
	return this->idEvento;
}

string Evento::getNombre()
{
	return this->nombre;
}

string Evento::getEstado()
{
	return this->estado;
}

string Evento::getTipo()
{
	return this->tipo;
}

void Evento::setRealizado()
{
	this->estado = "realizado";
}

void Evento::setCancelado()
{
	this->estado = "cancelado";
}

void Evento::setPorRealizar()
{
	this->estado = "por realizar";
}



Evento::~Evento()
{
}

int Evento::utilidad()
{
	int utilidad = 0;
	if (this->tipo.compare("cultural")) {
		utilidad = (4 * this->personasAsistentes) - (2 * this->personasEsperadas);
	}
	else if (this->tipo.compare("social")) {
		utilidad = (9 * this->personasAsistentes) - (5 * this->personasEsperadas);
	}
	else if (this->tipo.compare("deportivo")) {
		utilidad = (11 * this->personasAsistentes) - (8 * this->personasEsperadas);
	}
	return utilidad;
}

string Evento::verifyAdmin(ListaPersona* listaAdministrador, string ciudad)
{
	for (int i = 0; i < listaAdministrador->getN(); i++) {
		while(listaAdministrador)
	}
}
