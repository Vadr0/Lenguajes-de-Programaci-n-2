//actividad 3 : MÉTODOS VIRTUALES 
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() const = 0; // Método virtual 
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "El perro hace Guau" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "El gato hace Miau" << endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() const override {
        cout << "La vaca hace Muu" << endl;
    }
};
class Pato :public Animal{
public:
    void hacerSonido() const override{
        cout<<"El Pato hace cuac"<<endl;
    }
};

int main() {
    Perro* perro = new Perro();  // creamos instancias en los animales 
    Gato* gato = new Gato();
    Vaca* vaca = new Vaca();
    Pato* pato= new Pato();
    
    perro->hacerSonido();       //llamamos a la instancia que creamos 
    gato->hacerSonido();
    vaca->hacerSonido();
    pato->hacerSonido();
    return 0;
}
