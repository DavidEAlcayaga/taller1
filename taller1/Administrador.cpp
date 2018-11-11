#include "stdafx.h"
#include "Administrador.h"


Administrador::Administrador() {
    //Default Constructor
}

Administrador::Administrador(string nombre, string apellido, string ciudad, int monto, int id) : Persona(
        nombre, apellido, ciudad), monto(monto) {
        //Constructor con lista de eventos vacia(max 100)
        this->eventosAdministrados = new ListaEvento(100);
        this->id = "A"+to_string(id);

}

Administrador::Administrador(string nombre, string apellido, string ciudad, int monto,
                             ListaEvento *eventosAdministrados, int id) : Persona(nombre, apellido, ciudad){
        //Constructor con lista de eventos adquirida externamente
        this->monto = monto;
        this->eventosAdministrados = eventosAdministrados;
        this->id = "A"+to_string(id);
}

int Administrador::getMonto() {
        return this->monto;
}

ListaEvento* Administrador::getEventosAdministrados() {
        return this->eventosAdministrados;
}

Administrador::~Administrador() {

}

void Administrador::setMonto(int monto) {

    this->monto = monto;

}

string Administrador::toString() {
  return "NOMBRE: "+ nombre+" "+ apellido+" CIUDAD: "+ciudad+" ID: "+id + " Monto: "+ to_string(monto)+'\n'+
  "EVENTOS: " +'\n'+ eventosAdministrados->toString();
}
