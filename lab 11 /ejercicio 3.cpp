#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string direccion;

public:
    Persona() {}
    Persona(string nom, int ed, string dir) : nombre(nom), edad(ed), direccion(dir) {}

    void setNombre(string nom) { nombre = nom; }
    string getNombre() const { return nombre; }

    void setEdad(int ed) { edad = ed; }
    int getEdad() const { return edad; }

    void setDireccion(string dir) { direccion = dir; }
    string getDireccion() const { return direccion; }

    // Serializar el objeto
    void save(const string &filename) const {
        ofstream ofs(filename, ios::binary);
        if (!ofs) {
            cerr << "Error abriendo archivo para escribir." << endl;
            return;
        }
        size_t nombreLength = nombre.size();
        ofs.write(reinterpret_cast<const char*>(&nombreLength), sizeof(nombreLength));
        ofs.write(nombre.c_str(), nombreLength);
        ofs.write(reinterpret_cast<const char*>(&edad), sizeof(edad));
        size_t direccionLength = direccion.size();
        ofs.write(reinterpret_cast<const char*>(&direccionLength), sizeof(direccionLength));
        ofs.write(direccion.c_str(), direccionLength);
        ofs.close();
    }

    // Deserializar el objeto
    void load(const string &filename) {
        ifstream ifs(filename, ios::binary);
        if (!ifs) {
            cerr << "Error abriendo archivo para leer." << endl;
            return;
        }
        size_t nombreLength;
        ifs.read(reinterpret_cast<char*>(&nombreLength), sizeof(nombreLength));
        nombre.resize(nombreLength);
        ifs.read(&nombre[0], nombreLength);
        ifs.read(reinterpret_cast<char*>(&edad), sizeof(edad));
        size_t direccionLength;
        ifs.read(reinterpret_cast<char*>(&direccionLength), sizeof(direccionLength));
        direccion.resize(direccionLength);
        ifs.read(&direccion[0], direccionLength);
        ifs.close();
    }
};

int main() {
    Persona p1("Juan Perez", 30, "Calle Falsa 123");
    string filename = "persona.dat";

    // Serializar el objeto
    p1.save(filename);

    // Deserializar el objeto
    Persona p2;
    p2.load(filename);

    // Mostrar los atributos
    cout << "Nombre: " << p2.getNombre() << endl;
    cout << "Edad: " << p2.getEdad() << endl;
    cout << "Direccion: " << p2.getDireccion() << endl;

    return 0;
}
