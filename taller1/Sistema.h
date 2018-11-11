#pragma once
#include "ListaPersona.h"
class Sistema
{
private:
	ListaPersona * clientes;
	ListaPersona * administradores;
	ListaEvento * eventos;
	int correlativoAdmn;
  int correlativoCliente;
  int correlativoEvento;

public:
	Sistema();
	~Sistema();
};
