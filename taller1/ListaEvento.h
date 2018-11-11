#pragma once
#include "Evento.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class ListaEvento
{
private:
	Evento* listaEvento;
	int max;
	int n;

public:
	ListaEvento(); //Siempre hay que conservar el constructor vacío
	ListaEvento(int max);
	void ordenarId();
	bool addEvento(Evento evento);
	Evento* buscarEvento(string idEvento);
	void buscarEventoTipo(string tipo);
	bool eliminarEvento(string idEvento);
	int getN();
	~ListaEvento();

private:
	string getNewId();
};

