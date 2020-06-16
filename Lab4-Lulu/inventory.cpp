#include "inventory.h"
//-----------------------Inventory(--------------------------------------------
// Constractor
//------------------------------------------------------------------------
Inventory::Inventory() {
	errorCheck = "";
}

//----------------~Inventory()-------------------------------------------
///Destructor
//------------------------------------------------------------------------
Inventory::~Inventory() {

}

//-----------------------loadTransaction()--------------------------------------
// all movie in the store display current
//-----------------------------------------------------------------------------
void Inventory::loadTransaction(string line, CustomerHelper& cust, InventoryHelper& inven) {
	inven.displayAll();   // print all movies in the store
}
