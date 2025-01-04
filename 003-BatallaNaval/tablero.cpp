#include "tablero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void inicializarTablero(int tablero[TAM][TAM]) {
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			tablero[i][j] = 0;
		}
	}
}


/*
- = Oculto
N = Nave
X = Disparo a nave
O = Disparo al agua
*/
void mostrarTablero(int tablero[TAM][TAM], bool ocultar) {
	std::cout << std::endl << "    ";

	for (int i = 0; i < TAM; i++) { std::cout << i << " "; }
	std::cout << std::endl;

	for (int i = 0; i < TAM; i++) {
		std::cout << i << " |";
		for (int j = 0; j < TAM; j++) {
			// Cuando esta oculto y es el enemigo
			if (ocultar && tablero[i][j] == 1)
				std::cout << " -";
			// Caso jugador
			else if (tablero[i][j] == 1)
				std::cout << " N";
			// Caso disparo certado
			else if (tablero[i][j] == 2)
				std::cout << " X";
			// Caso disparo fallido
			else if (tablero[i][j] == 3)
				std::cout << " 0";
			// Caso borde
			else
				std::cout << " -";
		}
		std::cout << std::endl;
	}
}




void colocarNaves(int tablero[TAM][TAM]) {
	int x, y;

	for (int i = 0; i < NUM_NAVES; i++) {
		bool colocada = false;

		while (!colocada) {
			mostrarTablero(tablero);
			std::cout << "Coloca tu nave numero: " << i + 1 << " (Coordenada X): ";
			std::cin >> x;
			std::cout << "Coloca tu nave numero: " << i + 1 << " (Coordenada Y): ";
			std::cin >> y;

			if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
				tablero[x][y] = 1;
				colocada = true;
			}
			else std::cout << "Posicion invalida\n";
		}
	}
}

void colocarNavesOponente(int tablero[TAM][TAM]) {
	srand(time(0));

	for (int i = 0; i < NUM_NAVES; i++) {
		int x, y;

		do {
			x = rand() % TAM;
			y = rand() % TAM;
		} while (tablero[x][y] != 0);

		tablero[x][y] = 1;
	}
}

bool quedanNaves(int tablero[TAM][TAM]) {
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			if (tablero[i][j] == 1) return true;
		}
	}

	return false;
}

bool realizarDisparo(int tablero[TAM][TAM], int x, int y) {
	// Impacto
	if (tablero[x][y] == 1) {
		tablero[x][y] = 2;
		return true;
	}

	// Agua
	else if (tablero[x][y] == 0) {
		tablero[x][y] = 3;
		return false;
	}

	else std::cout << "Ya has disparado a esta casilla\n";

	return false;
}