#include <iostream>
// Incluimos la libreria para usar la funcion abs para las cargas
#include <cstdlib>

using namespace std;

#define k 8987551787.368176

class Cargas {
	// q1 y q2 son microculombios y r metros
	double q1, q2, r;
	
	public:
		void Leer();
		double Fuerza();
};

void Cargas::Leer() {
	cout << "Introduzca el valor de Q1: ";
	cin >> q1;
	cout << "Introduzca el valor de Q2: ";
	cin >> q2;
	cout << "Introduzca el valor de R: ";
	cin >> r;	
}

void Cargas::Fuerza() {
	// Aplicamos la formula F = k*q1*q2/r
	
}

int main() {
	Cargas obj;
}
