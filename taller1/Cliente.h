#pragma once
#include "Persona.h"
#include "ListaEvento.h"
#include <string>
using namespace std;

class Cliente : public Persona
{
private:
	int telefono;
  ListaEvento* eventosContratados;

public:
	Cliente();
  Cliente(string nombre, string apellido, string ciudad, int telefono, int id);

  ListaEvento* getEventosContratados();
  int getTelefono();
	
	string toString() override;

  virtual ~Cliente();
};
