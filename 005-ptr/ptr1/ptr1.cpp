// Declaracion y uso basico de punteros
#include <iostream>
using namespace std;

int main()
{
    int numero = 10;
    int* ptr = &numero;

    cout << "Valor de numero: " << numero << endl;
    cout << "Valor de la posicion de memoria de numero: " << &numero << endl;
    cout << "Valor de ptr: " << ptr << "\n";
    cout << "Valor hacia donde apunta ptr: " << *ptr << "\n";


    cout << "-------------------" << endl;

    *ptr = 20;
    cout << "Valor de la posicion de memoria de numero: " << &numero << endl;
    cout << "Valor hacia donde apunta ptr: " << *ptr << "\n";
}

