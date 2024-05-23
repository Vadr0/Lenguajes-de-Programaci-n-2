#include <iostream>
#include <string>
using namespace std;

class Forma {
public:
    virtual double calcularPerimetro() = 0;
    virtual ~Forma() {} // Agregar un destructor virtual
};

// Resto del código sin cambios


class Circulo : public Forma {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    double calcularPerimetro() override {
        return 2 * 3.1416 * radio;
    }
};

class Rectangulo : public Forma {
private:
    double largo;
    double ancho;

public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {}

    double calcularPerimetro() override {
        return 2 * (largo + ancho);
    }
};

class Triangulo : public Forma {
private:
    double lado1;
    double lado2;
    double lado3;

public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}

    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }
};

int main() {
    int opcion;
    double radio, largo, ancho, lado1, lado2, lado3;

    Forma* ptrForma = nullptr;

    do {
        cout << "Selecciona una forma:" << endl;
        cout << "1. Circulo" << endl;
        cout << "2. Rectangulo" << endl;
        cout << "3. Triangulo" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el radio del circulo: ";
                cin >> radio;
                ptrForma = new Circulo(radio);
                break;
            case 2:
                cout << "Ingresa el largo del rectangulo: ";
                cin >> largo;
                cout << "Ingresa el ancho del rectangulo: ";
                cin >> ancho;
                ptrForma = new Rectangulo(largo, ancho);
                break;
            case 3:
                cout << "Ingresa el lado 1 del triangulo: ";
                cin >> lado1;
                cout << "Ingresa el lado 2 del triangulo: ";
                cin >> lado2;
                cout << "Ingresa el lado 3 del triangulo: ";
                cin >> lado3;
                ptrForma = new Triangulo(lado1, lado2, lado3);
                break;
            default:
                cout << "Opcion no valida. Por favor, selecciona una opcion valida." << endl;
                break;
        }
    } while (ptrForma == nullptr); // Repetir hasta que se seleccione una opción válida

    double perimetro = ptrForma->calcularPerimetro();

    cout << "El perimetro de la forma seleccionada es: " << perimetro << endl;

    delete ptrForma;

    return 0;
}