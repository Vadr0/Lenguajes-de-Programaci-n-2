#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Interfaz para objetos asignables
class Asignable {
public:
    virtual void asignarTarea(const string& asignado) = 0;
};

// Interfaz para objetos con fecha límite
class Planificable {
public:
    virtual void establecerFechaLimite(const string& fechaLimite) = 0;
};

// Interfaz para objetos con seguimiento de progreso
class SeguimientoDeProgreso {
public:
    virtual void seguirProgreso(int progreso) = 0;
};

// Clase base para tareas
class Tarea {
protected:
    string descripcion;
public:
    Tarea(const string& desc) : descripcion(desc) {}
    virtual ~Tarea() {}
    virtual void mostrar() const {
        cout << "Descripción de la tarea: " << descripcion << endl;
    }
};

// Clase concreta que implementa una tarea asignable
class TareaAsignable : public Tarea, public Asignable {
protected:
    string asignado;
public:
    TareaAsignable(const string& desc) : Tarea(desc) {}
    void asignarTarea(const string& asignado) override {
        this->asignado = asignado;
    }
    void mostrar() const override {
        Tarea::mostrar();
        cout << "Asignada a: " << asignado << endl;
    }
};

// Clase concreta que implementa una tarea con fecha límite
class TareaPlanificable : public Tarea, public Planificable {
protected:
    string fechaLimite;
public:
    TareaPlanificable(const string& desc) : Tarea(desc) {}
    void establecerFechaLimite(const string& fechaLimite) override {
        this->fechaLimite = fechaLimite;
    }
    void mostrar() const override {
        Tarea::mostrar();
        cout << "Fecha límite: " << fechaLimite << endl;
    }
};

// Clase concreta que implementa una tarea con seguimiento de progreso
class TareaConSeguimiento : public Tarea, public SeguimientoDeProgreso {
protected:
    int progreso;
public:
    TareaConSeguimiento(const string& desc) : Tarea(desc), progreso(0) {}
    void seguirProgreso(int progreso) override {
        this->progreso = progreso;
    }
    void mostrar() const override {
        Tarea::mostrar();
        cout << "Progreso: " << progreso << "%" << endl;
    }
};

int main() {
    vector<Tarea*> tareas;
    
    // Ejemplo de creación de tareas
    Tarea* tarea1 = new TareaAsignable("Hacer la presentación");
    tarea1->mostrar();
    tareas.push_back(tarea1);
    
    Tarea* tarea2 = new TareaPlanificable("Preparar informe");
    tarea2->mostrar();
    tareas.push_back(tarea2);
    
    Tarea* tarea3 = new TareaConSeguimiento("Investigar mercado");
    tarea3->mostrar();
    tareas.push_back(tarea3);
    
    // Liberar memoria
    for (auto& tarea : tareas) {
        delete tarea;
    }
    
    return 0;
}
