#include "comedy.h"
//--------------------Comedy()-------------------------------------------
// Comedy()
// Constractor
//--------------------------------------------------------------------------
Comedy::Comedy(const string& str)
{
	loadString(str);
}

Comedy::Comedy(const string& comedyTitle, const int& comedyYear)
{
	title = comedyTitle;
	year = comedyYear;
}

//------------------~Comedy()------------------------------------------------
// ~Comedy()
//--------------------------------------------------------------------------
Comedy::~Comedy()
{

}

//-------------------------isEqual()-------------------------------
//  compare current moive with other movie is equal or not
//---------------------------------------------------------------
bool Comedy::isEqual(const Movie* other) const
{
	const Comedy* comedyPtr = (const Comedy*)other;
	return ((title == comedyPtr->title) && (year == comedyPtr->year));
}
//---------------------isGreater()----------------------------------
// compare current moive with other moive greater or not
//-----------------------------------------------------------------
bool Comedy::isGreater(const Movie* other) const
{
	const Comedy* comedyPtr = (const Comedy*)other;
	return ((title > comedyPtr->title) || ((title == comedyPtr->title) && (year > comedyPtr->year)));
}
//--------------------displayMovieInfo()-------------------------------------
// Display all movie's information month year majoracator
//---------------------------------------------------------------------------
string Comedy::displayMovieInfo() const
{
	ostringstream stringStream;
	stringStream  << setw(33) <<left << title << setw(1) << right << year
		<< setw(20) << left << director << setw(20) << left << stock << endl;
	return stringStream.str();
}

//------------------------displayCustomerInfo()-------------------------------
// display all customer information
//-----------------------------------------------------------------------------
string Comedy::displayCustomerInfo() const
{
	ostringstream stringStream;
	stringStream << " comedy: "<< title << " " << director
		<< " " << year;;
	return stringStream.str();
}
