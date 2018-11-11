#pragma once
#include "Evento.h"
class ListaEvento
{
private:
	Evento* listaEvento;
	int max;
	int n;

public:
	ListaEvento(); //Siempre hay que conservar el constructor vacío
	ListaEvento(int max);
	bool addEvento(Evento evento);
	Evento* buscarEvento(string idEvento);
	bool eliminarEvento(string idEvento);
	int getN();
	~ListaEvento();
};

