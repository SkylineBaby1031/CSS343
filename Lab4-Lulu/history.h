#pragma once
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "CustomerHelper.h"
#include "InventoryHelper.h"
#include "transaction.h"
using namespace std;

//--------------------------  class History ---------------------------------
// Displays histroy for a given cusomter
//   displays customer transactions.
//---------------------------------------------------------------------------

class History : public Transaction {
public:
	History();                       // constractor
	~History();                      // destructor
	virtual void loadTransaction(string, CustomerHelper&, InventoryHelper&);
	static const char comandType = 'H';  // command char 
};
