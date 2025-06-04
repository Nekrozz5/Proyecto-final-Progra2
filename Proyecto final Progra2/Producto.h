#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Producto
{
private:
	string nombre;
	int cantidad;
	double precio;

public:
	Producto();
	Producto(string nombre, int cantidad, double precio);
	~Producto();
	int getCantidad();
	double getPrecio();
	string toJson();


};

