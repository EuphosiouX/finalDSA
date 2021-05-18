#include "hashtable.h"
#include <iostream>
#include <iterator>

using namespace std;

// Constructor
HashTable::HashTable() {
	
}

void HashTable::insertItem(int key, string name, string password, int pin, double balance) {
	// Getting index from key
    hashValue = hashFunction(key);
    
    // Initialize new value
    Values val;
	val.key = key;
    val.name = name;
    val.password = password;
	val.pin = pin;
    val.balance = balance;

    
    for (auto x : hashTable[hashValue]) {
        if (x.key == val.key) {
            cout << "[ERROR] Duplicate ID " << val.key << endl;
            return;
        }
    }
    
    hashTable[hashValue].push_back(val);
}


void HashTable::changePassword(int key, string password) {
	hashValue = hashFunction(key);
	for (auto x: hashTable[hashValue]) {
		if (x.key == key) {
			deleteItem(key);
			insertItem(x.key, x.name, password, x.pin, x.balance);
			return;
		}
	}
}


void HashTable::deleteItem(int key){
  // get the hash index of key
    hashValue = hashFunction(key);

  // find the key in (inex)th list
    list <Values> :: iterator i;
    for (i = hashTable[hashValue].begin(); i != hashTable[hashValue].end(); i++) {
        Values currValue = *i;
        if (currValue.key == key)
              break;
    }

  // if key is found in hash table, remove it
    if (i != hashTable[hashValue].end())
        hashTable[hashValue].erase(i);
    else{
        cout << "ID NOT FOUND" << endl;
    }
}


// Search hashtable
void HashTable::searchHash(int key) {	
	hashValue = hashFunction(key);
	for (auto x : hashTable[hashValue]) {
		if (x.key == key) {
			cout << "ID: " << x.key << endl;
			cout << "Name: " << x.name << endl;
			cout << x.password << endl;
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

void HashTable::withdraw(int key, string password, int pin, double amt) {
	hashValue = hashFunction(key);
	for (auto x: hashTable[hashValue]) {
		if (x.key == key && x.password == password && x.pin == pin) {
			if (amt <= x.balance) {
				x.balance -= amt;
				cout << endl;
				cout << "You withdraw: $" << amt << "Your balance now: $" << x.balance << endl;
				deleteItem(key);
				insertItem(x.key, x.name, x.password, x.pin, x.balance);
				x.withdrawRecords.push_back(amt);	
				return;
			}
			else
			{
				cout << endl;
				cout << "Sorry, you cannot withdraw $" << amt << endl;
				cout << "Your current balance is only $" << x.balance << endl;
			}
		}
	}	
}

void HashTable::deposit(int key, string password, int pin, double amt) {
	hashValue = hashFunction(key);
	for (auto x: hashTable[hashValue]) {
		if (x.key == key && x.password == password && x.pin == pin) {
			if (amt > 0) {
				x.balance += amt;
				cout << endl;
				cout << "You deposit: $" << amt << "Your balance now: $" << x.balance << endl;
				x.depositRecords.push_back(amt);
				return;
			}
			else
			{
				cout << endl;
				cout << "Invalid amount" << endl;
			}
		}
	}	
}

void HashTable::withdrawRecords(int key) {
	hashValue = hashFunction(key);
	for (auto x: hashTable[hashValue]) {
		if (x.key == key) {
			for(auto i = x.withdrawRecords.begin(); i!= x.withdrawRecords.end(); ++i) {
				cout << "Withdraw records: [" << "$" << *i << "]" << endl;	
			}
			return;
		}
		else
		{
			cout << "Cannot access" << endl;
		}
	}
	
}
