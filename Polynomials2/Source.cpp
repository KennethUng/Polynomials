#include <iostream>
#include "Polynomial.h"
#include <string>

using namespace std;

int main() {
	string poly1, poly2;
	int choice;
	cout << "The form of the polynomials should be: ax^n + bx^(n+1) + cx^(n+2) .... ?x^(n+?), where n = 0" << endl;
	cout << "First Polynomial:";
	getline(cin, poly1);
	cout << "\n\nSecond Polynomial:";
	getline(cin, poly2);
	Polynomial first(poly1), second(poly2);
	cout << "\nWhat would you like to do?";
	cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
	cin >> choice;
	while (choice != 5) {
		if (choice >= 5) {
			cout << "\nChoose again.";
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
		}
		switch (choice) {
		case 1: 
			first + second;
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		case 2:
			//first - second;
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		case 3:
			//first * second;
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		case 4:
			//first = second;
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		}
	}
}