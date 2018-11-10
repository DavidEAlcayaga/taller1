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


ListaEvento::~ListaEvento()
{
}
