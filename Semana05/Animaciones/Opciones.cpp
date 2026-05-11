#include "pch.h"
#include "Opciones.h"

void ejercicio1() {
	limpiarPantalla();

	int x = Console::BufferWidth/2, y = Console::BufferHeight/2;
	char tecla = ' ';

	Console::KeyAvailable;

	while(true){
		Console::SetCursorPosition(x, y);
		Console::Write("0");
		if (Console::KeyAvailable){
			ConsoleKeyInfo key = Console::ReadKey(true);

			//Borrrar la posicion anterior
			Console::SetCursorPosition(x, y);
			Console::Write(" ");
		
			switch (key.Key) {
				case ConsoleKey::UpArrow:
					if (y <= 0) {
						y = Console::BufferHeight -1;
					}
					else {
						y--;
					}
					break;

				case ConsoleKey::DownArrow: 
					if (y >= Console::BufferHeight - 1) {
						y = 0;
					}
					else {
						 y++;
					}
					break;
			case ConsoleKey::LeftArrow: 
				if (x <= 0){
					x = Console::BufferWidth -1;
				}
				else {
					x--;
				}
				break;
			case ConsoleKey::RightArrow: 
				if (x >= Console::BufferWidth -1){
					x = 0;
				}
				else {
					x++;
				}
				;break;
			case ConsoleKey::Escape: return;
			}
		}
	}
}

void ejercicio2() {
	limpiarPantalla();

	Console::WriteLine("1. Movimiento Recto");
	Console::WriteLine("2. Movimiento Aleatorio");
	Console::WriteLine("3. Movimiento Curvo");
	Console::WriteLine("4. Todos los movimientos");
	Console::Write("Seleccione: ");
	int op = Int16::Parse(Console::ReadLine());

	switch (op) {
	case 1: movimientoRecto(); break;
	case 2: movimientoAleatorio(); break;
	case 3: movimientoCurvo(); break;
	case 4:
		movimientoRecto();
		movimientoAleatorio();
		movimientoCurvo();
		break;
	}
	pausa();
};

void ejercicio3(){
	int x = 10, y = 5;
	int dx = 1, dy = 1;

	int maxX = Console::BufferWidth - 1;
	int maxY = Console::BufferHeight - 1;

	limpiarPantalla();

	while (true) {
		Console::SetCursorPosition(x, y);
		Console::Write(" ");

		x += dx;
		y += dy;

		if (x <= 0 || x >= maxX) dx *= -1;
		if (y <= 0 || y >= maxY) dy *= -1;

		Console::SetCursorPosition(x, y);
		Console::Write("0");
		Sleep(30);

		if (Console::KeyAvailable) break;
	}
}

void ejercicio4() {
	int x = 0, y = 5;

	while (x < Console::BufferWidth - 5) {
		dibujarCuadrado(x, y);
		Sleep(80);
		borrarCuadrado(x, y);
		x++;
	}
};

void ejercicio5() {
	limpiarPantalla();
	int x = 40, y = 10;

	while (true) {
		Console::SetCursorPosition(x, y);
		Console::Write("|");
		Sleep(200);
		Console::SetCursorPosition(x, y);
		Console::Write("-");
		Sleep(200);
		Console::SetCursorPosition(x, y);
		Console::Write("\\");
		Sleep(200);
		Console::SetCursorPosition(x, y);
		Console::Write("/");
		Sleep(200);
		if (Console::KeyAvailable) break;
	}
};

void ejercicio6() {
	limpiarPantalla();
	int x = 10, y = 5;

	while (true) {
		for (int h = 0; h <= 10; h++) {
			dibujarTriangulo(x, y, h);
			Sleep(80);
			borrarTriangulo(x, y, h);
		}
		for (int h = 10; h >= 1; h--) {
			dibujarTriangulo(x, y, h);
			Sleep(80);
			borrarTriangulo(x, y, h);
		}
		if (Console::KeyAvailable) break;
	}
	pausa();
};

void ejercicio7() {
	limpiarPantalla();
	int centroX = Console::BufferWidth / 2;
	int centroy = Console::BufferHeight / 2;

	int radio = 10;

	double angulo1 = 0;
	double angulo2 = 0;

	int x1, y1, x2, y2;
	int prevX1 = -1, prevY1 = -1;
	int prevX2 = -1, prevY2 = -1;

	while (true) {
		if (prevX1 >= 0) {
			Console::SetCursorPosition(prevX1, prevY1);
			Console::Write(" ");
		}
		if (prevX2 >= 0) {
			Console::SetCursorPosition(prevX1, prevY2);
			Console::Write(" ");
		}

		x1 = centroX + (int)(radio * Math::Cos(angulo1));
		y1 = centroy + (int)(radio * Math::Sin(angulo1));
		x2 = centroX + (int)(radio * Math::Cos(angulo2));
		y2 = centroy + (int)(radio * Math::Sin(angulo2));

		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(x1, y1);
		Console::Write("0");

		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x2, y2);
		Console::Write("X");

		prevX1 = x1;
		prevY1 = y1;
		prevX2 = x2;
		prevY2 = y2;

		angulo1 += 0.1;
		angulo2 -= 0.1;

		Sleep(50);

		if (Console::KeyAvailable) break;
	}
};

