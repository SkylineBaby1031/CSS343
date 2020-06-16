// ----------------------- BinTree.h -------------------------------------------
// Programmer Name: Lu Lu
// Course Section Number : CSS343 B
// Creation Date : 4/28/2019
// Date of Last Modification : 4/28/2019
// -----------------------------------------------------------------------------
// Purpose - 
//		This is a class to create a binary search tree.
// -----------------------------------------------------------------------------
// Assumption :
//	-Each line consists of many strings and terminates with the string “$$”.
//	-Each line will be used to build one tree. 
//	-The duplicated strings (i.e., having equal values with existing node 
//	 data) are discarded, smaller strings go left, and bigger go right. 
// ----------------------------------------------------------------------------- 

#include <iostream>
#include <string>
#include "nodedata.h"
class BinTree {	
	// Accessors Overloads
	friend ostream& operator<<(ostream& output, const BinTree& tree);
public:
	// Constructors - Destructor
	BinTree();											
	BinTree(const BinTree &);							
	~BinTree();		

	bool isEmpty() const;								
	void makeEmpty();

	// Operator Overloads
	//(a)------- Overloading = -------------------------
	BinTree& operator=(const BinTree &);

	//(b)------- Overloading ==, != --------------------
	bool operator==(const BinTree &) const;				
	bool operator!=(const BinTree &) const;				

	//Accessors
	bool insert(NodeData*);		
	bool retrieve(const NodeData &, NodeData* &) const; 
	void displaySideways() const;						
	int getHeight(const NodeData &) const;				

	//Others
	void arrayToBSTree(NodeData*[]);				
	void bstreeToArray(NodeData*[]);					

private:
	struct Node {
		NodeData* data;									
		Node* left;										
		Node* right;									
	};
	Node* root;						

	//Utility functions
	Node* retrieveNode(const NodeData &, Node *) const;
	void deleteNode(Node *& n);							
	int retrieveLevel(Node *n) const;					
	void toArrayHelper(NodeData*[], Node*, int&) const;				
	void sideways(Node*, int) const;					
	bool equalHelper(Node*, Node*) const;					
	Node* copyConstrHelper(const Node*) const;				
	Node* balancedTreeHelper(NodeData*[], int, int);		
	void outputHelper(ostream&, Node*) const;


};
