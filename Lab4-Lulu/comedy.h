#pragma once
#include <string>
#include "movie.h"
using namespace std;
//--------------------------  class Comedy --------------------------------
// child class of Movie
//  sorts by title and year
//---------------------------------------------------------------------------
class Comedy : public Movie {
public:

	Comedy(const string&, const int&);
	Comedy(const string&);
	virtual ~Comedy();             // destructor

	static const char comandType = 'F';        // command char

	virtual string displayMovieInfo() const;
	virtual string displayCustomerInfo() const;
protected:

	virtual bool isEqual(const Movie* other) const;
	virtual bool isGreater(const Movie* other) const;

};
