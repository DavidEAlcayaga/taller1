#pragma once
#include <string>
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
	~Evento();
};

