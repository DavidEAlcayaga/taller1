#include "stdafx.h"
#include "Persona.h"


Persona::Persona(string nombre, string apellido, string ciudad) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->ciudad = ciudad;
    this->id = "NO_ID";

}

Persona::Persona() {
    //Default constructor
}

//<<<<<<< HEAD
string Persona::getId()
{
	return this->id;
}

//=======
Persona::~Persona() {

}

string Persona::getNombre() {
    return this->nombre;
}

string Persona::getApellido() {
    return this->apellido;
}

string Persona::getId() {
    return this->id;
}

string Persona::getCiudad() {
    return this->ciudad;
}
//>>>>>>> 91ae30baf363a79009df2cbf1f0aa502d4b79f5c

string Persona::toString() {
    return "NOMBRE: "+ nombre+" "+ apellido+" CIUDAD: "+ciudad+" ID: "+id;
}
