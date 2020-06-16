#include "transactionfactory.h"


Transaction* Transactionactory::createTransaction(const char& type) {
	Transaction  * tran = NULL;
	switch (type)                // get first character
	{
	case Borrow::comandType:
		tran = new Borrow();     // allocate Borrow
		break;
	case Return::comandType:
		tran = new Return();     // allocate Return
		break;
	case History::comandType:
		tran = new History();    // allocate History
		break;
	case Inventory::comandType:
		tran = new Inventory();  // allocate Inventory
		break;
	default:
		tran = NULL;
		break;
	}
	return tran;
}
