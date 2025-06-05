#include "Cajero.h"
#include <fstream>
#include <mutex>


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
    cout << "Cajero procesando ventas..." << endl;
    ifstream archivo("ventas.txt");

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo ventas.txt\n";
        return;
    }

    string nombreProducto;
    int cantidad;
    float precio;

    while (archivo >> nombreProducto >> cantidad >> precio) {

        Producto* p = SingletonStock::getInstancia().buscarProductoPorNombre(nombre);
        if (p != nullptr) {
            if (p->getCantidad() >= cantidad) {
                p->disminuirCantidad(cantidad);
                p->agregarVenta(cantidad, precio); 
                cout << "Cajero vendio " << cantidad << " unidades de " << nombreProducto << ". Stock restante: " << p->getCantidad() << endl;
            }
            else {
                cout << " Stock insuficiente para " << nombreProducto << ". Cantidad disponible: " << p->getCantidad() << endl;
            }
        }
        else {
            cout << "Producto " << nombreProducto << " no encontrado en el stock." << endl;
        }
    }

    archivo.close();
}
	
