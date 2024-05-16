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
        for (size_t i = 0; i < nombre.size(); ++i) {        //el size es un metodo de la libreria string 
            char& c = nombre[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + 1) % 26) + 'a';
            }
        }
        for (size_t i = 0; i < apellido.size(); ++i) {
            char& c = apellido[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + 1) % 26) + 'a';
            }
        }
        // Encriptar la dirección
        for (size_t i = 0; i < direccion.size(); ++i) {
            char& c = direccion[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + 1) % 26) + 'a';
            }
        }
        // Encriptar el número de tarjeta
        for (size_t i = 0; i < numeroTarjeta.size(); ++i) {
            char& c = numeroTarjeta[i];
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
        for (size_t i = 0; i < nombre.size(); ++i) {
            char& c = nombre[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' - 1 + 26) % 26) + 'a';
            }
        }
        for (size_t i = 0; i < apellido.size(); ++i) {
            char& c = apellido[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' - 1 + 26) % 26) + 'a';
            }
        }
        // Desencriptar la dirección
        for (size_t i = 0; i < direccion.size(); ++i) {
            char& c = direccion[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' - 1 + 26) % 26) + 'a';
            }
        }
        // Desencriptar el número de tarjeta
        for (size_t i = 0; i < numeroTarjeta.size(); ++i) {
            char& c = numeroTarjeta[i];
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

____________________________________________________________________________________________________________________________

class Cliente:
    def __init__(self, nombre, apellido, direccion, numero_tarjeta):
        self.nombre = nombre
        self.apellido = apellido
        self.direccion = direccion
        self.numero_tarjeta = numero_tarjeta

    def encriptar_informacion(self):
        # Encriptar el nombre y el apellido
        self.nombre = ''.join(chr(((ord(c) - ord('a') + 1) % 26) + ord('a')) if 'a' <= c <= 'z' else c for c in self.nombre)
        self.apellido = ''.join(chr(((ord(c) - ord('a') + 1) % 26) + ord('a')) if 'a' <= c <= 'z' else c for c in self.apellido)
        # Encriptar la dirección
        self.direccion = ''.join(chr(((ord(c) - ord('a') + 1) % 26) + ord('a')) if 'a' <= c <= 'z' else c for c in self.direccion)
        # Encriptar el número de tarjeta
        self.numero_tarjeta = ''.join(chr(((ord(c) - ord('0') + 1) % 10) + ord('0')) if '0' <= c <= '9' else c for c in self.numero_tarjeta)
        print("Información encriptada correctamente.")

    def desencriptar_informacion(self):
        # Desencriptar el nombre y el apellido
        self.nombre = ''.join(chr(((ord(c) - ord('a') - 1 + 26) % 26) + ord('a')) if 'a' <= c <= 'z' else c for c in self.nombre)
        self.apellido = ''.join(chr(((ord(c) - ord('a') - 1 + 26) % 26) + ord('a')) if 'a' <= c <= 'z' else c for c in self.apellido)
        # Desencriptar la dirección
        self.direccion = ''.join(chr(((ord(c) - ord('a') - 1 + 26) % 26) + ord('a')) if 'a' <= c <= 'z' else c for c in self.direccion)
        # Desencriptar el número de tarjeta
        self.numero_tarjeta = ''.join(chr(((ord(c) - ord('0') - 1 + 10) % 10) + ord('0')) if '0' <= c <= '9' else c for c in self.numero_tarjeta)
        print("Información desencriptada correctamente.")

    def mostrar_informacion(self):
        print("Nombre:", self.nombre)
        print("Apellido:", self.apellido)
        print("Dirección:", self.direccion)
        print("Número de tarjeta:", self.numero_tarjeta)


class ClienteSeguroProtegida(Cliente):
    def mostrar_informacion_cliente(self):
        print("Información del cliente:")
        print("Nombre:", self.nombre)
        print("Apellido:", self.apellido)
        print("Dirección:", self.direccion)
        print("Número de tarjeta:", self.numero_tarjeta)


if __name__ == "__main__":
    cliente_protegido = ClienteSeguroProtegida("Juan", "Perez", "Calle 123", "1234")
    
    print("Información del cliente antes de encriptar:")
    cliente_protegido.mostrar_informacion()
    
    cliente_protegido.encriptar_informacion()
    
    print("\nInformación del cliente después de encriptar:")
    cliente_protegido.mostrar_informacion()
    
    cliente_protegido.desencriptar_informacion()
    
    print("\nInformación del cliente después de desencriptar:")
    cliente_protegido.mostrar_informacion()
