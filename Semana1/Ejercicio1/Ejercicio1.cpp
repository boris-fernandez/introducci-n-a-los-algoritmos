#include <iostream>
using namespace std;

int main()
{
	int celsius;
	float fahrenheit;
    cout << "Ingrese el valor en celsius para convertir a fahrenheit \n";
    cin >> celsius;
    fahrenheit = (celsius * 1.8) + 32;
	cout << "El valor en fahrenheit es: " << fahrenheit << "\n";

}
