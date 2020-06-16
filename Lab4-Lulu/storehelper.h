#ifndef storeHelper_H
#define  storeHelper_H
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "CustomerHelper.h"
#include "InventoryHelper.h"
#include "comandloader.h"

class storeHelper {
public:
	void buildStore(ifstream&, ifstream&);               // build store
	void commandsReader(ifstream&);
private:
	CustomerHelper customer_object;
	InventoryHelper inventory_object;
	ComandLoader command_object;                 
};
#endif
