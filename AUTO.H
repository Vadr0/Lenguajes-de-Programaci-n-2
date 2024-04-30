#ifndef AUTO_H
#define AUTO_H

#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    string dni;

public:
    Usuario(string n, string d) : nombre(n), dni(d) {}

    string getNombre() { return nombre; }
    string getDni() { return dni; }

    ~Usuario() {
        // Destructor can be used to clean up resources if needed
    }
};

class Carro {
private:
    string marca;
    string modelo;
    float precio;
    Usuario* usuario;  // Pointer to a Usuario object

public:
    Carro(string m, string mod, float p = 0, Usuario* u = nullptr) 
        : marca(m), modelo(mod), precio(p), usuario(u) {}

    Carro& setMarca(string m);

    Carro& setModelo(string mod);

    Carro& setPrecio(float p);

    Carro& setUsuario(Usuario* u);

    void mostrarDatos();

    void venderAlContado();

    void venderACuotas(float inicial, int plazo);

    ~Carro() {
        delete usuario;  // Delete the Usuario object when Carro is destroyed
    }
};

#endif
