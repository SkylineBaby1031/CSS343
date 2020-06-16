
//#include "pch.h"
#include "poly.h"
#include <vector>
using namespace std;

// ----------------------- poly.cpp ----------------------------------------
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

//------------------------- Constructors ---------------------------------------
// ------------------------ Poly() ---------------------------------------------  
// Description: 
//		Initial the Polynomial with 0 coefficient and power of 0 if there has no
//		input for Poly();
// -----------------------------------------------------------------------------  
Poly::Poly()
{
	polySize = 1;
	polyArray = new int[polySize];
	polyArray[0] = 0;
} // end of Poly()

// ------------------------ Poly(int coefficient) ------------------------------  
// Description: 
//		Initial the Polynomial with only 1 input as coefficient;
// -----------------------------------------------------------------------------  
Poly::Poly(int coefficient)
{
	polySize = 1;
	polyArray = new int[polySize];
	polyArray[0] = coefficient;
} // end of Poly(int coefficient)

// ------------------------ Poly(int coefficient, int power) -------------------  
// Description: 
//		Initial the Polynomial with coefficient and power;
// -----------------------------------------------------------------------------  
Poly::Poly(int coefficient, int power)
{
	polySize = power + 1;
	polyArray = new int[polySize];
	for (int i = 0; i < polySize; i++)
	{
		polyArray[i] = 0;
	}
	polyArray[power] = coefficient;
} // end of Poly(int coefficient, int power)

// ------------------------ Poly(const Poly& poly) -----------------------------  
// Description: 
//		Deep copy of a poly Array;
// -----------------------------------------------------------------------------  
Poly::Poly(const Poly& poly)
{
	polySize = poly.polySize;
	polyArray = new int[polySize];
	for (int i = 0; i < polySize; i++)
	{
		polyArray[i] = poly.polyArray[i];
	}
} // end of Poly(const Poly& poly)

//------------------------ Deconstructors --------------------------------------
Poly::~Poly()
{
}


//------------------------- Overloading Operators ------------------------------

// ------------------------ "+" overloading ------------------------------------  
// Description: 
//		Overloading the addition operators "+" to add two polynomials; 
// -----------------------------------------------------------------------------
Poly Poly::operator+(const Poly& poly) const
{
	Poly newPoly = *this;
	newPoly += poly;
	return newPoly;
}//end of "+" overloading

// ------------------------ "-" overloading ------------------------------------  
// Description: 
//		Overloading the substraction operators "-" to substract two polynomials; 
// -----------------------------------------------------------------------------
Poly Poly::operator-(const Poly& poly) const
{
	Poly newPoly = *this;
	newPoly -= poly;
	return newPoly;
}//end of "-" overloading

// ------------------------ "*" overloading ------------------------------------  
// Description: 
//		Overloading the multiplication operators "*" to multiplication two 
//		polynomials; 
// -----------------------------------------------------------------------------
Poly Poly::operator*(const Poly& poly) const
{
	Poly newPoly = *this;
	newPoly *= poly;
	return newPoly;
}//end of "*" overloading

// ------------------------ "=" overloading ------------------------------------  
// Description: 
//		The assignment operator (=) to assign one polynomial to another; 
// -----------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& poly)
{
	int size;
	if (poly.polySize < polySize)
	{
		size = polySize;
	}
	else
	{
		size = poly.polySize;
	}//find the larger size of the array

	int *newArray = new int[size]; //init newArray
	for (int i = 0; i < size; i++)
	{
		newArray[i] = 0;
	}
	for (int i = 0; i < poly.polySize; i++)
	{
		newArray[i] = poly.polyArray[i];
	}//assign into this array

	delete polyArray;
	polyArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		polyArray[i] = newArray[i];
	}
	polySize = size;
	delete newArray;
	newArray = NULL;
	return *this;
}//end of "=" overloading

// ------------------------ "+=" overloading ------------------------------------  
// Description: 
//		Overloading he addition assignment operators (+=)
// ------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly& poly)
{
	bool polyIsLonger = poly.polySize >= polySize;//checking if poly has the larger array size
	//retrieve max size of polynomial
	int maxSize;
	if (polyIsLonger)
	{
		maxSize = poly.polySize;
	}
	else
	{
		maxSize = polySize;
	}
	int * newArray = new int[maxSize];
	int minSize;
	if (poly.polySize <= polySize)
	{
		minSize = poly.polySize;
	}
	else
	{
		minSize = polySize;
	}
	
	int extendedSize = abs(poly.polySize - polySize);//get the extended size;

	int i;
	for (i = 0; i < minSize; i++)
	{
		newArray[i] = polyArray[i] + poly.polyArray[i];
	}

	if (polyIsLonger)
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = poly.polyArray[j] + 0;
		}
	}// replace with 0 if there's no more element in the array
	else
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = polyArray[j] + 0;
		}
	}
	// deep copy the data from tempArray to this->array
	delete polyArray;
	polyArray = new int[maxSize];
	for (int j = 0; j < maxSize; j++)
	{
		polyArray[j] = newArray[j];
	}
	polySize = maxSize;
	delete newArray;
	newArray = NULL;
	return *this;
}//end of "+=" overloading

