#pragma once
#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool prestado;

public:
    // Constructor
    Libro(const std::string& titulo, const std::string& autor, const std::string& isbn);

    // Getters
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool estaPrestado() const;

    // Setters
    void setPrestado(bool estado);

    // Sobrecarga de operador <<
    friend std::ostream& operator<<(std::ostream& os, const Libro& libro);
};

#endif
