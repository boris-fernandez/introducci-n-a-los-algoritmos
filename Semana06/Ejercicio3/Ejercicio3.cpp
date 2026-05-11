#include "pch.h"
#include "Funciones.h"

using namespace System;

int main(cli::array<System::String ^> ^args){
    int m, n;
    Console::WriteLine("Ingresa el valor para m");
    m = leerDatos(2, 10);

    Console::WriteLine();
    Console::WriteLine("Ingresa el valor para n");
    n = leerDatos(2, 50);

    Console::WriteLine("Resultado de la operacion: {0}",calcular(m, n));
    return 0;
}
