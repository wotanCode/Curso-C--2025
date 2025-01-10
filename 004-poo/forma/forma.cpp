#include <iostream>

#ifndef PI
#define PI 3.14
#endif

// Pilares de la programacion orientada a objetos (POO)
// Encapsulacion --
// Abstraccion --
// Polimorfismo --
// Herencia --

class Forma {
public:
    virtual void mostrarInfo() const = 0; // polimorfismo
    virtual double calcularArea() const = 0; // polimorfismo
};

// Herencia
class Circulo : public Forma {
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

    double calcularPerimetro() const {
        return 2 * PI * radio;
    }

    // Polimorfismo
    void mostrarInfo() const override {
        std::cout << "Soy un circulo" << std::endl;
    }

    double calcularArea() const override {
        return PI * radio * radio;
    }
};

// Herencia
class Rectangulo : public Forma {
// Encapsulamiento
private:
    double largo, ancho;

public:
    // Metodo constructor
    Rectangulo(double l, double a) : largo(l), ancho(a) {}

    // Polimorfismo
    void mostrarInfo() const override {
        std::cout << "Soy un rectangulo de largo: " << largo << " y de ancho: " << ancho << std::endl;
    }

    double calcularArea() const override {
        return largo * ancho;
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

    Rectangulo r1(10, 5);

    std::cout << "Area del rectangulo" << r1.calcularArea() << std::endl;

}