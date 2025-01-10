#include <iostream>

#ifndef PI
#define PI 3.14
#endif

// Pilares de la programacion orientada a objetos (POO)
// Encapsulacion --
// Abstraccion --
// Poliformismo
// Herencia

//const double PI = 3.14;

class Circulo {
    // Encapsulacion
private:
    double radio;
public:
    // Metodo constructor
    // Abstraccion
    Circulo(double r) : radio(r) {}

    void setRadio(double r) {
        if (r > 0) radio = r;
    }

    double getRadio() const {
        return radio;
    }

    double calcularArea() const {
        return PI * radio * radio;
    }

    double calcularPerimetro() const {
        return 2 * PI * radio;
    }
};

int main()
{
    Circulo c1(5);
    Circulo c2(10);

    std::cout << "Radio c1: " << c1.getRadio() << std::endl;
    std::cout << "Area c1: " << c1.calcularArea() << std::endl;
    std::cout << "Perimetro c1: " << c1.calcularPerimetro() << std::endl;

    c1.setRadio(15);

    std::cout << "Radio c1: " << c1.getRadio() << std::endl;
    std::cout << "Area c1: " << c1.calcularArea() << std::endl;
    std::cout << "Perimetro c1: " << c1.calcularPerimetro() << std::endl;

    std::cout << "Radio c2: " << c2.getRadio() << std::endl;
    std::cout << "Area c2: " << c2.calcularArea() << std::endl;
    std::cout << "Perimetro c2: " << c2.calcularPerimetro() << std::endl;
}