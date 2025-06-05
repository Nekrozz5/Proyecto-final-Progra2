#include "Supermercado.h"
#pragma once
#include <mutex>

// Declaración del mutex global
extern std::mutex globalMutex;


Supermercado::Supermercado() {
    // Lanzar hilos
    hiloCajero = std::thread(&Cajero::ejecutar, &cajero);
    hiloSupervisor = std::thread(&Supervisor::ejecutar, &supervisor);
}

Supermercado::~Supermercado() {
    // Esperar a que terminen
    hiloCajero.join();
    hiloSupervisor.join();

    // Mostrar el stock actualizado
    std::cout << "Estado final del stock:\n";
    std::cout << SingletonStock::getInstance().toJson() << std::endl;
}
