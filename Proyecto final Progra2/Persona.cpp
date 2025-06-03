#include "Persona.h"

Persona::Persona()
{
	ci = 0;
	nombre = "";
	celular = 0;
	cargo = "";
}

Persona::~Persona()
{
}

Persona::Persona(int ci, string nombre, int celular, string cargo)
{
	this->ci = ci;
	this->nombre = nombre;
	this->celular = celular;
	this->cargo = cargo;
}

void Persona::mostrar()
{
	cout << "CI: " << ci << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Celular: " << celular << endl;
	cout << "Cargo: " << cargo << endl;
	cout << endl;
}

string Persona::getCargo()
{
	return cargo;
}
