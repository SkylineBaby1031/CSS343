#pragma once

#include <string>
#include <iostream>
using namespace std;

// ----------------------- poly.h ----------------------------------------
// Programmer Name: Lu Lu
// Course Section Number : CSS343 B
// Creation Date : 4/9/2019
// Date of Last Modification : 4/9/2019
// ---------------------------------------------------------------------------
// Purpose - 
//	Poly class: Present a polynomial function, store data in array
//		-allows input for polynomial.
//		-allows to execute +, -,* for two polynomials
//		-allows to check equal or not equal for two polynomials
//		-allows to check or change the coefficient at special power of the 
//		 polynomial
// --------------------------------------------------------------------------- 
// Assumption :
//	-User will always type -1 -1 when they want to end input,
//	-if user type in multiple pairs of numbers with the same power, 
//	they attend to add the two coeffcients for the same power's number 
//	(e.g  2 3 2 3 -1 -1, would represent 4x^3)
// --------------------------------------------------------------------------- 

class Poly
{
	friend ostream& operator<<(ostream &outStream, const Poly &poly);
	friend istream& operator>>(istream &inStream, Poly &poly);
public:
	// Constructors - Destructor
	Poly();
	Poly(int coefficient, int power);
	Poly(int coefficient);
	~Poly();
	Poly(const Poly& poly);

	// Operator Overloads
	//(a)------- Overloading +,-,* ----------------
	Poly operator+(const Poly &poly) const;
	Poly operator-(const Poly &poly) const;
	Poly operator*(const Poly &poly) const;

	//(b)------- Overloading = --------------------
	Poly& operator=(const Poly& poly);

	//(c)------- Overloading +=, -=, *= -----------
	Poly& operator+=(const Poly &poly);
	Poly& operator-=(const Poly &poly);
	Poly& operator*=(const Poly &poly);

	//(d)------- Overloading ==, != ---------------
	bool operator==(const Poly &poly) const;
	bool operator!=(const Poly &poly) const;

	//---------- Accessors ------------------------

	int getCoeff(int power);

	//---------- Mutators -------------------------

	bool setCoeff(int coeff, int power);

private:
	int* polyArray;
	int coefficient;
	int power;
	int polySize;

};
