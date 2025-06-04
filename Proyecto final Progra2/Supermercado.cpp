#include "Supermercado.h"
/*
Supermercado::Supermercado()
{
    cajeroPrincipal = new Cajero(1, "Ana", 70000001, "Cajero");
    supervisorPrincipal = new Supervisor(2, "Pedro", 70000002, "Supervisor");
}

Supermercado::~Supermercado()
{
    delete cajeroPrincipal;
    delete supervisorPrincipal;
}

void Supermercado::iniciarSimulacion(string archivoStockInicial, string archivoVentas, string archivoAdquisiciones)
{
    cout << "Iniciando simulacion del Supermercado...";

    try {
        //miStock.cargarStockInicial(archivoStockInicial);
        cout << "Stock inicial cargado.\n";
    }
    catch (const runtime_error& e) {
        cerr << "Error al cargar stock inicial: " << e.what() << endl;
        return;
    }

    
    /*thread hiloCajero(&Cajero::simularVentas, cajeroPrincipal, ref(miStock), archivoVentas);
    thread hiloSupervisor(&Supervisor::simularAdquisiciones, supervisorPrincipal, ref(miStock), archivoAdquisiciones);
    hiloCajero.join();
    hiloSupervisor.join();

    cout << "\nSimulacion de ventas y adquisiciones terminada.\n";

    generarReportesFinales();

    cout << "Simulacion finalizada.\n";
}

void Supermercado::generarReportesFinales()
{
    cout << "--- Reportes Finales del Supermercado ---"<< endl;
    cout << miStock.generarReporteStock();
    cout << miStock.generarReporteProductosMasVendidos();
    cout << miStock.generarReporteProductosMayorGanancia();
}
*/