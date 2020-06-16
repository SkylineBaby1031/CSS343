#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "storeHelper.h"
//--------------------------buildStore()---------------------------------------
// build data base
// movie and customters
//--------------------------------------------------------------------------
void storeHelper::buildStore(ifstream& moiveData, ifstream& customerData) {
	inventory_object.processInventory(moiveData);
	customer_object.loadCustomer(customerData);
}

//------------------------commnadsReader()------------------------------------
// comand read function
//--------------------------------------------------------------------------
void storeHelper::commandsReader(ifstream& commands) {
	command_object.commandsReader(commands,customer_object,inventory_object);
}
