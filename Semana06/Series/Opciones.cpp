#include "pch.h"
#include "Opciones.h"

void ejercicio1() {
	Console::WriteLine();
	Console::WriteLine("============ EJERCICIO 1============");
	Console::WriteLine("Serie: termino impar = (-1)^i* (a+i)^b / (b+x!)");
	Console::WriteLine("       termino par = (-1)^i* (b-i)^a / (b+x!)");
	Console::WriteLine("x itera de 1 a 7 por termino");

	int n = leerEnteroRango("Cantidad de terminos (12 a 14): ", 12, 14);
	int a = leerEnteroRango("Valor de a [2, 4]: ", 2, 4);
	int b = leerEnteroRango("Valor de b [2, 4] ", 2, 4);

	Console::WriteLine(" ");
	double suma = ejer1ImprimirYSumar(n, a, b);
	Console::WriteLine(" ");
	Console::WriteLine("suma es: {0:F3}", suma);
}

void ejercicio3() {
	int m, n;
	Console::WriteLine();
	Console::WriteLine("============ EJERCICIO 3============");
	Console::WriteLine("Ingresa el valor para m");
	m = leerEnteroRango("Valor de m [2, 10]: ", 2, 10);

	Console::WriteLine();
	n = leerEnteroRango("Valor de m [2, 50]: ", 2, 50);

	Console::WriteLine("Resultado de la operacion: {0}", ejer3Operacion(m, n));
}