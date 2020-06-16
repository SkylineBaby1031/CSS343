#include <iostream>
#include <fstream>
#include "storeHelper.h"
using namespace std;
//-------------------------------------------------------------------------
// Checks valid data files

int main() {
	ifstream infile1("data4movies.txt");
	if (!infile1) {
		cout << "File could not be found ." << endl;
		return 1;
	}
	ifstream infile2("data4commands.txt");
	if (!infile2) {
		cout << "File could not be found ." << endl;
		return 1;
	}

	ifstream infile3("data4customers.txt");
	if (!infile3) {
		cout << "File could not be found." << endl;
		return 1;
	}

	storeHelper store;
	store.buildStore(infile1, infile3);
	store.commandsReader(infile2);
	return 0;
}
