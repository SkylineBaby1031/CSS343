#include "InventoryHelper.h"
//-------------------InventoryHelper()-----------------------------------------
// read line by line
//  creates different objects of Moive
//-------------------------------------------------------------------------

void InventoryHelper::processInventory(ifstream& infile) {

	count = 0;
	string s;                                     //  movie information

	for (;;) {

		getline(infile, s);                       // inser info into string
		if (infile.eof()) break;

		Movie* a = MovieFactory::createMovie(s);

		switch (s[0])
		{
		case Drama::comandType:
			dramaBST.insert(a);             // insert Drama movie
			break;
		case Comedy::comandType:
			comedyBST.insert(a);            // insert Comedy movie
			break;
		case  Classics::comandType:
			classicsBST.insert(a);          // insert Classics movie
			break;
		default:
			addError(s);                    
			break;
		}
	}
	displayErrors();                              // display errors
}

Movie* InventoryHelper::retriveMovie(Movie* temp, char type)  {
	// use swith case to find appropriate Tree
	switch (type)
	{
	case 'D':
		return dramaBST.retrieve(temp);
		break;
	case 'F':
		return comedyBST.retrieve(temp);
		break;
	case 'C':
		return classicsBST.retrieve(temp);
		break;
	default:
		break;
	}
	return NULL;
}

//----------------------displayAll()-----------------------------------------------
// display the inventroy and information
//------------------------------------------------------------------------------
void InventoryHelper::displayAll() {
	cout << endl;
	cout << "*****************************************************************************" << endl;
	cout << "                                Comedies Inventory " << endl;
	cout << "*****************************************************************************" << endl;
	cout << " Title                           Year Director          Stock" << endl;
	comedyBST.displayAll();
	cout << "*****************************************************************************" << endl;
	cout << "                                Dramas Inventory " << endl;
	cout << "*****************************************************************************" << endl;
	cout << " Director             Title                    Year     Stock" << endl;
	dramaBST.displayAll();
	cout << "*****************************************************************************" << endl;
	cout << "                                Classics Inventory" << endl;
	cout << "*****************************************************************************" << endl;
	cout << " Month  Year  Major actor        Title                  Director       Stock" << endl;
	classicsBST.displayAll();
	cout << "*****************************************************************************" << endl;
	cout << endl << endl;
}
//-------------------------addError()-------------------------------------------
// collectts errors movie
//------------------------------------------------------------------------------
void InventoryHelper::addError(string error) {
	count++;
	ostringstream temp;
	temp << count;
	errorCheck += temp.str() + ") ";
	errorCheck += error;
	errorCheck += "\n";
}

//---------------------displayErrors()-------------------------------------------
// dispalays all errors movie file
//-------------------------------------------------------------------------
void InventoryHelper::displayErrors() const {
	cout << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "                                Invalid movie list" << endl << endl;
	cout << errorCheck;
	cout << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

}
