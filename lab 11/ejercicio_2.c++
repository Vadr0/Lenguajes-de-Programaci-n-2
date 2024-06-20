#include <iostream>

using namespace std;


double divide(int num1, int num2) {
    if (num2 == 0) {
        throw runtime_error("No se puede dividir por cero");
    }
    return static_cast<double>(num1) / num2;
}


int main() {
    try {
        int num1, num2;
        cout << "Ingrese el primer número: ";
        cin >> num1;
        cout << "Ingrese el segundo número: ";
        cin >> num2;


        double resultado = divide(num1, num2);
        cout << "El resultado de la división es: " << resultado << endl;
    } catch (const runtime_error& e) {
        cout << "Se produjo una excepción: " << e.what() << endl;
    }


    return 0;
}
