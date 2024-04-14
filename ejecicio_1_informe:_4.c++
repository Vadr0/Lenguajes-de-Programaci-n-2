#include <iostream>
using namespace std;

// Definimos el número máximo de libros, autores y usuarios que nuestro sistema puede manejar
#define MAX_LIBROS 100
#define MAX_AUTORES 100
#define MAX_USUARIOS 100

// Definimos la longitud máxima de los nombres y direcciones
#define MAX_NOMBRE 100
#define MAX_DIRECCION 100

// Clase Libro
class Libro {
public:
    char ISBN[14];
    char titulo[MAX_NOMBRE];
    int anioPublicacion;
    int cantidadEjemplares;
    int idAutor;  // Usamos el ID del autor en lugar del objeto Autor
};

// Clase Autor
class Autor {
public:
    char nombre[MAX_NOMBRE];
    char nacionalidad[MAX_NOMBRE];
    int librosEscritos[MAX_LIBROS];  // Usamos los IDs de los libros en lugar de los objetos Libro
    int numLibrosEscritos;
};

// Clase Usuario
class Usuario {
public:
    char nombre[MAX_NOMBRE];
    char direccion[MAX_DIRECCION];
    char numeroTelefono[15];
    int librosPrestados[MAX_LIBROS];  // Usamos los IDs de los libros en lugar de los objetos Libro
    int numLibrosPrestados;
};

// Creamos arrays para almacenar todos los libros, autores y usuarios
Libro libros[MAX_LIBROS];
Autor autores[MAX_AUTORES];
Usuario usuarios[MAX_USUARIOS];

// Contadores para llevar la cuenta de cuántos libros, autores y usuarios tenemos
int numLibros = 0;
int numAutores = 0;
int numUsuarios = 0;

// Funciones para agregar libros, autores y usuarios
void agregarLibro(Libro libro) {
    libros[numLibros] = libro;
    numLibros++;
}

void agregarAutor(Autor autor) {
    autores[numAutores] = autor;
    numAutores++;
}

void agregarUsuario(Usuario usuario) {
    usuarios[numUsuarios] = usuario;
    numUsuarios++;
}

// Definiciones y clases de Libro, Autor y Usuario como en el ejemplo anterior...
int main() {
    // Crear un autor
    Autor autor;
    cout << "Ingrese el nombre del autor: ";
    cin.getline(autor.nombre, MAX_NOMBRE);
    cout << "Ingrese la nacionalidad del autor: ";
    cin.getline(autor.nacionalidad, MAX_NOMBRE);
    autor.numLibrosEscritos = 0;
    agregarAutor(autor);

    // Crear un libro
    Libro libro;
    cout << "\nIngrese el ISBN del libro: ";
    cin.getline(libro.ISBN, 14);
    cout << "Ingrese el título del libro: ";
    cin.getline(libro.titulo, MAX_NOMBRE);
    cout << "Ingrese el año de publicación del libro: ";
    cin >> libro.anioPublicacion;
    cout << "Ingrese la cantidad de ejemplares del libro: ";
    cin >> libro.cantidadEjemplares;
    cin.ignore();  // Ignorar el '\n' que queda en el buffer de entrada
    libro.idAutor = 0;  // Suponemos que el libro fue escrito por el primer autor
    agregarLibro(libro);

    // Crear un usuario
    Usuario usuario;
    cout << "\nIngrese el nombre del usuario: ";
    cin.getline(usuario.nombre, MAX_NOMBRE);
    cout << "Ingrese la dirección del usuario: ";
    cin.getline(usuario.direccion, MAX_DIRECCION);
    cout << "Ingrese el número de teléfono del usuario: ";
    cin.getline(usuario.numeroTelefono, 15);
    usuario.numLibrosPrestados = 0;
    agregarUsuario(usuario);

    return 0;
}
