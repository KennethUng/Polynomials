#include "Polynomial.h"
#include <iostream>
#include <string>

using namespace std;

int Polynomial::getSize() {
	return size;
}
void Polynomial::display() {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << *(coefficient + i) << "x^" << *(exponent + i) << " ";
		}
		else if (*(coefficient + i) < 0) {
			cout << "- " << *(coefficient + i) * -1 << "x^" << *(exponent + i) << " ";
		}
		else if (*(coefficient + i) > 0) {
			cout << "+ " << *(coefficient + i) << "x^" << *(exponent + i) << " ";
		}
	}
}

void Polynomial::setSize(string poly) {
	//Parses the string to find the highest exponent and passes that exponent to the private variable size.
	for (unsigned int i = 0; i < (poly.length() - 1); i++) {
		if (poly.substr(i, 1) == "^") {
			size = (stoi(poly.substr(i + 1, 1)) + 1);
		}
	}
}
/*This will create the polynomial and store it into an array.*/
void Polynomial::setPolynomial() {
	int counter;
	coefficient = new float[size];
	exponent = new int[size];
	for (unsigned int i = 0; i < input.length() - 1; i++) {
		if (input.substr(i, 2) == "x^") {
			*(exponent + stoi(input.substr(i + 2, 1))) = stoi(input.substr(i+2,1));
		}
	}
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input.substr(i, 1) == " " && input.substr(i + 2, 1) != " ") {
			int j = (i + 1);
			string answer;
			while (input.substr(j, 1) != "x") {
				if (input.substr(j, 1) != "+" && input.substr(j, 1) != " ") {
					answer += input.substr(j, 1);
					j++;
				}
			}
			for (unsigned int k = i; k < input.length(); k++) {
				if (input.substr(k, 1) == "x") {
					*(coefficient + stoi(input.substr(k + 2, 1))) = stof(answer);
					break;
				}
			}
		}
	}
}

Polynomial::Polynomial(string poly) {
	input = poly;
	setSize(poly);
	setPolynomial();
}
void Polynomial::operator+(Polynomial poly2) {
	float* add;
	if (size == poly2.getSize()) {
		add = new float[size];
		for (int i = 0; i < size; i++) {
			*(add + i) = (*(coefficient + i) + *(poly2.coefficient + i));
		}
	}

}
void Polynomial::operator=(Polynomial poly2) {
	coefficient = new float[poly2.getSize()];
	exponent = new int[poly2.getSize()];
	for (int i = 0; i < poly2.getSize(); i++){
		*(coefficient + i) = *(poly2.coefficient + i);
		*(exponent + i) = *(poly2.exponent + i);

	}
}