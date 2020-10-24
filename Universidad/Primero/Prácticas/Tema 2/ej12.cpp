#include <iostream>
// Incluimos la biblioteca 'cmath' para usar las funciones sqrt y pow
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	// Resolvemos ax^2 +bx +c
	cout << "Introduzca valor de A: ";
	cin >> a;
	cout << "Introduzca valor de B: ";
	cin >> b;
	cout << "Introduzca valor de C: ";
	cin >> c;
	
	cout << endl;
	
	// Comprobamos que no nos salga una raiz imaginaria
	if ( pow(b, 2) -4*a*c < 0 ) {
		cout << "ERROR: No se puede resolver la raiz cuadrada de un entero negativo!" << endl;
		return 0;
	}
	// Hacemos el cast para que no se produzca truncamiento
	float resultado1 = (float) ( -1*b + sqrt(pow(b, 2) -4*a*c)/2*a )
	float resultado2 = (float) ( -1*b - sqrt(pow(b, 2) -4*a*c)/2*a )
	
	cout << "X1 = " << resultado1 << endl;
	cout << "X2 = " << resultado2 << endl;
}
