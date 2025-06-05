#include "SingletonStock.h"
SingletonStock::SingletonStock() :SingletonStock(10)
{
    ifstream archivo("stock.txt"); 

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo stock.txt\n";
        return;
    }

    string nombre;
    int cantidad;

    while (archivo >> nombre >> cantidad) {
        Producto* nuevoProducto = new Producto(nombre, cantidad, 0.0, 0.0);
        try {
            registrarProducto(nuevoProducto);
        }
        catch (const exception& e) {
            cerr << "Error al registrar el producto '" << nombre << "'." << endl;
            delete nuevoProducto;
        }
    }

    archivo.close();
}



SingletonStock::SingletonStock(int cantidadMaxima) :productos(cantidadMaxima)
{

}

SingletonStock::~SingletonStock()
{
	  
}

SingletonStock& SingletonStock::getInstancia()
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
string SingletonStock::toJson() {
    stringstream json;
    json << "[";
    for (size_t i = 0; i <productos.getCantidadActual() ; ++i) {
        json << productos[i]->toJson(); if (i<productos.getCantidadActual()-1)
        {
			json << ",";
        }
    }
    json << "]";
    return json.str();
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

void SingletonStock::venderProducto(string nombre, int cantidadVendida)
{
    lock_guard<mutex> lock(globalMutex); 
    Producto* p = buscarProductoPorNombre(nombre);
    if (p != nullptr) {
        if (p->getCantidad() >= cantidadVendida) {
            p->disminuirCantidad(cantidadVendida);
            p->registrarVenta(cantidadVendida);
            cout << "Venta registrada: " << cantidadVendida << " de " << nombre << endl;
        }
        else {
            cerr << "No hay suficiente stock de " << nombre << " para vender " << cantidadVendida << endl;
        }
    }
    else {
        cerr << "Producto " << nombre << " no encontrado en el stock." << endl;
    }
}
void SingletonStock::adquirirProducto(string nombre, int cantidadAdquirida) {
    lock_guard<mutex> lock(globalMutex); 
    Producto* p = buscarProductoPorNombre(nombre);
    if (p != nullptr) {
        p->incrementarCantidad(cantidadAdquirida);
        p->registrarAdquisicion(cantidadAdquirida); 
        cout << "Adquisicion registrada: " << cantidadAdquirida << " de " << nombre << endl;
    }
    else {
       
        cerr << "Producto " << nombre << " no encontrado para adquirir. Agreguelo primero." << endl;
    }
}
bool compararPorUnidadesVendidas(Producto* a, Producto* b) {
    return a->getUnidadesVendidas() > b->getUnidadesVendidas();
}

bool compararPorGananciaTotal(Producto* a, Producto* b) {
    return a->getGananciaTotal() > b->getGananciaTotal();
}

string SingletonStock::reporteProductosMasVendidos()
{
    lock_guard<mutex> lock(globalMutex); 
    VectorGenerico<Producto> productosCopia = productos; 
    productosCopia.ordenar(compararPorUnidadesVendidas);

    stringstream report;
    report << "Reporte de los 3 productos mas vendidos:\n";
    for (int i = 0; i < min(3, productosCopia.getCantidadActual()); ++i) {
        Producto* p = productosCopia[i];
        report << "  " << p->getNombre()
            << " - Unidades vendidas: " << p->getUnidadesVendidas()
            << " - Monto recaudado: " << p->getMontoRecaudado() << "\n";
    }
    return report.str();
}

string SingletonStock::reporteProductosMayorGanancia() {
    lock_guard<mutex> lock(globalMutex); 
    VectorGenerico<Producto> productosCopia = productos; 
    productosCopia.ordenar(compararPorGananciaTotal);

    stringstream report;
    report << "Reporte de los 3 productos que representan una mayor ganancia:\n";
    for (int i = 0; i < min(3, productosCopia.getCantidadActual()); ++i) {
        Producto* p = productosCopia[i];
        report << "  " << p->getNombre()
            << " - Unidades vendidas: " << p->getUnidadesVendidas() 
            << " - Ganancia total: " << p->getGananciaTotal() << "\n";
    }
    return report.str();
}