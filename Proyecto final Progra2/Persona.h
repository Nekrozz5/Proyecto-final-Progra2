#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persona
{
protected:
	int ci;
	string nombre;
	int celular;
	string cargo;
public:
	Persona();
	~Persona();
	Persona(int ci, string nombre, int celular, string cargo);
	virtual void mostrar();
	string getCargo();


};

