#include "customer.h"
//-------------------------Customer()-------------------------------------------
// constractor
//--------------------------------------------------------------------------
Customer::Customer()
{
	addOne = 1; // default 1
}

Customer::Customer(int id, string last, string first)
{
	addOne = 1;
	customerId = id;
	FirstName = first;
	lastName = last;
	head = NULL;
	headCheck = NULL;
}

//--------------------~Customer-------------------------------------------------
// destructor
//--------------------------------------------------------------------------
Customer::~Customer()
{
	List * del = head;   	// delete
	while (del != NULL) {
		head = head->next;
		del->info = NULL;
		delete del;
		del = head;
	}

	TransactionCheck * delLog =headCheck;
	while (delLog != NULL) {
		headCheck =headCheck->next;
		delLog->movie = NULL;
		delete delLog;
		delLog =headCheck;
	}
	print_array.clear();
}

//---------------getMyID()-------------------------------------------------------
// return customer id
//------------------------------------------------------------------------------
int Customer::getMyID() const
{
	return customerId;
}

//--------------------addTransaction()---------------------------------------------
// using linked list to save transcation
//------------------------------------------------------------------------------
bool Customer::addTransaction(const char type, Movie* movie )
{
	List * ptr = new List;
	ptr->transaction = type;
	ptr->info = movie;
	ptr->next = NULL;

	if (head == NULL) {
		ptr->next = head;
		head = ptr;
	}
	else {
		List * current = head;

		while (current->next != NULL) {
			current = current->next;
		}
		current->next = ptr;
	}
	return true;
}
//------------------- movieBorrow()-----------------------------------------
// customer borrow moive
// check valid stock for borrow
//------------------------------------------------------------------------------
bool Customer::movieBorrow( Movie* movie)
{
	// check if stock is not empty
	if (movie->getStock() != 0 && borrowMovie(movie))
	{
		movie->decreaseStock();
		return addTransaction('B', movie);  // add movie to customer history
	}
	return false;
}

//------------------- movieReturn()--------------------------------------------
// customer return  moive
// check valid stock for return
//------------------------------------------------------------------------------
bool Customer::movieReturn(Movie* movie)
{

	if (returnMovie(movie)) {
		movie->addStock(addOne);    // add stock +1
		return addTransaction('R', movie); // add movie to customer history
	}
	return false;
}

//-------------------movieHistory()-----------------------------------------------
// display the movie history for customer borrow and return
//------------------------------------------------------------------------------
void Customer::movieHistory()
{
	cout << endl;
//	cout << "-----------------------------------------------------------------------------" << endl;
	cout << getCustomerInfo() << endl << "History:" << endl;
	List * current = head;
    // go thought the list
	while (current != NULL)
	{
		if (current->transaction == 'B') { // command char
			print_array.push_back("Borrow" + current->info->displayCustomerInfo());
		}
		else {
			print_array.push_back("Return" + current->info->displayCustomerInfo());
		}
		current = current->next;
	}

	vector<string>::reverse_iterator checkHistory; // display history
	for (checkHistory = print_array.rbegin(); checkHistory != print_array.rend(); ++checkHistory) {
		cout << *checkHistory << endl;
	}
//	cout << "-----------------------------------------------------------------------------" << endl;
	cout << endl;
}

//-------------------------getCustomerInfo()-----------------------------------
//  return customer information
//-----------------------------------------------------------------------------
string Customer::getCustomerInfo()
{
	ostringstream stringStream;
	stringStream << "Customer ID " << customerId << ": " << lastName << " " << FirstName;
	return  stringStream.str();
}

bool Customer::borrowMovie(Movie* borrMovie)
{

	TransactionCheck * ptr = new TransactionCheck;
	ptr->movie = borrMovie;
	ptr->next = NULL;

	if (headCheck == NULL) {
		ptr->next =headCheck;
		headCheck = ptr;
	}
	else {
		TransactionCheck * current =headCheck;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = ptr;
	}
	return true;
}

bool Customer::returnMovie(Movie * dataptr)
{


	if (headCheck == NULL){
		return false;
	}

	TransactionCheck * current =headCheck->next;
	TransactionCheck * priv =headCheck;

	if (priv->movie->isEqual(dataptr))
	{
		priv->movie = NULL;
		delete priv;
		headCheck = current;
		return true;
	}

	while (current != NULL) {

		//same as before
		if (current->movie->isEqual(dataptr))
		{
			priv->next = current->next;
			current->movie = NULL;
			delete  current;
			return true;
		}
		priv = current;
		current = current->next;
	}

	return false; // not found
}
