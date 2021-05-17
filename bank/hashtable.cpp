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


// Delete specific id
void HashTable::deleteItem(int key){
  // get the hash index of key
      int hashValue = hashFunction(key);

  // find the key in (inex)th list
      list <Values> :: iterator i;
      for (i = hashTable[hashValue].begin(); i != hashTable[hashValue].end(); i++) {
          Values currValue = *i;
        if (currValue.key == key)
              break;
      }

  // if key is found in hash table, remove it
    if (i != hashTable[hashValue].end()) {
    	hashTable[hashValue].erase(i);
        cout << "[INFO] ID " << key << " deleted" << endl;
        return;
	}        
    else {
        cout << "[ERROR] ID " << key << " not found" << endl;
    }
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
