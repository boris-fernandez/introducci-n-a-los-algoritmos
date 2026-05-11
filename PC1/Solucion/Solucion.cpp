#include <iostream>
using namespace std;

int main()
{
    double cantidad;
    int billetes100, billetes10, monedas1, monedas050, monedas020, monedas010;

    // Pedimos al usuario la cantidad de dinero
    cout << "Ingrese la cantidad para convertir ";
    cin >> cantidad;

    // Convertir a billetes de 100
    billetes100 = cantidad / 100;
    cantidad -= billetes100 * 100;

    // Convertir a billetes de 10
    billetes10 = cantidad / 10;
    cantidad -= billetes10 * 10;

    // Convertir a monedas de 1 sol
    monedas1 = cantidad / 1;
    cantidad -= monedas1 * 1;

    // Convertimos el restante a centavos para evitar errores con decimales
    int centavos = cantidad * 100 + 0.5;

    // Convertir a monedas de 0.50 sol
    monedas050 = centavos / 50;
    centavos %= 50;

    // Convertir a monedas de 0.50 sol
    monedas020 = centavos / 20;
    centavos %= 20;

    // Convertir a monedas de 0.10 sol
    monedas010 = centavos / 10;

    cout << billetes100 << " billetes de 100 soles" << endl;
    cout << billetes10 << " billetes de 10 soles" << endl;
    cout << monedas1 << " monedas de 1 sol" << endl;
    cout << monedas050 << " monedas de 0.50" << endl;
    cout << monedas020 << " monedas de 0.20" << endl;
    cout << monedas010 << " monedas de 0.10" << endl;

    return 0;
}