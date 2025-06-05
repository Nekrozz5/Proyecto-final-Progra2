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
	double precioUnitario; 
	double costoUnitario;  
	int unidadesVendidas;
	double montoRecaudado;
	double gananciaTotal;
public:
	Producto();
	Producto(string nombre, int cantidad, double precioUnitario, double costoUnitario);
	~Producto();
	int getCantidad();
	string getNombre();
	string toJson();
	double getPrecioUnitario();
	double getCostoUnitario();
	int getUnidadesVendidas();
	double getMontoRecaudado();
	double getGananciaTotal();
	void incrementarCantidad(int cantidad);
	void disminuirCantidad(int cantidad);
	void registrarVenta(int cantidadVendida);
	void registrarAdquisicion(int cantidadAdquirida);

};

