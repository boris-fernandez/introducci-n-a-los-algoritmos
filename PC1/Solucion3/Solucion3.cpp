#include <iostream>
using namespace std;

int main() {
    double litros, pago;

    // Pedimos los litros consumidos
    cout << "Ingrese la cantidad de litros consumidos: ";
    cin >> litros;

    pago = 20; // Cuota fija mensual

    if (litros <= 50) {
        // No se cobra consumo adicional
        pago = pago;
    }
    else if (litros <= 200) {
        // Se cobra desde el litro 51 hasta el consumo
        pago = pago + (litros - 50) * 2;
    }
    else {
        // Se cobra de 200 a 3.5 soles
        pago = pago + (150 * 2) + (litros - 200) * 3.5;
    }

    // Mostramos el resultado
    cout << "El total a pagar es: " << pago;

    return 0;
}