#pragma once
#include "Persona.h"
#include "ListaEvento.h"
#include <string>
using namespace std;

class Cliente : public Persona
{
private:
	int numeroTelefonico;
	ListaEvento* listaEventoContratado;

public:
	Cliente();
	~Cliente();
};

