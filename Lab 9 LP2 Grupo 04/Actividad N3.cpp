#include <iostream>

using namespace std;

class Calculadora {
public:
    // Suma de dos enteros
    int sumar(int a, int b) {
        return a + b;
    }

    // Suma de dos números de punto flotante
    double sumar(double a, double b) {
        return a + b;
    }

    // Suma de tres enteros
    int sumar(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculadora calc;

    // Llamada al método sumar(int, int)
    int resultado1 = calc.sumar(3, 4);
    cout << "Suma de 3 y 4 (int): " << resultado1 << endl;

    // Llamada al método sumar(double, double)
    double resultado2 = calc.sumar(2.5, 3.5);
    cout << "Suma de 2.5 y 3.5 (double): " << resultado2 << endl;

    // Llamada al método sumar(int, int, int)
    int resultado3 = calc.sumar(1, 2, 3);
    cout << "Suma de 1, 2 y 3 (int): " << resultado3 << endl;

    return 0;
}
