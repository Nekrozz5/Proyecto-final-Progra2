#pragma once
#include"VectorGenerico.h"
#include "Producto.h"
#include <sstream>
#include <fstream>
using namespace std;

class SingletonStock
{
private:
	VectorGenerico<Producto> productos;
private:
	SingletonStock();
public:
	SingletonStock();
	SingletonStock(int cantidadMaxima);
	~SingletonStock();
	static SingletonStock& getInstance();
	void registrarProducto(Producto* producto);
	string toJson();
	Producto* buscarProductoPorNombre(string nombre);

	
};

