#include <iostream>
using namespace std;

int mayor(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    else if (b >= a && b >= c) {
        return b;
    }
    else {
        return c;
    }
}


int main()
{
    int n1, n2, n3;

    cout << "Ingrese tres numeros enteros: ";
    cin >> n1 >> n2 >> n3;

    cout << "El mayor es: " << mayor(n1, n2, n3) << endl;

    return 0;
}