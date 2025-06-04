#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Producto
{
protected:
	string nombre;
	int cantidad;
	int precio;
public:
	Producto();
	Producto(string nombre, int cantidad, int precio);
	~Producto();
	int getCantidad();
	string toJson();


};

