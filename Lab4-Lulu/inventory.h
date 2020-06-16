#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "CustomerHelper.h"
#include "InventoryHelper.h"
#include "transaction.h"
using namespace std;

//--------------------------  class Inventory -------------------------------
// child class of Transaction.
// Displays  all moive information
//---------------------------------------------------------------------------

class Inventory : public Transaction {
public:
	Inventory();                     // constractor
	~Inventory();                    // destructor
	virtual void loadTransaction(string, CustomerHelper&, InventoryHelper&);
	static const char comandType = 'I';  // command char
};
