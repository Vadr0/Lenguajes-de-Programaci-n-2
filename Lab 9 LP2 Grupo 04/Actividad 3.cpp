#include <iostream>

using namespace std;

class Calculadora {
public:
    int sumar(int a, int b) {   // Suma de dos enteros
        return a + b;
    }
    double sumar(double a, double b) {  // Suma de dos números de punto flotante
        return a + b;
    }
    int sumar(int a, int b, int c) {        // Suma de tres enteros
        return a + b + c;
    }
};

int main() {
    Calculadora calc;
    int resultado1 = calc.sumar(3, 4);
    cout << "Suma de 3 y 4 (int): " << resultado1 << endl;
    double resultado2 = calc.sumar(2.5, 3.5);
    cout << "Suma de 2.5 y 3.5 (double): " << resultado2 << endl;
    int resultado3 = calc.sumar(1, 2, 3);
    cout << "Suma de 1, 2 y 3 (int): " << resultado3 << endl;
    return 0;
}
