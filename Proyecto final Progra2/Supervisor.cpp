#include "Supervisor.h"
#include <fstream>
#include <mutex>
//extern mutex globalMutex;
Supervisor::Supervisor()
{
    this->ci = 0;
    this->nombre = "Sin nombre";
    this->celular = 0;
	this->cargo = "Supervisor";
}

Supervisor::Supervisor(int ci, string nombre, int celular, string cargo) 
{
	this->ci = ci;
	this->nombre = nombre;
	this->celular = celular;
	this->cargo = "Supervisor";
}

Supervisor::~Supervisor()
{
}

void Supervisor::ejecutar()
{
    

    cout << "Supervisor procesando ventas..." << endl;
    ifstream archivo("adquisiciones.txt");

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
            p->incrementarCantidad(cantidad);
            cout << "Adquisicion: " << nombreProducto << " Cantidad: " << cantidad << " - Stock actual: " << p->getCantidad() << endl;
        }
        else {
            Producto* nuevoProducto = new Producto(nombreProducto, cantidad);
            try {
                SingletonStock::getInstancia().registrarProducto(nuevoProducto);
                cout << "Nuevo producto adquirido y registrado: " << nombreProducto << " Cantidad: " << cantidad << endl;
            }
            catch (const exception& e) {
                cerr << "Error al registrar el nuevo producto '" << nombreProducto << "': " << e.what() << endl;
                delete nuevoProducto; 
            }
        }
    }

    archivo.close();
}





