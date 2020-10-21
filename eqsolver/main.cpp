#include <iostream>
#include <vector>

#define VAR 'x'

using namespace std;

vector<string> splitString(string str, char deliminator);
string getSubstring(string str, unsigned int start, unsigned int end);
string getSubstring(string str, int fromEnd);
string toStr(char value);

bool hasVar(string element);
bool hasVarWpow(string element);
float getVarPow(string element);

float getEqGrade(vector<string> eqArr);
void solveEq(vector<string> eqArr);
float sum(vector<float> mVector);

int main() {
  cout << "Ecuación a resolver: ";
	// String para almacenar ecuacion
	string eqStr;
    // Hacemos un getline porque cin tan solo toma los datos hasta que
    // encuentra un espacio.
	getline(cin, eqStr);
	if (eqStr == "") {
		eqStr = "4x = 2";
		eqStr = "1x^2 +1x -2 = 0";
	}
	cout << "Su ecuación: " << eqStr << endl;
	
	// Comprobamos que es una ecuacion por el caracter '='
	for (unsigned int i = 0; i < eqStr.size(); i++) {
		if (eqStr[i] == '=') {
			break;
		}
		if (i == eqStr.size()) {
			cout << "Ecuación inválida!" << endl;
			exit(0);
		}
	}
	
	// Dividimos la string en ' ' para recoger los elementos y guardarlos en un vector
	vector<string> eqArr = splitString(eqStr, ' ');
	cout << "Su ecuación es de nivel: "	<< getEqGrade(eqArr) << endl;
	solveEq(eqArr);
}

/// STRING FUNCTIONS
// Func to split a string with a given char
vector<string> splitString(string str, char deliminator) {
	vector<string> strVct;
	unsigned int relStart = 0;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] == deliminator) {
			// Hacemos el substring y despues lo añadimos al vector str
			strVct.push_back(getSubstring(str, relStart, i));
			relStart = i+1;
			// Si el delimitador esta en el ultimo caracter sacamos el vector
			if (relStart >= str.size()) {
				return strVct;
			}
		}
	}
	strVct.push_back(getSubstring(str, relStart, str.size()));
	return strVct;
}

// Func to do substring having an interval
string getSubstring(string str, unsigned int start, unsigned int end) {
	string result = "";
	for (unsigned int i = start; i < end; i++) {
        result += str[i];
	}
	return result;
}

// Func to remove last characters of a string (has to be a negative number)
string getSubstring(string str, int fromEnd) {
	string result = "";
	if (fromEnd < 0) {
		for (int i = 0; i < (fromEnd + str.size()); i++) {
			result.push_back(str[i]);
		}
	}
	return result;
}

string toStr(char value) {
	// Una string es un array de chars por tanto:
	string str;
	str.push_back(value);
	return str;
}
/// EQUATION FUNCTIONS
// Func to check if an element has the Var
bool hasVar(string element) {
	for (unsigned int i = 0; i < element.size(); i++) {
		if (element[i] == VAR) {
			return true;
		}
	}
	return false;
}

// Func to check if an element has a pow with the Var
bool hasVarWpow(string element) {
	// Suponemos que seria 1x^2 : x^
	for (unsigned int i = 0; i < element.size(); i++) {
		if (element[i] == VAR && element[i+1] == '^') {
			return true;
		}
	}
	return false;
}

// Func to get the pow of the var
float getVarPow(string element) {
	string strPow;
	if (hasVarWpow(element)) {
		for (unsigned int i = 0; i < element.size(); i++) {
			if (element[i] == VAR) {
				for (unsigned int j = i+2; j < element.size(); j++) {
					strPow += element[j];
				}
				return stof(strPow);
			}
		}
	}
	return 1;
}

float getEqGrade(vector<string> eqArr) {
	float grade = 0;
	for (unsigned int i = 0; i < eqArr.size(); i++) {
		if (hasVar(eqArr[i])) {
			if (getVarPow(eqArr[i]) > grade) {
				grade = getVarPow(eqArr[i]);
			}
		}
	}
	return grade;
}

void solveEq(vector<string> eqArr) {
	if (getEqGrade(eqArr) == 1) {
		// Hacemos dos vectores de polinomios
		// Uno con los elementos del primer lado y el otro con los del otro lado
		vector<string> poly1, poly2;
		bool sameFind = false;
		for (unsigned int i = 0; i < eqArr.size(); i++) {
			if (eqArr[i] == "=") {
				// Pasamos al otro vector
				sameFind = true;
				continue;
			}
			if (sameFind) {
				poly2.push_back(eqArr[i]);
			} else {
				poly1.push_back(eqArr[i]);
			}
		}
		// Creamos otros dos vectores para almacenar las cifras
		// En el primero guardaremos las Xs y en el segundo los independientes
		vector<float> polyVar, polyVal;
		for (unsigned int i = 0; i < poly1.size(); i++) {
			if (hasVar(poly1[i])) {
				polyVar.push_back(stof(getSubstring(poly1[i], -1)));
			} else {
				polyVal.push_back(stof(poly1[i])*(-1));
			}
		}
		for (unsigned int i = 0; i < poly2.size(); i++) {
			if (hasVar(poly2[i])) {
				polyVar.push_back(stof(getSubstring(poly1[i], -2))*(-1));
			} else {
				polyVal.push_back(stof(poly2[i]));
			}
		}
		// Ahora solo tenemos que imprimir : sum(polyVal)/sum(polyVar)
		cout << "Resultado: " << VAR << " = " << sum(polyVal)/sum(polyVar) << endl;
	}
}

float sum(vector<float> mVector) {
	float result = 0;
	for (unsigned int i = 0; i < mVector.size(); i++) {
		result += mVector[i];
	}
	return result;
}