// ------------------------ "-=" overloading ------------------------------------  
// Description: 
//		Overloading he substraction assignment operators (-=)
// ------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly& poly)
{

	bool polyIsLonger = poly.polySize >= polySize;

	int maxSize;
	if (polyIsLonger)
	{
		maxSize = poly.polySize;
	}
	else
	{
		maxSize = polySize;
	}

	int * newArray = new int[maxSize];

	int minSize = (poly.polySize <= polySize) ? poly.polySize : polySize;

	int extendedSize = abs(poly.polySize - polySize);

	int i;
	for (i = 0; i < minSize; i++)
	{
		newArray[i] = polyArray[i] - poly.polyArray[i];
	}
	
	if (polyIsLonger)// replace with 0 if there's no more element in the array
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = 0 - poly.polyArray[j];
		}
	}
	else
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = polyArray[j];
		}
	}

	// deep copy the data from tempArray to this->array
	delete polyArray;
	polyArray = new int[maxSize];
	for (int j = 0; j < maxSize; j++)
	{
		polyArray[j] = newArray[j];
	}
	polySize = maxSize;
	delete newArray;
	newArray = NULL;
	return *this;
}//end of "-=" overloading

// ------------------------ "*=" overloading ------------------------------------  
// Description: 
//		Overloading the multiplication assignment operators (*=)
// ------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly& poly)
{
	//the maxSiz is the sum of each polynomial's biggest power minus 1, because both of the polynomial has power of 0
	int maxSize = poly.polySize + polySize - 1;
	int * newArray = new int[maxSize];
	//init newArray
	for (int i = 0; i < maxSize; i++)
	{
		newArray[i] = 0;
	}


	for (int i = 0; i < polySize; i++)
	{
		for (int j = 0; j < poly.polySize; j++)
		{
			newArray[i + j] += polyArray[i] * poly.polyArray[j];
		}
	}
	// deep copy the data from tempArray to this->array
	delete polyArray;
	polyArray = new int[maxSize];
	for (int j = 0; j < maxSize; j++)
	{
		polyArray[j] = newArray[j];
	}
	polySize = maxSize;
	delete newArray;
	newArray = NULL;

	return *this;
}//end of "*=" overloading

// ------------------------ "==" overloading ------------------------------------  
// Description: 
//		The equality operators (==) 
// ------------------------------------------------------------------------------
bool Poly::operator==(const Poly& poly) const
{
	//check which length is longer
	bool thisLengthShorter = polySize < poly.polySize;
	int shortSize = (thisLengthShorter) ? polySize : poly.polySize;
	int longSize = (!thisLengthShorter) ? polySize : poly.polySize;

	//compare the elements
	for (int i = 0; i < shortSize; i++)
	{
		if (polyArray[i] != poly.polyArray[i])
		{
			return false;
		}
	}
	//check if the rest of elements are all 0
	if (thisLengthShorter)
	{
		for (int i = shortSize; i < longSize; i++)
		{
			if (poly.polyArray[i] != 0)
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		for (int i = shortSize; i < longSize; i++)
		{
			if (polyArray[i] != 0)
			{
				return false;
			}
		}

		return true;
	}

	return false;
}//end of "==" overloading

// ------------------------ "!=" overloading ------------------------------------  
// Description: 
//		The inequality operators (!=) 
// ------------------------------------------------------------------------------
bool Poly::operator!=(const Poly& poly) const
{
	return !(*this == poly);
}//end of "!=" overloading

//------------------------- Accessors -------------------------------------------
// ------------------------ "<<" overloading ------------------------------------  
// Description: 
//		Overload << to output an entire polynomial, print “ +5x^3 -2x^2 +4” to 
//		represent the Poly 5 x cubed minus 2 x squared plus 4;
// ------------------------------------------------------------------------------
ostream& operator<<(ostream &oStr, const Poly &poly)
{
	int count = 0;
	for (int i = 0; i < poly.polySize; i++)
	{
		count += poly.polyArray[i];
	}
	if (count == 0)
	{
		oStr << "0";
		return oStr;
	}

	// print poly element whose power over or equal  2
	for (int i = poly.polySize - 1; i > 1; i--)
	{
		if (poly.polyArray[i] != 0)
		{
			if (poly.polyArray[i] > 0)
			{
				oStr << '+';
			}
			oStr << poly.polyArray[i] << "x^" << i;
		}
	}

	// print power=1
	if (poly.polyArray[1] != 0)
	{
		if (poly.polyArray[1] > 0)
		{
			oStr << '+';
		}
		oStr << poly.polyArray[1] << 'x';
	}

	// print power= 0
	if (poly.polyArray[0] != 0)
	{
		if (poly.polyArray[0] > 0)
		{
			oStr << '+';
		}
		oStr << poly.polyArray[0];
	}

	return oStr;
}//end of "<<" overloading

// ------------------------ getCoeff(int power) ---------------------------------  
// Description: 
//		Get one term's coefficient;
// ------------------------------------------------------------------------------
int Poly::getCoeff(int power)
{
	// if power over the limit  return 0
	if (power >= polySize || power < 0)
	{
		return 0;
	}
	return polyArray[power];
}//end of getCoeff(int power)

//------------------------- Mutators --------------------------------------------
// ------------- SplitString(string s, vector<string>& v, const char c) ---------  
// Description: 
//		Helper function. Split the string;
// ------------------------------------------------------------------------------
static void SplitString(string s, vector<string>& v, const char c)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			v.push_back(s.substr(count, i - count));
			count = i + 1;
		}
	}
	v.push_back(s.substr(count, s.size()));
}

