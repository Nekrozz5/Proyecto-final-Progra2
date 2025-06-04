#include "SingletonStock.h"
SingletonStock::SingletonStock() :SingletonStock(3)
{
}
SingletonStock::SingletonStock(int cantidadMaxima) :productos(cantidadMaxima)
{

}

SingletonStock::~SingletonStock()
{
	 
}

SingletonStock& SingletonStock::getInstance()
{
	static SingletonStock instancia;
	return instancia;
}

void SingletonStock::registrarProducto(Producto* producto)
{
	if (buscarProductoPorNombre(producto->getNombre()) != nullptr) {
		throw exception("Ya existe un usuario con el numero registrado");
	}
	productos.registrar(producto);
}
Producto* SingletonStock::buscarProductoPorNombre(string nombre)
{
	for (int i = 0; i < productos.getCantidadActual(); i++) {
		if (productos[i]->getNombre() == nombre) {
			return productos[i];
		}
	}
	return nullptr;
}
