#include "pch.h"
#include "Funciones.h"

int leerDatos(int min, int max){
	int m;
	bool esvalido = false;

    while (!esvalido) {
        try {
            Console::Write("El valor debe ser entre {0} y {1}: ", min, max);
            m = Int32::Parse(Console::ReadLine());

            if (m >= min && m <= max) esvalido = true;
            else Console::WriteLine("Error: El numero {0} esta fuera del rango ({1} - {2}).", m, min, max);
        }
        catch (...) {
            Console::WriteLine("Error: Debes ingresar un numero entero valido.");
        }
    }
    return m;
}


double calcular(int m, int n) {
    double resultado = 0.0;
    for (int i = 1; i <= m; i++){
        double numerador = Math::Pow(2, i) * (n + i);
        double denominador = Math::Pow(2, i - 1);
        
        resultado += numerador / denominador;
    }
    return resultado;
}
