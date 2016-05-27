/*
* Created by : Kenneth Ung
* Date : 5/26/16
* Project 3 : Polynomials
*/
#include <iostream>
#include "Polynomial.h"
#include <string>

using namespace std;

int main() {
	string poly1, poly2;
	int choice;
	cout << "The form of the polynomials should be: ax^n + bx^(n+1) + cx^(n+2) .... ?x^(n+?), where n = 0" << endl;
	cout << "YOU MUST INCLUDE SPACES BETWEEN YOUR OPERATORS: ie. 2x^0 + 2x^2, there is a space between 0 and + and a space between + and 2" << endl;
	cout << "First Polynomial:";	
	getline(cin, poly1);
	cout << "\n\nSecond Polynomial:";
	getline(cin, poly2);
	Polynomial first(poly1), second(poly2);
	//Polynomial first("x^0 + x^1 + x^2 + x^3 + x^4"); //<-- Test Cases
	//Polynomial second("x^0 + x^1 + x^2 + x^3"); //<-- Test Cases
	cout << endl << "Polynomial 1: ";
	first.display();
	cout << endl << "Polynomial 2: ";
	second.display();
	cout << "\n\nWhat would you like to do?";
	cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
	cin >> choice;
	while (choice != 5) {
		if (choice >= 5) {
			cout << "\nChoose again.";
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
		}
		switch (choice) {
		case 1: {
			Polynomial third = first + second;
			cout << "(";
			first.display();
			cout << ") + (";
			second.display();
			cout << ") = ";
			third.display();
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		}
		case 2: {
			Polynomial third = first - second;
			cout << "(";
			first.display();
			cout << ") - (";
			second.display();
			cout << ") = ";
			third.display();
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		}
		case 3: {
			Polynomial third = first * second;
			cout << "(";
			first.display();
			cout << ") * (";
			second.display();
			cout << ") = ";
			third.display();
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		}
		case 4: {
			first = second;
			first.display();
			cout << " = ";
			second.display();
			cout << "\n\n(1)Addition\n\n(2)Subtraction\n\n(3)Multiplication\n\n(4)Assignment\n\n(5)Quit\n";
			cin >> choice;
			break;
		}
		}
	}
}