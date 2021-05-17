#include "hashtable.h"
#include <iostream>
#include <iterator>

using namespace std;

// Constructor
HashTable::HashTable() {
	
}

// Insert item to the hash table
void HashTable::insertItem(int key, string name, string password, int pin, double balance) {
	// Initialize new value
	Values val;
	val.key = key;
	val.name = name;
	val.password = password;
	val.pin = pin;
	val.balance = balance;
	val.next = nullptr;
	
	// Getting index from key
	hashValue = hashFunction(key);
	
	for (auto x : hashTable[hashValue]) {
		if (x.key == val.key) {
			cout << "[ERROR] Duplicate ID " << val.key << endl;
			return;
		}
	}
	hashTable[hashValue].push_back(val);
}


// Delete item from hash tables by key
void HashTable::deleteItem(int key) {
	
}


// Search hashtable
void HashTable::searchHash(int key) {	
	hashValue = hashFunction(key);
	for (auto x : hashTable[hashValue]) {
		if (x.key == key) {
			cout << "ID: " << x.key << endl;
			cout << "Name: " << x.name << endl;
			cout << "Balance: $" << x.balance << endl;
			return;
		}
	}
	cout << "[ERROR] ID " << key << " not found";
	return;	
}


int HashTable::hashFunction(int key) {
	return key % 10;
}
