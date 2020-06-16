#include "transaction.h"

//-----------------Transaction()-----------------------------------------------
// constractor
//--------------------------------------------------------------------------
Transaction::Transaction()
{
	errorCheck = "";
}

void Transaction::loadTransaction(string a, CustomerHelper& b, InventoryHelper& c)
{
}


//-------------------------checkValidCustomer()----------------------------------------
// check the correct custoemr id
//--------------------------------------------------------------------------
bool Transaction::checkValidCustomer(Customer * customer, int id)
{
	if (customer == NULL) {
		ostringstream stringStream;
		stringStream << id;
		addError("**Incorrect  Customer ID** " + stringStream.str()); // invalid customer id
		return false;
	}
	return true;
}

//----------------------addErrors()---------------------------------------------
// get all errors messages
//--------------------------------------------------------------------------

void Transaction::addError(string error)
{
	errorCheck += "!! ";
	errorCheck += error;
	errorCheck += "\n";
}

//------------------------getErros()-------------------------------------------
// get all error essage and check
//--------------------------------------------------------------------------
string Transaction::getErrors()
{
	return errorCheck;
}
