#include <iostream>

using namespace std;

int main() {
	float longitud_en_metros = 15000;
	float Precio_total_en_euros1 = 5000*(longitud_en_metros/5280.0);
	float Precio_total_en_euros2 = 5000*(longitud_en_metros/5280);
	cout << Precio_total_en_euros1 << endl << Precio_total_en_euros2 << endl;
}
