#include "Polynomial.h"
#include <iostream>
#include <string>

using namespace std;
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
	for (int i = 0; i < poly.length() - 1; i++) {
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
	for (int i = 0; i < input.length() - 1; i++) {
		if (input.substr(i, 2) == "x^") {
			*(exponent + stoi(input.substr(i + 2, 1))) = stoi(input.substr(i+2,1));
		}
	}
	for (int i = 0; i < input.length(); i++) {
		if (input.substr(i, 1) == " " && input.substr(i + 2, 1) != " ") {
			int j = (i + 1);
			string answer;
			while (input.substr(j, 1) != "x") {
				answer += input.substr(j, 1);
				j++;
			}
			for (int k = i; k < input.length(); k++) {
				if (input.substr(k, 1) == "x") {
					*(coefficient + stoi(input.substr(k + 2, 1))) = stoi(answer);
					break;
				}
			}
		}
	}
}

Polynomial::Polynomial(string poly) {
	input = poly;
}