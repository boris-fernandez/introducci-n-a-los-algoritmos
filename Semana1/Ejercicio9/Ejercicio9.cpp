#include <iostream>
using namespace std;

int main()
{
    char num;

    cout << "Ingrese un numero entero: ";
    cin >> num;

    if (num >= 48 && num <= 57) {
        cout << "Es un digito.";
    }
    else if (num >= 65 && num <= 90) {
        cout << "Es una letra mayuscula.";
    }
    else if (num >= 97 && num <= 122) {
        cout << "Es una letra minuscula.";
    }
    else {
        cout << "Es otro caracter.";
    }

}