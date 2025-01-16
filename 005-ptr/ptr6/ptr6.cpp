// Punteros y miembros de clase
#include <iostream>
using namespace std;

class MiClaseDePrueba {
public:
    void mostrar() {
        cout << "Hola desde mi clase de prueba" << endl;
    }
};

int main()
{
    MiClaseDePrueba miObjeto;
    void (MiClaseDePrueba:: * ptrMiMetodo)() = &MiClaseDePrueba::mostrar;
    // & Obtiene la direccion del metodo de la clase
    // :: Accede a un miembro de la clase

    (miObjeto.*ptrMiMetodo)();

    return 0;
}
