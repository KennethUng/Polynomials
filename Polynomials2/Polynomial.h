
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <string>

//Class declaration of Polynomials
class Polynomial {
private:
	float *coefficient; //Completed
	int *exponent; //??
	std::string input; //Completed
	int size; //Completed
	void setSize(std::string); //Completed
	void setPolynomial(); //Completed
public:
	~Polynomial();
	Polynomial(Polynomial &);
	Polynomial(std::string); //Completed
	void operator+(Polynomial);
	void operator-(Polynomial);
	void operator*(Polynomial);
	void operator=(Polynomial);
	void display();
};
#endif

