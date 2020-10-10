#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

vector<string> splitString(string str, string deliminator) {
	vector<string> strVct;
	int relStart = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == deliminator) {
			// Hacemos el substring y despues lo añadimos al vector str
			
		}
	}
}

string getSubstring(string str, int start, int end) {
	for (int i = 0; i <	str.size(); i++) {
		str
	}	
}

int main() {
	cout << "Ecuacion a resolver: ";
	// String para almacenar ecuacion
	string eqStr;
	getline(cin, eqStr);
	cout << "Su ecuacion: " << eqStr << endl;
	
	// Comprobamos que es una ecuacion por el caracter '='
	for (int i = 0; i < eqStr.size(); i++) {
		if (eqStr[i] == '=') {
			break;
		}
		if (i == eqStr.size()) {
			cout << "Ecuacion invalida!" << endl;
			exit(0);
		}
	}
	
	// Dividimos la string en ' ' para recoger los elementos
	vector<string> eqArr;
    eqArr = split(eqStr, " ");

}

