#include <iostream>
 
using namespace std;

class Movimiento {
	float velO, spcO, a, t;
	
	public:
		void pedirDatos();
		float velocidadFinal();
		float espacioFinal();
};
 
void Movimiento::pedirDatos() {
	cout << "Introduzca la velocidad inicial: ";
	cin >> velO;
	cout << "Introduzca el espacio inicial: ";
	cin >> spcO;
	cout << "Introduzca la aceleracion: ";
	cin >> a;
	cout << "Introduzca el tiempo: ";
	cin >> t;
}

float Movimiento::velocidadFinal() {
	return velO + a*t;
}
 
float Movimiento::espacioFinal() {
	return spcO + velO*t + 0.5*a*t*t;
}
 
int main() {
	Movimiento m;
	m.pedirDatos();
	cout << "Aplicamos las formulas:\nVf = Vo + a * t\nS = So + Vo * t * 0.5 * a * t^2\n";
	cout << "La velocidad final es de: " << m.velocidadFinal() << endl;
	cout << "El espacio final es de : " << m.espacioFinal() << endl;
	return 0;
 }
