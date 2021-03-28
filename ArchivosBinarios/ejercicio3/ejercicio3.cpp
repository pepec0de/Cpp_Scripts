#include <string.h>
#include <iostream>
#include <fstream>
typedef char Cadena[90];
#define Incremento 4
using namespace std;
struct TFecha {//Almacena una fecha
    int Dia;
    int Mes;
    int Anyo;
};
struct TProducto {
    Cadena CodProd; // de producto.
    int Cantidad; //Cantidad en el almac�n.
    Cadena NombreProd; //Nombre del producto.
    float Precio; //Precio por unidad.
    Cadena Descripcion; // opcional del producto.
    TFecha Caducicidad; //Caducidad del producto.
};

int main() {
    // Leemos miAlmacen.dat
    fstream f;
    f.open("miAlmacen.dat", ios::binary | ios::in);
    f.seekg(0, ios::end); 
    int tamano = f.tellg();
    cout << "Tamaño = " << tamano << endl;

    int nproduc;
    f.seekg(0, ios::beg);
    f.read((char*) &nproduc, sizeof(int));
    cout << "nproduc = " << nproduc << endl;
    
    Cadena nombre;
    f.read((char*) nombre, sizeof(Cadena));
    cout << "nombre = " << nombre << endl;

    Cadena dir;
    f.read((char*) dir, sizeof(Cadena));
    cout << "dir = " << dir << endl;
    cout << "posicion = " << f.tellg() << endl; 
    //f.seekg(sizeof(int)+2*sizeof(Cadena), ios::beg);
    TProducto prod;
    //f.read((char*) &prod, sizeof(TProducto));
    /*f.read((char*) &prod, sizeof(TProducto));
    cout << "prod =\n" << " CodProd = " << prod.CodProd << endl;*/
    // Vamos a buscar el codigo
    f.seekg(sizeof(int)+2*sizeof(Cadena), ios::beg);
    do {
        f.read((char*) &prod, sizeof(TProducto)); // 941924
    } while(strcmp(prod.CodProd, "111") != 0 && f.tellg() < tamano);
    if (f.tellg() < tamano) { 
        cout << "Producto encontrado: " << prod.CodProd << endl;
    } else {
        cout << "Producto no encontrado.\n";
    }
    f.close();
    return 0;
}
