#pragma once
#include <string>
using namespace std;

class Persona
{
private:
	string nombre;
	string apellido;
	string id;
	string ciudad;

public:
	Persona();
	string getId();
	~Persona();
};

