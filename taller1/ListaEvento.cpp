#include "stdafx.h"
#include "ListaEvento.h"
#include <cstring>



ListaEvento::ListaEvento()
{
}

ListaEvento::ListaEvento(int max)
{
	this->max = max;
	this->n = 0;
	this->listaEvento = new Evento[max];
}

void ListaEvento::ordenarId()
{
	Evento* aux = nullptr;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (((listaEvento[i].getIdEvento()).compare(listaEvento[j].getIdEvento())) == -1) {
				aux = &listaEvento[i];
				listaEvento[i] = listaEvento[j];
				listaEvento[j] = *aux;
			}
		}
	}
}

bool ListaEvento::addEvento(Evento evento)
{
	if (this->n != max) {
		evento.setId(getNewId());
		this->listaEvento[n] = evento;
		this->n++;
		return true;
	}
	else {
		return false;
	}
}

Evento * ListaEvento::buscarEvento(string idEvento)
{
	int i = 0;
	while (i < this->n && (this->listaEvento[i].getIdEvento()).compare(idEvento)==0) {
		i++;
	}
	if ((this->listaEvento[i].getIdEvento()).compare(idEvento)==0) {
		return &this->listaEvento[i];
	}
	else {
		return nullptr;
	}
}

void ListaEvento::buscarEventoTipo(string tipo)
{
	for (int i = 0; i < n; i++) {
		if ((this->listaEvento[i].getTipo()).compare(tipo)==0 || tipo.compare("todos")==0) {
			cout << listaEvento[i].getNombre();
			cout << listaEvento[i].getIdEvento();
			cout << listaEvento[i].getEstado();
		}
	}
}

bool ListaEvento::eliminarEvento(string idEvento)
{
	int i = 0;
	while (i < this->n && (this->listaEvento[i].getIdEvento()).compare(idEvento)==0) {
		i++;
	}
	if ((this->listaEvento[i].getIdEvento()).compare(idEvento)==0) {
		for (int j = i; j < n-1; j++) {
			this->listaEvento[j] = this->listaEvento[j + 1];
			//Eliminar pos n
			this->n--;
			return true;
		}
	}
	else {
		return false;
	}
}


int ListaEvento::getN()
{
	return this->n;
}


ListaEvento::~ListaEvento()
{
}

string ListaEvento::getNewId()
{
	string aux = listaEvento[n].getIdEvento();
	if (aux.length == 2) {
		int aux2 = (int)aux[1];
		aux2++;
		aux = aux[0] + (std::to_string(aux2));
		return aux;
	}
	else if (aux.length == 3) {
		int aux2 = (int)(aux[1]+aux[2]);
		if (aux2 < 99) {
			aux2++;
			aux = aux[0] + (std::to_string(aux2));
			return aux;
		}
		else {
			aux2++;
			aux = (aux[0]+1) + '0';
		}
	}
}
