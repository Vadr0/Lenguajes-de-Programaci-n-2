#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // Para usar stringstream

using namespace std;

class Producto {
protected:
    string nombre;
    double precio;
    int codigo;

public:
    Producto(string nombre, double precio, int codigo) : nombre(nombre), precio(precio), codigo(codigo) {}

    virtual ~Producto() {}

    virtual void mostrarDetalles() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Código: " << codigo << endl;
    }

    int obtenerCodigo() const {
        return codigo;
    }
};

class Libro : public Producto {
private:
    string autor;

public:
    Libro(string nombre, double precio, int codigo, string autor) : Producto(nombre, precio, codigo), autor(autor) {}

    void mostrarDetalles() const override {
        Producto::mostrarDetalles();
        cout << "Autor: " << autor << endl;
    }
};

class Electronico : public Producto {
private:
    string marca;

public:
    Electronico(string nombre, double precio, int codigo, string marca) : Producto(nombre, precio, codigo), marca(marca) {}

    void mostrarDetalles() const override {
        Producto::mostrarDetalles();
        cout << "Marca: " << marca << endl;
    }
};

class Ropa : public Producto {
private:
    string talla;

public:
    Ropa(string nombre, double precio, int codigo, string talla) : Producto(nombre, precio, codigo), talla(talla) {}

    void mostrarDetalles() const override {
        Producto::mostrarDetalles();
        cout << "Talla: " << talla << endl;
    }
};

class Comida : public Producto {
private:
    string fechaVencimiento;

public:
    Comida(string nombre, double precio, int codigo, string fechaVencimiento) : Producto(nombre, precio, codigo), fechaVencimiento(fechaVencimiento) {}

    void mostrarDetalles() const override {
        Producto::mostrarDetalles();
        cout << "Fecha de vencimiento: " << fechaVencimiento << endl;
    }
};

class Juguete : public Producto {
private:
    string material;

public:
    Juguete(string nombre, double precio, int codigo, string material) : Producto(nombre, precio, codigo), material(material) {}

    void mostrarDetalles() const override {
        Producto::mostrarDetalles();
        cout << "Material: " << material << endl;
    }
};

class Mueble : public Producto {
private:
    string material;

public:
    Mueble(string nombre, double precio, int codigo, string material) : Producto(nombre, precio, codigo), material(material) {}

    void mostrarDetalles() const override {
        Producto::mostrarDetalles();
        cout << "Material: " << material << endl;
    }
};

template <typename T>
class Inventario {
private:
    T** productos;
    int cantidad;
    int capacidad;

    void expandir() {
        capacidad *= 2;
        T** nuevosProductos = new T*[capacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevosProductos[i] = productos[i];
        }
        delete[] productos;
        productos = nuevosProductos;
    }

public:
    Inventario() : cantidad(0), capacidad(10) {
        productos = new T*[capacidad];
    }

    ~Inventario() {
        for (int i = 0; i < cantidad; i++) {
            delete productos[i];
        }
        delete[] productos;
    }

    void agregar(T* producto) {
        if (cantidad == capacidad) {
            expandir();
        }
        productos[cantidad++] = producto;

        // Construir la cadena de detalles del producto
        ostringstream detallesProducto;
        detallesProducto << "Agregado: " << producto->nombre << " - Código: " << producto->obtenerCodigo();

        // Registrar en archivo
        escribirArchivo("registro.txt", detallesProducto.str());
    }

    void eliminar(int codigo) {
        for (int i = 0; i < cantidad; i++) {
            if (productos[i]->obtenerCodigo() == codigo) {
                delete productos[i];
                for (int j = i; j < cantidad - 1; j++) {
                    productos[j] = productos[j + 1];
                }
                cantidad--;

                // Construir la cadena de detalles del producto eliminado
                ostringstream detallesProducto;
                detallesProducto << "Eliminado - Código: " << codigo;

                // Registrar en archivo
                escribirArchivo("registro.txt", detallesProducto.str());

                return;
            }
        }
        cout << "Producto no encontrado." << endl;
    }

    T* buscar(int codigo) const {
        for (int i = 0; i < cantidad; i++) {
            if (productos[i]->obtenerCodigo() == codigo) {
                return productos[i];
            }
        }
        return nullptr;
    }

    void listar() const {
        for (int i = 0; i < cantidad; i++) {
            productos[i]->mostrarDetalles();
            cout << endl;
        }

        // Registrar en archivo
        escribirArchivo("registro.txt", "Listado de productos");
    }

