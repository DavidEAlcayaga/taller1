#include "stdafx.h"
#include "ListaPersona.h"


ListaPersona::ListaPersona()
{
}

ListaPersona::ListaPersona(int max)
{
    this->max = max;
    this->cant = 0;
    this->listaPersona = new Persona [max];
}

bool ListaPersona::addPersona(Persona persona)
{
    if (this->cant != max) {
        this->listaPersona[cant] = persona;
        this->cant++;
        return true;
    }
    else {
        return false;
    }
}

Persona * ListaPersona::buscarPersona(string id)
{
    int i = 0;
    while (i < this->cant && (this->listaPersona[i].getId()).compare(id)) {
        i++;
    }
    if ((this->listaPersona[i].getId()).compare(id)) {
        return &this->listaPersona[i];
    }
    else {
        return nullptr;
    }
}

bool ListaPersona::eliminarPersona(string id)
{
    int i = 0;
    while (i < this->cant && (this->listaPersona[i].getId()).compare(id)) {
        i++;
    }
    if ((this->listaPersona[i].getId()).compare(id)) {
        for (int j = i; j < cant - 1; j++) {
            this->listaPersona[j] = this->listaPersona[j + 1];
            //Eliminar pos n
            this->cant--;
            return true;
        }
    }
    else {
        return false;
    }
}

int ListaPersona::getCant()
{
    return this->cant;
}


ListaPersona::~ListaPersona()
{
    delete[] listaPersona;
}

string ListaPersona::toString() {
    string s = "";
    for(int i=0; i<cant; i++){
       s+=listaPersona[i].toString()+'\n';
    }
}
