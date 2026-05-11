#include <iostream>
using namespace std;

int main()
{
    auto operacion = [](int numero) -> int {
        const int valor_constante = 5;
        return (numero * numero) + valor_constante;
        };

    int resultado = operacion(3);

    cout << "El resultado de la operacion es: " << resultado << endl;

    return 0;
}