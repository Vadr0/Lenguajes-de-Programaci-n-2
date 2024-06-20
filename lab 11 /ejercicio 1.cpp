#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName;
    ifstream file;

    cout << "Ingrese el nombre del archivo: ";
    cin >> fileName;

    try {
        file.open(fileName);
        if (!file) {  
            throw runtime_error("No se pudo abrir el archivo.");
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
