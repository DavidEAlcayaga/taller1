#pragma once
#include "Persona.h"
class ListaPersona
{
private:
	Persona * listaPersona;
	int max;
	int n;

public:
	ListaPersona(); //Siempre hay que conservar el constructor vac�o
	ListaPersona(int n);
	~ListaPersona();
};

