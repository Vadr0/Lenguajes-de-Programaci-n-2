#include <iostream>
using namespace std;

class Auto {
private:
    const char* tipoAuto;

public:
    Auto(const char* tipo) {
        tipoAuto = tipo;
    }

    void mostrarInformacion() {
        cout << "tipo de auto: " << tipoAuto << endl;
    }
};

class Carrera {
private:
    int distanciaTotal;
    int dificultadOponente;

public:
    Carrera(int distancia, int dificultad) {
        while (distancia < 5000 || distancia > 6000) {
            cout << "¡Solo puedes elegir 5000m a 6000m para la distancia!" << endl;
            cout << "Elige la distancia de la carrera (5000m a 6000m) --> :" <<distancia<<endl; 

        }
        distanciaTotal = distancia;

        if (dificultad >= 1 && dificultad <= 3) { 
            dificultadOponente = dificultad;
        } else if (dificultad >= 4 && dificultad <= 7) {
            dificultadOponente = dificultad;
        } else if (dificultad >= 8 && dificultad <= 10) {
            dificultadOponente = dificultad;
            if (dificultadOponente >= 5 && dificultadOponente <= 10) {
                cout << "acabas de perder :( La dificultad seleccionada es demasiado alta " << endl;
                return; // terminamos la creación de la instancia
            }
        } else {
            cout << "¡Solo puedes elegir 1, 2 o 3 para fácil, 4, 5, 6 o 7 para medio, y 8, 9 o 10 para difícil!" << endl;
            dificultadOponente = 1; // establecemos un valor predeterminado
        }
    }

    void competir() { 
        cout << "¡Comienza la carrera de " << distanciaTotal << " metros con dificultad " << dificultadOponente << "!" <<endl;

        if (dificultadOponente < 5) {
            cout << "VAMOOOOS. Has ganado la carrera " << endl;
            return; // Termina la competencia
        }

    }
};

int main() {
    int distancia;
    int dificultad;
    int tipoSeleccionado;

    cout << "Elige el tipo de auto:" << endl;
    cout << "1. bocho" << endl;
    cout << "2. rayo macuin" << endl;
    cout << "3. tico" << endl;
    cin >> tipoSeleccionado;

    const char* tipoAutoSeleccionado = "";
    switch (tipoSeleccionado) {
        case 1:
            tipoAutoSeleccionado = "bocho";
            break;
        case 2:
            tipoAutoSeleccionado = "rayo macuin";
            break;
        case 3:
            tipoAutoSeleccionado = "tico";
            break;
        default:
            cout << "opción inválida. selecciona 1, 2 o 3." << endl;
            return 12;
    }

    // Crear una instancia de la clase Auto con el tipo seleccionado
    Auto autoSeleccionado(tipoAutoSeleccionado);

    // Mostrar la información del auto seleccionado
    autoSeleccionado.mostrarInformacion();
    // Solicitar al usuario la distancia de la carrera
    cout << "elige la distancia de la carrera (5000m a 6000m):" << endl;
    cout << " --> " ;
    cin >> distancia;

    // validar la distancia ingresada
    while (distancia < 5000 || distancia > 6000) {
        cout << "¡solo puedes elegir 5000m a 6000m para la distancia >:( !" << endl;
        cout << "elige la distancia de la carrera (5000m a 6000m): -->" ;
        cin >> distancia;
    }

    // solicitar al usuario la dificultad del oponente
    cout << "Elige la dificultad del oponente --> (1 al 10):" <<endl;
    cin >> dificultad;

    // Crear una instancia de la clase Carrera con los valores seleccionados por el usuario
    Carrera carrera(distancia, dificultad);

    // Iniciar la competencia
    carrera.competir(); 
    return 12;
}

//vadro
