#pragma once
#include <string>
#include <iostream>
#include "movie.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//--------------------------  class customer  --------------------------------
//  save customer last name first name and customer ID
//   keep checking the customer's brorow and return
//---------------------------------------------------------------------------

class Customer {
public:

	Customer();                    // constractor
	Customer(int, string, string);
	~Customer();                   // destructor
	bool movieBorrow(Movie*);      // borrow
	bool movieReturn(Movie*);      // return
	void movieHistory();           // display borrow and return history
	int getMyID() const ;          // get customer ID
	string getCustomerInfo();

private:

	bool addTransaction(const char, Movie*); // add transaction
	bool returnMovie(Movie*);      // check vail for return
	bool borrowMovie(Movie*);

	int customerId;
	string lastName;
	string FirstName;
	int addOne;

 	vector <string> print_array;
 // history
	struct  List {
		List * next;
		char transaction;   // comand type
		Movie * info;
	};
	List * head;

	struct TransactionCheck{
		Movie * movie;
		char transaction;      // comand type b or r
		TransactionCheck * next;
	};
	TransactionCheck *headCheck;


};
