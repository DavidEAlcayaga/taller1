#pragma once
#include "Persona.h"
#include "Administrador.h"
#include "Cliente.h"
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
	bool addAdmin(Administrador administrador);
	bool addCliente(Cliente cliente);
	Persona* buscarPersona(string id);
	Administrador* buscarAdmin(string id);
	Cliente* buscarCliente(string id);
	void toString(string ciudad);
	bool eliminarPersona(string id);
	Administrador* getPosAdmin(int pos);
	int getN();
	string toString();
	~ListaPersona();

private:
	string getNewId();
};
