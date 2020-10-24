#include <iostream>

using namespace std;

int main() {
	// Como se deben recoger unos cuantos valores he decidido 
	// crear una matriz para no repetir codigo.
	
	float notas[5];
	// Tomamos el tamaño de la matriz:
	unsigned int tNotas = sizeof(notas)/sizeof(notas[0]);
	float sumatorio;

	for (unsigned int i = 0; i < tNotas; i++) {
		cout << "Introduzca valor de nota " << i+1 << ": ";
		cin >> notas[i];
		sumatorio += notas[i];
	}
	cout << endl;
	cout << "Su nota media es: " << sumatorio/tNotas << endl;
	return 0;
}
