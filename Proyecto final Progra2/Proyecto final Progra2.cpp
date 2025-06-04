#include <iostream>
#include "SingletonStock.h"
using namespace std;

int main() {
    SingletonStock& stock = SingletonStock::getInstance();

    cout << "Contenido del stock cargado desde el archivo:\n";
    cout << stock.toJson() << endl;

    return 0;
}
