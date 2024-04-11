#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Interfaz para objetos asignables
class Asignable {
public:
    virtual void asignarTarea(const string& asignado) = 0;
    virtual ~Asignable() {} // Agregamos un destructor virtual
};

// Interfaz para objetos con fecha límite
class Planificable {
public:
    virtual void establecerFechaLimite(const string& fechaLimite) = 0;
    virtual ~Planificable() {} // Agregamos un destructor virtual
};

// Interfaz para objetos con seguimiento de progreso
class SeguimientoDeProgreso {
public:
    virtual void seguirProgreso(int progreso) = 0;
    virtual ~SeguimientoDeProgreso() {} // Agregamos un destructor virtual
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
class TareaAsignable : public Tarea {
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
class TareaPlanificable : public Tarea {
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
class TareaConSeguimiento : public Tarea {
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
    TareaAsignable tarea1("Hacer la presentación");
    tarea1.asignarTarea("Juan");
    tareas.push_back(&tarea1);
    
    TareaPlanificable tarea2("Preparar informe");
    tarea2.establecerFechaLimite("2024-04-15");
    tareas.push_back(&tarea2);
    
    TareaConSeguimiento tarea3("Investigar mercado");
    tarea3.seguirProgreso(50);
    tareas.push_back(&tarea3);
    
    // Ejemplo de mostrar tareas
    cout << "Lista de tareas:" << endl;
    for (const auto& tarea : tareas) {
        tarea->mostrar();
        cout << endl;
    }
    
    return 0;
}


#ifndef INTERFACES_H
#define INTERFACES_H

#include <string>

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

#endif // INTERFACES_H

#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>
#include "Interfaces.h"

using namespace std;

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

#endif // TAREA_H


#ifndef TAREAS_ASIGNABLES_H
#define TAREAS_ASIGNABLES_H

#include "Interfaces.h"
#include "Tarea.h"

using namespace std;

// Clase que extiende la funcionalidad de una tarea asignable
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

#endif // TAREAS_ASIGNABLES_H

#ifndef TAREAS_PLANIFICABLES_H
#define TAREAS_PLANIFICABLES_H

#include "Interfaces.h"
#include "Tarea.h"

using namespace std;

// Clase que extiende la funcionalidad de una tarea planificable
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

#endif // TAREAS_PLANIFICABLES_H


#ifndef TAREAS_CON_SEGUIMIENTO_H
#define TAREAS_CON_SEGUIMIENTO_H

#include "Interfaces.h"
#include "Tarea.h"

using namespace std;

// Clase que extiende la funcionalidad de una tarea con seguimiento de progreso
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

#endif // TAREAS_CON_SEGUIMIENTO_H




#include <iostream>
#include <vector>
#include "TareasAsignables.h"
#include "TareasPlanificables.h"
#include "TareasConSeguimiento.h"

using namespace std;

int main() {
    vector<Tarea*> tareas;

    // Ejemplo de creación de tareas
    TareaAsignable* tarea1 = new TareaAsignable("Hacer la presentación");
    tarea1->asignarTarea("Juan");
    tareas.push_back(tarea1);

    TareaPlanificable* tarea2 = new TareaPlanificable("Preparar informe");
    tarea2->establecerFechaLimite("2024-04-15");
    tareas.push_back(tarea2);

    TareaConSeguimiento* tarea3 = new TareaConSeguimiento("Investigar mercado");
    tarea3->seguirProgreso(50);
    tareas.push_back(tarea3);

    // Ejemplo de mostrar tareas
    cout << "Lista de tareas:" << endl;
    for (const auto& tarea : tareas) {
        tarea->mostrar();
        cout << endl;
    }

    // Liberar memoria
    for (auto& tarea : tareas) {
        delete tarea;
    }

    return 0;
}