void ejercicio8() {
	limpiarPantalla();
	Console::CursorVisible = false;

	int width = Console::BufferWidth;
	int height = Console::BufferHeight;

	int mitadX = width / 2;

	int lado = Math::Min(mitadX, height) - 4;
	if (lado % 2 != 0) lado--;

	int m = lado / 2;

	// izquierda
	int cx1 = mitadX / 2;
	int cy1 = height / 2;
	int left1 = cx1 - m, right1 = cx1 + m;
	int top1 = cy1 - m, bottom1 = cy1 + m;

	// derecha
	int cx2 = mitadX + (mitadX / 2);
	int cy2 = height / 2;
	int left2 = cx2 - m, right2 = cx2 + m;
	int top2 = cy2 - m, bottom2 = cy2 + m;

	int x1 = left1, y1 = top1;
	int x2 = left2, y2 = top2;

	int prevX1 = -1, prevY1 = -1;
	int prevX2 = -1, prevY2 = -1;

	int dir1 = 0, dir2 = 0;
	int vueltas1 = 0, vueltas2 = 0;

	Random^ rnd = gcnew Random();

	// rangos distintos
	int tiempo1 = rnd->Next(10, 19);
	int tiempo2 = rnd->Next(30, 61); 

	int t1 = Environment::TickCount;
	int t2 = Environment::TickCount;

	while (true)
	{
		int ahora = Environment::TickCount;

		// IZQUIERDA
		if (ahora - t1 >= tiempo1)
		{
			if (prevX1 >= 0)
			{
				Console::SetCursorPosition(prevX1, prevY1);
				Console::Write(" ");
			}

			switch (dir1)
			{
			case 0: x1++; if (x1 >= right1) dir1 = 1; break;
			case 1: y1++; if (y1 >= bottom1) dir1 = 2; break;
			case 2: x1--; if (x1 <= left1) dir1 = 3; break;
			case 3: y1--; if (y1 <= top1) { dir1 = 0; vueltas1++; } break;
			}

			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(x1, y1);
			Console::Write("O");

			prevX1 = x1; prevY1 = y1;

			tiempo1 = rnd->Next(10, 19);
			t1 = ahora;
		}

		// DERECHA
		if (ahora - t2 >= tiempo2)
		{
			if (prevX2 >= 0)
			{
				Console::SetCursorPosition(prevX2, prevY2);
				Console::Write(" ");
			}

			switch (dir2)
			{
			case 0: y2++; if (y2 >= bottom2) dir2 = 1; break;
			case 1: x2++; if (x2 >= right2) dir2 = 2; break;
			case 2: y2--; if (y2 <= top2) dir2 = 3; break;
			case 3: x2--; if (x2 <= left2) { dir2 = 0; vueltas2++; } break;
			}

			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(x2, y2);
			Console::Write("X");

			prevX2 = x2; prevY2 = y2;

			tiempo2 = rnd->Next(30, 61);
			t2 = ahora;
		}

		Console::ResetColor();

		Console::SetCursorPosition(2, 1);
		Console::Write("Izq (rapido): {0} vueltas   ", vueltas1);

		Console::SetCursorPosition(mitadX + 2, 1);
		Console::Write("Der (lento): {0} vueltas   ", vueltas2);

		Console::SetCursorPosition(2, 2);
		Console::Write("Vel Izq: {0} ms   ", tiempo1);

		Console::SetCursorPosition(mitadX + 2, 2);
		Console::Write("Vel Der: {0} ms   ", tiempo2);

		Sleep(1);

		if (Console::KeyAvailable)
			break;
	}

	Console::CursorVisible = true;
};

void ejercicio9() {
	limpiarPantalla();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Console::SetCursorPosition(40 + 2 * j, 12 + i);
			cout << "*";
		}
	}
}

void ejercicio10() {
	limpiarPantalla();
	Console::Write("Ingrese altura del triangulo: ");
	int altura = Int16::Parse(Console::ReadLine());
	DibujarTriangulo(altura);
}

void ejercicio11() {
	limpiarPantalla();
	Console::Write("Ingrese tamanio de la estrella: ");
	int tama�o = Int16::Parse(Console::ReadLine());
	DibujarEstrella(tama�o);
}
void ejercicio12() {
	Console::WriteLine("Pendiente...");
	pausa();
}