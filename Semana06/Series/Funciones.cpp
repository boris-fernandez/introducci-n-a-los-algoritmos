#include "pch.h"
#include "Funciones.h"

//Ejercicio1
int leerEnteroRango(String^ mensaje, int minVal, int maxVal) {
	int valor = 0;
	bool valido = false;

	do {
		Console::Write(mensaje);
		String^ input = Console::ReadLine();
		try {
			valor = Int32::Parse(input);
			if (valor >= minVal && valor <= maxVal) valido = true;
			else Console::WriteLine("Error: El numero {0} esta fuera del rango ({1} - {2}).", valor, minVal, maxVal);
		}
		catch (...) {
			Console::WriteLine("Error: Ingrese un numero entero valido");
		}
	} while (!valido);

	return valor;
};

long long factorial(int n) {
	long long result = 1;
	for (int i = 2; i < n; i++){
		result *= i;
	}
	return result;
}

double ejer1ImprimirYSumar(int n, int a, int b) {
	double suma = 0.0;
	for (int i = 0; i <= n; i++){
		long long num = ejer1CalcularNumerador(i, a, b);
		long long den = ejer1CalcularDenominador(i, b);
		suma += (double)num / (double)den;
		Console::Write("{0}/{1}", num, den);
		if (i < n){
			Console::Write(" ;");
		}
	}
	return suma;

};

long long potenciaLL(long long base, int exp) {
	long long result = 1;
	for (int k = 0; k < exp; k++){
		result *= base;
	}
	return result;
};

int ejer1CalcularX(int i) {
	return ((i - 7) % 7) + 1;
};

long long ejer1CalcularNumerador(int i, int a, int b) {
	long long signo = (i % 2 == 0) ? 1LL : -1LL;

	if (i % 2 != 0) return signo * potenciaLL((long long)(a + i), b);
	else return signo * potenciaLL((long long)(b - i), a);
	
};

long long ejer1CalcularDenominador(int i, int b) {
	int x = ejer1CalcularX(i);
	return (long long)b + factorial(x);
};


//Ejercicio3
double ejer3Operacion(int m, int n) {
	double resultado = 0.0;
	for (int i = 1; i <= m; i++) {
		double numerador = Math::Pow(2, i) * (n + i);
		double denominador = Math::Pow(2, i - 1);

		resultado += numerador / denominador;
	}
	return resultado;
}
