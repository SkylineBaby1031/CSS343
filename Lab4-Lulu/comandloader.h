#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "movie.h"
#include "InventoryHelper.h"
#include  "CustomerHelper.h"
#include "transactionfactory.h"
using namespace std;
//--------------------------  class ComandLoader ----------------------------
//  Uses factory class create transactions
// command transcation
//---------------------------------------------------------------------------
class ComandLoader {
public:

	ComandLoader();                       // constractor
	virtual ~ComandLoader();              // destractor
	void commandsReader(ifstream&, CustomerHelper&, InventoryHelper&);  // read commands
	void displayErrors() const;                                           // display errors
private:

	string invalidTran;                             
};