    void escribirArchivo(const string& nombreArchivo, const string& contenido) const {
        ofstream archivo(nombreArchivo, ios::app);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo.");
        }
        archivo << contenido << endl;
        archivo.close();
    }
};

bool validarEntero(const string &input, int &valor) {
    try {
        size_t index;
        valor = stoi(input, &index);
        return index == input.length();
    } catch (const invalid_argument &) {
        return false;
    } catch (const out_of_range &) {
        return false;
    }
}

bool validarDecimal(const string &input, double &valor) {
    try {
        size_t index;
        valor = stod(input, &index);
        return index == input.length();
    } catch (const invalid_argument &) {
        return false;
    } catch (const out_of_range &) {
        return false;
    }
}

bool validarOpcion(int &opcion) {
    string input;
    getline(cin, input);
    return validarEntero(input, opcion);
}

int main() {
    Inventario<Producto> inventario;

    int opcion;
    do {
        cout << "1. Agregar producto" << endl;
        cout << "2. Eliminar producto" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Listar productos" << endl;
        cout << "5. Salir" << endl;
        cout << "Opción: ";

        while (!validarOpcion(opcion)) {
            cout << "Opción no válida. Por favor ingrese un número." << endl;
            cout << "Opción: ";
        }

        switch (opcion) {
            case 1: {
                string nombre;
                string precioStr;
                string codigoStr;
                double precio;
                int codigo;
                cout << "Nombre: ";
                getline(cin, nombre);

                while (true) {
                    cout << "Precio: ";
                    getline(cin, precioStr);
                    if (validarDecimal(precioStr, precio)) {
                        break;
                    } else {
                        cout << "Precio no válido. Por favor ingrese un número." << endl;
                    }
                }

                while (true) {
                    cout << "Código: ";
                    getline(cin, codigoStr);
                    if (validarEntero(codigoStr, codigo)) {
                        break;
                    } else {
                        cout << "Código no válido. Por favor ingrese un número entero." << endl;
                    }
                }

                int tipo;
                cout << "Tipo de producto (1. Libro, 2. Electrónico, 3. Ropa, 4. Comida, 5. Juguete, 6. Mueble): ";
                while (!validarOpcion(tipo) || tipo < 1 || tipo > 6) {
                    cout << "Tipo de producto no válido. Por favor ingrese un número entre 1 y 6." << endl;
                    cout << "Tipo de producto (1. Libro, 2. Electrónico, 3. Ropa, 4. Comida, 5. Juguete, 6. Mueble): ";
                }

                switch (tipo) {
                    case 1: {
                        string autor;
                        cout << "Autor: ";
                        getline(cin, autor);
                        inventario.agregar(new Libro(nombre, precio, codigo, autor));
                        break;
                    }
                    case 2: {
                        string marca;
                        cout << "Marca: ";
                        getline(cin, marca);
                        inventario.agregar(new Electronico(nombre, precio, codigo, marca));
                        break;
                    }
                    case 3: {
                        string talla;
                        cout << "Talla: ";
                        getline(cin, talla);
                        inventario.agregar(new Ropa(nombre, precio, codigo, talla));
                        break;
                    }
                    case 4: {
                        string fechaVencimiento;
                        cout << "Fecha de vencimiento: ";
                        getline(cin, fechaVencimiento);
                        inventario.agregar(new Comida(nombre, precio, codigo, fechaVencimiento));
                        break;
                    }
                    case 5: {
                        string material;
                        cout << "Material: ";
                        getline(cin, material);
                        inventario.agregar(new Juguete(nombre, precio, codigo, material));
                        break;
                    }
                    case 6: {
                        string material;
                        cout << "Material: ";
                        getline(cin, material);
                        inventario.agregar(new Mueble(nombre, precio, codigo, material));
                        break;
                    }
                }
                break;
            }
            case 2: {
                int codigo;
                cout << "Código del producto a eliminar: ";
                while (!validarOpcion(codigo)) {
                    cout << "Código no válido. Por favor ingrese un número entero." << endl;
                    cout << "Código del producto a eliminar: ";
                }
                inventario.eliminar(codigo);
                break;
            }
            case 3: {
                int codigo;
                cout << "Código del producto a buscar: ";
                while (!validarOpcion(codigo)) {
                    cout << "Código no válido. Por favor ingrese un número entero." << endl;
                    cout << "Código del producto a buscar: ";
                }
                Producto* producto = inventario.buscar(codigo);
                if (producto != nullptr) {
                    producto->mostrarDetalles();
                } else {
                    cout << "Producto no encontrado" << endl;
                }
                break;
            }
            case 4:
                inventario.listar();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
