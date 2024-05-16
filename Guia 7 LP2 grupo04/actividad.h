#include <iostream>
#include <string>
using namespace std;

// Clase base Cliente
class Cliente {
protected:
    string nombre;
    string apellido;
    string direccion;
    string numeroTarjeta;
    // Método protegido para encriptar la información
    void encriptarInformacion() {
        // Encriptar el nombre y el apellido
        for (char& c : nombre) {
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + 1) % 26) + 'a';
            }
        }
        for (char& c : apellido) {
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + 1) % 26) + 'a';
            }
        }
        // Encriptar la dirección
        for (char& c : direccion) {
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + 1) % 26) + 'a';
            }
        }
        // Encriptar el número de tarjeta
        for (char& c : numeroTarjeta) {
            if (c >= '0' && c <= '9') {
                c = ((c - '0' + 1) % 10) + '0';
            }
        }
        cout << "Información encriptada correctamente." << endl;
    }
public:
    // Constructor
    Cliente(string _nombre, string _apellido, string _direccion, string _numeroTarjeta)
        : nombre(_nombre), apellido(_apellido), direccion(_direccion), numeroTarjeta(_numeroTarjeta) {}
    // Destructor virtual
    virtual ~Cliente() {}
    // Método para mostrar la información del cliente
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de tarjeta: " << numeroTarjeta << endl;
    }
};

// Clase derivada ClienteSeguro utilizando herencia protegida
class ClienteSeguroProtegida : protected Cliente {
public:
    // Constructor que llama al constructor de la clase base y que inicializa los atributos adicionales
    ClienteSeguroProtegida(string _nombre, string _apellido, string _direccion, string _numeroTarjeta)
        : Cliente(_nombre, _apellido, _direccion, _numeroTarjeta) {}
    // Método público para mostrar la información del cliente
    void mostrarInformacionCliente() {
        // Acceso a los miembros protegidos de la clase base
        cout << "Información del cliente:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de tarjeta: " << numeroTarjeta << endl;
    }
    // Método para encriptar la información del cliente (llama al método protegido de la clase base)
    void encriptarInformacionCliente() {
        encriptarInformacion();
    }
    // Método para desencriptar la información del cliente
    void desencriptarInformacionCliente() {
        // Desencriptar el nombre y el apellido
        for (char& c : nombre) {
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' - 1 + 26) % 26) + 'a';
            }
        }
        for (char& c : apellido) {
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' - 1 + 26) % 26) + 'a';
            }
        }
        // Desencriptar la dirección
        for (char& c : direccion) {
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' - 1 + 26) % 26) + 'a';
            }
        }
        // Desencriptar el número de tarjeta
        for (char& c : numeroTarjeta) {
            if (c >= '0' && c <= '9') {
                c = ((c - '0' - 1 + 10) % 10) + '0';
            }
        }
        cout << "Información desencriptada correctamente." << endl;
    }
};

int main() {
    // Crear un objeto de la clase ClienteSeguro utilizando herencia protegida
    ClienteSeguroProtegida clienteProtegido("Juan", "Perez", "Calle 123", "1234");
    // Mostrar la información del cliente antes de encriptar
    cout << "Información del cliente antes de encriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    // Encriptar la información del cliente
    clienteProtegido.encriptarInformacionCliente();
    // Mostrar la información del cliente después de encriptar
    cout << "\nInformación del cliente después de encriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    // Desencriptar la información del cliente
    clienteProtegido.desencriptarInformacionCliente();
    // Mostrar la información del cliente después de desencriptar
    cout << "\nInformación del cliente después de desencriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    return 0;
}