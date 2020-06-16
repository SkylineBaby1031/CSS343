#include "comandloader.h"

//-------------------ComandLoader()-------------------------
// Constractor
//----------------------------------------------------------
ComandLoader::ComandLoader()
{
}

//-------------------~ComandLoader()------------------------
// Destructor
//----------------------------------------------------------
ComandLoader::~ComandLoader()
{
}
//-------------------commandsReader()--------------------------------
// read the file line by line
// send each line the factory function
//--------------------------------------------------------------------
void ComandLoader::commandsReader(ifstream & infile2, CustomerHelper& cust, InventoryHelper& inven) {

	string temp;
	Transaction * transction = NULL;
	char type;
	for (;;) {
		infile2 >> type;                                               // insert the type
		transction = Transactionactory::createTransaction(type);
		if (infile2.eof())
		break;
		switch (type)
		{
		// case Inventory
		case 'I':
			getline(infile2, temp);       // get transaction information
			transction->loadTransaction(temp, cust, inven);
			invalidTran += transction->getErrors();     // add errors
			delete transction;
			transction = NULL;
			break;
		// case History
		case 'H':
			getline(infile2, temp);
			transction->loadTransaction(temp, cust, inven);
			invalidTran += transction->getErrors();  // add errors
			delete transction;
			transction = NULL;
			break;
		// case Borrow
		case 'B':
			getline(infile2, temp);
			transction->loadTransaction(temp, cust, inven);
			invalidTran += transction->getErrors();
			delete transction;
			transction = NULL;
			break;
	    // case Return
		case 'R':
			getline(infile2, temp);
			transction->loadTransaction(temp, cust, inven);
			invalidTran += transction->getErrors();
			delete transction;
			transction = NULL;
			break;
		// invalid transaction type
		default:
			getline(infile2, temp);     // get invalid movie info
			string a(1, type);
			invalidTran += "* Invalid transaction type: " + a +"\n";  // add invalid transaction
			break;
		}
	}
	delete transction;
	transction = NULL;
	displayErrors();          // display all errors
}

//-----------------displayErrors()----------------------------------
// display all errors that appears during reading the transactions
//--------------------------------------------------------------------
void ComandLoader::displayErrors() const {
	cout << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "                                **Overall INVALID Report**" << endl << endl;
	cout << invalidTran;
	cout << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

}
