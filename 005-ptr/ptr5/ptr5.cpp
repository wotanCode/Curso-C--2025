// Punteros y funciones

#include <iostream>
using namespace std;

void saludo();
void saludo() {
    cout << "Hola desde la funcion saludo!" << endl;
}

int main()
{
    void (*mifuncionPtr)() = saludo; // Declaracion de un puntero a funcion
    mifuncionPtr(); // Llama a la funcion a traves del puntero

    return 0;
}