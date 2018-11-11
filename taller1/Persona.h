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
// HEAD
	Persona();
	string getId();
	~Persona();
	
	//Constructores
    Persona();
    Persona(string nombre, string apellido, string ciudad);
//>>>>>>> 91ae30baf363a79009df2cbf1f0aa502d4b79f5c

    //Getters
    string getNombre();
    string getApellido();
    string getId();
    string getCiudad();

    virtual string toString();

    //Destructor
    virtual ~Persona();
};
