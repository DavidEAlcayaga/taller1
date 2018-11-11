#include "stdafx.h"
#include "ListaPersona.h"


ListaPersona::ListaPersona()
{
}

ListaPersona::ListaPersona(int max)
{
	this->max = max;
	this->n = 0;
	this->listaPersona = new Persona [max];
}

void ListaPersona::ordenarId()
{
	Persona* aux = nullptr;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (((listaPersona[i].getId()).compare(listaPersona[j].getId())) == -1) {
				aux = &listaPersona[i];
				listaPersona[i] = listaPersona[j];
				listaPersona[j] = *aux;
			}
		}
	}
}

bool ListaPersona::addPersona(Persona persona)
{
	if (this->n != max) {
		this->listaPersona[n] = persona;
		this->n++;
		return true;
	}
	else {
		return false;
	}
}

Persona * ListaPersona::buscarPersona(string id)
{
	int i = 0;
	while (i < this->n && (this->listaPersona[i].getId()).compare(id)==0) {
		i++;
	}
	if ((this->listaPersona[i].getId()).compare(id)==0) {
		return &this->listaPersona[i];
	}
	else {
		return nullptr;
	}
}

bool ListaPersona::eliminarPersona(string id)
{
	int i = 0;
	while (i < this->n && (this->listaPersona[i].getId()).compare(id)==0) {
		i++;
	}
	if ((this->listaPersona[i].getId()).compare(id)==0) {
		for (int j = i; j < n - 1; j++) {
			this->listaPersona[j] = this->listaPersona[j + 1];
			//Eliminar pos n
			this->n--;
			return true;
		}
	}
	else {
		return false;
	}
}

int ListaPersona::getN()
{
	return this->n;
}


ListaPersona::~ListaPersona()
{
}

string ListaPersona::getNewId()
{
	string aux = listaPersona[n].getId();
	if (aux.length == 2) {
		int aux2 = (int)aux[1];
		aux2++;
		aux = aux[0] + (std::to_string(aux2));
		return aux;
	}
	else if (aux.length == 3) {
		int aux2 = (int)(aux[1] + aux[2]);
		if (aux2 < 99) {
			aux2++;
			aux = aux[0] + (std::to_string(aux2));
			return aux;
		}
		else {
			aux2++;
			aux = (aux[0] + 1) + '0';
			return aux;
		}
	}
}
