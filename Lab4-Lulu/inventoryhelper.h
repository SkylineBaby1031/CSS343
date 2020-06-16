#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "BSTree.h"
#include "moviefactory.h"

//--------------------------  class InventoryHelper ------------------------
//  Read given file then sort and insert
//    movies  BSTrees (Drama,Classiscs, Comedy).
//    displays all BTrees  invalid movies.
//---------------------------------------------------------------------------

class InventoryHelper {
public:
	void processInventory(ifstream &);
	Movie * retriveMovie(Movie*, char);      // retrive movie from BSTtree
	void displayAll();
private:
	void addError(string);          //  erros invalid movie
	void displayErrors() const;    // displays  invalid movies
	int count;                           // count error massages
	string errorCheck;
	BinTree dramaBST;    //BSTREES Drama
	BinTree classicsBST;               // BStrees  classics
	BinTree comedyBST;                // BStrees  comedy
};
