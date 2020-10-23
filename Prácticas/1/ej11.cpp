#include <iostream>

int main() {
  float gCelsius;
  cout << "Escriba los grados Celsius: " << endl;
  cin >> gCelsius;
  cout << endl;
  
  // Grados Fahrenheit = 9/5 * celsius +32
  cout << gCelsius << " ºC equivalen a " << (9/5)*gCelsius +32 << endl;
  return 0;
}
