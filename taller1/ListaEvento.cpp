#include "stdafx.h"
#include "ListaEvento.h"


ListaEvento::ListaEvento()
{
}

ListaEvento::ListaEvento(int max)
{
	this->max = max;
	this->n = 0;
	this->listaEvento = new Evento[max];
}

bool ListaEvento::addEvento(Evento evento)
{
	if (this->n != max) {
		this->listaEvento[n] = evento;
		this->n++;
		return true;
	}
	else {
		return false;
	}
}

Evento * ListaEvento::buscarEvento(string idEvento)
{
	int i = 0;
	while (i < this->n && (this->listaEvento[i].getIdEvento()).compare(idEvento)) {
		i++;
	}
	if ((this->listaEvento[i].getIdEvento()).compare(idEvento)) {
		return &this->listaEvento[i];
	}
	else {
		return nullptr;
	}
}

bool ListaEvento::eliminarEvento(string idEvento)
{
	int i = 0;
	while (i < this->n && (this->listaEvento[i].getIdEvento()).compare(idEvento)) {
		i++;
	}
	if ((this->listaEvento[i].getIdEvento()).compare(idEvento)) {
		for (int j = i; j < n-1; j++) {
			this->listaEvento[j] = this->listaEvento[j + 1];
			//Eliminar pos n
			this->n--;
			return true;
		}
	}
	else {
		return false;
	}
}


int ListaEvento::getN()
{
	return this->n;
}


ListaEvento::~ListaEvento()
{
}
