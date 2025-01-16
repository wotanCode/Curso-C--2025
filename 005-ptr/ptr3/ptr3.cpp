// Pasar un puntero a una funcion

#include <iostream>
using namespace std;

void incrementar(int* valor);
void incrementar(int* valor) {
    *valor += 10; // * Desreferencia el puntero para modificar directamente el valor apuntado
}

int main()
{
    int numero = 5;
    incrementar(&numero);

    cout << "El nuevo valor es: " << numero << endl;

    return 0;
}