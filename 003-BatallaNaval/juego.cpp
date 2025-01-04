#include "juego.h"
#include "tablero.h"
#include "limpiarConsola.h"
#include <iostream>

void jugar() {
	int tableroJugador[TAM][TAM], tableroOponente[TAM][TAM];

	inicializarTablero(tableroJugador);
	inicializarTablero(tableroOponente);

	std::cout << "Coloca tus naves\n";
	std::cout << "Tienes " << TAM << " cantidad de naves\n";

	colocarNaves(tableroJugador);
	colocarNavesOponente(tableroOponente);
	bool turnoJugador = true;

	while (quedanNaves(tableroJugador) && quedanNaves(tableroOponente)) {

		if (turnoJugador) {
			limpiarConsola();

			std::cout << "Tablero del jugador\n";
			mostrarTablero(tableroJugador);
			std::cout << std::endl << "Tablero del computador\n";
			mostrarTablero(tableroOponente, true);

			int x, y;
			
			bool disparoValido = false;

			while (!disparoValido) {

				std::cout << "Tu turno de atacar\n";
				std::cout << "Ingresa la coordenada X: ";
				std::cin >> x;
				std::cout << "Ingresa la coordenada Y: ";
				std::cin >> y;

				if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
					if (tableroOponente[x][y] == 0 || tableroOponente[x][y] == 1) {
						realizarDisparo(tableroOponente, x, y);
						disparoValido = true;
						turnoJugador = false;
					}
					else std::cout << "Ya has disparado aqui\n";
				}
				else std::cout << "Coordenadas invalidas\n";
			}
		} 
		// Turno computador
		else {
			int x, y;
			bool disparoValido = false;

			while (!disparoValido) {
				x = rand() % TAM;
				y = rand() % TAM;

				if (tableroJugador[x][y] == 0 || tableroJugador[x][y] == 1) {
					realizarDisparo(tableroJugador, x, y);
					disparoValido = true;
					turnoJugador = true;
				}
			}
		}
					
	}

	// Finaliza el juego
	if (quedanNaves(tableroJugador)) {
		std::cout << "Felicidades, has ganado!\n";
		mostrarTablero(tableroJugador);
		mostrarTablero(tableroOponente);
	}
	else {
		std::cout << "Has perdido\n";
		mostrarTablero(tableroJugador);
		mostrarTablero(tableroOponente);
	}
}

void menu() {
	int opcion;

	do {
		std::cout << "\n=Menu=\n";
		std::cout << "1. Jugar\n";
		std::cout << "2. Salir\n";
		std::cout << "Selecciona una opcion: ";
		std::cin >> opcion;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (opcion) {
		case 1:
			jugar();
			break;
		case 2:
			std::cout << "Gracias por jugar!\n";
			std::cin.get();
			break;
		default:
			std::cout << "Opcion invalida\n";
			std::cout << "Presionar enter para continuar...\n";
			std::cin.get();
			limpiarConsola();
			
		}
	} while (opcion != 2);
}