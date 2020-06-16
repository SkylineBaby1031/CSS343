#include "CustomerHelper.h"

//------------------- CustomerHelper()---------------------------------------
// Constractor
//--------------------------------------------------------------------------
CustomerHelper::CustomerHelper()
{
}

//---------------------~CustomerHelper()-----------------------------------------
// desctuctor
//--------------------------------------------------------------------------
CustomerHelper::~CustomerHelper()
{
}

//-------------------------loadCustomer(ifstream& file)---------------------------
// read the input file for the customer information
//--------------------------------------------------------------------------
void CustomerHelper::loadCustomer(ifstream& file)
{
	for (;;) {	// loop to read the file

		int id;
		string last;
		string first;
		string temp;

		getline(file, temp, ' ');                            // get id
		stringstream(temp) >> id;                            // convert id to int
		getline(file, last, ' ');                            // get last name
		getline(file, first);                                // get first name

		if (file.eof()) break;

		Customer *  ptr = new Customer (id, last, first);
		bool success = table.insertCustomer(id, ptr);           // insert customer into HashTable
		 if (!success)
			 delete ptr;                                     // invalid case, not inserted
	}
}

//-----------------getCustomer()----------------------------------------------
// customer from hashtable
//--------------------------------------------------------------------------
Customer*  CustomerHelper::getCustomer(int id) {
	Customer *  customer = NULL;                   // poitner to a customer
	customer = table.getCustomer(id);              // rertive customer from hashtable
	return customer;                                // return customer
}
