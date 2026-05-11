#include "pch.h"
#include "Opciones.h"
using namespace System;

void mostrarMenu() {
    Console::WriteLine("\tMEMU DE OPCINES");
    Console::WriteLine("1. Ejercicio 1");
    Console::WriteLine("3. Ejercicio 3");
    Console::WriteLine("0. Salir");
}

int main(cli::array<System::String ^> ^args){
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEnteroRango("Ingrese su opcion: ", 0, 6);
        switch (opcion) {
        case 1: ejercicio1(); break;
        case 3: ejercicio3(); break;
        case 0: Console::WriteLine("Saliendo......"); break;
        }
        if (opcion != 0){
            Console::WriteLine("Presione cualquier tecla para continuar.........");
            Console::ReadKey();
            Console::Clear();
        }
    } while (opcion != 0);


    return 0;
}
