#include "pch.h"
#include <iostream>
using namespace std;

using namespace System;

int main(cli::array<System::String ^> ^args){
    cout << "Hellow world" << " Student " << "\n";


    Console::Write("Hellow world" + " Estrudiante " + "\n");

    Console::SetCursorPosition(10,5);
    Console::Write("Hellow world {0} numero de estudiantes {1} {2}\n", "Estudiante", 101, "Seccion A");

    for (int i = 0; i < 5; i++){
        Console::WriteLine("No me voy a portar mal {0}",i);
    }

    Console::Write("Ingrrese el numero para multiplicar: ");
    int numero;
    numero = Int32::Parse(Console::ReadLine());

    Console::BackgroundColor = ConsoleColor::Blue;
    Console::ForegroundColor = ConsoleColor::Yellow;

    for (int i = 12; i >= 1; i--){
        Console::WriteLine("{0} x {1} = {2}", numero, i, numero * i);
    }
    Console::ResetColor();

    Console::Write("Ingrrese el numero para multiplicar: ");
    numero = Int32::Parse(Console::ReadLine());
    int i = 12;
    Console::BackgroundColor = ConsoleColor::Yellow;
    Console::ForegroundColor = ConsoleColor::Blue;
    while (i >= 1) {
        Console::SetCursorPosition(30, i + 11);
        Console::WriteLine("{0} x {1} = {2}", numero, i, numero * i);
        i--;
    }
    Console::ResetColor();

    Console::SetCursorPosition(0,25);
    Console::Write("Ingrrese el numero para multiplicar: ");
    numero = Int32::Parse(Console::ReadLine());
    i = 12;
    Console::BackgroundColor = ConsoleColor::Red;
    Console::ForegroundColor = ConsoleColor::White;
    do {
        Console::SetCursorPosition(60, i + 11);
        Console::WriteLine("{0} x {1} = {2}", numero, i, numero * i);
        i--;
    } while (i >= 1);
    Console::ResetColor();
    Console::SetCursorPosition(0, 27);
    Console::WriteLine("Presione una tecla para continuar...");
    Console::ReadKey();
    return 0;
}
