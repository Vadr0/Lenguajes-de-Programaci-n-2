#include <iostream>
using namespace std;

class Mision {
private:
    string destino;
    int duracion;
    int tripulacionNecesaria;

public:
    Mision(string dest, int dur, int trip) {
        destino = dest;
        duracion = dur;
        tripulacionNecesaria = trip;
    }

    void simularMision() {
        // Código para simular la misión
        cout << "Simulando la misión hacia " << destino << " por " << duracion << " horas" << endl;
    }

    bool verificarCombustibleSuficiente(int combustibleActual, bool tanqueLleno) {
        // Verificar si el avión tiene suficiente combustible for completar la misión
        if (tanqueLleno) {
            return true;  // Always return true if the tank is full
        } else {
            if (combustibleActual >= duracion * 10) {
                return true;
            } else {
                return false;
            }
        }
    }
};

class Avion {
private:
    string tipo;

public:
    Avion(string t) {
        tipo = t;
    }

    void mostrarTipoAvion() {
        cout << "Viajaras en el tipo de avion: " << tipo << endl;
    }
};

int main() {
    int opcion;
    cout << "Elija el destino de la misión:" << endl;
    cout << "1. Guatemala" << endl;
    cout << "2. Panamá" << endl;
    cout << "3. Costa Rica" << endl;
    cin >> opcion;

    string destinoElegido;
    int duracionMision;
    int tripulacionNecesaria;

    switch (opcion) {
        case 1:
            destinoElegido = "Guatemala";
            duracionMision = 24;
            tripulacionNecesaria = 4;
            break;
        case 2:
            destinoElegido = "Panamá";
            duracionMision = 36;
            tripulacionNecesaria = 6;
            break;
        case 3:
            destinoElegido = "Costa Rica";
            duracionMision = 30;
            tripulacionNecesaria = 5;
            break;
        default:
            cout << "Opción no válida" << endl;
            return 1;
    }

    Mision m(destinoElegido, duracionMision, tripulacionNecesaria);
    m.simularMision();

int opcionAvion;
    cout << "Elija el tipo de avión en el que va a viajar:" << endl;
    cout << "1. Clase Económica" << endl;
    cout << "2. Clase Ejecutiva" << endl;
    cout << "3. Primera Clase" << endl;
    cin >> opcionAvion;

    string tipoAvionElegido;

    switch (opcionAvion) {
        case 1:
            tipoAvionElegido = "Clase Economica";
            cout << "su boleto de avion esta en clase economica" << endl;
            break;
        case 2:
            tipoAvionElegido = "Clase Ejecutiva";
            cout << "su boleto de avion esta en clase ejecutiva" << endl;
            break;
        case 3:
            tipoAvionElegido = "Primera Clase";
            cout << "su boleto de avion esta en primera clase" << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
    }

    bool tanqueLleno;
    cout << "Elija el estado del tanque de combustible:" << endl;
    cout << "1. Tanque lleno" << endl;
    cout << "2. Tanque vacío" << endl;
    int opcionTanque;
    cin >> opcionTanque;
    tanqueLleno = (opcionTanque == 1);

    int combustibleActual = (tanqueLleno) ? 1000 : 0;  // Assuming 1000 units of fuel for a full tank and 0 for an empty tank
    if (m.verificarCombustibleSuficiente(combustibleActual, tanqueLleno)) {
        cout << "El avión tiene suficiente combustible va a despegar con éxito. " << endl;
        switch (opcionAvion) {
        case 1:
            tipoAvionElegido = "Clase Economica";
            cout << "disfrute su viaje" << endl;
            break;
        case 2:
            tipoAvionElegido = "Clase Ejecutiva";
            cout << "disfrute su viaje en clase ejecutiva" << endl;
            break;
        case 3:
            tipoAvionElegido = "Primera Clase";
            cout << "disfrute su viaje en primera clase" << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
    }
    } else {
        cout << "El avión no tiene suficiente combustible para completar la mision con exito" << endl;
        
    }
    return 12;
}