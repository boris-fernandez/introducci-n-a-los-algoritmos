#include <iostream>
using namespace std;

// Función que muestra el menú de opciones
void menu() {
    cout << "Ingrese un numero valido" << endl;
    cout << "Pizza Grande (1)" << endl;
    cout << "Pizza Familiar (2)" << endl;
    cout << "Pizza Fiesta (3)" << endl;
}

int main()
{
    int tamanoPizza;
    double precioUnitario, precioFinal = 0;

    menu(); // Mostramos el menú
    cin >> tamanoPizza; // Leemos el tipo de pizza

    // Pedimos el precio unitario
    cout << "Ingrese el precio unitario de la pizza" << endl;
    cin >> precioUnitario;

    // Aplicamos descuento según el tipo de pizza
    if (tamanoPizza == 1) {
        precioFinal = precioUnitario - (precioUnitario * 0.10); // 10% descuento
        cout << "El tamano de la pizza es Grande\n";
    }
    else if (tamanoPizza == 2) {
        precioFinal = precioUnitario - (precioUnitario * 0.15); // 15% descuento
        cout << "El tamano de la pizza es Familiar\n";
    }
    else if (tamanoPizza == 3) {
        precioFinal = precioUnitario - (precioUnitario * 0.20); // 20% descuento
        cout << "El tamano de la pizza es Fiesta\n";
    }
    else {
        cout << "Numero no valido";
        return 0; // Finaliza si la opción es incorrecta
    }

    // Mostramos el total a pagar
    cout << "Total a pagar: " << precioFinal;
}