#include <iostream>
using namespace std;

// Función para convertir un número a cualquier base
string convertirBase(int numero, int base) {
    string resultado = "";

    while (numero > 0) {
        int residuo = numero % base;
        resultado = char(residuo + '0') + resultado;
        numero /= base;
    }

    return resultado;
}

int main() {
    int latitud, longitud, altitud;
    char metal;
    int hora, minuto, segundo;

    // Entrada de datos
    cout << "Latitud: " << endl; 
    cin >> latitud;
    cout << "Longitud: " << endl;
    cin >> longitud;
    cout << "Altitud: " << endl;
    cin >> altitud;
    cout << "Metal precioso (O/A/D): " << endl;
    cin >> metal;
    cout << "Hora: " << endl;
    cin >> hora;
    cout << "Minuto: " << endl;
    cin >> minuto;
    cout << "Segundo: " << endl;
    cin >> segundo;

    // Conversiones
    string latitudBase2 = convertirBase(latitud, 2);
    string longitudBase4 = convertirBase(longitud, 4);
    string altitudBase6 = convertirBase(altitud, 6);

    int ascii = int(metal);
    string metalBin = convertirBase(ascii, 2);

    string horaBase2 = convertirBase(hora, 2);
    string minutoBase4 = convertirBase(minuto, 4);
    string segundoBase4 = convertirBase(segundo, 4);

    // Salida
    cout << "\nDatos encriptados:\n";
    cout << latitudBase2 << " "
        << longitudBase4 << " "
        << altitudBase6 << " "
        << metalBin << " "
        << horaBase2 << " "
        << minutoBase4 << " "
        << segundoBase4 << endl;

    return 0;
}