// ------------------------ ">>" overloading ------------------------------------  
// Description: 
//		Overload >> to input all coeffs (sets all terms of one Poly, in a loop; 
//		it is expected that a user enters one coefficient and an exponent 
//		repeatedly, Enters -1 for both when done; no data type-checking). 
// ------------------------------------------------------------------------------
istream& operator>>(istream& iStr, Poly& poly)
{
	bool inputLoop = true;
	//get nums list from input, and retrieve the biggest power number to decide the size for poly's array
	string str = "";

	while (inputLoop)
	{
		string line = "";
		getline(iStr, line);
		if (line.size() >= 5)
		{
			inputLoop = !(line.substr(line.size() - 5, 5) == "-1 -1");
		}
		str += line;
		//if no space at last input
		if (line[line.size() - 1] != ' ') {

			str += " ";
		}
	}
	str = str.substr(0, str.size() - 1);
	vector<string> numStr;
	//split the string by space
	SplitString(str, numStr, ' ');
	int numSize = numStr.size() - 2;
	int *nums = new int[numSize];
	int bigstPow = 0;
	for (int i = 0; i < numSize; i++)
	{
		nums[i] = atoi(numStr[i].c_str());
		if (i % 2 != 0)
		{
			bigstPow = (bigstPow >= nums[i]) ? bigstPow : nums[i];
		}
	}
	int newLength = bigstPow + 1;
	
	int *newArray = new int[newLength];

	for (int i = 0; i < newLength; i++)
	{
		newArray[i] = 0;
	}

	for (int i = 0; i < numSize; i += 2)
	{
		newArray[nums[i + 1]] += nums[i];
	}

	//deep copy of temp array to assign poly's array
	delete poly.polyArray;
	poly.polyArray = new int[newLength];
	for (int j = 0; j < newLength; j++)
	{
		poly.polyArray[j] = newArray[j];
	}
	poly.polySize = newLength;

	delete nums;
	nums = NULL;
	delete newArray;
	newArray = NULL;

	return iStr;
}//end of ">>" overloading

// ------------------------ setCoeff(int coeff, int power) ------------------------  
// Description: 
//		Set one coefficient;
// ------------------------------------------------------------------------------
bool Poly::setCoeff(int coeff, int power)
{
	// if power is incorrect   return false
	if (power < 0)
	{
		return false;
	}
	//if power if over the limit in this array, extend this array
	if (power >= polySize)
	{
		int newLength = power + 1;
		int * newArray = new int[newLength];
		for (int i = 0; i < polySize; i++)
		{
			newArray[i] = polyArray[i];
		}
		for (int i = polySize; i < power; i++)
		{
			newArray[i] = 0;
		}
		delete polyArray;
		polyArray = new int[newLength];
		for (int i = 0; i < newLength; i++)
		{
			polyArray[i] = newArray[i];
		}
		polySize = newLength;
		delete newArray;
		newArray = NULL;
	}
	//set coeff on special power
	polyArray[power] = coeff;
	return true;
}//end of setCoeff(int coeff, int power) 