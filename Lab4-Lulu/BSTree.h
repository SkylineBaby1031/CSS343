#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "drama.h"
//--------------------------  class BinTree  --------------------------------
// using a tree structure each node points to movie
// each node has at most two children
//---------------------------------------------------------------------------

class BinTree {

public:
	int movieID;

	BinTree();							   // constructor
	~BinTree();							   // destructor
	void makeEmpty();
	bool isEmpty() const;            // check if empty
	Movie * retrieve(const Movie*); // retrive the tree
	bool insert(Movie *);
	void displayAll();

private:
	struct Node {
		Movie* data;
		Node* left;
		Node* right;
	};
	Node* root;

	//helpers
	void makeEmptyHelper(Node*&);
	void inorderDisplay(Node*) const;
	Movie* retriveHelper(Node*&, const Movie*) const;
	bool insertHelper(Node*&, Movie*);
};
#endif
