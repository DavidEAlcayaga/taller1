#include "stdafx.h"
#include "Sistema.h"


Sistema::Sistema()
{
  this->administradores = new ListaPersona(1000);
  this->clientes = new ListaPersona(1000);
  this->eventos = new ListaEvento(1000);
  this->correlativoAdmn = 0;
  this->correlativoCliente = 0;
  this->correlativoEvento = 0;
}


Sistema::~Sistema()
{
}
