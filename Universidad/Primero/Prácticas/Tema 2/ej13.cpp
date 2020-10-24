#include <iostream>

using namespace std;

int main() {
	// Como se deben recoger unos cuantos valores he decidido 
	// crear una matriz para no repetir codigo.
	float notas[5];
	float sumatorio;
	
	for (unsigned int i = 0; i < sizeof(notas); i++) {
		cout << "Introduzca valor de nota " << i << ": ";
		cin >> notas[i];
		sumatorio += notas[i];
	}
	
	cout << "Su media es: " << sumatorio/sizeof(notas) << endl;
	return 0;
	
}
