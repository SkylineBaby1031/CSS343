#include "classics.h"
#include <sstream>
//--------------------------------------------------------------------------
// constractor
//--------------------------------------------------------------------------
Classics::Classics(const string& str)
{
	loadString(str);
}

Classics::Classics(const string& actor, const int& MovieMonth, const int& MovieYear)
{
	majorActor = actor;
	month = MovieMonth;
	year = MovieYear;
}

//-------------------~Classics()---------------------------------
// ~Classics()
//---------------------------------------------------------------
Classics::~Classics()
{
}

//-------------------------isEqual()-------------------------------
//  compare current moive with other movie is equal or not
//---------------------------------------------------------------
bool Classics::isEqual(const Movie* other) const
{
	const Classics*  classicPtr = (const Classics*)other;
	return ((majorActor == classicPtr->majorActor) && (year == classicPtr->year) && (month == classicPtr->month));
}

//---------------------isGreater()----------------------------------
// compare current moive with other moive greater or not
//-----------------------------------------------------------------
bool Classics::isGreater(const Movie* other) const
{
	const Classics*  classicPtr = (const Classics*)other;
	return ((year > classicPtr->year) || ((year == classicPtr->year) && (month > classicPtr->month))
		|| ((year == classicPtr->year) && (month == classicPtr->month) && (majorActor > classicPtr->majorActor)));
}


//-----------------------loadString()------------------------------------
// helper function read the string and assign information to current movie
//------------------------------------------------------------------------
void Classics::loadString(const string& info) {
	stringstream ss;
	ss << info;
	string temp;
	getline(ss, temp, ',');      // get type of movie (char)
	type = temp[0];
	getline(ss, temp, ',');      // get stock number (int)
	stringstream(temp) >> stock;
	getline(ss, director, ',');  // get director string
	getline(ss, title, ',');     // get title string
	ss >> temp;                  // add second name to first name
	majorActor += temp;
	majorActor += ' ';
	ss >> temp;                 // add second name to first name
	majorActor += temp;
	ss >> month;                // add month
	ss >> year;                 // add month
}

//--------------------displayMovieInfo()-------------------------------------
// Display all movie's information month year majoracator
//---------------------------------------------------------------------------
string  Classics::displayMovieInfo() const {
	ostringstream stringStream;
	stringStream << " "  << setw(7) <<left  << month << setw(6) << left << year <<
		setw(18) << left << majorActor << setw(23) << left <<
		 title << setw(17) << left <<  director << setw(5) << left<< stock << endl;
	return  stringStream.str();

}

//------------------------displayCustomerInfo()-------------------------------
// display all customer information
//-----------------------------------------------------------------------------
string Classics::displayCustomerInfo() const {
	ostringstream stringStream;
	stringStream << " classic: " << month << " " << year << ' ' << majorActor  << title <<  director;
	return  stringStream.str();
}
