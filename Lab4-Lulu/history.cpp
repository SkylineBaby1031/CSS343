#include "history.h"
//-----------------------History()-------------------------------------------
// Constractor
//--------------------------------------------------------------------------
History::History() {
	errorCheck = "";
}

//---------------------------~History()--------------------------------------
// Destructor
//--------------------------------------------------------------------------
History::~History() {

}

//--------------------- loadTransaction()----------------------------------------
// read the line by line to get customer ID
// display customer hsitory
//--------------------------------------------------------------------------
void History::loadTransaction(string line, CustomerHelper& cus, InventoryHelper& inven) {

	int id;
	Customer * customer = NULL;

	stringstream ss;
	ss << line;                 // insert string into reader

	ss >> id;
	customer = cus.getCustomer(id);
	if (checkValidCustomer(customer, id)) {  // check if customer exist
		customer->movieHistory();                     // display customer history
	}
}
