// Arreglos y punteros

#include <iostream>
using namespace std;

int main()
{
    int arr[] = { 10, 20, 30 };
    int* ptr = arr; // arr ya es un puntero al primer elemento

    cout << "Primer elemento: " << *ptr << endl;
    ptr++; // incrementa el puntero para el siguiente elemento
    cout << "Segundo elemento: " << *ptr << "\n";
}
