#include "stdafx.h"
#include "ListaPersona.h"


ListaPersona::ListaPersona()
{
}

ListaPersona::ListaPersona(int max)
{
	this->max = max;
	this->n = 0;
	this->listaPersona = new Persona [max];
}

bool ListaPersona::addPersona(Persona persona)
{
	if (this->n != max) {
		this->listaPersona[n] = persona;
		this->n++;
		return true;
	}
	else {
		return false;
	}
}

Persona * ListaPersona::buscarPersona(string id)
{
	int i = 0;
	while (i < this->n && (this->listaPersona[i].getId()).compare(id)) {
		i++;
	}
	if ((this->listaPersona[i].getId()).compare(id)) {
		return &this->listaPersona[i];
	}
	else {
		return nullptr;
	}
}

bool ListaPersona::eliminarPersona(string id)
{
	int i = 0;
	while (i < this->n && (this->listaPersona[i].getId()).compare(id)) {
		i++;
	}
	if ((this->listaPersona[i].getId()).compare(id)) {
		for (int j = i; j < n - 1; j++) {
			this->listaPersona[j] = this->listaPersona[j + 1];
			//Eliminar pos n
			this->n--;
			return true;
		}
	}
	else {
		return false;
	}
}

int ListaPersona::getN()
{
	return this->n;
}


ListaPersona::~ListaPersona()
{
}
