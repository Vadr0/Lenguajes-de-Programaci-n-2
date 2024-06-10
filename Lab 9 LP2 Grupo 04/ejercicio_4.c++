#include <iostream>
#include <string>
using namespace std;

//clases 
class Personaje {
public:
    virtual void atacar() = 0;
    virtual void defender() = 0;
    virtual void habilidadEspecial() = 0;

//clases derivadas    
};
class Guerrero : public Personaje {
public:
    void atacar() override {
        cout << "El guerrero ataca con su espada." << endl;
    }

    void defender() override {
        cout << "El guerrero se defiende con su escudo." << endl;
    }

    void habilidadEspecial() override {
        cout << "El guerrero usa su habilidad especial: Golpe Poderoso." << endl;
    }
};

class Mago : public Personaje {
public:
    void atacar() override {
        cout << "El mago ataca con un hechizo de fuego." << endl;
    }

    void defender() override {
        cout << "El mago se defiende con un escudo mágico." << endl;
    }

    void habilidadEspecial() override {
        cout << "El mago usa su habilidad especial: Bola de Fuego." << endl;
    }
};

class Arquero : public Personaje {
public:
    void atacar() override {
        cout << "El arquero ataca con su arco y flechas." << endl;
    }

    void defender() override {
        cout << "El arquero se defiende esquivando el ataque." << endl;
    }

    void habilidadEspecial() override {
        cout << "El arquero usa su habilidad especial: Lluvia de Flechas." << endl;
    }
};

// programa main :D

int main() {
    Personaje* personajes[3];

    Guerrero guerrero;
    Mago mago;
    Arquero arquero;

    personajes[0] = &guerrero;
    personajes[1] = &mago;
    personajes[2] = &arquero;

    for (int i = 0; i < 3; i++) {
        personajes[i]->atacar();
        personajes[i]->defender();
        personajes[i]->habilidadEspecial();
    }

    return 0;
}
