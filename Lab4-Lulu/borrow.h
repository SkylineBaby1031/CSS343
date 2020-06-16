#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "CustomerHelper.h"
#include "InventoryHelper.h"
#include "transaction.h"
using namespace std;

class Borrow : public Transaction {

public:

	Borrow();                 // constractor
	~Borrow();                // destructor
	static const char comandType = 'B';   // command char for borror movie
	virtual void loadTransaction(string, CustomerHelper&, InventoryHelper&); //  load transaction

protected:

	void borrowMovie(Customer*, Movie*, Movie*);   // borrow movie function
	void readTransaction(string info, Customer* customer, InventoryHelper&); // helper for load transaction
};
