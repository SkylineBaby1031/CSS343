
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//--------------------------  class Movie -----------------------------------
//  abstract class Movie.
// Abstact class for child classes Drama, Comdey,Classiscs.
//---------------------------------------------------------------------------
class Movie {
public:

	virtual ~Movie() {};                // destructor
	virtual bool isEqual(const Movie* rhs) const = 0;   // pure virtual
	virtual bool isGreater(const Movie* rhs) const = 0; // pure virtual
	virtual string displayMovieInfo() const = 0;     //  pure virtual
	virtual string displayCustomerInfo() const = 0;    // pure virtual
	virtual bool addStock(int);    // +1 stock
	virtual bool decreaseStock();       // -1 stock
	virtual int getStock();             // get stock

protected:

	Movie();
	void loadString(const string&);   
	char type;
	int stock;
	string director;
	string title;
	int year;

};
#endif
