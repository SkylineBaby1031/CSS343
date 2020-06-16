// ----------------------- BinTree.cpp ----------------------------------------
// Programmer Name: Lu Lu
// Course Section Number : CSS343 B
// Creation Date : 4/28/2019
// Date of Last Modification : 4/28/2019
// ---------------------------------------------------------------------------
// Purpose - 
//	This is a class to create a binary search tree.
// --------------------------------------------------------------------------- 
// Assumption :
//	-Each line consists of many strings and terminates with the string “$$”.
//	-Each line will be used to build one tree. 
//	-The duplicated strings (i.e., having equal values with existing node 
//	 data) are discarded, smaller strings go left, and bigger go right. 
// --------------------------------------------------------------------------- 

//#include "pch.h"
#include "bintree.h"


using namespace std;

//------------------------- Constructors ---------------------------------------
// ------------------------ BinTree() ------------------------------------------  
// Description: 
//		Creates an empty tree.
// -----------------------------------------------------------------------------  
BinTree::BinTree()
{
	root = NULL;
}// end of BinTree()

// ----------------- copyConstrHelper(const Node* pNode) const -----------------  
// Description: 
//		Helper function for deep copy
// -----------------------------------------------------------------------------  
BinTree::Node* BinTree::copyConstrHelper(const Node* pNode) const
{
	if (pNode == NULL)
	{
		return NULL;
	}
	Node* newNode = new Node;
	NodeData* newData = new NodeData;
	*newData = *pNode->data;
	newNode->data = newData;
	newNode->left = copyConstrHelper(pNode->left);
	newNode->right = copyConstrHelper(pNode->right);

	return newNode;

}// end of copyConstrHelper(const Node* pNode) const

// ------------------------ BinTree(const BinTree & comTree) ----------------------  
// Description: 
//		Deep copy of a poly Array;
// -----------------------------------------------------------------------------  
BinTree::BinTree(const BinTree & comTree)
{
	root = copyConstrHelper(comTree.root);
}// end of BinTree(const BinTree & comTree)


//------------------------ Deconstructors --------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}// end of ~BinTree()



// ------------------------ isEmpty() ------------------------------------------  
// Description: 
//		Check if the tree is empty or not. 
//		- return true if empty.
// ----------------------------------------------------------------------------- 
bool BinTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}// end of isEmpty()

// ------------------------ makeEmpty() ----------------------------------------  
// Description: 
//		Delete Nodes and make the tree empty
// ----------------------------------------------------------------------------- 
void BinTree::makeEmpty()
{
	deleteNode(root);
}//end of makeEmpty()


// ------------------- deleteNode(Node *& n) -----------------------------------  
// Description: 
//		Recursively delete node
// ----------------------------------------------------------------------------- 
void BinTree::deleteNode(Node *& n)
{
	if (n != NULL)
	{
		deleteNode(n->left);
		deleteNode(n->right);
		delete n->data;
		n->data = NULL;
		delete n;
		n = NULL;
	}
}// end of deleteNode(Node *& n)


//------------------------- Overloading Operators ------------------------------

// ------------------------ "=" overloading ------------------------------------  
// Description: 
//		The assignment operator (=) to assign one tree to another; 
// -----------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree & comTree)
{
	if (*this == comTree)
	{
		return *this;
	}
	else if (root != NULL)
	{
		makeEmpty();
	}
	root = copyConstrHelper(comTree.root);
	return *this;
}// end of "=" overloading

// -------------- equalHelper(Node* curNode, Node* pNode) ----------------------  
// Description: 
//		Recursively checking if the every node is equal
//		- helper function for "="
// ----------------------------------------------------------------------------- 
bool BinTree::equalHelper(Node* curNode, Node* pNode) const
{
	if (curNode == NULL && pNode == NULL)
	{
		return true;
	}
	if (curNode == NULL && pNode != NULL || curNode != NULL && pNode == NULL)
	{
		return false;
	}

	if (*curNode->data != *pNode->data)
	{
		return false;
	}
	if (curNode != NULL && pNode != NULL)
	{
		return equalHelper(curNode->left, pNode->left) && equalHelper(curNode->right, pNode->right);
	}

	return true;

}// end of equalHelper(Node* curNode, Node* pNode)

