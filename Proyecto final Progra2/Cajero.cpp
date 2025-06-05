#include "Cajero.h"
#include <fstream>
#include <mutex>


<<<<<<< HEAD

=======
// declarado extern si está fuera del Singleton
>>>>>>> parent of ae0c67a (aaaaaaa)


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
<<<<<<< HEAD
		this->cargo = "cajero";
=======
	
	this->cargo = "cajero";
>>>>>>> parent of ae0c67a (aaaaaaa)
}

Cajero::~Cajero()
{
}

void Cajero::ejecutar() {
<<<<<<< HEAD
   
=======
   // Producto* p = SingletonStock::getInstance().buscarProductoPorNombre(nombre);
>>>>>>> parent of ae0c67a (aaaaaaa)

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
<<<<<<< HEAD
        
=======
        //lock_guard<mutex> lock(globalMutex); // Protege acceso al stock
>>>>>>> parent of ae0c67a (aaaaaaa)

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
	
