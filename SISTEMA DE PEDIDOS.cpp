#include <iostream>
using namespace std;

class Producto {
public:
    int codigo;
    string descripcion;
    int stock;
    float precio;
    
    Producto(int cod, string desc, int stk, float prc) : codigo(cod), descripcion(desc), stock(stk), precio(prc) {}
};

class Inventario {
private:
    static const int MAX_PRODUCTOS = 100;
    Producto disponibles[MAX_PRODUCTOS];
    int numDisponibles;
    Producto agotados[MAX_PRODUCTOS];
    int numAgotados;

public:
    Inventario() : numDisponibles(0), numAgotados(0) {}

    void agregarProducto(Producto prod) {
        if (numDisponibles < MAX_PRODUCTOS) {
            disponibles[numDisponibles++] = prod;
        } else {
            cout << "No se puede agregar más productos, el inventario está lleno." << endl;
        }
    }

    void actualizarInventario() {
        for (int i = 0; i < numDisponibles; ++i) {
            if (disponibles[i].stock == 0) {
                agotados[numAgotados++] = disponibles[i];
                // Eliminar el producto agotado moviendo los elementos restantes hacia la izquierda
                for (int j = i; j < numDisponibles - 1; ++j) {
                    disponibles[j] = disponibles[j + 1];
                }
                numDisponibles--;
                i--; // Decrementar el índice para revisar el nuevo elemento en la misma posición
            }
        }
    }

    void mostrarDisponibles() {
        cout << "Productos disponibles:" << endl;
        for (int i = 0; i < numDisponibles; ++i) {
            cout << "Código: " << disponibles[i].codigo << ", Descripción: " << disponibles[i].descripcion << ", Stock: " << disponibles[i].stock << ", Precio: " << disponibles[i].precio << endl;
        }
    }

    void mostrarAgotados() {
        cout << "Productos agotados:" << endl;
        for (int i = 0; i < numAgotados; ++i) {
            cout << "Código: " << agotados[i].codigo << ", Descripción: " << agotados[i].descripcion << ", Stock: " << agotados[i].stock << ", Precio: " << agotados[i].precio << endl;
        }
    }
};

int main() {
    Inventario inventario;

    // Agregar productos al inventario
    Producto papitas(1, "Bolsa de papitas", 10, 1.5);
    Producto piqueos(2, "Bolsa de piqueos", 5, 2.0);
    Producto cocaCola(3, "Botella de Coca Cola", 0, 3.0);

    inventario.agregarProducto(papitas);
    inventario.agregarProducto(piqueos);
    inventario.agregarProducto(cocaCola);

    // Actualizar el inventario
    inventario.actualizarInventario();

    // Mostrar productos disponibles y agotados
    inventario.mostrarDisponibles();
    inventario.mostrarAgotados();

    return 0;
}

    void mostrarDisponibles() {
        cout << "Productos disponibles:" << endl;
        for (const auto& prod : disponibles) {
            cout << "Código: " << prod.codigo << ", Descripción: " << prod.descripcion << ", Stock: " << prod.stock << ", Precio: " << prod.precio << endl;
        }
    }

    void mostrarAgotados() {
        cout << "Productos agotados:" << endl;
        for (const auto& prod : agotados) {
            cout << "Código: " << prod.codigo << ", Descripción: " << prod.descripcion << ", Stock: " << prod.stock << ", Precio: " << prod.precio << endl;
        }
    }
};

int main() {
    Inventario inventario;

    // Agregar productos al inventario
    Producto papitas(1, "Bolsa de papitas", 10, 1.5);
    Producto piqueos(2, "Bolsa de piqueos", 5, 2.0);
    Producto cocaCola(3, "Botella de Coca Cola", 0, 3.0);

    inventario.agregarProducto(papitas);
    inventario.agregarProducto(piqueos);
    inventario.agregarProducto(cocaCola);

    // Actualizar el inventario
    inventario.actualizarInventario();

    // Mostrar productos disponibles y agotados
    inventario.mostrarDisponibles();
    inventario.mostrarAgotados();

    return 0;
}
