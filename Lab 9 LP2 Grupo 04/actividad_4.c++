#include <iostream>
#include <string>
using namespace std;

//clase base B)

class Animal {
public:
    virtual void hacerSonido() {
        cout << "el animal hace sonido" << endl;
    }
};

//clases derivadas

class Pollito : public Animal {
public:
    void hacerSonido() override {
        cout << "el pollito hace: pio pio" << endl;
    }
};
class Oveja : public Animal {
public:
    void hacerSonido() override {
        cout << "la oveja hace: beeeeee" << endl;
    }
};
class Puerco : public Animal {
public:
    void hacerSonido() override {
        cout << "el puerco hace: oink oink" << endl;
    }
};
int main() {
    Animal* animales[3]; //arreglo de punteros

    Pollito pollito; //instancias 
    Oveja oveja;
    Puerco puerco;

    animales[0] = &pollito; //asignamos direcciones a las instancias 
    animales[1] = &oveja;
    animales[2] = &puerco;

    for (int i = 0; i < 3; i++) {
        animales[i]->hacerSonido();
    }

    return 0;
}
