#include "Cajero.h"
#include <fstream>
#include <mutex>
Cajero::Cajero()
{
}

Cajero::Cajero(int ci, string nombre, int celular, string cargo) 
	
{
	
	
		this->ci = ci;
		this->nombre = nombre;
		this->celular = celular;
	
	this->cargo = "cajero";
}

Cajero::~Cajero()
{
}
	
