#include"pch.h"
#include "Funciones.h"

void limpiarPantalla() {
	Console::Clear();
}

void pausa() {
	Console::SetCursorPosition(0, 25);
	Console::Write("Presione una tecla para continuar....");
	Console::ReadKey();
}

void mostrarMenu() {
	limpiarPantalla();

	Console::SetCursorPosition(10, 2);
	Console::WriteLine("===== MENU DE EJERCICICOS ======");

	for (int i = 1; i <= 12; i++){
		Console::SetCursorPosition(10, 3 + i);
		Console::WriteLine("{0} Ejercicio {0}", i);
	}
	Console::SetCursorPosition(10, 16);
	Console::WriteLine("0. Salir");
	Console::SetCursorPosition(10, 16);
	Console::Write("Seleccione opcion: ");
}

void movimientoRecto() {
	int max = Console::BufferWidth;
	for (int x = 0; x < max; x++){
		limpiarPantalla();
		Console::SetCursorPosition(x, 10);
		Console::Write("*");
		Sleep(50);
	}
};

void movimientoAleatorio() {
	limpiarPantalla();
	Random^ aleatorio = gcnew Random();

	int x = Console::BufferWidth / 2;
	int y = Console::BufferHeight / 2;

	Console::SetCursorPosition(0, 0);
	Console::WriteLine("Presiona ENTER para salir (o escribe algo)....");
	while (!Console::KeyAvailable) {

		Console::SetCursorPosition(x,y);
		Console::Write(" ");
		

		x += aleatorio->Next(-8, 9);
		y += aleatorio->Next(-8, 9);

		if (x >= Console::BufferWidth) x = Console::BufferWidth - 1;
		if (x < 0) x = 0;

		if (y >= Console::BufferHeight) y = Console::BufferHeight - 1;
		if (y < 1) y = 1;

		Console::SetCursorPosition(x, y);
		Console::Write("*");

		Sleep(100);
	}
	Console::ReadKey(true);

};

void movimientoCurvo() {
	for (int x = 0; x < 60; x++){
		limpiarPantalla();
		int y = (int)(10 + 5 * sin(x * 0.2));
		Console::SetCursorPosition(x, y);
		Console::Write("*");
		Sleep(50);
	}
};


void dibujarCuadrado(int x, int y) {
	limpiarPantalla();
	for (int i = 0; i < 4; i++) {
		Console::SetCursorPosition(x + i, y);
		Console::Write("*");
		Console::SetCursorPosition(x + i, y + 3);
		Console::Write("*");
	};
	for (int i = 0; i < 4; i++) {
		Console::SetCursorPosition(x, y + i);
		Console::Write("*");
		Console::SetCursorPosition(x + 3, y + i);
		Console::Write("*");
	};
};

void borrarCuadrado(int x, int y) {
	for (int i = 0; i < 4; i++) {
		Console::SetCursorPosition(x + i, y);
		Console::Write(" ");
		Console::SetCursorPosition(x + i, y + 3);
		Console::Write(" ");
		Console::SetCursorPosition(x, y + i);
		Console::Write(" ");
		Console::SetCursorPosition(x + 3, y + i);
		Console::Write(" ");
	};
};

void dibujarTriangulo(int x, int y, int altura) {
	for (int i = 0; i < altura; i++){
		for (int j = 0; j < i; j++){
			Console::SetCursorPosition(x + j, y + i);
			Console::Write("*");
		}
	}
};
void borrarTriangulo(int x, int y, int altura) {
	for (int i = 0; i < altura; i++) {
		for (int j = 0; j < i; j++) {
			Console::SetCursorPosition(x + j, y + i);
			Console::Write(" ");
		}
	}
};

void DibujarTriangulo(int altura) {
	Console::WriteLine("Triangulo:\n");

	for (int fila = 1; fila <= altura; fila++) {
		// Espacios para centrar
		for (int espacio = 1; espacio <= altura - fila; espacio++) {
			cout << " ";
		}

		// Asteriscos (crecen en cada fila)
		for (int estrella = 1; estrella <= (2 * fila - 1); estrella++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}
void DibujarEstrella(int tamaño) {
	Console::WriteLine("Estrella:\n");

	int centro = tamaño / 2;

	for (int i = 0; i < tamaño; i++) {
		for (int j = 0; j < tamaño; j++) {
			if (i == centro || j == centro || i == j || i + j == tamaño - 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}