// ------------------------ "==" overloading ------------------------------------  
// Description: 
//		The equality operators (==) 
// ------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree & tree) const
{
	if (this->isEmpty() && tree.isEmpty())
	{
		return true;
	}
	if (!this->isEmpty() && tree.isEmpty() || this->isEmpty() && !tree.isEmpty())
	{
		return false;
	}
	return equalHelper(root, tree.root);

}// end of "==" overloading

// ------------------------ "!=" overloading ------------------------------------  
// Description: 
//		The inequality operators (!=) 
// ------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree & tree) const
{
	return 	!(*this == tree);
}//end of "!=" overloading

// ------------------------ insert(NodeData* pRoot) ----------------------------  
// Description: 
//		Insert Node into a tree
// ----------------------------------------------------------------------------- 
bool BinTree::insert(NodeData* pRoot)
{
	Node *newNode = new Node;
	NodeData * newData = new NodeData;
	*newData = *pRoot;
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		Node * curNode = root;
		bool notAssigned = true;

		while (notAssigned)
		{
			if (*pRoot == *curNode->data)
			{
				delete newNode;
				delete newData;
				newNode = NULL;
				newData = NULL;
				return false;
			} 
			if (*pRoot < *curNode->data)
			{
				if (curNode->left == NULL)
				{
					curNode->left = newNode;
					notAssigned = false;
				}
				else
				{
					curNode = curNode->left;
				}
			}
			else
			{
				if (curNode->right == NULL)
				{
					curNode->right = newNode;
					notAssigned = false;
				}
				else
				{
					curNode = curNode->right;
				}
			}
		}


	}
	delete pRoot;
	pRoot = NULL;
	return true;
}// end of insert(NodeData* pRoot)

// ------------------------ retrieveLevel(Node *n) ----------------------------  
// Description: 
//		Count the level for each node
// ----------------------------------------------------------------------------- 
int BinTree::retrieveLevel(Node *n) const
{
	if (n == NULL)
	{
		return 0;
	}
	int leftLevel = 1 + retrieveLevel(n->left);
	int	rightLevel = 1 + retrieveLevel(n->right);
	int localLevel = (leftLevel > rightLevel) ? leftLevel : rightLevel;
	return localLevel;
}//end of retrieveLevel(Node *n)

// ------ retrieveNode(const NodeData & data, Node * node) ---------------------  
// Description: 
//		get the node with the given nodedata
// ----------------------------------------------------------------------------- 
BinTree::Node* BinTree::retrieveNode(const NodeData & data, Node * node) const
{
	Node * newNode = NULL;
	if (node != NULL)
	{
		if (*node->data == data)
		{
			newNode = node;
		}
		else
		{
			if (newNode == NULL)
			{

				newNode = retrieveNode(data, node->left);
			}

			if (newNode == NULL)
			{
				newNode = retrieveNode(data, node->right);
			}
		}
	}
	return newNode;
}// end of retrieveNode(const NodeData & data, Node * node)

// ------------------ getHeight(const NodeData & data) -------------------------  
// Description: 
//		get the Height of the node
// ----------------------------------------------------------------------------- 
int BinTree::getHeight(const NodeData & data) const
{
	Node * newNode = retrieveNode(data, root);
	return retrieveLevel(newNode);
}// end of getHeight(const NodeData & data)


// ------ retrieve(const NodeData & serData, NodeData* & retData) --------------  
// Description: 
//		retrive the node from the tree
//		- return true if found
// ----------------------------------------------------------------------------- 
bool BinTree::retrieve(const NodeData & serData, NodeData* & retData) const
{

	if (isEmpty())
	{
		return false;
	}
	Node* curNode = root;
	while (curNode != NULL)
	{
		if (*curNode->data == serData)
		{
			retData = curNode->data;
			return true;
		}
		else if (*curNode->data < serData)
		{
			curNode = curNode->right;
		}
		else
		{
			curNode = curNode->left;
		}
	}
	delete curNode;
	curNode = NULL;
	return false;
}// end of retrieve(const NodeData & serData, NodeData* & retData)

