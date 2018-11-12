#include "stdafx.h"
#include "Cliente.h"


Cliente::Cliente() {}

Cliente::Cliente(string nombre, string apellido, string ciudad, int telefono, string id)
: Persona(nombre, apellido, ciudad), telefono(telefono) {

	this->id = "";
        this->eventosContratados = new ListaEvento(100);
}

ListaEvento *Cliente::getEventosContratados() {
        return this->eventosContratados;
}

int Cliente::getTelefono() {
        return this->telefono;
}

Cliente::~Cliente() {

}

string Cliente::toString() {
        return "NOMBRE: "+ nombre+" "+ apellido+" CIUDAD: "+ciudad+" ID: "+id+
        " TELEFONO: "+to_string(telefono)+'\n'+"EVENTOS: "+'\n'+eventosContratados->toString();
}
