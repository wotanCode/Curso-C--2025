#include "usuario.h"
#include <iostream>

// Constructor
Usuario::Usuario(const std::string& nombre, const std::string& email, const std::string& password)
    : nombre(nombre), email(email), password(password) {
}

// M�todos
void Usuario::registrarPrestamo(Libro* libro) {
    if (!libro->estaPrestado()) {
        prestamos.push_back(libro);
        libro->setPrestado(true);
        std::cout << "Prestamo registrado para el libro: " << libro->getTitulo() << "\n";
    }
    else {
        std::cout << "El libro ya est� prestado.\n";
    }
}

void Usuario::devolverPrestamo(const std::string& isbn) {
    for (size_t i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i]->getISBN() == isbn) {
            prestamos[i]->setPrestado(false);
            std::cout << "Libro devuelto: " << prestamos[i]->getTitulo() << "\n";
            prestamos.erase(prestamos.begin() + i);
            return;
        }
    }
    std::cout << "No se encontro un pr�stamo con ese ISBN.\n";
}

void Usuario::mostrarPrestamos() const {
    std::cout << "Prestamos del usuario " << nombre << ":\n";
    for (const auto& libro : prestamos) {
        std::cout << "- " << libro->getTitulo() << "\n";
    }
}

// M�todo para validar contrase�a
bool Usuario::validarPassword(const std::string& intento) const {
    return password == intento;
}

// Getters
std::string Usuario::getNombre() const {
    return nombre;
}

std::string Usuario::getEmail() const {
    return email;
}
