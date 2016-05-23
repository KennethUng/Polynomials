
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <string>

//Class declaration of Polynomials
class Polynomial {
private:
	float *coefficient;
	int *exponent;
	std::string input;
	int size;
	void setSize(std::string);
	void setPolynomial();
public:
	Polynomial(std::string);
	void operator+(Polynomial);
	void operator-(Polynomial);
	void operator*(Polynomial);
	void operator=(Polynomial);
	void display();
	int getSize();

};
#endif
