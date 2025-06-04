#pragma once
#include "Persona.h"
using namespace std;
class Cajero :public Persona
{
public:
	Cajero();
	Cajero(int ci, string nombre, int celular, string cargo);
	~Cajero();

};

