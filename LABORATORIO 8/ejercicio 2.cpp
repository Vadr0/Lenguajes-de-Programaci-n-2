#include <iostream>
#include <string>
using namespace std;

class Reproductor {
public:
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
    virtual ~Reproductor() = default;
};

class ReproductorMP3 : public Reproductor {
public:
    ReproductorMP3(const string& archivo) : archivo(archivo), estado("detenido") {}

    void reproducir() override {
        if (estado == "reproduciendo") {
            cout << "El archivo " << archivo << " ya se está reproduciendo." << endl;
        } else {
            estado = "reproduciendo";
            cout << "Reproduciendo " << archivo << "..." << endl;
        }
    }

    void pausar() override {
        if (estado == "pausado") {
            cout << "El archivo " << archivo << " ya está pausado." << endl;
        } else if (estado == "detenido") {
            cout << "No se puede pausar porque " << archivo << " está detenido." << endl;
        } else {
            estado = "pausado";
            cout << "Pausando " << archivo << "..." << endl;
        }
    }

    void detener() override {
        if (estado == "detenido") {
            cout << "El archivo " << archivo << " ya está detenido." << endl;
        } else {
            estado = "detenido";
            cout << "Deteniendo " << archivo << "..." << endl;
        }
    }

private:
    string archivo;
    string estado;
};

//Programa pricipal
int main() {
    ReproductorMP3 reproductor("mi_cancion.mp3");

    reproductor.reproducir();  // tiene que salir: "Reproduciendo mi_cancion.mp3..."
    reproductor.pausar();      // tiene que salir: "Pausando mi_cancion.mp3..."
    reproductor.detener();     // tiene que salir: "Deteniendo mi_cancion.mp3..."
    reproductor.pausar();      // tiene que salir: "No se puede pausar porque mi_cancion.mp3 está detenido."
    reproductor.detener();     // tiene que salir: "El archivo mi_cancion.mp3 ya está detenido."

    return 0;
}
