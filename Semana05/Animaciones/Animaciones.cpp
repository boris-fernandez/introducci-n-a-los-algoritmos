#include "pch.h"
#include "Opciones.h"

int main(cli::array<System::String ^> ^args){
    int opcion;
    
    do {
        mostrarMenu();
        opcion = Int32::Parse(Console::ReadLine());
        switch (opcion) {
        case 1: ejercicio1(); break;
        case 2: ejercicio2(); break;
        case 3: ejercicio3(); break;
        case 4: ejercicio4(); break;
        case 5: ejercicio5(); break;
        case 6: ejercicio6(); break;
        case 7: ejercicio7(); break;
        case 8: ejercicio8(); break;
        case 9: ejercicio9(); break;
        case 10: ejercicio10(); break;
        case 11: ejercicio11(); break;
        case 12: ejercicio12(); break;
        case 0: Console::WriteLine("Saliendo"); break;
        default: Console::WriteLine("Opcion invalida"); break;
        };
        if (opcion !=0){
            pausa();
            limpiarPantalla();
        }
    } while (opcion != 0);
    return 0;
}
