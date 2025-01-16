// Punteros y memoria dinamica

#include <iostream>

using namespace std;

int main()
{
    int* ptr = new int;
    *ptr = 42;

    cout << "Valor en memoria dinamica: " << *ptr << endl;
    
    delete ptr; // Libera la memoria dinamica asignada por new

    cout << "Valor en memoria dinamica: " << *ptr << endl;

}

