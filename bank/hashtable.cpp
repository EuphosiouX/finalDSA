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
	hashValue = hashFunction(key);
	for (auto it: hashTable) {
		if (it.first == hashValue) {
			hashTable.erase(hashValue);
			cout << "DELETED" << endl;
		}
		else {
			cout << "[ERROR] No ID found" << endl;
		}
	}
}

// Display the hash tables
void HashTable::displayHash() {	
	for (auto it : hashTable) {
		cout << "ID: " << it.second.key << endl;
		cout << "Name: " << it.second.name << endl;
		cout << "Password: " << it.second.password << endl;
		cout << "Pin Number: " << it.second.pin << endl;
		cout << "Balance: " << it.second.balance << endl;
	}   	   	
}

int HashTable::hashFunction(int key) {
	return key % 10;
}

