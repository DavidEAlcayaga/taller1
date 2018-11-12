#include "stdafx.h"
#include "Evento.h"


Evento::Evento()
{
}

Evento::Evento(string nombre, string ciudad, string idCliente, string tipo, int personasEsperadas, string idAdministrador)
{
	this->nombre = nombre;
	this->ciudad = ciudad;
	this->idCliente = idCliente;
	this->tipo = tipo;
	this->personasEsperadas = personasEsperadas;
	this->estado = "por realizar";
	this->personasAsistentes = 0;
	this->idAdministrador = idAdministrador;
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

string Evento::getIdAdministrador()
{
	return this->idAdministrador;
}

int Evento::coste()
{
	int coste = 0;
	if (this->tipo.compare("cultural")) {
		coste = (2 * this->personasEsperadas);
	}
	else if (this->tipo.compare("social")) {
		coste = (5 * this->personasEsperadas);
	}
	else if (this->tipo.compare("deportivo")) {
		coste = (8 * this->personasEsperadas);
	}
	return coste;
}

int Evento::getPersonasEsperadas()
{
	return this->personasEsperadas;
}

int Evento::getPersonasAsistentes()
{
	return this->personasAsistentes;
}

void Evento::setId(string id)
{
	this->idEvento = id;
}

void Evento::setRealizado(int asistentes)
{
	this->estado = "realizado";
	this->personasAsistentes = asistentes;
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

