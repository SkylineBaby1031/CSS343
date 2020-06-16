#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
using namespace std;

//--------------------------  class HashTable  ------------------------------
// HashTable data stucture
//  holds customers
// access by customer ID
// no duplicate customer
//---------------------------------------------------------------------------
class HashTable {
	static const int SIZE = 50;
	static const int Hash = 52;
public:
	HashTable();   // constractor
	~HashTable();  // descturctor
	Customer * getCustomer(int);
	bool insertCustomer(int, Customer *); // insert customer into hashtable
private:
	void makeEmpty();  // helper make empty
	void buildTable();

	struct HashList;
	struct HashEntry
	{
		HashList * head;
	};

	struct HashList   // linked list
	{
		Customer * data;
		int key;
		HashList * next;
	};

	HashEntry table[SIZE];   // hastable array
};
