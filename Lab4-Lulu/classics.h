#pragma once
#include <string>
#include "movie.h"
using namespace std;
//--------------------------  class Classics --------------------------------
//  child class of Movie
//  have  month and majorActor
// sorted by majoractor, month, and year
//---------------------------------------------------------------------------

class Classics : public Movie {
public:

	Classics(const string&);
	Classics(const string&, const int&, const int&);
	virtual ~Classics();      // destructor

	static const char comandType = 'C';      // command char

	virtual string displayCustomerInfo() const;        // display custoemr information
	virtual string displayMovieInfo() const;      // display movie information

protected:

	void loadString(const string&);
	virtual bool isEqual(const Movie* other) const;       // operator=
	virtual bool isGreater(const Movie* other) const;     // operator>=
	int month;
	string majorActor;
};
