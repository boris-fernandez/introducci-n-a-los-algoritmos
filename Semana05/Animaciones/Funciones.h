#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;
using namespace System;

//PROTOTIPOS
void limpiarPantalla();
void pausa();
void mostrarMenu();

//MOVIMIENTOS
void movimientoRecto();
void movimientoAleatorio();
void movimientoCurvo();

void dibujarCuadrado(int, int);
void borrarCuadrado(int, int);

void dibujarTriangulo(int, int, int);
void borrarTriangulo(int, int, int);

void DibujarTriangulo(int);
void DibujarEstrella(int);
void DibujarTablero();