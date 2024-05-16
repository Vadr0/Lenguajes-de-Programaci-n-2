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
        for (size_t i = 0; i < direccion.size(); ++i) {  // Encriptar la dirección
            char& c = direccion[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + 1) % 26) + 'a';
            }
        }
        for (size_t i = 0; i < numeroTarjeta.size(); ++i) { // Encriptar el número de tarjeta
            char& c = numeroTarjeta[i];
            if (c >= '0' && c <= '9') {
                c = ((c - '0' + 1) % 10) + '0';
            }
        }
        cout << "Información encriptada correctamente." << endl;
    }
public:
    Cliente(string _nombre, string _apellido, string _direccion, string _numeroTarjeta)
        : nombre(_nombre), apellido(_apellido), direccion(_direccion), numeroTarjeta(_numeroTarjeta) {}
    virtual ~Cliente() {}
    void mostrarInformacion() {          //mostrar
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de tarjeta: " << numeroTarjeta << endl;
    }
};

class ClienteSeguroProtegida : protected Cliente {       //se hereda o se deriba  
public:
    ClienteSeguroProtegida(string _nombre, string _apellido, string _direccion, string _numeroTarjeta)
        : Cliente(_nombre, _apellido, _direccion, _numeroTarjeta) {}
    void mostrarInformacionCliente() {
        cout << "Información del cliente:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de tarjeta: " << numeroTarjeta << endl;
    }
    void encriptarInformacionCliente() {     //metodo para encriptar la informacion de la clase base
        encriptarInformacion();
    }
    void desencriptarInformacionCliente() {     //metodo para desencriptar
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
        for (size_t i = 0; i < direccion.size(); ++i) {
            char& c = direccion[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' - 1 + 26) % 26) + 'a';
            }
        }
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
    ClienteSeguroProtegida clienteProtegido("Juan", "Perez", "Parra 1245", "679416522");
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





    #include <iostream>
#include <string>
using namespace std;

class Cuentas{
public:
    string cliente;
    float saldo;
    virtual void cargarSaldo()=0;
};

class Cta_deb: public Cuentas
{
    public:
    virtual void cargarSaldo() override
    {
        this -> saldo=0;
    }
};
class Cta_cred: public Cuentas{
public:
    virtual void cargarSaldo() override
    {
        this-> saldo=5000;    }
};
int main (){
    Cta_deb cta1;
    cta1.cargarSaldo();
    cout<<"la cuenta tiene saldo: "<<cta1.saldo<<endl;

    Cta_cred cta2;
    cta2.cargarSaldo();
    cout<<"la cuenta tiene saldo: "<<cta2.saldo<<endl;
}
