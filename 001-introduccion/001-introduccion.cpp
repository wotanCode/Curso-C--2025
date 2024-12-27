// 001-introduccion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream> // Para consola en C++
//#include <stdio.h> // Para lenguaje C
//#include <conio.h> // Para sistemas muy antiguos

using namespace std; // Para la consola en C++

int main()
{
    // Tipos de datos
    int numero = 10;
    float decimal = 10.5;
    double decimal2 = 10.54;
    char letra = 'a';
    bool booleano = true;
    string cadena = "Hola mundo";

    cout << cadena << endl;
    cout << "El booleano es: " << booleano << endl;
    cout << "Ingresa el valor de un numero y se le sumara 10" << endl;
    cin >> numero;
    int total;
    total = numero + decimal;
	cout << "El resultado es: " << total << endl;

    /*
    Todas las operaciones basicas
    sumar, restar, multiplicar, dividir, modulo
    */
    cout << "------------------\n";
    cout << "Operadores matematicos\n";
    cout << "Total +10: " << total + 10 << endl;
    cout << "Total -10: " << total - 10 << endl;
    cout << "Total *10: " << total * 10 << endl;
    cout << "Total /10: " << total / 10 << endl;
    cout << "Total %10: " << total % 10 << endl;

    // Operadores de incremento y decremento
    cout << "------------------\n";
    cout << "Operadores de incremento y decremento\n";
    cout << "++Total: " << ++total << endl;
    cout << "--Total: " << --total << endl;

    // Operadores de comparacion
    cout << "------------------\n";
    cout << "Operadores de comparacion\n";
    cout << "Total == 10: " << (total == 10) << endl;
	cout << "Total != 10: " << (total != 10) << endl;
	cout << "Total > 10: " << (total > 10) << endl;
	cout << "Total < 10: " << (total < 10) << endl;
	cout << "Total >= 10: " << (total >= 10) << endl;
	cout << "Total <= 10: " << (total <= 10) << endl;

	// Operadores logicos
    cout << "------------------\n";
    cout << "Operadores logicos\n";
	cout << "Total == 10 && Total > 0: " << (total == 10 && total > 0) << endl;
    cout << "Total == 10 || Total > 0: " << (total == 10 || total > 0) << endl;
	cout << "!(Total == 10): " << !(total == 10) << endl;

    cout << "------------------\n";
    cout << "Presiona cualquier tecla para cerrar";
    cin.get(); // Espera a que el usuario preione una tecla
}
