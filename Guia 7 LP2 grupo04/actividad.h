#include <iostream>
#include <string>
using namespace std;

// Declaración anticipada del prototipo de la función burbuja
void burbuja(string& str);

// Clase base Cliente
class Cliente {
protected:
    string nombre;
    string apellido;
    string direccion;
    string numeroTarjeta;
public:
    Cliente(string _nombre, string _apellido, string _direccion, string _numeroTarjeta)
        : nombre(_nombre), apellido(_apellido), direccion(_direccion), numeroTarjeta(_numeroTarjeta) {}

    virtual ~Cliente() {}

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de tarjeta: " << numeroTarjeta << endl;
    }
};

// Clase derivada con herencia protegida
class ClienteSeguroProtegida : protected Cliente {
private:
    string originalNombre;
    string originalApellido;
    string originalDireccion;
    string originalNumeroTarjeta;
public:
    ClienteSeguroProtegida(string _nombre, string _apellido, string _direccion, string _numeroTarjeta)
        : Cliente(_nombre, _apellido, _direccion, _numeroTarjeta), originalNombre(_nombre), originalApellido(_apellido), originalDireccion(_direccion), originalNumeroTarjeta(_numeroTarjeta) {}

    void mostrarInformacionCliente() {
        cout << "Información del cliente:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de tarjeta: " << numeroTarjeta << endl;
    }

    void encriptarInformacionCliente() {
        burbuja(nombre);
        burbuja(apellido);
        burbuja(direccion);
        burbuja(numeroTarjeta);
        cout << "Información encriptada correctamente." << endl;
    }

    void desencriptarInformacionCliente() {
        nombre = originalNombre;
        apellido = originalApellido;
        direccion = originalDireccion;
        numeroTarjeta = originalNumeroTarjeta;
        cout << "Información desencriptada correctamente." << endl;
    }
};

// Función burbuja para ordenar caracteres en una cadena
void burbuja(string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    ClienteSeguroProtegida clienteProtegido("Juan Lopez", "Perez del Campo", "Urb:Callao Calle 123", "76251734");
    
    cout << "Información del cliente antes de encriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    
    clienteProtegido.encriptarInformacionCliente();
    
    cout << "\nInformación del cliente después de encriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    
    clienteProtegido.desencriptarInformacionCliente();
    
    cout << "\nInformación del cliente después de desencriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    
    return 0;
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



    Cta_cred cta2;
    cta2.cargarSaldo();
    cout<<"la cuenta tiene saldo: "<<cta2.saldo<<endl;
}
