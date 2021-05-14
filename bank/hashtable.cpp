#include "hashtable.h"
#include <iostream>
#include <iterator>

using namespace std;

// Constructor
HashTable::HashTable() {
	
}

// Insert item to the hash table
void HashTable::insertItem(int key, string name, string password, int pin, double balance) {
	Values value;
	value.key = key;
	value.name = name;
	value.password = password;
	value.pin = pin;
	value.balance = balance;
	
	// Pointing to the first element of Linked List at an index of HashTable 
	Values *head;
	
	hashValue = hashFunction(value.key);
	Values currValue = hashTable.find(hashValue)->second;
        head = &currValue;
	
	map<int, Values>::iterator it;
	
	// Handling maximum size error of the hash table
	if (it != hashTable.end() && hashTable.size() == max_hash_size) { 
        cout << "[ERROR] Hashtable is full" << endl;
    } else {
  		hashValue = hashFunction(value.key);
    	hashTable.emplace(hashValue, value);
    	cout << "[INFO] Item successfully inserted" << endl;
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

