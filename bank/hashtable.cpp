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
	Values* value = new Values;
	value->key = key;
	value->name = name;
	value->password = password;
	value->pin = pin;
	value->balance = balance;
	value->next = nullptr;
	
	// Pointing to the first element of Linked List at an index of HashTable 
	Values *head;
	
	// Getting index from key
	hashValue = hashFunction(value->key);
   	auto it = hashTable.find(hashValue);
	
	// If key is not found
	if (it == hashTable.end()) {
		hashTable.emplace(hashValue, *value);
		cout << "[INFO] Item successfully inserted" << endl;
		return;
	} 
	// If key is found and there is value
	else {
		// Insert value at the last linked-list of the index
		Values currValue = hashTable.find(hashValue)->second;
		head = &currValue;
		while (head->next != nullptr){  		
			if (head->next == nullptr) {
				head->next = value; 
				return;			
			}
			head = head->next;
		}
	}
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

