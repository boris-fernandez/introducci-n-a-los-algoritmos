#include <iostream>
using namespace std;

int main()
{
    int sueldoFijo = 2500;
    int bono = 500;
    int edad = 0;
    int sueldoFinal = 0;
    string nacionalidad;

    cout << "Ingrese la edad del jugador";
    cin >> edad;

    cout << "Ingrese nacionaliada (E: Extranjero y N: Nacional)";
    cin >> nacionalidad;

    if (nacionalidad == "E") sueldoFinal = bono;
    if (edad >= 15 && edad <= 20) {
        cout << sueldoFinal << endl;
        sueldoFinal = sueldoFijo + 1400 + sueldoFinal;
        
    }else if(edad >=21 && edad<= 25){
        sueldoFinal = sueldoFijo + 1500 + sueldoFinal;
    }
    else if(edad >= 26 && edad <= 30) {
        sueldoFijo = sueldoFinal + 1200 + sueldoFinal;
    }
    else{
        sueldoFinal = sueldoFijo;
    }
    cout << sueldoFinal;
    return 0;
}