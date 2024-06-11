#include <iostream>
using namespace std;

class Animal {         // Clase base Animal con métodos virtuales
public:
    virtual void comer() {
        cout << "El animal está comiendo." << endl;
    }
    
    virtual void dormir() {
        cout << "El animal está durmiendo." << endl;
    }

    virtual void moverse() {
        cout << "El animal se está moviendo." << endl;
    }

    virtual ~Animal() {}
};

class Mamifero : public Animal {
public:
    void comer() override {
        cout << "El mamífero está comiendo hierba o carne." << endl;
    }
    
    void dormir() override {
        cout << "El mamífero está durmiendo en su guarida." << endl;
    }

    void moverse() override {
        cout << "El mamífero está caminando o corriendo." << endl;
    }
};

class Ave : public Animal {
public:
    void comer() override {
        cout << "El ave está comiendo semillas o insectos." << endl;
    }
    
    void dormir() override {
        cout << "El ave está durmiendo en su nido." << endl;
    }

    void moverse() override {
        cout << "El ave está volando." << endl;
    }
};

class Reptil : public Animal {
public:
    void comer() override {
        cout << "El reptil está comiendo insectos o pequeños animales." << endl;
    }
    
    void dormir() override {
        cout << "El reptil está durmiendo bajo una roca." << endl;
    }

    void moverse() override {
        cout << "El reptil está reptando." << endl;
    }
};

int main() {
    Animal* animales[3];      // Crear objetos de diferentes tipos de animales
    animales[0] = new Mamifero();
    animales[1] = new Ave();
    animales[2] = new Reptil();
    for (int i = 0; i < 3; ++i) {    // Recorrer el arreglo 
        animales[i]->comer();
        animales[i]->dormir();
        animales[i]->moverse();
        cout << endl;
    }
    for (int i = 0; i < 3; ++i) {      // Liberar memoria
        delete animales[i];
    }

    return 0;
}
