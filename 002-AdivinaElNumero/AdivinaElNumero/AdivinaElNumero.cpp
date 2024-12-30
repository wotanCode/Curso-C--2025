#include <iostream>
#include <cstdlib> // Entre otras funcionalidades para generar numeros aleatorios
#include <ctime> // Para poder usar la funcion time

/*
Temas:
- If/else/switch
- For/while/do-while
- funciones
*/
using namespace std;

int totalJuegos = 0;
int juegosGanados = 0;
int juegosPerdidos = 0;

void jugar();
void mostrarEstadisticas();

int main()
{
    int opcion = 0;
    srand(time(0)); // Semilla en base al tiempo en segundos

    do {
        cout << "==Menu principal==\n";
        cout << "1. Jugar\n";
        cout << "2. Ver estadisticas\n";
        cout << "3. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n";
                jugar();
                break;
            case 2:
                cout << "\n";
                mostrarEstadisticas();
                break;
            case 3:
                cout << "\n";
                cout << "Hasta pronto!\n";
                break;
            default:
                cout << "Opcion invalida\n";
                break;
        }
        cout << "\n";

    } while (opcion != 3);

    return 0;
}

void jugar() {
    int numAleatorio = rand() % 10 + 1;
    int intento;
    int numIntentosRestantes = 3; // 3 intentos para adivinar
    bool adivinado = false;

    cout << "He pensado un numero entre 1 y 10\n";
    cout << "Intenta adivinarlo!\n";
    // cout << "El numero secreto (No se lo digas a nadie) es: " << numAleatorio << "\n";

    while (numIntentosRestantes > 0) {
        cout << "Te quedan " << numIntentosRestantes << " intentos\n";
        cout << "Ingresa tu numero: ";
        cin >> intento;

        if (intento == numAleatorio) {
            cout << "Acertaste!\n";
            adivinado = true;
            juegosGanados++;
            break;
        }
        else if (intento < numAleatorio) {
            cout << "Muy bajo!\n";
        }
        else {
            cout << "Muy alto!\n";
        }

        cout << "\n";
        numIntentosRestantes--;
    }

    if (!adivinado) {
        cout << "Fallaste! El numero era: " << numAleatorio << "\n";
        juegosPerdidos++;
    }

    totalJuegos++;
}

void mostrarEstadisticas() {
    cout << "== Estadisticas == \n";
    cout << "Total juegos jugados: " << totalJuegos << "\n";
    cout << "Juegos ganados: " << juegosGanados << "\n";
    cout << "Juegos perdidos: " << juegosPerdidos << "\n";

    if (totalJuegos > 0) {
        double precision = (juegosGanados / static_cast<double>(totalJuegos)) * 100;
		cout << "Precision: " << precision << "%\n";
    }
    else {
        cout << "Debes jugar al menos una vez para mostrar la precision\n";
    }
}