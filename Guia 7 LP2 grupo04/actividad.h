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
}
____________________________________________________________________________________________________________________________

class Cliente:
    def __init__(self, nombre, apellido, direccion, numero_tarjeta):
        self.nombre = nombre
        self.apellido = apellido
        self.direccion = direccion
        self.numero_tarjeta = numero_tarjeta

    def mostrar_informacion(self):
        print(f"Nombre: {self.nombre}")
        print(f"Apellido: {self.apellido}")
        print(f"Dirección: {self.direccion}")
        print(f"Número de tarjeta: {self.numero_tarjeta}")


class ClienteSeguroProtegida(Cliente):
    def __init__(self, nombre, apellido, direccion, numero_tarjeta):
        super().__init__(nombre, apellido, direccion, numero_tarjeta)
        self.original_nombre = nombre
        self.original_apellido = apellido
        self.original_direccion = direccion
        self.original_numero_tarjeta = numero_tarjeta

    def mostrar_informacion_cliente(self):
        print("Información del cliente:")
        print(f"Nombre: {self.nombre}")
        print(f"Apellido: {self.apellido}")
        print(f"Dirección: {self.direccion}")
        print(f"Número de tarjeta: {self.numero_tarjeta}")

    def encriptar_informacion_cliente(self):
        self.nombre = self.burbuja(self.nombre)
        self.apellido = self.burbuja(self.apellido)
        self.direccion = self.burbuja(self.direccion)
        self.numero_tarjeta = self.burbuja(self.numero_tarjeta)
        print("Información encriptada correctamente.")

    def desencriptar_informacion_cliente(self):
        self.nombre = self.original_nombre
        self.apellido = self.original_apellido
        self.direccion = self.original_direccion
        self.numero_tarjeta = self.original_numero_tarjeta
        print("Información desencriptada correctamente.")

    @staticmethod
    def burbuja(s):
        arr = list(s)
        n = len(arr)
        for i in range(n):
            for j in range(0, n-i-1):
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
        return ''.join(arr)


if __name__ == "__main__":
    cliente_protegido = ClienteSeguroProtegida("Juan Lopez", "Perez del Campo", "Urb:Callao Calle 123", "76251734")

    print("Información del cliente antes de encriptar:")
    cliente_protegido.mostrar_informacion_cliente()

    cliente_protegido.encriptar_informacion_cliente()

    print("\nInformación del cliente después de encriptar:")
    cliente_protegido.mostrar_informacion_cliente()

    cliente_protegido.desencriptar_informacion_cliente()

    print("\nInformación del cliente después de desencriptar:")
    cliente_protegido.mostrar_informacion_cliente()


Codigo mejoradi
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

    // Método protegido para encriptar información
    void encriptar(string& str) {
        burbuja(str);
    }

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

// Clase derivada con herencia pública
class ClienteSeguro : public Cliente {
private:
    string originalNombre;
    string originalApellido;
    string originalDireccion;
    string originalNumeroTarjeta;
public:
    ClienteSeguro(string _nombre, string _apellido, string _direccion, string _numeroTarjeta)
        : Cliente(_nombre, _apellido, _direccion, _numeroTarjeta), originalNombre(_nombre), originalApellido(_apellido), originalDireccion(_direccion), originalNumeroTarjeta(_numeroTarjeta) {}

    void mostrarInformacionCliente() {
        cout << "Información del cliente:" << endl;
        mostrarInformacion();
    }

    void encriptarInformacionCliente() {
        encriptar(nombre);
        encriptar(apellido);
        encriptar(direccion);
        encriptar(numeroTarjeta);
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
    ClienteSeguro clienteProtegido("Juan Lopez", "Perez del Campo", "Urb:Callao Calle 123", "76251734");
    
    cout << "Información del cliente antes de encriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    
    clienteProtegido.encriptarInformacionCliente();
    
    cout << "\nInformación del cliente después de encriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    
    clienteProtegido.desencriptarInformacionCliente();
    
    cout << "\nInformación del cliente después de desencriptar:" << endl;
    clienteProtegido.mostrarInformacionCliente();
    
    return 0;
}


