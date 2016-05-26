#include "Polynomial.h"
#include <iostream>
#include <string>

using namespace std;
/*This function is responsible for displaying the Polynomial correctly.*/
void Polynomial::display() {

	for (int i = 0; i < size; i++) {
		if (*(coefficient + i) != 0) {
			if (i == 0) {
				if (*(coefficient + i) == 1) {
					cout << "x^" << *(exponent + i) << " ";
				}
				else if (*(coefficient + i) == -1) {
					cout << "-x^" << *(exponent + i) << " ";
				}
				else {
					cout << *(coefficient + i) << "x^" << *(exponent + i) << " ";
				}
			}
			else if (*(coefficient + i) == 1) {
				cout << "+ x^" << *(exponent + i) << " ";
			}
			else if (*(coefficient + i) == -1) {
				cout << "- x^" << *(exponent + i) << " ";
			}
			else if (*(coefficient + i) < 0) {
				cout << "- " << *(coefficient + i) * -1 << "x^" << *(exponent + i) << " ";
			}
			else if (*(coefficient + i) > 0) {
				cout << "+ " << *(coefficient + i) << "x^" << *(exponent + i) << " ";
			}
		}
	}
}
/*This function is responsible to take a string and find the higest possible exponent and set the size to that.*/
void Polynomial::setSize(string poly) {
	//Parses the string to find the highest exponent and passes that exponent to the private variable size.
	for (unsigned int i = 0; i < (poly.length() - 1); i++) {
		if (poly.substr(i, 1) == "x") {
			/*Size of the Polynomial will be highest number + 1, since we want the indexes to go from 0-size.*/
			size++;
		}
	}
	coefficient = new float[size]();
	exponent = new int[size]();
}
/*This will create the polynomial and store it into an array.*/
void Polynomial::setPolynomial(string input) {
	/*Begin Coefficient adding..*/
	int counter = 0;
	for (unsigned int i = 0; i < input.length(); i++) {
		/*Base Case*/
		if (i == 0) {
			string answer;
			if (input.substr(i, 1) == "x") {
				*(coefficient + counter) = 1;
			}
			int j = 0;
			while (input.substr(j, 1) != "x") {
				answer+= input.substr(j, 1);
				j++;
			}
			if (answer.length() == 1 && answer.substr(0, 1) == "-") {
				answer += "1";
			}
			*(coefficient + counter++) = stof(answer);

		}
		else if(input.substr(i,1) == " " && input.substr(i+2, 1) == " ") {
			string answer;
			int j = (i + 1);
			while (input.substr(j, 1) != "x") {
				if(input.substr(j,1) != "+" && input.substr(j,1) != " ") {
					answer += input.substr(j, 1);
				}
				j++;
			}
			if ((answer.length() == 1 && answer.substr(0,1) == "-") || answer.empty()) {
				answer += "1";
			}
			*(coefficient + counter++) = stof(answer);
		}
	}
	/*End Coefficient adding...*/
	/*Begin Exponent Adding...*/
	counter = 0;
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input.substr(i, 1) == "^") {
			int j = (i + 1);
			string answer;
			while (input.substr(j, 1) != " " && j != input.length()) {
				answer += input.substr(j++, 1);
			}
			*(exponent + counter++) = stoi(answer);
		}
	}

}

Polynomial::Polynomial(string poly) {
	size = 0;
	setSize(poly);
	setPolynomial(poly);

}
Polynomial Polynomial::operator+(const Polynomial &poly2 ) {
	string answer = "";
	int index1 = 0, index2 = 0;
	int sizeLocal = *(exponent + (size - 1)) > *(poly2.exponent + (poly2.size - 1)) ? *(exponent +(size-1)) : *(poly2.exponent + (poly2.size -1));
	for (int i = 0; i <= sizeLocal; i++) {
		float coeff = 0;
		for (int j = index1; j < size; j++) {
			if (*(exponent + j) == i) {
				index1++;
				coeff += *(coefficient + j);
				break;
			}
		}
		for (int k = index2; k < poly2.size; k++) {
			if (*(poly2.exponent + k) == i) {
				index2++;
				coeff += *(poly2.coefficient + k);
				break;
			}
		}
		if (coeff != 0) {
			answer += to_string(coeff);
			answer += "x^" + to_string(i);
			answer += i == sizeLocal ? "" : " + ";
		}
	}
	return Polynomial(answer);
}
Polynomial Polynomial::operator-(const Polynomial &poly2) {
	string answer = "";
	int index1 = 0, index2 = 0;
	int sizeLocal = *(exponent + (size - 1)) > *(poly2.exponent + (poly2.size - 1)) ? *(exponent + (size - 1)) : *(poly2.exponent + (poly2.size - 1));
	for (int i = 0; i <= sizeLocal; i++) {
		float coeff = 0;
		for (int j = index1; j < size; j++) {
			if (*(exponent + j) == i) {
				index1++;
				coeff += *(coefficient + j);
				break;
			}
		}
		for (int k = index2; k < poly2.size; k++) {
			if (*(poly2.exponent + k) == i) {
				index2++;
				coeff -= *(poly2.coefficient + k);
				break;
			}
		}
		if (coeff != 0) {
			answer += to_string(coeff);
			answer += "x^" + to_string(i);
			answer += i == sizeLocal ? "" : " + ";
		}
	}
	return Polynomial(answer);
}
Polynomial Polynomial::operator*(const Polynomial &poly2) {
	string answer = "";
	int sizeLocal = *(exponent + (size - 1)) + *(poly2.exponent + (poly2.size - 1)) - 1;
	float *tempCo = new float[sizeLocal]();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < poly2.size; j++) {
			*(tempCo + (i + j)) += (*(coefficient + i) * *(poly2.coefficient + j));
		}
	}
	for (int i = 0; i < sizeLocal; i++) {
		if (*(tempCo + i) != 0) {
			answer += to_string(*(tempCo + i));
			answer += "x^";
			answer += to_string(i);
			answer += i == (sizeLocal - 1) ? "" : " + ";
		}
	}
	delete[] tempCo;
	return Polynomial(answer);
}
Polynomial& Polynomial::operator=(const Polynomial & poly2) {
	coefficient = new float[poly2.size];
	exponent = new int[poly2.size];
	for (int i = 0; i < poly2.size; i++){
		*(coefficient + i) = *(poly2.coefficient + i);
		*(exponent + i) = *(poly2.exponent + i);
	}
	return *this;
}
Polynomial::Polynomial(const Polynomial &poly2) {
	size = poly2.size;
	coefficient = new float[size];
	exponent = new int[size];
	for (int i = 0; i < size; i++) {
		*(coefficient + i) = *(poly2.coefficient + i);
		*(exponent + i) = *(poly2.exponent + i);
	}
}
Polynomial::~Polynomial() {
	cout << "Freeing Memory..."<< endl;
	delete[] coefficient;
	delete[] exponent;
}
Polynomial::Polynomial() {

}