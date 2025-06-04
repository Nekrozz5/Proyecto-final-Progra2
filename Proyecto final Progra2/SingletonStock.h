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
	SingletonStock(int cantmaxima);
	~SingletonStock();
	static SingletonStock& getInstance();
	void registrarProducto(Producto* producto);
	string toJson();
	SingletonStock* buscarProductoPorNombre(string nombre);

	
};

