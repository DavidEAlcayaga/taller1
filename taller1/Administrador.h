#pragma once
#include "ListaEvento.h"
#include "Persona.h"
class Administrador:public Persona
{
private:
	int monto;
	ListaEvento *eventosAdministrados;

public:
	Administrador();

  Administrador(string nombre, string apellido, string ciudad, int monto, int id);

  virtual ~Administrador();

  Administrador(string nombre, string apellido, string ciudad, int monto, ListaEvento *eventosAdministrados, int id);

  int getMonto();

  ListaEvento* getEventosAdministrados();

  void setMonto(int monto);

  string toString() override;
};
