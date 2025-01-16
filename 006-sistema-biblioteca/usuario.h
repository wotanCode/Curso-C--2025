#pragma once
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "libro.h"

class Usuario {
private:
    std::string nombre;
    std::string email;
    std::string password;  // Nuevo atributo para la contraseña
    std::vector<Libro*> prestamos;

public:
    // Constructor
    Usuario(const std::string& nombre, const std::string& email, const std::string& password);

    // Métodos
    void registrarPrestamo(Libro* libro);
    void devolverPrestamo(const std::string& isbn);
    void mostrarPrestamos() const;
    bool validarPassword(const std::string& intento) const; // Método para validar la contraseña

    // Getters
    std::string getNombre() const;
    std::string getEmail() const;
};

#endif
