/*
* Created by : Kenneth Ung
* Date : 5/26/16
* Project 3 : Polynomials
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <string>

//Class declaration of Polynomials
class Polynomial {
private:
	float *coefficient; //Completed
	int *exponent; //Completed
	int size; //Completed
	void setSize(std::string); //Completed
	void setPolynomial(std::string); //Completed
public:
	~Polynomial();//Completed
	Polynomial(const Polynomial &);//Completed
	Polynomial();//Completed
	Polynomial(std::string); //Completed
	Polynomial operator+(const Polynomial &);//Completed
	Polynomial operator-(const Polynomial &);//Completed
	Polynomial operator*(const Polynomial &);//Completed
	Polynomial& operator=(const Polynomial &);//Completed
	void display();//Completed
};
#endif

