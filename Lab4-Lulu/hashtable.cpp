#include "hashtable.h"
//-----------------HashTable()----------------------------------------------
// Constractor
//--------------------------------------------------------------------------
HashTable::HashTable() {
	buildTable();
}

//----------------------buildTable()-------------------------------------
// helper function initizilized all header
//--------------------------------------------------------------------------
void HashTable::buildTable() {
	for (int i = 0; i < SIZE; ++i) {
		table[i].head = NULL;
	}
}

//-----------------------~HashTable()-------------------------------------------
// ~HashTable()
// Desctuctor
//--------------------------------------------------------------------------
HashTable::~HashTable() {
	makeEmpty();
}

//-----------------------makeEmpty()-----------------------------------------
// Delete all linked list
//--------------------------------------------------------------------------
void HashTable::makeEmpty() {
	for (int i = 0; i < SIZE; ++i) {
		if (table[i].head != NULL) {
			HashList* del = table[i].head;

			while (table[i].head != NULL) {
				table[i].head = table[i].head->next;
				delete del->data;
				delete del;
				del = NULL;
				del = table[i].head;
			}
		}
	}
}

//---------------------insertCustomer()------------------------------------------
// find hash table number for the customer
// insert customer to the hashtable
//--------------------------------------------------------------------------
bool HashTable::insertCustomer(int key, Customer * customer) {

	if (key > 9999 || key < 0) {
		return false;
	}

	int hash = (key % Hash);

	HashList * node = new HashList;
	node->data = customer;               // point to customer
	node->key = key;                     // point to key
	node->next = NULL;


	if (table[hash].head == NULL) {
		node->next = table[hash].head;
		table[hash].head = node;
	} // more than one nodes
	else {
		HashList * current = table[hash].head;
		while (current->next != NULL) {
			// check if duplicate
			if (key == current->key) {
				delete node->data;      // delete customer
				delete node;            // delete pointer
				node = NULL;
				return false;
			}
			current = current->next;
		}
		current->next = node; // add to the list
	}
	return true;
}

//---------------------getCustomer()-----------------------------------------
// find index in the hashtable
// triverse ll at hashtable and return
//--------------------------------------------------------------------------
Customer * HashTable::getCustomer(int key) {

	if (key > 9999 || key < 0) {
		return NULL;
	}

	int hash = (key % Hash);                // assign hash

	if (table[hash].head == NULL) {         // no customer
		return NULL;
	}
	else {
		HashList * node = table[hash].head; // traves linked list
		while (node != NULL) {
			if (key == node->key) {         // found
				return node->data;
			}
			node = node->next;
		}
	}
	return NULL;                           // not found
}
