#include "pch.h"
#include "Opciones.h"

using namespace System;

int main(cli::array<System::String ^> ^args){
    int opcion;
    do {
        limpiarPantalla();
        Console::WriteLine("==== JUEGO: CARRERA A 20 ====");
        Console::WriteLine("1. Jugar");
        Console::WriteLine("2. Ver Instrucciones");
        Console::WriteLine("3. Salir");
        Console::Write("Selecciona una opcion: ");

        try {
            opcion = Int32::Parse(Console::ReadLine());
        }
        catch (...) {
            opcion = 0;
        }

        switch (opcion) {
        case 1: jugar(); break;
        case 2: instrucciones(); break;
        case 3: Console::WriteLine("¡Gracias por jugar!"); break;
        default: Console::WriteLine("Opcion no valida."); Sleep(700); break;
        }

    } while (opcion != 3);

    return 0;
}
