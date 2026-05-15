#include <iostream>
using namespace std;

int main()
{
	int cantidad;
	int precioPorNeumatico;
	double total;
	cout << "Ingrese el numero de neumaticos que quieres comprar\n";
	cin >> cantidad;

	if (cantidad < 3) {
		precioPorNeumatico = 145;
		total = cantidad * precioPorNeumatico;
		cout << "El precio por neumatico es de: " << precioPorNeumatico << " y el total a pagar es de: " << total;
	}
	else if (cantidad >= 3 && cantidad <= 5) {
		precioPorNeumatico = 135;
		total = cantidad * precioPorNeumatico;
		cout << "El precio por neumatico es de: " << precioPorNeumatico << " y el total a pagar es de: " << total;
	}
	else {
		precioPorNeumatico = 120;
		total = cantidad * precioPorNeumatico;
		cout << "El precio por neumatico es de: " << precioPorNeumatico << " y el total a pagar es de: " << total;
	}
}