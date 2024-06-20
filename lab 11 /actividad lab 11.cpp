#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string nombre = "", double precio = 0.0, int cantidad = 0)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    string getNombre() const {
        return nombre;
    }

    double getPrecio() const {
        return precio;
    }

    int getCantidad() const {
        return cantidad;
    }

    void setPrecio(double nuevoPrecio) {
        precio = nuevoPrecio;
    }

    void setCantidad(int nuevaCantidad) {
        cantidad = nuevaCantidad;
    }

    void vender(int cantidadVendida) {
        if (cantidadVendida <= cantidad) {
            cantidad -= cantidadVendida;
        } else {
            throw runtime_error("Cantidad insuficiente en inventario.");
        }
    }

    void mostrarProducto() const {
        cout << "Nombre: " << nombre << ", Precio: " << precio << ", Cantidad: " << cantidad << endl;
    }

    void guardarProducto(ofstream &archivo) const {
        archivo << nombre << ' ' << precio << ' ' << cantidad << endl;
    }

    void cargarProducto(ifstream &archivo) {
        archivo >> nombre >> precio >> cantidad;
    }
};

class Inventario {
private:
    static const int MAX_PRODUCTOS = 100;
    Producto productos[MAX_PRODUCTOS];
    int numProductos;

public:
    Inventario() : numProductos(0) {
        cargarInventario();
    }

    void agregarProducto(const Producto& producto) {
        if (numProductos < MAX_PRODUCTOS) {
            productos[numProductos++] = producto;
            guardarInventario();
        } else {
            throw runtime_error("Inventario lleno.");
        }
    }

    void actualizarProducto(const string& nombre, double nuevoPrecio, int nuevaCantidad) {
        for (int i = 0; i < numProductos; ++i) {
            if (productos[i].getNombre() == nombre) {
                productos[i].setPrecio(nuevoPrecio);
                productos[i].setCantidad(nuevaCantidad);
                guardarInventario();
                return;
            }
        }
        throw runtime_error("Producto no encontrado.");
    }

    void venderProducto(const string& nombre, int cantidadVendida) {
        for (int i = 0; i < numProductos; ++i) {
            if (productos[i].getNombre() == nombre) {
                productos[i].vender(cantidadVendida);
                guardarInventario();
                return;
            }
        }
        throw runtime_error("Producto no encontrado.");
    }

    void generarInforme() const {
        cout << "Informe de inventario:" << endl;
        for (int i = 0; i < numProductos; ++i) {
            productos[i].mostrarProducto();
        }
    }

    void guardarInventario() const {
        ofstream archivo("inventario.txt");
        for (int i = 0; i < numProductos; ++i) {
            productos[i].guardarProducto(archivo);
        }
        archivo.close();
    }

    void cargarInventario() {
        ifstream archivo("inventario.txt");
        numProductos = 0;
        while (archivo && numProductos < MAX_PRODUCTOS) {
            Producto producto;
            producto.cargarProducto(archivo);
            if (archivo) {
                productos[numProductos++] = producto;
            }
        }
        archivo.close();
    }

    Producto buscarProducto(const string& nombre) const {
        for (int i = 0; i < numProductos; ++i) {
            if (productos[i].getNombre() == nombre) {
                return productos[i];
            }
        }
        throw runtime_error("Producto no encontrado.");
    }
};

int main() {
    Inventario inventario;

    try {
        // Agregar productos
        inventario.agregarProducto(Producto("Laptop", 1500.0, 10));
        inventario.agregarProducto(Producto("Mouse", 25.0, 50));

        // Actualizar un producto
        inventario.actualizarProducto("Laptop", 1450.0, 8);

        // Vender un producto
        inventario.venderProducto("Mouse", 5);

        // Generar informe
        inventario.generarInforme();

        // Buscar un producto
        Producto p = inventario.buscarProducto("Laptop");
        p.mostrarProducto();

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
