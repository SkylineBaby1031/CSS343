#include "borrow.h"
//-------------------------Borrow()--------------------------
// Constractor
//-----------------------------------------------------------
Borrow::Borrow()
{
	errorCheck = "";
}

//-----------------~Borrow()--------------------------------
// Destructor
//-----------------------------------------------------------
Borrow::~Borrow()
{
}

//--------------------loadTransaction()----------------------
// read line and get vaild customer id
// valid customer id then call helper function
//-----------------------------------------------------------

void Borrow::loadTransaction(string line, CustomerHelper& cust, InventoryHelper& inven)
{
	string temp;
	int customerId;
	Customer * customer = NULL;

	stringstream ss;
	ss << line;
	ss >> customerId;

	customer = cust.getCustomer(customerId);
	if (checkValidCustomer(customer, customerId)) {  // check the correct customer
		getline(ss, temp);                            // get the movie information
		readTransaction(temp, customer, inven);
	}
}

//--------------------readTrnasaction()------------------------------
// keep read the line, helper function for loadTransaction()
//-------------------------------------------------------------------
void Borrow::readTransaction(string info, Customer* customer, InventoryHelper& inven)
{
	stringstream ss;
	ss << info;                          // insert string into reader
	char movietype, mediatype;
	string temp1, temp2;
	string majorActor;
	int movieYear = 0;
	int movieMonth = 0;
	Movie * tempMovie = NULL;
	Movie * cusMovie = NULL;

	ss >> mediatype;                     // insert media tye

	if (mediatype == DVD) {              // check if media type is valid
		ss >> movietype;                 // insert movie type
		switch (movietype)
		{
		case 'D': // Drama case
			getline(ss, temp2, ',');
			getline(ss, temp1, ',');
			tempMovie = new Drama(temp1, temp2);
			cusMovie = inven.retriveMovie(tempMovie, movietype);
			borrowMovie(customer, cusMovie, tempMovie); // call helper method
			delete tempMovie;
			tempMovie = NULL;
			break;

		case 'F':  // Comedy case
			getline(ss, temp2, ',');
			getline(ss, temp1);
			stringstream(temp1) >> movieYear;
			tempMovie = new Comedy(temp2, movieYear);
			cusMovie = inven.retriveMovie(tempMovie, movietype);
			borrowMovie(customer, cusMovie, tempMovie);
			delete tempMovie;
			tempMovie = NULL;
			break;

		case 'C': // classes case
			getline(ss, temp1, ' ');
			getline(ss, temp1, ' ');
			stringstream(temp1) >> movieMonth;
			getline(ss, temp1, ' ');
			stringstream(temp1) >> movieYear;
			ss >> temp1;
			majorActor += temp1;
			majorActor += ' ';
			ss >> temp1;
			majorActor += temp1;
			tempMovie = new Classics(majorActor, movieMonth, movieYear);
			cusMovie = inven.retriveMovie(tempMovie, movietype);
			borrowMovie(customer, cusMovie, tempMovie);
			delete tempMovie;
			tempMovie = NULL;
			break;
			// invalid movie type
		default:
			getline(ss, temp1);
			string a(1, movietype);
			addError("**Invalid movie type** " + a + temp1); // add invalud movie type
			break;
		}
	}
	// invalid meida type
	else {
		string a(1, mediatype);
		getline(ss, temp1);
		addError("**Invalid  media type** " + a + temp1);	// add invalid media type
	}
}
//-----------------------borrowMovie()---------------------------------
// customer borrow movie , check the inventory
// error message if stock is empty
//---------------------------------------------------------------------
void Borrow::borrowMovie(Customer* customer, Movie *cusMovie, Movie * tempMovie)
{
	if (cusMovie != NULL) {
		bool success = customer->movieBorrow(cusMovie);   // borrow
		if (!success) {  // not true print error message
			addError(customer->getCustomerInfo() + ". Attempt to borrow empty stock for"
				+ "\n" + cusMovie->displayCustomerInfo());
		}
	}
	else {  // invalid movie
		addError("**Invalid retrive of** " + tempMovie->displayCustomerInfo());   // add invalid moive
	}
}
