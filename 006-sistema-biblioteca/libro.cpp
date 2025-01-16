// archivo: Libro.cpp
#include "Libro.h"

// Constructor
Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& isbn)
    : titulo(titulo), autor(autor), isbn(isbn), prestado(false) {
}

// Getters
std::string Libro::getTitulo() const {
    return titulo;
}

std::string Libro::getAutor() const {
    return autor;
}

std::string Libro::getISBN() const {
    return isbn;
}

bool Libro::estaPrestado() const {
    return prestado;
}

// Setters
void Libro::setPrestado(bool estado) {
    prestado = estado;
}

// Sobrecarga de operador
std::ostream& operator<<(std::ostream& os, const Libro& libro) {
    os << "Titulo: " << libro.titulo << "\n"
        << "Autor: " << libro.autor << "\n"
        << "ISBN: " << libro.isbn << "\n"
        << "Prestado: " << (libro.prestado ? "Si" : "No") << "\n";
    return os;
}