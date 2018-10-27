#pragma once
#include "ListaEvento.h"
#include "Persona.h"
class Administrador:public Persona
{
private:
	int monto;
	ListaEvento* listaEvento;

public:
	Administrador();
	~Administrador();
};

