#pragma once
#include "Persona.h"
class ListaPersona
{
private:
    Persona* listaPersona;
    int max;
    int cant;

public:
    //Constructores
    ListaPersona();
    ListaPersona(int max);
    //Metodos del ArrayList

    bool addPersona(Persona persona);
    Persona* buscarPersona(string id);
    bool eliminarPersona(string id);
    string toString();
    int getCant();

    //Destructor
    ~ListaPersona();
};
