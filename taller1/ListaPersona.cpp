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


ListaPersona::~ListaPersona()
{
}
