#pragma once
#include <string>
#include "ListaPersona.h"
using namespace std;
class Evento
{
private:
	string nombre;
	string ciudad;
	string idCliente;
	string idAdministrador;
	string idEvento;
	string tipo;
	string estado;
	int personasEsperadas;
	int personasAsistentes;

public:
	Evento();
	Evento(string nombre, string ciudad, string idCliente, string tipo, int personasEsperadas, ListaPersona* listaAdministrador);
	~Evento();

private:
	string verifyAdmin(ListaPersona* listaAdministrador, string ciudad);

};


