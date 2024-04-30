#include <iostream>
#include <string>
#include "auto.cpp"
using namespace std;

int main() {
string marca;
    int marcaOption;

    cout << "Bienvenido a la Venta de Carros. Por favor, ingrese los datos del carro:" << endl;

    cout << "Marca: " << endl;
    cout << "1. Toyota" <<endl;
    cout << "2. Ford" <<endl;
    cout << "3. Hyundai" <<endl;
    cout << "Ingrese el número correspondiente a la marca: ";
    cin >> marcaOption;

    switch (marcaOption) {
        case 1:
            marca = "Toyota";
            break;
        case 2:
            marca = "Ford";
            break;
        case 3:
            marca = "Hyundai";
            break;
        default:
            cout << "Opción inválida. Se utilizará el modelo por defecto." << endl;
            marca = "Desconocido";
            break;
    }

    std::string modelo;
    int modeloOption;
    float precioBase = 25000.0;

    cout << "Modelo: " << endl;
    cout << "1. 2020" << endl;
    cout << "2. 2022" << endl;
    cout << "3. 2023" << endl;
    cout << "4. 2024" << endl;
    cout << "Ingrese el número correspondiente al modelo: ";
    cin >> modeloOption;

    switch (modeloOption) {
        case 1:
            modelo = "2020";
            break;
        case 2:
            modelo = "2022";
            precioBase *= 1.05; // Incremento del 5% en el precio
            break;
        case 3:
            modelo = "2023";
            precioBase *= 1.1; // Incremento del 10% en el precio
            break;
        case 4:
            modelo = "2024";
            precioBase *= 1.15; // Incremento del 15% en el precio
            break;
        default:
            std::cout << "Opción inválida. Se utilizará el modelo por defecto." << endl;
            modelo = "Desconocido";
            break;
    }

    cout << "Por favor, tenga en cuenta que el precio base del carro puede aumentar dependiendo del modelo seleccionado. El precio base actual es: $" << precioBase << endl;

    int opcion;
    do {
        cout << "¿Desea pagar el carro al contado o a cuotas? (1: Contado / 2: Cuotas): ";
        cin >> opcion;
    } while (opcion != 1 && opcion != 2);

    if (opcion == 1) {
        Carro carro(marca, modelo, precioBase);
        cout << "¡Datos ingresados correctamente!" << endl;
        carro.mostrarDatos();
        carro.venderAlContado();
    } else {
        float inicial;
        cout << "Ingrese el monto inicial a pagar: $";
        cin >> inicial;

        int plazo;
        cout << "¿A cuántos meses desea pagar? (6 / 12 / 24): ";
        cin >> plazo;

        Carro carro(marca, modelo);
        carro.setPrecio(precioBase);
        carro.venderACuotas(inicial, plazo);
    }

    return 0;
}