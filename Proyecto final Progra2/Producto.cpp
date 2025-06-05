#include "Producto.h"

Producto::Producto()
{
    nombre = "";
    cantidad = 0;
    precioUnitario = 0.0;
    costoUnitario = 0.0;
    unidadesVendidas = 0;
    montoRecaudado = 0.0;
    gananciaTotal = 0.0;
}

Producto::Producto(string nombre, int cantidad, double precioUnitario, double costoUnitario)
{
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->precioUnitario = precioUnitario;
    this->costoUnitario = costoUnitario;
    this->unidadesVendidas = 0;
    this->montoRecaudado = 0.0;
    this->gananciaTotal = 0.0;
}

Producto::~Producto()
{
}

int Producto::getCantidad()
{
    return cantidad;
}

string Producto::getNombre()
{
    return nombre;
}

double Producto::getPrecioUnitario() {
    return precioUnitario;
}

double Producto::getCostoUnitario() {
    return costoUnitario;
}

int Producto::getUnidadesVendidas() {
    return unidadesVendidas;
}

double Producto::getMontoRecaudado() {
    return montoRecaudado;
}

double Producto::getGananciaTotal() {
    return gananciaTotal;
}


string Producto::toJson()
{
    stringstream json;
    json << "{";
    json << "\"nombre\":\"" << nombre << "\",";
    json << "\"cantidad\":" << cantidad << ",";
    json << "\"precioUnitario\":" << precioUnitario << ",";
    json << "\"costoUnitario\":" << costoUnitario << ",";
    json << "\"unidadesVendidas\":" << unidadesVendidas << ",";
    json << "\"montoRecaudado\":" << montoRecaudado << ",";
    json << "\"gananciaTotal\":" << gananciaTotal;
    json << "}";
    return json.str();
}

void Producto::incrementarCantidad(int cantidad)
{
    this->cantidad += cantidad;
}

void Producto::disminuirCantidad(int cantidad)
{
    this->cantidad -= cantidad;
}

void Producto::registrarVenta(int cantidadVendida) {
    this->unidadesVendidas += cantidadVendida;
    this->montoRecaudado += cantidadVendida * precioUnitario;
    this->gananciaTotal += cantidadVendida * (precioUnitario - costoUnitario);
}

void Producto::registrarAdquisicion(int cantidadAdquirida) {
    this->cantidad += cantidadAdquirida;
}