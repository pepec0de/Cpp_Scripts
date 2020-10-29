#include <iostream>

using namespace std;

// Definimos la constante de gravedad
#define g 9.8

class Energia {
	private:
		// (masa) m en kg; (velocidad) v en km/h; (altura) h en km
		double m, v, h;
	
	public:
		void Leer();
		float ECinetica();
		float EPotencial();
};

float Energia::ECinetica() {
	// Aplicamos la formula Ec = 0.5*m*v^2
	return 0.5 * m *v*v
}

float Energia::EPotencial() {
	// Aplicamos la formula Ep = m*g*h
	return m * g * h;
}

int main() {
	// Convertimos las magnitudes al sistema internacional
	return 0;
}
