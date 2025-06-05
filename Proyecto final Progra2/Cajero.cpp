#include "Cajero.h"
#include <fstream>
#include <mutex>


// declarado extern si está fuera del Singleton


Cajero::Cajero()
{
    this->ci = 0;
    this->nombre = "Sin nombre";
    this->celular = 0;
	this->cargo = "cajero";
}

Cajero::Cajero(int ci, string nombre, int celular, string cargo) 
	
{
	
	
		this->ci = ci;
		this->nombre = nombre;
		this->celular = celular;
	
	this->cargo = "cajero";
}

Cajero::~Cajero()
{
}

void Cajero::ejecutar() {
   // Producto* p = SingletonStock::getInstance().buscarProductoPorNombre(nombre);

    cout << "Cajero procesando ventas..." << endl;
    ifstream archivo("ventas.txt");

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo ventas.txt\n";
        return;
    }

    string nombre;
    int cantidad;
    float precio;

    while (archivo >> nombre >> cantidad >> precio) {
        //lock_guard<mutex> lock(globalMutex); // Protege acceso al stock

        Producto* p = SingletonStock::getInstance().buscarProductoPorNombre(nombre);
        if (p != nullptr) {
            p->disminuirCantidad(cantidad); // Supone que hay suficiente stock
        }
        else {
            cerr << "Producto no encontrado en stock: " << nombre << endl;
        }
    }

    archivo.close();
}
	
