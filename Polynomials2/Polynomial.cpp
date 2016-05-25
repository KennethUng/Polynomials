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
		if (poly.substr(i, 1) == "^") {
			/*Size of the Polynomial will be highest number + 1, since we want the indexes to go from 0-size.*/
			size = (stoi(poly.substr(i + 1, 1)) + 1);
		}
	}
	coefficient = new float[size]();
	exponent = new int[size]();
}
/*This will create the polynomial and store it into an array.*/
void Polynomial::setPolynomial() {
	/*Begin Coefficient adding..*/
	for (int i = 0; i < input.length(); i++) {
		if (i == 0) {
			string answer;
			if (input.substr(i, 1) == "x") {
				*(coefficient + stoi(input.substr(i + 2, 1))) = 1;
			}
			int j = 0;
			while (input.substr(j, 1) != "x") {
				answer+= input.substr(j, 1);
				j++;
			}
			if (answer.length() == 1 && answer.substr(0, 1) == "-") {
				answer += "1";
			}
			*(coefficient + stoi(input.substr(j+2,1))) = stof(answer);

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
			*(coefficient + stoi(input.substr(j + 2, 1))) = stof(answer);
		}
	}
	/*End Coefficient adding...*/
	/*Begin Exponent Adding...*/
	for (int i = 0; i < input.length(); i++) {
		if (input.substr(i, 1) == "^") {
			*(exponent + stoi(input.substr(i + 1, 1))) = stoi(input.substr(i + 1, 1));
		}
	}

}

Polynomial::Polynomial(string poly) {
	input = poly;
	setSize(poly);
	setPolynomial();
//	for (int i = 0; i < size; i++) {
//		cout << "[" << coefficient[i] << "]";
//	}
}
void Polynomial::operator+(Polynomial poly2) {
	float* add;
	if (size == poly2.size) {
		add = new float[size];
		for (int i = 0; i < size; i++) {
			*(add + i) = (*(coefficient + i) + *(poly2.coefficient + i));
		}
	}

}
void Polynomial::operator=(Polynomial poly2) {
	delete[] coefficient;
	delete[] exponent;
	coefficient = new float[poly2.size];
	exponent = new int[poly2.size];
	for (int i = 0; i < poly2.size; i++){
		*(coefficient + i) = *(poly2.coefficient + i);
		*(exponent + i) = *(poly2.exponent + i);

	}
}
Polynomial::Polynomial(Polynomial &Poly2) {
	input = Poly2.input;
	*coefficient = *Poly2.coefficient;
	*exponent = *Poly2.exponent;
}
Polynomial::~Polynomial() {
	cout << "Freeing Memory..."<< endl;
	delete[] coefficient;
	delete[] exponent;
}