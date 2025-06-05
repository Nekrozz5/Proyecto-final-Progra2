#pragma once
#include "Cajero.h"
#include "Supervisor.h"
#include <thread>


class Supermercado {
private:
    Cajero cajero;
    Supervisor supervisor;
    std::thread hiloCajero;
    std::thread hiloSupervisor;

public:
    Supermercado();
    ~Supermercado();
};
