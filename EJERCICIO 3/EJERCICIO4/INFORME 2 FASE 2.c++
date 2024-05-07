#include <iostream>
using namespace std;

class CuentaBancaria {
private:
  double saldo;
  static double tasaInteres; // Atributo estático para almacenar la tasa de interés

public:
  CuentaBancaria() {
    saldo = 0.0;
  }

  double getSaldo() {
    return saldo;
  }

  void deposito(double cantidad) {
    saldo += cantidad;
  }

  void retiro(double cantidad) {
    if (cantidad <= saldo) {
      saldo -= cantidad;
    } else {
      cout << "Saldo insuficiente" << endl;
    }
  }

  double calcularInteresGanado() {
    return saldo * tasaInteres;
  }

  static void setTasaInteres(double nuevaTasa) { // Método estático para cambiar la tasa de interés
    tasaInteres = nuevaTasa;
  }
};

double CuentaBancaria::tasaInteres = 0.05; // Inicialización del atributo estático

int main() {
  CuentaBancaria cuenta;
  cout << "Saldo inicial: " << cuenta.getSaldo() << endl;

  cuenta.deposito(100.0);
  cout << "Saldo después del depósito: " << cuenta.getSaldo() << endl;

  cuenta.retiro(50.0);
  cout << "Saldo después del retiro: " << cuenta.getSaldo() << endl;

  cuenta.retiro(200.0); // Esto dará como resultado un mensaje de saldo insuficiente
  cout << "Saldo final: " << cuenta.getSaldo() << endl;

  cuenta.setTasaInteres(0.1); // Cambiamos la tasa de interés a 10%
  double interesGanado = cuenta.calcularInteresGanado();
  cout << "Interés ganado: " << interesGanado << endl;

  return 0;
}




*************************************************************+EJERCICIO4******************************************************************



  #include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    Vector2D operator+(const Vector2D& other) const {
        double sumX = this->x + other.x;
        double sumY = this->y + other.y;
        return Vector2D(sumX, sumY);
    }

    Vector2D operator-(const Vector2D& other) const {
        double diffX = this->x - other.x;
        double diffY = this->y - other.y;
        return Vector2D(diffX, diffY);
    }
};

int main() {
    // Creando vectores
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    Vector2D sum = v1 + v2;
    cout << "Resultado de la suma: (" << sum.getX() << ", " << sum.getY() << ")\n";

    // Restando vectores
    Vector2D diff = v1 - v2;
    cout << "Resultado de la resta: (" << diff.getX() << ", " << diff.getY() << ")\n";

    return 0;
}
