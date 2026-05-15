#include "pch.h"
#include "Opciones.h"

void instrucciones() {
    limpiarPantalla();
    Console::BackgroundColor = ConsoleColor::DarkBlue;
    Console::ForegroundColor = ConsoleColor::White;
    Console::WriteLine(" === REGLAS DE LA CARRERA A 20 === ");
    Console::ResetColor();

    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::WriteLine("1. El objetivo es acumular puntos sin pasarte de 20.");
    Console::WriteLine("2. En cada turno, decides si quieres lanzar el dado (s/n).");
    Console::WriteLine("3. Si llegas exactamente a 20: ¡GANASTE!");
    Console::WriteLine("4. Si te pasas de 20: PERDISTE.");
    Console::WriteLine("5. Si decides plantarte (n):");
    Console::WriteLine("   - Si tienes entre 15 y 19 puntos: ¡GANASTE!");
    Console::WriteLine("   - Si tienes menos de 15 puntos: PERDISTE por bajo puntaje.");
    Console::WriteLine("----------------------------------------------------------");
    Console::ResetColor();
    Console::ForegroundColor = ConsoleColor::DarkGray;
    Console::WriteLine("Presiona cualquier tecla para volver al menu...");
    Console::ResetColor();
    Console::ReadKey();
};

void jugar() {
    int vecesJugar;
    bool entradaValida = false;
    int vecesGandas = 0;
    Random^ random = gcnew Random();

    while (!entradaValida) {
        try {
            Console::WriteLine();
            Console::Write("Cuantas veces quieres jugar?: ");
            vecesJugar = Int32::Parse(Console::ReadLine());
            if (vecesJugar > 0) entradaValida = true;
            else Console::WriteLine("Debes ingresar un numero mayor a 0.");
        }
        catch (...) { 
            Console::WriteLine("Solo se permiten numeros enteros."); 
        }
    }

    for (size_t i = 0; i < vecesJugar; i++) {
        int puntos = 0;
        bool finPartida = false;
        char respuesta;

        limpiarPantalla();
        Console::WriteLine("JUEGO NUMERO {0} DE {1}", i + 1, vecesJugar);

        while (!finPartida) {
            Console::WriteLine();
            Console::Write("¿Lanzar dado? (s/n): ");
            respuesta = Console::ReadLine()[0];

            if (respuesta == 's' || respuesta == 'S') {
                puntos = jugarTurnoJugador(puntos, random);

                if (puntos >= 20) {
                    finPartida = true;
                    verificarGanador(puntos);
                    if (puntos == 20) vecesGandas++;
                }
            }
            else if (respuesta == 'n' || respuesta == 'N') {
                finPartida = true;
                verificarGanador(puntos);
                if (puntos >= 15 && puntos < 20) vecesGandas++;
            }
        }

        Console::WriteLine("Fin de la partida {0}. Presiona una tecla...", i + 1);
        Console::ReadKey();
    }
    mostrarResumenFinal(vecesJugar, vecesGandas);
}

void mostrarResumenFinal(int jugadas, int ganadas) {
    limpiarPantalla();
    double porcentaje = 0;
    if (jugadas > 0) {
        porcentaje = ((double)ganadas / jugadas) * 100;
    }

    Console::BackgroundColor = ConsoleColor::Cyan;
    Console::ForegroundColor = ConsoleColor::Black;
    Console::WriteLine("========================================");
    Console::WriteLine("          RESUMEN DE LA SESION          ");
    Console::WriteLine("========================================");
    Console::ResetColor();

    Console::WriteLine("Partidas Totales: {0}", jugadas);

    Console::ForegroundColor = ConsoleColor::Green;
    Console::WriteLine("Partidas Ganadas: {0}", ganadas);

    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::WriteLine("Porcentaje de Victoria: {0}%", porcentaje.ToString("F2"));
    Console::ResetColor();

    Console::WriteLine("========================================");
    Console::ForegroundColor = ConsoleColor::DarkGray;
    Console::WriteLine("Presiona cualquier tecla para volver al menu...");
    Console::ResetColor();
    Console::ReadKey();
}