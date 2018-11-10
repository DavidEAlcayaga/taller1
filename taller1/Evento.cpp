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



Evento::~Evento()
{
}

string Evento::verifyAdmin(ListaPersona* listaAdministrador, string ciudad)
{
	return string();
}
