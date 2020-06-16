#pragma once
#include <string>
#include "movie.h"
#include <iostream>
#include <fstream>
using namespace std;
//--------------------------  class Drama --------------------------------
// child class of Movie
// Dramma Movie sorts by director and title.
// by director and title.
//---------------------------------------------------------------------------
class Drama : public Movie {
public:

	Drama(const string&);
	Drama(const string&, const string&);
	virtual ~Drama();     // destructor

	static const char comandType = 'D';        // comand char

	virtual string displayMovieInfo() const;
	virtual string displayCustomerInfo() const;
protected:

	virtual bool isEqual(const Movie* other) const;
	virtual bool isGreater(const Movie* other) const;

};
