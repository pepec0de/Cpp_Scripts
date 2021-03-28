// Tutorial -> https://youtu.be/P7XGOBoVzW4
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef char Cadena[100];

class Persona {
    Cadena nombre;
    int edad;
public:
    Persona() {
        strcpy(nombre, "");
        edad = 0;
    }

    Persona(Cadena pNombre, int pEdad) {
        strcpy(nombre, pNombre);
        edad = pEdad;
    }

    void whoAreYou() {
        cout << "Hola soy " << nombre << ", tengo " << edad << endl; 
    }
};
int main() {
    Persona angel("Angel", 18);
    
    fstream fichero;
    // ios::binary -> archivo binario
    // ios::out -> modo escritura
    // ios::in -> modo lectura
    // ios::trunc -> para crear el archivo si no existe
    fichero.open("ejercicio1.dat", ios::binary | ios::out | ios::in);
    if (fichero.fail()) {
        cout << "FAIL()\n";
        // Estas dos lineas son prescindibles
        fichero.close();
        fichero.clear();
        fichero.open("ejercicio1.dat", ios::binary | ios::out | ios::trunc);
        fichero.close();
        fichero.clear();
        fichero.open("ejercicio1.dat", ios::binary | ios::out | ios::in);
        fichero.write((char*) &angel, sizeof(Persona));
    } else {
        fichero.write((char*) &angel, sizeof(Persona));
    }

//    fichero.seekg(0);
    fichero.open("ejercicio1.dat", ios::binary | ios::out | ios::in);

    Persona copiaAngel;
    fichero.read((char*) &copiaAngel, sizeof(Persona));
    
    angel.whoAreYou();
    copiaAngel.whoAreYou();

    fichero.close();

    return 0;
}
