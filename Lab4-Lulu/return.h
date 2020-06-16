#pragma once
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "CustomerHelper.h"
#include "InventoryHelper.h"
#include "transaction.h"
using namespace std;

//--------------------------  class Return ----------------------------------
// child class of Transaction.
//  Returns movie
// update  Inventory
//---------------------------------------------------------------------------
class Return : public Transaction {
public:
	Return();                 // constractor
	~Return();                // destructor
	static const char comandType = 'R';  // comand char
	virtual void loadTransaction(string, CustomerHelper&, InventoryHelper&);
protected:
	void loadReturn(Customer*, Movie*, Movie*);
	void readTransaction(string info, Customer* customer, InventoryHelper& );
};
