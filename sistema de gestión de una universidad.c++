#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Declaración de la clase Profesor
class Profesor;

// Declaración de la clase Alumno
class Alumno;

// Declaración de la clase Asignatura
class Asignatura {
private:
    int codigo;
    string nombre;
    string descripcion;
    Profesor* profesor;
    vector<Alumno*> alumnosMatriculados;
    vector<int> notas;
    vector<int> faltas;

public:
    Asignatura(int codigo, string nombre, string descripcion, Profesor* profesor) : codigo(codigo), nombre(nombre), descripcion(descripcion), profesor(profesor) {}

    void matricularAlumno(Alumno* alumno) {
        alumnosMatriculados.push_back(alumno);
        notas.push_back(10);
        faltas.push_back(0);
    }

    void desmatricularAlumno(int pos) {
        alumnosMatriculados.erase(alumnosMatriculados.begin() + pos);
        notas.erase(notas.begin() + pos);
        faltas.erase(faltas.begin() + pos);
    }

    void registrarNota(int pos, int nota) {
        notas[pos] = nota;
    }

    void registrarFalta(int pos) {
        faltas[pos]++;
    }

    int getCodigo() const {
        return codigo;
    }

    string getNombre() const {
        return nombre;
    }

    string getDescripcion() const {
        return descripcion;
    }

    Profesor* getProfesor() const {
        return profesor;
    }

    const vector<Alumno*>& getAlumnosMatriculados() const {
        return alumnosMatriculados;
    }

    const vector<int>& getNotas() const {
        return notas;
    }

    const vector<int>& getFaltas() const {
        return faltas;
    }
};

// Declaración de la clase Profesor
class Profesor {
private:
    string nombre;
    string direccion;
    int telefono;
    vector<Asignatura*> asignaturas;

public:
    Profesor(string nombre, string direccion, int telefono) : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void impartirAsignatura(Asignatura* asignatura) {
        asignaturas.push_back(asignatura);
    }

    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    int getTelefono() const {
        return telefono;
    }

    const vector<Asignatura*>& getAsignaturas() const {
        return asignaturas;
    }

    void mostrar() {
        cout << "El profesor " << nombre << " :" << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de teléfono: " << telefono << endl;
        cout << "Asignaturas: ";
        for (const auto& asignatura : asignaturas) {
            cout << asignatura->getNombre() << ", ";
        }
        cout << endl;
    }
};

// Declaración de la clase Alumno
class Alumno {
private:
    string nombre;
    string direccion;
    int nmatricula;
    vector<Asignatura*> asignaturasMatriculadas;

public:
    Alumno(string nombre, string direccion, int nmatricula) : nombre(nombre), direccion(direccion), nmatricula(nmatricula) {}

    void matricularseEnAsignatura(Asignatura* asignatura) {
        asignaturasMatriculadas.push_back(asignatura);
        asignatura->matricularAlumno(this);
    }

    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    int getNmatricula() const {
        return nmatricula;
    }

    const vector<Asignatura*>& getAsignaturasMatriculadas() const {
        return asignaturasMatriculadas;
    }

    void mostrar() {
        cout << "El alumno " << nombre << " :" << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Número de matrícula: " << nmatricula << endl;
        cout << "Asignaturas matriculadas: ";
        for (const auto& asignatura : asignaturasMatriculadas) {
            cout << asignatura->getNombre() << " - Nota: " << asignatura->getNotas()[0] << ", ";
        }
        cout << endl;
    }
};

int main() {
    Profesor profesor1("Lina", "Jose Luis Bustamante y Rivero", 937118873);
    Asignatura asignatura1(235552, "Matemáticas", "Matemáticas para ingeniería", &profesor1);
    Alumno alumno1("Cristiano Ronaldo", "lisboa", 0007);

    cout <<"¿Qué desea ver?" << endl;
    cout << " 1.- Alumnos " << endl;
    cout << " 2.- Profesores " << endl;
    int ver;
    cin >> ver;
    switch(ver) 
    {   
        case 1:
            alumno1.matricularseEnAsignatura(&asignatura1);
            alumno1.mostrar();
            break; 
        case 2:
            profesor1.impartirAsignatura(&asignatura1);
            profesor1.mostrar(); 
            break; 
        default:
            cout << "No es una opción válida" << endl; 
    } 
    return 0;
}
