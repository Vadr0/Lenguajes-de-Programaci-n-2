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

EN PYTHON:

class Producto:
    def __init__(self, codigo, descripcion, stock, precio):
        self.codigo = codigo
        self.descripcion = descripcion
        self.stock = stock
        self.precio = precio

class Inventario:
    MAX_PRODUCTOS = 100

    def __init__(self):
        self.disponibles = []
        self.agotados = []

    def agregar_producto(self, producto):
        if len(self.disponibles) < self.MAX_PRODUCTOS:
            self.disponibles.append(producto)
        else:
            print("No se puede agregar más productos, el inventario está lleno.")

    def actualizar_inventario(self):
        for producto in self.disponibles[:]:
            if producto.stock == 0:
                self.agotados.append(producto)
                self.disponibles.remove(producto)

    def mostrar_disponibles(self):
        print("Productos disponibles:")
        for producto in self.disponibles:
            print("Código:", producto.codigo, ", Descripción:", producto.descripcion, ", Stock:", producto.stock, ", Precio:", producto.precio)

    def mostrar_agotados(self):
        print("Productos agotados:")
        for producto in self.agotados:
            print("Código:", producto.codigo, ", Descripción:", producto.descripcion, ", Stock:", producto.stock, ", Precio:", producto.precio)

if __name__ == "__main__":
    inventario = Inventario()

    # Agregar productos al inventario
    papitas = Producto(1, "Bolsa de papitas", 10, 1.5)
    piqueos = Producto(2, "Bolsa de piqueos", 5, 2.0)
    coca_cola = Producto(3, "Botella de Coca Cola", 0, 3.0)

    inventario.agregar_producto(papitas)
    inventario.agregar_producto(piqueos)
    inventario.agregar_producto(coca_cola)

    # Actualizar el inventario
    inventario.actualizar_inventario()

    # Mostrar productos disponibles y agotados
    inventario.mostrar_disponibles()
    inventario.mostrar_agotados()

    
EN JAVA:

import java.util.ArrayList;

class Producto {
    int codigo;
    String descripcion;
    int stock;
    float precio;

    Producto(int cod, String desc, int stk, float prc) {
        codigo = cod;
        descripcion = desc;
        stock = stk;
        precio = prc;
    }
}

class Inventario {
    private static final int MAX_PRODUCTOS = 100;
    private ArrayList<Producto> disponibles;
    private ArrayList<Producto> agotados;

    Inventario() {
        disponibles = new ArrayList<>();
        agotados = new ArrayList<>();
    }

    void agregarProducto(Producto prod) {
        if (disponibles.size() < MAX_PRODUCTOS) {
            disponibles.add(prod);
        } else {
            System.out.println("No se puede agregar más productos, el inventario está lleno.");
        }
    }

    void actualizarInventario() {
        for (Producto prod : disponibles) {
            if (prod.stock == 0) {
                agotados.add(prod);
            }
        }
        disponibles.removeAll(agotados);
    }

    void mostrarDisponibles() {
        System.out.println("Productos disponibles:");
        for (Producto prod : disponibles) {
            System.out.println("Código: " + prod.codigo + ", Descripción: " + prod.descripcion + ", Stock: " + prod.stock + ", Precio: " + prod.precio);
        }
    }

    void mostrarAgotados() {
        System.out.println("Productos agotados:");
        for (Producto prod : agotados) {
            System.out.println("Código: " + prod.codigo + ", Descripción: " + prod.descripcion + ", Stock: " + prod.stock + ", Precio: " + prod.precio);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Inventario inventario = new Inventario();

        // Agregar productos al inventario
        Producto papitas = new Producto(1, "Bolsa de papitas", 10, 1.5f);
        Producto piqueos = new Producto(2, "Bolsa de piqueos", 5, 2.0f);
        Producto cocaCola = new Producto(3, "Botella de Coca Cola", 0, 3.0f);

        inventario.agregarProducto(papitas);
        inventario.agregarProducto(piqueos);
        inventario.agregarProducto(cocaCola);

        // Actualizar el inventario
        inventario.actualizarInventario();

        // Mostrar productos disponibles y agotados
        inventario.mostrarDisponibles();
        inventario.mostrarAgotados();
    }
}
