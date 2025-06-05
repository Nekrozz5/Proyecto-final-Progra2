#pragma once
#include <iostream>
#include"VectorGenerico.h"
#include "Producto.h"
#include <mutex>
#include <fstream>
#include <sstream>
using namespace std;
extern mutex globalMutex;

class SingletonStock
{
private:
	VectorGenerico<Producto> productos;
	SingletonStock();
public:
	
	SingletonStock(int cantidadMaxima);
	~SingletonStock();
	static SingletonStock& getInstancia();
	void registrarProducto(Producto* producto);
	string toJson();
	Producto* buscarProductoPorNombre(string nombre);
	void venderProducto(string nombre, int cantidadVendida);
	void adquirirProducto(string nombre, int cantidadAdquirida);
	string reporteProductosMasVendidos();
	string reporteProductosMayorGanancia();


	
};