// ------ balancedTreeHelper(NodeData* ndArr[], int low, int high) ------------  
// Description: 
//		Recursively insert the node to have a balanced tree
// ----------------------------------------------------------------------------- 
BinTree::Node* BinTree::balancedTreeHelper(NodeData* ndArr[], int low, int high)
{
	if (low > high)
	{
		return NULL;
	}
	Node* newNode = new Node;
	NodeData* newData = new NodeData;
	int index = (low + high) / 2;
	*newData = *ndArr[index];
	delete ndArr[index];
	ndArr[index] = NULL;
	newNode->data = newData;
	int leftIndex = 0;
	int rightIndex = 0;
	newNode->left = balancedTreeHelper(ndArr, low, index - 1);
	newNode->right = balancedTreeHelper(ndArr, index + 1, high);

	return newNode;

}//end of balancedTreeHelper(NodeData* ndArr[], int low, int high)

// ------------------ arrayToBSTree(NodeData* ndArr[]) -------------------------  
// Description: 
//		put array elements into Binary search tree
// ----------------------------------------------------------------------------- 
void BinTree::arrayToBSTree(NodeData* ndArr[])
{
	int count = 0;
	// count how many elements in the array
	while (ndArr[count] != NULL)
	{
		count++;
	}

	int index = count - 1;
	root = balancedTreeHelper(ndArr, 0, index);


}// end of arrayToBSTree(NodeData* ndArr[])

// ------ toArrayHelper(NodeData* ndArr[], Node* node, int& count) ------------  
// Description: 
//		to array Helper
// ----------------------------------------------------------------------------- 
void BinTree::toArrayHelper(NodeData* ndArr[], Node* node, int& count) const
{
	if (node == NULL)
	{
		return;
	}
	NodeData* newData = new NodeData;
	*newData = *node->data;
	toArrayHelper(ndArr, node->left, count);
	ndArr[count] = newData;
	count++;
	toArrayHelper(ndArr, node->right, count);
}// end of toArrayHelper(NodeData* ndArr[], Node* node, int& count)

// ------------------ bstreeToArray(NodeData* ndArr[]) -------------------------  
// Description: 
//		put tree to an array
// ----------------------------------------------------------------------------- 
void BinTree::bstreeToArray(NodeData* ndArr[])
{
	int count = 0;
	toArrayHelper(ndArr, root, count);
	makeEmpty();
}// end of bstreeToArray(NodeData* ndArr[])

//------------------------- Accessors -------------------------------------------
// ------------------------ "<<" overloading ------------------------------------  
// Description: 
//		Overload << to display the tree using inorder traversal. The NodeData 
//		class is responsible for displaying its own data.
// ------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const BinTree& tree)
{
	tree.outputHelper(output, tree.root);
	output << endl;
	return output;
}//end of "<<" overloading

// ----------- outputHelper(ostream& oput, Node* pNode) ------------------------  
// Description:
//		output Helper
// ----------------------------------------------------------------------------- 
void BinTree::outputHelper(ostream& oput, Node* pNode) const
{
	if (pNode == NULL)
	{
		return;
	}
	outputHelper(oput, pNode->left);
	oput << *pNode->data << " ";
	outputHelper(oput, pNode->right);
}// end of outputHelper(ostream& oput, Node* pNode)

// ------------------------- displaySideways() ---------------------------------  
// Description:
//		Display a binary tree on side ways
// ----------------------------------------------------------------------------- 
void BinTree::displaySideways() const {
	sideways(root, 0);
}// end of displaySideways()

// ----------------- sideways(Node* current, int level) ------------------------  
// Description:
//		Helper for displaySideways
// ----------------------------------------------------------------------------- 
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;     
		sideways(current->left, level);
	}
}// end of sideways(Node* current, int level)