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
	Evento(string nombre, string ciudad, string idCliente, string tipo, int personasEsperadas, string idAdministrador);
	string getIdEvento();
	string getNombre();
	string getEstado();
	string getTipo();
	string getIdAdministrador();
	int coste();
	int getPersonasEsperadas();
	int getPersonasAsistentes();
	void setId(string id);
	void setRealizado(int asistentes);
	void setCancelado();
	void setPorRealizar();
	~Evento();
	int utilidad();
	string verifyAdmin(ListaPersona* listaAdministrador, string ciudad);

};


