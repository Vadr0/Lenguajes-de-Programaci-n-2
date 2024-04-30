#include "auto.h"
#include <iostream>
using namespace std;

Usuario::Usuario(string n, string d) : nombre(n), dni(d) {}

string Usuario::getNombre() { return nombre; }
string Usuario::getDni() { return dni; }

Carro::Carro(string m, string mod, float p, Usuario* u) : marca(m), modelo(mod), precio(p), usuario(u) {}

Carro& Carro::setMarca(string m) {
    marca = m;
    return *this;
}

Carro& Carro::setModelo(string mod) {
    modelo = mod;
    return *this;
}

Carro& Carro::setPrecio(float p) {
    precio = p;
    return *this;
}

Carro& Carro::setUsuario(Usuario* u) {
    usuario = u;
    return *this;
}

void Carro::mostrarDatos() {
    cout << "Datos del Carro:" <<endl;
    cout << "Marca: " << marca <<endl;
    cout << "Modelo: " << modelo <<endl;
    cout << "Precio: $" << precio <<endl;
    if(usuario != nullptr) {
        cout << "Nombre del Usuario: " << usuario->getNombre() <<endl;
        cout << "DNI del Usuario: " << usuario->getDni() <<endl;
    }
}

void Carro::venderAlContado() {
    std::cout << "El carro " << marca << " " << modelo << " ha sido vendido al contado por $" << precio << endl;
}

void Carro::venderACuotas(float inicial, int plazo) {
    float interes = 0.0;
    if (plazo == 6) {
        interes = 0.05;
    } else if (plazo == 12) {
        interes = 0.1;
    } else if (plazo == 24) {
        interes = 0.15;
    }

    float montoPrestamo = precio - inicial;
    float cuotaMensual = (montoPrestamo + (montoPrestamo * interes)) / plazo;
    std::cout << "El carro " << marca << " " << modelo << " ha sido vendido a cuotas mensuales de $" << cuotaMensual << " durante " << plazo << " meses"<<endl;
}
