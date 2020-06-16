#include  "BSTree.h"



//----------------------BinTree()-------------------------
// constractor
//---------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;   // set root to NULL
	movieID = 0;
}


//----------------------------~BinTree()-----------------
// destructor
//---------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}

//----------------------makeEmpty()-----------------------
// make the tree empty
//---------------------------------------------------------
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);  // call helper function
}

//-------------------makeEmptyHelper()----------------------
// helper function for makeEmpty
//---------------------------------------------------------
void BinTree::makeEmptyHelper(Node* & node)
{
	//base case
	if (node == NULL) { return; }
	makeEmptyHelper(node->left);
	makeEmptyHelper(node->right);
	delete node->data;                  // delete data
	node->data = NULL;                  // set data to NULL
	delete node;                        // delte root
	node = NULL;                        // set root to NULL
}


////-------------------------isEmpty()----------------------------
// check if the tree is empty
//----------------------------------------------------------------
bool  BinTree::isEmpty() const
{
	return (root == NULL);
}

//----------------------displayAll()-------------------------------
// display the tree
//----------------------------------------------------------------
void BinTree::displayAll()
{
	inorderDisplay(root);
	cout << endl;
}

//-----------------------inorderDisplay()------------------------
// display the tree in inorder
//----------------------------------------------------------------
void BinTree::inorderDisplay(Node* node) const {
	if (node == NULL) { return; }
	// recurisve call
	inorderDisplay(node->left);  // left
	cout << node->data->displayMovieInfo();
	inorderDisplay(node->right); // right
}


Movie* BinTree::retrieve(const Movie* checkData) {

	return retriveHelper(root, checkData); // call helper for retrieve
}

Movie* BinTree::retriveHelper(Node*& node, const Movie* checkData) const {

	if (node == NULL) {
		return  NULL;
	}
	if (node->data->isEqual( checkData)) {
		return node->data;
	}
	else if (node->data->isGreater(checkData)){
		return retriveHelper(node->left, checkData);
	}
	else {
		return retriveHelper(node->right, checkData);
	}
}


//--------------------insert()----------------------------------
// insert data into tree resusively
//----------------------------------------------------------------
bool BinTree::insert(Movie* data) {
	return insertHelper(root, data);
}

//------------------------insertHelper()-------------------------
// helper for insert
//----------------------------------------------------------------
bool BinTree::insertHelper(Node*& new_node, Movie* data) {
	if (new_node == NULL) {
		new_node = new Node();
		new_node->data = data;
		new_node->left = new_node->right = NULL;
		return true;
	}
	if (new_node->data->isEqual(data)) {

		bool new_stock = new_node->data->addStock(data->getStock()); // increase the stock
		delete data;
		data = NULL;
		return new_stock;
	}
	if (new_node->data->isGreater(data)) {
		return insertHelper(new_node->left, data);
	}
	else {
		return insertHelper(new_node->right, data);
	}
}
