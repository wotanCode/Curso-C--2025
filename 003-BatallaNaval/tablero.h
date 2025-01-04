#pragma once

const int TAM = 4;
const int NUM_NAVES = 3;

void inicializarTablero(int tablero[TAM][TAM]);
void mostrarTablero(int tablero[TAM][TAM], bool ocultar = false);
void colocarNaves(int tablero[TAM][TAM]);
void colocarNavesOponente(int tablero[TAM][TAM]);
bool quedanNaves(int tablero[TAM][TAM]);
bool realizarDisparo(int tablero[TAM][TAM], int x, int y);