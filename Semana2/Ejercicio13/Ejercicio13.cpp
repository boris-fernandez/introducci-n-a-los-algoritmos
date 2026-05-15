#include <iostream>
#include <string>
using namespace std;

int main() {
    string codigo;

    cout << "Ingrese codigo del empleado: ";
    cin >> codigo;

    int HH = stoi(codigo.substr(6, 2));
    int MM = stoi(codigo.substr(8, 2));
    int SS = stoi(codigo.substr(10, 2));

    char nombre = (char)stoi(codigo.substr(0, 2));
    char paterno = (char)stoi(codigo.substr(2, 2));
    char materno = (char)stoi(codigo.substr(4, 2));

    cout << "Hora de entrada: " << HH << endl;
    cout << "Minuto de entrada: " << MM << endl;
    cout << "Segundos de entrada: " << SS << endl;

    cout << "Su nombre empieza con la letra: " << nombre << endl;
    cout << "Su apellido paterno inicia con la letra: " << paterno << endl;
    cout << "Su apellido materno inicia con la letra: " << materno << endl;

    if (HH > 9 || (HH == 9 && (MM > 0 || SS > 0))) {
        cout << "¿Llego tarde? V" << endl;
    }
    else {
        cout << "¿Llego tarde? F" << endl;
    }

    return 0;
}