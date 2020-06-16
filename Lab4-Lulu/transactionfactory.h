#pragma once
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;
//--------------------------  class TransactionFactory ----------------------
// TransactionFactory factory fucntion
//    create new transaction
//---------------------------------------------------------------------------

class Transactionactory {
public:
	static Transaction* createTransaction(const char&); 
};
