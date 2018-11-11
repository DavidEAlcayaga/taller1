#pragma once
#include <string>
using namespace std;

class Persona
{

//Elementos de la clase personas deben poder ser accedidos
//por las clases hijas

protected:
	string nombre;
	string apellido;
	string id;
	string ciudad;

public:
	
	//Constructores
    Persona();
    Persona(string nombre, string apellido, string ciudad);

    //Getters
    string getNombre();
    string getApellido();
    string getId();
    string getCiudad();

    virtual string toString();

    //Destructor
    virtual ~Persona();
};
