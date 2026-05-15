#include "pch.h"
#include "Funciones.h"

void limpiarPantalla() {
	Console::Clear();
};	

int generarLanzamiento(Random^ random) {
	int resultado = random->Next(1, 7);
	return resultado;
};

void dibujarDado(int valor) {
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::WriteLine("  -----");
    switch (valor) {
    case 1:
        Console::WriteLine(" |     |");
        Console::WriteLine(" |  o  |");
        Console::WriteLine(" |     |");
        break;
    case 2:
        Console::WriteLine(" | o   |");
        Console::WriteLine(" |     |");
        Console::WriteLine(" |   o |");
        break;
    case 3:
        Console::WriteLine(" | o   |");
        Console::WriteLine(" |  o  |");
        Console::WriteLine(" |   o |");
        break;
    case 4:
        Console::WriteLine(" | o o |");
        Console::WriteLine(" |     |");
        Console::WriteLine(" | o o |");
        break;
    case 5:
        Console::WriteLine(" | o o |");
        Console::WriteLine(" |  o  |");
        Console::WriteLine(" | o o |");
        break;
    case 6:
        Console::WriteLine(" | o o |");
        Console::WriteLine(" | o o |");
        Console::WriteLine(" | o o |");
        break;
    }

    Console::WriteLine("  -----");
    Console::ResetColor();
};

int jugarTurnoJugador(int puntajeActual, Random^ random) {
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::ForegroundColor = ConsoleColor::White;
    Console::Write("--- FASE DE LANZAMIENTO ---");
    Console::ResetColor();
    Console::WriteLine();
    Console::Write("Lanzando");
    animarCarga();

    int lanzamiento = generarLanzamiento(random);
    dibujarDado(lanzamiento);

    int nuevoTotal = puntajeActual + lanzamiento;
    Console::WriteLine("Sacaste: {0}", lanzamiento);
    Console::WriteLine("Puntaje total: {0}", nuevoTotal);
    Console::WriteLine("-------------------------");

    return nuevoTotal;
};


void verificarGanador(int puntos) {
    if (puntos == 20) {
        Console::ForegroundColor = ConsoleColor::Green;
        Console::WriteLine("==========================================");
        Console::WriteLine("        ¡Llegaste a 20! GANASTE           ");
        Console::WriteLine("==========================================");
    }
    else if (puntos > 20) {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::WriteLine("==========================================");
        Console::WriteLine("      ¡TE PASASTE. PERDISTE! ({0} pts)    ", puntos);
        Console::WriteLine("==========================================");
    }
    else if (puntos >= 15 && puntos < 20) {
        Console::ForegroundColor = ConsoleColor::Green;
        Console::WriteLine("==========================================");
        Console::WriteLine("   GANASTE. Te plantaste con {0} puntos.  ", puntos);
        Console::WriteLine("==========================================");
    }
    else {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::WriteLine("==========================================");
        Console::WriteLine("   PERDISTE por bajo puntaje ({0} pts)    ", puntos);
        Console::WriteLine("==========================================");
    }

    Console::ResetColor();
    Console::WriteLine();
}

void animarCarga() {
    for (int i = 0; i < 7; i++) {
        Sleep(300);
        Console::Write(".");
    }
    Console::WriteLine();
};