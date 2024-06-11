#include <iostream>
#include <string>

using namespace std;

class Producto {
protected:
    string nombre;
    float precio;
    int codigo;

public:
    Producto(string nombre, float precio, int codigo)
        : nombre(nombre), precio(precio), codigo(codigo) {}

    virtual void mostrarDetalles() const = 0;  // Método virtual puro
    virtual void aplicarDescuento(float porcentaje) = 0;  // Nuevo método virtual puro

    virtual ~Producto() {}
};

class Libro : public Producto {
private:
    string autor;
    int paginas;

public:
    Libro( string nombre, float precio, int codigo,string autor, int paginas)
        : Producto(nombre, precio, codigo), autor(autor), paginas(paginas) {}

    void mostrarDetalles() const override {
        cout << "Libro:\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Precio: " << precio << "\n";
        cout << "Código: " << codigo << "\n";
        cout << "Autor: " << autor << "\n";
        cout << "Páginas: " << paginas << "\n";
    }

    void aplicarDescuento(float porcentaje) override {
        precio -= precio * (porcentaje / 100);
    }
};

class Electronico : public Producto {
private:
    int garantia;

public:
    Electronico(string nombre, float precio, int codigo, int garantia)
        : Producto(nombre, precio, codigo), garantia(garantia) {}

    void mostrarDetalles() const override {
        cout << "Electrónico:\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Precio: " << precio << "\n";
        cout << "Código: " << codigo << "\n";
        cout << "Garantía: " << garantia << " años\n";
    }

    void aplicarDescuento(float porcentaje) override {
        precio -= precio * (porcentaje / 100);
    }
};

class Ropa : public Producto {
private:
    string talla;

public:
    Ropa(string nombre, float precio, int codigo, string talla)
        : Producto(nombre, precio, codigo), talla(talla) {}

    void mostrarDetalles() const override {
        cout << "Ropa:\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Precio: " << precio << "\n";
        cout << "Código: " << codigo << "\n";
        cout << "Talla: " << talla << "\n";
    }

    void aplicarDescuento(float porcentaje) override {
        precio -= precio * (porcentaje / 100);
    }
};

class Comida : public Producto {
private:
    string fechaExpiracion;

public:
    Comida(string nombre, float precio, int codigo, string fechaExpiracion)
        : Producto(nombre, precio, codigo), fechaExpiracion(fechaExpiracion) {}

    void mostrarDetalles() const override {
        cout << "Comida:\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Precio: " << precio << "\n";
        cout << "Código: " << codigo << "\n";
        cout << "Fecha de Expiración: " << fechaExpiracion << "\n";
    }

    void aplicarDescuento(float porcentaje) override {
        precio -= precio * (porcentaje / 100);
    }
};

class Juguete : public Producto {
private:
    int edadRecomendada;

public:
    Juguete(string nombre, float precio, int codigo, int edadRecomendada)
        : Producto(nombre, precio, codigo), edadRecomendada(edadRecomendada) {}

    void mostrarDetalles() const override {
        cout << "Juguete:\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Precio: " << precio << "\n";
        cout << "Código: " << codigo << "\n";
        cout << "Edad Recomendada: " << edadRecomendada << " años\n";
    }

    void aplicarDescuento(float porcentaje) override {
        precio -= precio * (porcentaje / 100);
    }
};

class Mueble : public Producto {
private:
    string material;

public:
    Mueble(string nombre, float precio, int codigo,  string material)
        : Producto(nombre, precio, codigo), material(material) {}

    void mostrarDetalles() const override {
        cout << "Mueble:\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Precio: " << precio << "\n";
        cout << "Código: " << codigo << "\n";
        cout << "Material: " << material << "\n";
    }

    void aplicarDescuento(float porcentaje) override {
        precio -= precio * (porcentaje / 100);
    }
};

int main() {
    const int numProductos = 6;
    Producto* productos[numProductos];

    productos[0] = new Libro("El Padrino", 15.99, 1001, "Mario Puzo", 608);
    productos[1] = new Electronico("Celular", 1199.99, 1002, 2);
    productos[2] = new Ropa("Polo", 19.99, 1003, "L");
    productos[3] = new Comida("Pan", 1.99, 1004, "01-01-2025");
    productos[4] = new Juguete("Lego", 49.99, 1005, 6);
    productos[5] = new Mueble("Mesa", 129.99, 1006, "Madera");

    cout<<"ingrese que producto deseaa ver :"<<endl;
    cout<<"1.-Libro :"<<endl;
    cout<<"2.-Electronico :"<<endl;
    cout<<"3.-Ropa :"<<endl;
    cout<<"4.-Comida:"<<endl;
    cout<<"5.-Juguete:"<<endl;
    cout<<"6.-Mueble:"<<endl;
    int pro;
    cin>>pro;
    switch (pro) {
        case 1:
            productos[0]->mostrarDetalles();
            cout << "\n";
            break;
        case 2:
            productos[1]->mostrarDetalles();
            cout << "\n";
            break;
        case 3:
            productos[2]->mostrarDetalles();
            cout << "\n";
            break;
        case 4:
            productos[3]->mostrarDetalles();
            cout << "\n";
            break;
        case 5:
            productos[4]->mostrarDetalles();
            cout << "\n";
            break;
        case 6:
            productos[5]->mostrarDetalles();
            cout << "\n";
            break;
        default:
            cout << "ingrese un producto valido" << endl;
            break;
    }
    cout<<"desea agregar descuento?:"<<endl;
    cout<<"1.-si:"<<endl;
    cout<<"2.-no"<<endl;
    int des;
    cin>>des;
    switch (des) {
        case 1:
            switch (pro) {
            case 1:
                productos[0]->aplicarDescuento(10);
                productos[0]->mostrarDetalles();
                cout << "\n";
                break;
            case 2:
                productos[1]->aplicarDescuento(10);
                productos[1]->mostrarDetalles();
                cout << "\n";
                break;
            case 3:
                productos[2]->aplicarDescuento(10);
                productos[2]->mostrarDetalles();
                cout << "\n";
                break;
            case 4:
                productos[3]->aplicarDescuento(10);
                productos[3]->mostrarDetalles();
                cout << "\n";
                break;
            case 5:
                productos[4]->aplicarDescuento(10);
                productos[4]->mostrarDetalles();
                cout << "\n";
                break;
            case 6:
                productos[5]->aplicarDescuento(10);
                productos[5]->mostrarDetalles();
                cout << "\n";
                break;
            default:
                cout << "ingrese un producto valido" << endl;
                break;
            }
            break;
        case 2:
            break;
        default:
            cout << "ingrese si o no" << endl;
            break;
    }

    for (int i = 0; i < numProductos; ++i) {     // Liberar memoria
        delete productos[i];
    }
    return 0;
}
