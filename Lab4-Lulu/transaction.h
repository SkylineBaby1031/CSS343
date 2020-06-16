#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "CustomerHelper.h"
#include "InventoryHelper.h"
using namespace std;
//--------------------------  class Transaction -----------------------------------
//  parent  class for child classes Borrow,
// Rerurn, Inventory, Hisory
// records erros and adds erros
//---------------------------------------------------------------------------
class Transaction {
public:
	Transaction();              // constractor
	virtual ~Transaction() {};  // destructor
	virtual void loadTransaction(string, CustomerHelper&, InventoryHelper&);
	string getErrors();                                                            //  arrors massages
	static const char DVD = 'D'; // comand char
protected:
	bool checkValidCustomer(Customer*, int);           // check if customer is valid
	string errorCheck;
	void addError(string);
};
