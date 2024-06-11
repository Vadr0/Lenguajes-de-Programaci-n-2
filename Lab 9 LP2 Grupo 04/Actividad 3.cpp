#include <iostream>
using namespace std;

class Figura {      // Clase base Figura con método virtual calcularArea()
public:
    virtual double calcularArea() {
        return 0;
    }
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return 3.1416 *radio* radio;
    }
};
class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double b) : ancho(a), alto(b) {}
    double calcularArea() override {
        return ancho * alto;
    }
};
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return (base * altura) / 2;
    }
};

int main() {
    Figura* figuras[3];                 // Crear objetos de diferentes tipos de figuras
    figuras[0] = new Circulo(5);
    figuras[1] = new Rectangulo(4, 6);
    figuras[2] = new Triangulo(3, 7);

    for (int i = 0; i < 3; ++i) {
        cout << "El área de la figura es: " << figuras[i]->calcularArea() << endl;
    }

    for (int i = 0; i < 3; ++i) {   // Liberar memoria
        delete figuras[i];
    }

    return 0;
}
