#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para system()
//#include <limits>  // Para std::numeric_limits

#include "Libro.h"
#include "Usuario.h"

void mostrarMenu();
void agregarLibro(std::vector<Libro>& libros);
void mostrarLibros(const std::vector<Libro>& libros);
void prestarLibro(std::vector<Libro>& libros, Usuario& usuario);
void devolverLibro(Usuario& usuario);
void limpiarConsola();
Usuario* iniciarSesion(std::vector<Usuario>& usuarios);

void limpiarConsola() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarMenu() {
    std::cout << "\n--- Sistema de Biblioteca ---\n";
    std::cout << "1. Agregar un libro\n";
    std::cout << "2. Mostrar todos los libros\n";
    std::cout << "3. Prestar un libro\n";
    std::cout << "4. Devolver un libro\n";
    std::cout << "5. Mostrar libros prestados por el usuario\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

void agregarLibro(std::vector<Libro>& libros) {
    std::string titulo, autor, isbn;
    std::cout << "Ingrese el título del libro: ";
    std::getline(std::cin, titulo);
    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, autor);
    std::cout << "Ingrese el ISBN del libro: ";
    std::getline(std::cin, isbn);

    libros.emplace_back(titulo, autor, isbn);
    limpiarConsola();
    std::cout << "Libro agregado exitosamente.\n";
}

void mostrarLibros(const std::vector<Libro>& libros) {
    if (libros.empty()) {
        limpiarConsola();
        std::cout << "No hay libros registrados.\n";
        return;
    }

    std::cout << "\n--- Lista de Libros ---\n";
    for (size_t i = 0; i < libros.size(); ++i) {
        std::cout << i + 1 << ". " << libros[i].getTitulo() << " - " << libros[i].getAutor()
            << " (ISBN: " << libros[i].getISBN() << ", Prestado: "
            << (libros[i].estaPrestado() ? "Si" : "No") << ")\n";
    }
}

void prestarLibro(std::vector<Libro>& libros, Usuario& usuario) {
    mostrarLibros(libros);
    if (libros.empty()) return;

    int seleccion;
    std::cout << "Seleccione el número del libro a prestar: ";
    std::cin >> seleccion;
    std::cin.ignore(); // Limpiar el buffer

    if (seleccion < 1 || seleccion > static_cast<int>(libros.size())) {
        limpiarConsola();
        std::cout << "Seleccion inválida.\n";
        return;
    }

    Libro& libro = libros[seleccion - 1];
    usuario.registrarPrestamo(&libro);
}

void devolverLibro(Usuario& usuario) {
    usuario.mostrarPrestamos();
    std::string isbn;
    std::cout << "Ingrese el ISBN del libro a devolver: ";
    std::getline(std::cin, isbn);
    usuario.devolverPrestamo(isbn);
}

Usuario* iniciarSesion(std::vector<Usuario>& usuarios) {
    while (true) {
        limpiarConsola();
        std::cout << "--- Iniciar Sesion ---\n";
        std::cout << "Usuarios disponibles:\n";

        for (size_t i = 0; i < usuarios.size(); ++i) {
            std::cout << i + 1 << ". " << usuarios[i].getNombre() << "\n";
        }

        int seleccion;
        std::cout << "Seleccione el número del usuario: ";
        std::cin >> seleccion;
        std::cin.ignore(); // Limpiar el buffer

        if (seleccion < 1 || seleccion > static_cast<int>(usuarios.size())) {
            std::cout << "Seleccion inválida. Intente nuevamente.\n";
            continue;
        }

        Usuario& usuario = usuarios[seleccion - 1];
        std::string password;
        std::cout << "Ingrese la contraseña: ";
        std::getline(std::cin, password);

        if (usuario.validarPassword(password)) {
            limpiarConsola();
            std::cout << "Inicio de sesion exitoso.\n";
            return &usuario;
        }
        else {
            std::cout << "Contraseña incorrecta. Intente nuevamente.\n";
        }
    }
}

int main() {
    std::vector<Libro> libros;

    // Crear usuarios con contraseñas
    std::vector<Usuario> usuarios = {
        Usuario("Juan Gomez", "juan.gomez@email.com", "1"),
        Usuario("Maria Lopez", "maria.lopez@email.com", "2"),
        Usuario("Carlos Perez", "carlos.perez@email.com", "3")
    };

    Usuario* usuario = iniciarSesion(usuarios);

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer

        switch (opcion) {
        case 1:
            agregarLibro(libros);
            break;
        case 2:
            mostrarLibros(libros);
            break;
        case 3:
            prestarLibro(libros, *usuario);
            break;
        case 4:
            devolverLibro(*usuario);
            break;
        case 5:
            usuario->mostrarPrestamos();
            break;
        case 6:
            std::cout << "Saliendo del sistema. ¡Hasta luego!\n";
            break;
        default:
            limpiarConsola();
            std::cout << "Opcion inválida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
