#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace System;

void limpiarPantalla();
int generarLanzamiento(Random^);
int jugarTurnoJugador(int, Random^);
void verificarGanador(int);
void dibujarDado(int);
void animarCarga();