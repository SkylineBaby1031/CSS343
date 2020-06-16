#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include  "hashtable.h"
#include "customer.h"
using namespace std;
//--------------------------  class CusomerHelper -------------------------
// puts customersinto HashTble
//    retrieve the customer
//---------------------------------------------------------------------------
class CustomerHelper {
public:

	CustomerHelper();                   // constractor
	~CustomerHelper();                  // destructor
	void loadCustomer(ifstream &);   //  file with customers
	Customer* getCustomer(int id);      
private:

	HashTable table;                     // HashTable
};
