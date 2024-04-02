#include <iostream>
#include <vector>
#include <algorithm> // Necesario para remover o añadir
using namespace std;

class Producto {
public:
    string nombre;
    int cantidad;
    Producto(string nombre, int cantidad) : nombre(nombre), cantidad(cantidad) {}
};

class Inventario {

private:
    vector<Producto> disponibles;
    vector<Producto> agotados;

public:
    void agregarProducto(string nombre, int cantidad) {
        Producto nuevoProducto(nombre, cantidad);
        disponibles.push_back(nuevoProducto);
    }

    void actualizarInventario() {
        agotados.clear(); // Clear para eliminar prodcutos ya comprados

        // Mover productos que estaban disponibles a agotados
        for (auto it = disponibles.begin(); it != disponibles.end(); ) {
            if (it->cantidad <= 0) {
                agotados.push_back(*it);
                it = disponibles.erase(it); // Eliminar el producto de disponibles
            } else {
                ++it;
            }
        }
    }

    void mostrarInventario() {
        cout << "Productos disponibles:\n";
        for (const auto& producto : disponibles) {
            cout << producto.nombre << ": " << producto.cantidad << " unidades\n";
        }

        cout << "\nProductos agotados:\n";
        for (const auto& producto : agotados) {
            cout << producto.nombre << "\n";
        }
    }
};

int main() {
    Inventario inventario;

    // Agregar algunos productos al inventario
    inventario.agregarProducto("Producto A", 10);
    inventario.agregarProducto("Producto B", 5);
    inventario.agregarProducto("Producto C", 0);
    inventario.agregarProducto("Producto D", -3);

    // Actualizar el inventario para reflejar los productos agotados
    inventario.actualizarInventario();

    // Mostrar el inventario actualizado
    inventario.mostrarInventario();

    return 0;
}
