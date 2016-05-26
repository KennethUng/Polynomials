
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <string>

//Class declaration of Polynomials
class Polynomial {
private:
	float *coefficient; //Completed
	int *exponent; //??
	int size; //Completed
	void setSize(std::string); //Completed
	void setPolynomial(std::string); //Completed
public:
	~Polynomial();
	Polynomial(const Polynomial &);
	Polynomial();
	Polynomial(std::string); //Completed
	Polynomial operator+(const Polynomial &);
	Polynomial operator-(const Polynomial &);
	Polynomial operator*(const Polynomial &);
	Polynomial& operator=(const Polynomial &);
	void display();
};
#endif

