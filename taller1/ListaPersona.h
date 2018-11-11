#pragma once
#include "Persona.h"
class ListaPersona
{
private:
    Persona* listaPersona;
    int max;
    int n;

public:
//<<<<<<< HEAD
	ListaPersona(); //Siempre hay que conservar el constructor vacío
	ListaPersona(int n);
	void ordenarId();
	bool addPersona(Persona persona);
	Persona* buscarPersona(string id);
	bool eliminarPersona(string id);
	int getN();
	string toString();
	~ListaPersona();

private:
	string getNewId();
};
