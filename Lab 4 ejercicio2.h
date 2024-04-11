#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Declaración anticipada de la clase Cliente
class Cliente;

// Interfaz para objetos que pueden ser vendidos
class Vendible {
public:
    virtual double calcularPrecio() const = 0;
    virtual ~Vendible() {}
};

// Declaración anticipada de la clase Venta
class Venta;

// Clase para representar un producto
class Producto : public Vendible {
private:
    int codigo;
    string descripcion;
    double precio;

public:
    Producto(int codigo, const string& descripcion, double precio)
        : codigo(codigo), descripcion(descripcion), precio(precio) {}

    // Calcular el precio del producto
    double calcularPrecio() const override {
        return precio;
    }
};

// Interfaz para objetos que pueden realizar pagos
class Pagable {
public:
    virtual void realizarPago(double monto) = 0;
    virtual ~Pagable() {}
};

// Clase para representar un cliente
class Cliente : public Pagable {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<Vendible*> compras; // Lista de compras realizadas por el cliente

public:
    Cliente(const string& nombre, const string& direccion, const string& telefono)
        : nombre(nombre), direccion(direccion), telefono(telefono) {}

    // Agregar una compra al cliente
    void agregarCompra(Vendible* compra) {
        compras.push_back(compra);
    }

    // Realizar un pago
    void realizarPago(double monto) override {
        cout << "Cliente " << nombre << " realiza un pago de $" << monto << endl;
        // Lógica para registrar el pago en el sistema de la tienda
    }
};

// Clase para representar una venta
class Venta {
private:
    int numeroFactura;
    string fecha;
    Cliente* cliente;
    vector<Vendible*> productos;

public:
    Venta(int numeroFactura, const string& fecha, Cliente* cliente)
        : numeroFactura(numeroFactura), fecha(fecha), cliente(cliente) {}

    // Agregar un producto a la venta
    void agregarProducto(Vendible* producto) {
        productos.push_back(producto);
    }
};

int main() {
    // Ejemplo de uso del sistema
    Cliente cliente("Juan", "Calle 123", "123456789");

    Producto producto1(1, "Camisa", 20.0);
    Producto producto2(2, "Pantalón", 30.0);

    cliente.agregarCompra(&producto1);
    cliente.agregarCompra(&producto2);

    cliente.realizarPago(50.0);

    return 0;
}
