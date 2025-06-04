#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread> 
#include "SingletonStock.h"
#include "Cajero.h"
#include "Supervisor.h"
#include <fstream> 

using namespace std;

class Supermercado
{
public:
    Supermercado();
    ~Supermercado();

    void iniciarSimulacion(string archivoStockInicial, string archivoVentas, string archivoAdquisiciones);

private:
    Cajero* cajeroPrincipal;
    Supervisor* supervisorPrincipal;
    void generarReportesFinales();
};