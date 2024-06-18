#include <iostream>
using namespace std;

// Definición de la clase Ruta
template<typename T>
class Ruta {
private:
    string origen;
    string destino;
    T distancia;
    T tiempoEntrega;

public:
    Ruta(string origen = "", string destino = "", T distancia = 0, T tiempoEntrega = 0)
        : origen(origen), destino(destino), distancia(distancia), tiempoEntrega(tiempoEntrega) {}

    string getOrigen() const { return origen; }
    string getDestino() const { return destino; }
    T getDistancia() const { return distancia; }
    T getTiempoEntrega() const { return tiempoEntrega; }

    void mostrarRuta() const {
        cout << "Origen: " << origen << ", Destino: " << destino
             << ", Distancia: " << distancia << ", Tiempo de entrega: " << tiempoEntrega << endl;
    }
};

// Definición de la clase GestorRutas
template<typename T, int N>
class GestorRutas {
private:
    Ruta<T> rutas[N];
    int numRutas;

public:
    GestorRutas() : numRutas(0) {}

    void agregarRuta(const Ruta<T>& ruta) {
        if (numRutas < N) {
            rutas[numRutas++] = ruta;
        } else {
            cout << "Capacidad máxima de rutas alcanzada." << endl;
        }
    }

    void mostrarRutas() const {
        for (int i = 0; i < numRutas; ++i) {
            rutas[i].mostrarRuta();
        }
    }

    void optimizarRutas() {
        // Ordenamiento básico por tiempo de entrega (bubble sort)
        for (int i = 0; i < numRutas - 1; ++i) {
            for (int j = 0; j < numRutas - i - 1; ++j) {
                if (rutas[j].getTiempoEntrega() > rutas[j + 1].getTiempoEntrega()) {
                    // Intercambio de rutas
                    Ruta<T> temp = rutas[j];
                    rutas[j] = rutas[j + 1];
                    rutas[j + 1] = temp;
                }
            }
        }
    }
};

// Función de plantilla para ordenar y mostrar las rutas
template<typename T, int N>
void ordenarYMostrarRutas(GestorRutas<T, N>& gestor) {
    // Optimizar rutas antes de mostrarlas
    gestor.optimizarRutas();
    cout << "Rutas ordenadas por tiempo de entrega:" << endl;
    gestor.mostrarRutas();
}
int main() {
    // Crear algunas rutas de ejemplo
    Ruta<int> ruta1("cerro colorado", "sachaca", 500, 15);
    Ruta<int> ruta2("Joseluis Bustamante y Ribero", "tiabaya", 3000, 45);
    Ruta<int> ruta3("tiabaya", "Univeridad Catolica Santa Maria", 5000, 45);

    // Crear un gestor de rutas con capacidad para 10 rutas
    GestorRutas<int, 10> gestor;
    gestor.agregarRuta(ruta1);
    gestor.agregarRuta(ruta2);
    gestor.agregarRuta(ruta3);

    cout << "Rutas antes de optimizar:" << endl;
    gestor.mostrarRutas();

    // Llamar a la función de plantilla para ordenar y mostrar las rutas
    ordenarYMostrarRutas(gestor);

    return 0;
}
