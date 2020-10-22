#include <iostream>
#include <cmath>

#define PI 3.1415926

using namespace std;

int main() {
	float radio;
	cout << "Inserte el valor del radio: ";
	cin >> radio;
	cout << endl;
	cout << "Longitud: " << 2*PI*radio << endl;
	cout << "Superficie: " << PI*pow(radio, 2) << endl;
	cout << "Esfera: " << 4*PI*pow(radio, 3)/3 << endl;
	return 0;
}
