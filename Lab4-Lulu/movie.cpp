#include "movie.h"
//----------------------Movie()---------------------------------------------
// constractor
//--------------------------------------------------------------------------
Movie::Movie()
{
	type = ' ';   // initial all data
	stock = 0;
	director ="";
	title = "";
	year = 0;
}

//--------------------------loadString()---------------------------------------
// assign inforamtion to a current movie
//--------------------------------------------------------------------------
void Movie::loadString( const string& info)
{
	stringstream ss;
	ss << info;                      // insert string info
	string temp;
	getline(ss, temp, ',');       // get movie type
	type = temp[0];               // assign movie type
	getline(ss, temp, ',');       // get stock
	stringstream ( temp ) >> stock; // assign stock
	getline(ss, director, ',');      // assign director
	getline(ss, title, ',');         // assign title
	getline(ss, temp, ',');          // get year
	stringstream(temp) >> year;      // assign year
}

//---------------addStock()-----------------------------------------------
// increase stock +1 function
//--------------------------------------------------------------------------
bool Movie::addStock(int addToStock)
{
	if (addToStock < 0) { return false; }
      stock += addToStock; // +1 
	  return true;
}

//------------------------getStock()---------------------------------------
// get stock
//--------------------------------------------------------------------------
int Movie::getStock() {
	return stock;
}

//----------------------decreaseStock()-------------------------------------
// decrease stock -1 function
//--------------------------------------------------------------------------
bool Movie::decreaseStock()
{
	if (stock <= 0) { return false; }
	stock--;    // -1
	return true;
}
