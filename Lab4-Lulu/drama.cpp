#include "drama.h"
#include <sstream>
//----------------- Drama()---------------------------------------
// Constractor
//----------------------------------------------------------------
Drama::Drama(const string& str)
{
	loadString(str);
}

Drama::Drama(const string& drameTitle, const string& drameDirector) {
	title = drameTitle;
	director = drameDirector;
}

//----------------- ~Drama()-------------------------------------------------
// Destructor
//----------------------------------------------------------------
Drama::~Drama()
{
}

//-------------------------isEqual()-------------------------------
//  compare current moive with other movie is equal or not
//---------------------------------------------------------------
bool Drama::isEqual (const Movie* other) const {
	const Drama* dramaPtr = (const Drama*)other;
	return ((title == dramaPtr->title) && (director == dramaPtr->director));
}

//---------------------isGreater()----------------------------------
// compare current moive with other moive greater or not
//-----------------------------------------------------------------
bool Drama::isGreater(const Movie* other) const {
	const Drama* dramaPtr = (const Drama*)other;
	return ((director > dramaPtr->director) || ((director == dramaPtr->director) && (title > dramaPtr->title)));
}

//--------------------displayMovieInfo()-------------------------------------
// Display all movie's information month year majoracator
//---------------------------------------------------------------------------
string Drama::displayMovieInfo() const {
	ostringstream stringStream;
	stringStream << setw(21) << left << director << setw(21) << left << title;
	stringStream << setw(9) << right << year << setw(8) << right << stock << endl;
	return stringStream.str();
}

//------------------------displayCustomerInfo()-------------------------------
// display all customer information
//-----------------------------------------------------------------------------
string Drama::displayCustomerInfo() const {
	ostringstream stringStream;
	stringStream << " drama: "<< director << " " << title;
	stringStream << " " << year;;
	return stringStream.str();
}
