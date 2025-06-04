#include "Producto.h"

Producto::Producto()
{
}

Producto::Producto(string nombre, int cantidad, int precio)
{
    this->nombre = nombre;
    this->cantidad = cantidad;
	this->precio = precio;
}

Producto::~Producto()
{
}

int Producto::getCantidad()
{
    return cantidad;
}

string Producto::toJson()
{
	stringstream json;
	json << "{";
	json << "\"nombre\":" << nombre << ",";
	json << "\"cantidad\":\"" << cantidad << "\",";
	json << "\"precio\":"<<precio;
	json << "}";
	return json.str();
}
