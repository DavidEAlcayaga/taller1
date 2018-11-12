#pragma once
#include "ListaPersona.h"
#include "ListaEvento.h"
#include <string>
#include <iostream>
#include <sstream>
#include <istream>
using namespace std;
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
	bool LeerArchivos();
	bool GuardarArchivos();
	bool AgregarEvento();
	bool AgregarAdministrador();
	bool AgregarCliente();
	bool EventoRealizado(string id, int cantidadAsistentes);
	bool CancelarEvento(string id);
	void EventosTipo(string tipo);
	void ClientesCiudad(string ciudad);
	void Administradores();
	~Sistema();
};
