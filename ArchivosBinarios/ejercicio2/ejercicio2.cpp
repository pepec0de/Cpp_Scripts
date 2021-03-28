#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef char Cadena[90];

int main() {
    fstream fichero;
    fichero.open("ejercicio2.dat", ios::binary | ios::out | ios::in);
    if (fichero.fail()) {
        cout << "FAIL()" << endl;
        fichero.close();
        fichero.clear();
        fichero.open("ejercicio2.dat", ios::binary | ios::out);
        fichero.close();
        fichero.clear();
        fichero.open("ejercicio2.dat", ios::binary | ios::out | ios::in);
    }
    Cadena dato1, dato2, dato3, dato4;
    strcpy(dato1, "dato1");
    strcpy(dato2, "dato2");
    strcpy(dato3, "dato3");
    strcpy(dato4, "dato4");

    fichero.write((char*) &dato1, sizeof(Cadena));
    fichero.write((char*) &dato2, sizeof(Cadena));
    fichero.write((char*) &dato3, sizeof(Cadena));
    fichero.write((char*) &dato4, sizeof(Cadena));

    // Ahora los intentamos leer con un tipo de variable diferente
    fichero.seekg(0);
    Cadena i1, i2, i3, i4;
    fichero.read((char*) &i1, sizeof(Cadena));
    if(fichero.good()) cout << "GOOD() true\n"; else cout << "GOOD() false\n";
    cout << i1 << endl;
    return 0;
}
