#include "return.h"
//-----------------------Return()-------------------------------------------
// Constractor
//--------------------------------------------------------------------------
Return::Return() {
	errorCheck = "";
}

//------------------------~Return()--------------------------------------------
// Destructor
//--------------------------------------------------------------------------
Return::~Return() {

}

//-----------------------loadTransaction()------------------------------------------
// read the line get the customer id and check valid
//--------------------------------------------------------------------------
void Return::loadTransaction(string line, CustomerHelper& cust, InventoryHelper& inven) {

	string temp;
	int customerId;            // customer id
	Customer * customer = NULL;

	stringstream ss;
	ss << line;

	ss >> customerId;
	customer = cust.getCustomer(customerId);
	if (checkValidCustomer(customer, customerId)) {
		getline(ss, temp);
		readTransaction(temp, customer, inven);
	}
}


void Return::readTransaction(string info, Customer* customer, InventoryHelper& inven){

	stringstream ss;                     // get reader
	ss << info;                          // insert string
	char movietype;
	char mediatype;
	string temp1;
	string temp2;
	string majorActor;
	int movieYear = 0;
	int MovieMonth = 0;
	Movie * temp_movie = NULL;
	Movie * customer_movie = NULL;

	ss >> mediatype;                     // insert media tye

	if (mediatype == DVD) {              // check if media type valid
		ss >> movietype;                 // insert movie type
		switch (movietype)
		{
			// case Drama
		case 'D':
			getline(ss, temp2, ',');     // insert  director
			getline(ss, temp1, ',');     // insert title
			temp_movie = new Drama(temp1, temp2);
			customer_movie = inven.retriveMovie(temp_movie, movietype);  // retrive
			loadReturn(customer, customer_movie, temp_movie); //  helper
			delete temp_movie;          // delete
			temp_movie = NULL;
			break;
			// case Comedy
		case 'F':
			getline(ss, temp2, ',');    // insert title
			getline(ss, temp1);         // hold year
			stringstream(temp1) >> movieYear;  // assign  year
			temp_movie = new Comedy(temp2, movieYear);
			customer_movie = inven.retriveMovie(temp_movie, movietype);  // retrive
			loadReturn(customer, customer_movie, temp_movie); //  helper
			delete temp_movie;          // delete
			temp_movie = NULL;
			break;
			// case Classics
		case 'C':
			getline(ss, temp1, ' ');
			getline(ss, temp1, ' ');
			stringstream(temp1) >> MovieMonth; //  month
			getline(ss, temp1, ' ');
			stringstream(temp1) >> movieYear;   //  year
			ss >> temp1;                 // get last name
			majorActor += temp1;
			majorActor += ' ';
			ss >> temp1;                 // get first name
			majorActor += temp1;
			temp_movie = new Classics(majorActor, MovieMonth, movieYear);
			customer_movie = inven.retriveMovie(temp_movie, movietype); // retrive
			loadReturn(customer, customer_movie, temp_movie); //  helper
			delete temp_movie;         // delete
			temp_movie = NULL;
			break;
			// invalid movie type
		default:
			getline(ss, temp1);
			string a(1, movietype);
			addError("**Invalid movie type** " + a + temp1);
			break;
		}
	}
	// not DVD
	else {
		string a(1, mediatype);
		getline(ss, temp1);
		addError("**Invalid media type** " + a + temp1);
	}
}
//-------------------loadReturn()-------------------------------------------------
// check  cusomter return movie of not.
// Check customre borrow the movie. Also,
//add error massage
//--------------------------------------------------------------------------
void Return::loadReturn(Customer* customer, Movie *customer_movie, Movie * temp_movie) {
	if (customer_movie != NULL) {   // check
			bool sucees = customer->movieReturn(customer_movie);   // try to return
			if (!sucees) {
				addError(customer->getCustomerInfo() + "\n" + "Didn't borrow followed "  // add invalid return
					+ customer_movie->displayCustomerInfo());
			}
	}
	else {
		addError("**Invalid retrive of** " + temp_movie->displayCustomerInfo());                 // add invalid moive
	}
}
