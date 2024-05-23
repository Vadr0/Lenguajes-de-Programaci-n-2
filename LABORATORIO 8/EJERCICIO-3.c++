#include <iostream>
using namespace std;

class Empleado {
public:
    virtual double calcularSalario() = 0;  // Método puro virtual
};

class EmpleadoTiempoCompleto : public Empleado {
public:
    EmpleadoTiempoCompleto(double salarioMensual) : _salarioMensual(salarioMensual) {}

    double calcularSalario() override {
        return _salarioMensual;
    }

private:
    double _salarioMensual;
};

class EmpleadoMedioTiempo : public Empleado {
public:
    EmpleadoMedioTiempo(double tarifaPorHora, int horasTrabajadas)
        : _tarifaPorHora(tarifaPorHora), _horasTrabajadas(horasTrabajadas) {}

    double calcularSalario() override {
        return _tarifaPorHora * _horasTrabajadas;
    }

private:
    double _tarifaPorHora;
    int _horasTrabajadas;
};

int main() {
    EmpleadoTiempoCompleto empleado1(5000.0);
    EmpleadoMedioTiempo empleado2(20.0, 80);

    cout << "Salario del empleado a tiempo completo: " << empleado1.calcularSalario() << endl;
    cout << "Salario del empleado a medio tiempo: " << empleado2.calcularSalario() << endl;

    return 0;
}