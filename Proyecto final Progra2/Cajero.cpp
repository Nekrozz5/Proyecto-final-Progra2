#include "Cajero.h"

Cajero::Cajero()
{
}

Cajero::Cajero(int ci, string nombre, int celular, string cargo) :
	Persona(ci, nombre, celular, cargo)  
{
	this->cargo = "cajero";
}

Cajero::~Cajero()
{
}
	
