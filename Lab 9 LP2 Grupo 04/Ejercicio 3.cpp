#include <iostream>

using namespace std;

// Clase base Empleado
class Empleado {
public:
    virtual double calcularSalario() const = 0; // Método virtual puro
    virtual ~Empleado() {} // Destructor virtual
};

class EmpleadoAsalariado : public Empleado {
private:
    double salarioSemanal;
public:
    EmpleadoAsalariado(double salario) : salarioSemanal(salario) {}
    double calcularSalario() const override {
        return salarioSemanal;
    }
};

class EmpleadoPorHora : public Empleado {
private:
    double salarioPorHora;
    int horasTrabajadas;
public:
    EmpleadoPorHora(double salario, int horas) : salarioPorHora(salario), horasTrabajadas(horas) {}
    double calcularSalario() const override {
        return horasTrabajadas * salarioPorHora;
    }
};

class EmpleadoComisionista : public Empleado {
private:
    double ventasTotales;
    double tasaComision;
public:
    EmpleadoComisionista(double ventas, double tasa) : ventasTotales(ventas), tasaComision(tasa) {}
    double calcularSalario() const override {
        return ventasTotales * tasaComision;
    }
};

int main() {
    Empleado* vector[3];   // Crear un arreglo de punteros a Empleados
    vector[0] = new EmpleadoAsalariado(1000.0);   // Agregar empleados al arreglo
    vector[1] = new EmpleadoPorHora(20.0, 40);
    vector[2] = new EmpleadoComisionista(5000.0, 0.1);
    for (int i = 0; i < 3; ++i) {    // Calcular y mostrar los salarios
        cout << "Salario: " << vector[i]->calcularSalario() << endl;
    }
    for (int i = 0; i < 3; ++i) {   // Liberar la memoria
        delete vector[i];
    }

    return 0;
}
