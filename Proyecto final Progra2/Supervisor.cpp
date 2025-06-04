#include "Supervisor.h"

Supervisor::Supervisor()
{
}

Supervisor::Supervisor(int ci, string nombre, int celular, string cargo) :Persona(ci, nombre, celular, cargo)
{
	this->cargo = "Supervisor";
}

Supervisor::~Supervisor()
{
}
