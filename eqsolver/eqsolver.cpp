#include <iostream>
#include <vector>

#define VAR "x"

using namespace std;

vector<string> splitString(string str, char deliminator);
string getSubstring(string str, int start, int end);

int main() {
	cout << "Ecuacion a resolver: ";
	// String para almacenar ecuacion
	string eqStr;
	getline(cin, eqStr);
	if (eqStr == "") {
		eqStr = "4x = 2";
		eqStr = "1x^2 +1x -2 = 0";
	}
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
	vector<string> eqArr = splitString(eqStr, ' ');
	cout << VAR << endl;
}

/// STRING FUNCTIONS
// Func to split a string with a given char
vector<string> splitString(string str, char deliminator) {
	vector<string> strVct;
	int relStart = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == deliminator) {
			// Hacemos el substring y despues lo añadimos al vector str
			strVct.push_back(getSubstring(str, relStart, i));
			relStart = i+1;
			if (relStart >= str.size()) {
				return strVct;
			}
		}
	}
	strVct.push_back(getSubstring(str, relStart, str.size()));
	return strVct;
}

// Func to have substring having an interval
string getSubstring(string str, int start, int end) {
	string result = "";
	for (int i = start; i <	end; i++) {
		result += str[i];
	}
	return result;
}

// Func to have substring starting from the end
string getSubstring(string str, int start) {
	string result = "";
	return result;
}

/// EQUATION FUNCTIONS
// Func to check if an element has the Var
