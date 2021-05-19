#include "hashtable.h"
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

// Class Constructor HashTable
HashTable::HashTable() {
	for(int i=0;i<max_hash_size;i++) {
		hashTable[i] = new linkedList;
		hashTable[i]->key = 0;
		hashTable[i]->name = "empty";
		hashTable[i]->password = "empty";
		hashTable[i]->pin = 0;
		hashTable[i]->balance = 0.0;
		hashTable[i]->next = nullptr;
	} 
}

// Insert item to the hash table
void HashTable::insertItem(int key, string name, string password, int pin, double balance) {
	// Get the index of hashtable
	int hashValue = hashFunction(key);
	
	// First element in the index
	if (hashTable[hashValue]->name=="empty" && hashTable[hashValue]->password=="empty"&&hashTable[hashValue]->pin==0&&hashTable[hashValue]->balance==0.0){
		// Check if there's duplicated ID
		for (auto i=keyRecords.begin(); i!=keyRecords.end(); ++i) {
			if (*i == key) {
				 cout << "Duplicated ID" << endl;
				 return;
			}		 
		}
		// Set the value and push_back
		hashTable[hashValue]->key = key;
		hashTable[hashValue]->name = name;
		hashTable[hashValue]->password = name;
		hashTable[hashValue]->pin = pin;
		hashTable[hashValue]->balance = balance;
		keyRecords.push_back(key);
	}
	
	// If not, create a new element at the end of the linked list
	else 
	{
		// Check if there's duplicated ID
		for (auto i=keyRecords.begin(); i!=keyRecords.end(); ++i) {
			if (*i == key) {
				cout << "Duplicated ID" << endl;
				return;
			}		 
		}
		// Create a pointer on the first element of the index
		linkedList *temp = hashTable[hashValue];
		// Create a pointer to make new linkedList
		linkedList *head = new linkedList;
		// Set the value and push_back
		if (temp->key != key) {
			head->key = key;
			head->name = name;
			head->password = password;
			head->pin = pin;
			head->balance = balance;
			keyRecords.push_back(key); 
			while(temp->next != nullptr) {
				temp = temp->next;
			}
		temp->next = head; 
		}
	}
}

// Delete item from hash tables by key
void HashTable::deleteItem(int key) {
	// Get the index of hashtable
	hashValue = hashFunction(key);
	
	// Create a pointer at the first element of the index
	linkedList *temp = hashTable[hashValue];
	linkedList *prev = hashTable[hashValue];
	
	if (hashValue != 0) {
		// If there is no linked list
		if (temp->next == nullptr) {
			if (temp->key == key) {
				keyRecords.remove(temp->key); 
				free(temp);
				cout<< "ID " << key << " deleted" << endl;
				return;
			}
		}
		
		// Else if the first value of linked list matches key 
		else if (temp->key == key) {
			prev = temp;
			temp = temp->next;
			keyRecords.remove(prev->key); 
			free(prev);
			hashTable[hashValue] = temp;			
			cout<< "ID " << key << " deleted" << endl;
			return;			
		}
			
		// Else iterate through linked list
		else {
			while (temp->next != nullptr)
			{
				prev = temp;
				temp = temp->next;
				if (temp->key == key) {
					prev->next = temp->next;
					temp->next = nullptr;
					keyRecords.remove(temp->key); 
					cout<< "ID " << key << " deleted" << endl;
					return;  
				}	
				// If it does not exist
				cout << "ID " << key << " does not exist" << endl;
				return;			
			}		
		}	
	}
}

// Display the hash tables of a particular key
void HashTable::displayHash(int key) { 
	// Get the index of hashtable
	hashValue = hashFunction(key);
	
	// Check if the index of the hashtable not equal to zero
	if(hashValue!=0) {
		// Create a temp pointer at the first element of the index
		linkedList *temp = hashTable[hashValue];
			// While haven't reach the end of the linkedList
			while (temp->next != nullptr) {
				// Check if input key is equal to the value key stored
				if (temp->key == key) {
					cout << "ID: " << temp->key << "\n";
					cout << "Name: " << temp->name << "\n";
					cout << "Balance: " << temp->balance << "\n";
					return;
				}
				temp = temp->next;
			}
		// Check if temp is empty or the key doesn't match
		if (temp == nullptr || temp->key != key){
			cout<<"Error when displaying ID " << key << endl;
			return;
		}
	} 
}

// Change Password
void HashTable::changePassword(int key, string password) {
	// Get the index of hashtable
	hashValue = hashFunction(key);
	
	// Check if the index of the hashtable not equal to zero
	if(hashValue!=0) {
		// Create a temp pointer at the first element of the index
		linkedList *temp = hashTable[hashValue];
		// While haven't reach the end of the linkedList
		while (temp->next != nullptr) {
			// Check if input key is equal to the value key stored
			// If equal, change password with the one inputted
			if (temp->key == key) {
				temp->password = password;
				return;
			}	
			temp = temp->next;
		}
		// Check if temp is empty or the key doesn't match
		if (temp == nullptr || temp->key != key) {
			cout << "No Element found at key " << key <<endl;
			return; 
		}
	} 
}

// Withdraw function
void HashTable::withdrawal(int key, int pin, double amt) {
	// Get the index of hashtable
	hashValue = hashFunction(key);
 
 	// Check if the index of the hashtable not equal to zero
	if (hashValue != 0) {
		// Create a temp pointer at the first element of the index
		linkedList *temp = hashTable[hashValue];
		// While haven't reach the end of the linkedList
		while(temp->next != nullptr) {
			// Check if input key and pin are equal to the value key and pin stored
			if (temp->key == key && temp->pin == pin) {
				// Check if inputted ammount is less than existing balance
				// If true, decrement the balance by the amount of money inputted
				// Push the amount of money withdraw to the withdrawRecords
				if (amt <= temp->balance) {
					temp->balance -= amt;
					temp->withdrawRecords.push_back(amt);
					cout << "Successfully withrawn $" << amt << endl;
					return;
				}
				// Else, show error
				else {
					cout << "Insufficient balance" << endl;
				}
			} 
			temp = temp->next;
		}
		// Check if temp is empty
		if (temp == nullptr) {
			return;	
		} 
		//  Check if the inpuuted key and pin don't match with stored one
		if (temp->key != key && temp->pin != pin)
		{
			cout << "You're not allowed to withdraw" << key <<endl;
			return; 
		}	
	}
}

// Deposit function
void HashTable::deposit(int key, int pin, double amt) {
	// Get the index of hashtable
	hashValue = hashFunction(key);
	
	// Check if the index of the hashtable not equal to zero
	if (hashValue != 0) {
		// Create a temp pointer at the first element of the index
		linkedList *temp = hashTable[hashValue];
		// While haven't reach the end of the linkedList
		while(temp->next != nullptr) {
			// Check if input key and pin are equal to the value key and pin stored
			if (temp->key == key && temp->pin == pin) {
				// Check if inputted ammount is larger than 0
				// If true, increment the balance by the amount of money inputted
				// Push the amount of money deposit to the depositRecords
				if (amt > 0) {
					temp->balance += amt;
					temp->depositRecords.push_back(amt);
					cout << "Successfully deposit $" << amt << endl;
					return;
				}
				// Else, show error
				else {
					cout << "Must be bigger amount than 0" << endl;
				}
			}
			temp = temp->next;
		}
		// Check if temp is empty
		if (temp == nullptr) {
			return;	
		} 
		//  Check if the inpuuted key and pin don't match with stored one
		if (temp->key != key && temp->pin != pin)
		{
			cout << "You're not allowed to deposit" << key <<endl;
			return; 
		}
	}
}

// Get the withdraw records of certain customer
void HashTable::getWithdrawRecords(int key) {
	// Get the index of hashtable
 	hashValue = hashFunction(key);
 
 	// Check if the index of the hashtable not equal to zero
	if (hashValue != 0) {
		// Create a temp pointer at the first element of the index
		linkedList *temp = hashTable[hashValue];
		// While haven't reach the end of the linkedList
		while(temp->next != nullptr) {
			// Check if input key is equal to the value key stored
			if (temp->key == key) {
				cout << "Withdraw records: [";
				for(auto i = temp->withdrawRecords.begin(); i!= temp->withdrawRecords.end(); ++i) {
					cout << "$" << *i << ","; 
				}
			cout << "]" << endl;
			return;
			}	
			temp = temp->next;
		}
		// Check if temp is empty
		if (temp == nullptr) {
			return; 
		}
		//  Check if the inpuuted key doesn't match with stored one
		if (temp->key != key)
		{
			cout << "You're not allowed to get the withdraw records" << key <<endl;
			return; 
		} 	
	}
}

// Get the deposit records of certain customer
void HashTable::getDepositRecords(int key) {
	// Get the index of hashtable
 	hashValue = hashFunction(key);
 	
 	// Check if the index of the hashtable not equal to zero
	if (hashValue != 0) {
		// Create a temp pointer at the first element of the index
		linkedList *temp = hashTable[hashValue];
			// While haven't reach the end of the linkedList
			while(temp->next != nullptr) {
				// Check if input key is equal to the value key stored
				if (temp->key == key) {
					cout << "Deposit records: [";
					for(auto i = temp->depositRecords.begin(); i!= temp->depositRecords.end(); ++i) {
						cout << "$" << *i << ","; 
					}
					cout << "]" << endl;
					return;
				}
				temp = temp->next;
			}
		// Check if temp is empty
		if (temp == nullptr) {
			return; 
		} 
		//  Check if the inpuuted key doesn't match with stored one
		if (temp->key != key)
		{
			cout << "You're not allowed to get the deposit records" << key <<endl;
			return; 
		} 		
	}
}

// Function to get the index of the hashtable
int HashTable::hashFunction(int key) {
 	return key % max_hash_size;
}

// Class constructor EncryptDecrypt
EncryptDecrypt::EncryptDecrypt() {
	
}

// Encrypt password to ASCII 
string EncryptDecrypt::encryptPassword(string password) {
	for (int i = 0; i < password.length(); i++) {	
		password[i] = password[i] + 2;	
	}
	return password;		
}

// Decrypt password to ASCII 
string EncryptDecrypt::decryptPassword(string password) {
	for (int i = 0; i < password.length(); i++) {	
		password[i] = password[i] - 2;	
	}
	return password;
}

// Encrypt pin to ASCII 
int EncryptDecrypt::encryptPin(int pin) {
	string inputPin = to_string(pin);
	
	for (int i = 0; i < inputPin.length(); i++) {	
		inputPin[i] = inputPin[i] + 2;	
	}
	
	int encryptedPin = stoi(inputPin);
	
	return encryptedPin;
}

// Decrypt pin to ASCII 
int EncryptDecrypt::decryptPin(int pin) {
	string inputPin = to_string(pin);
	for (int i = 0; i < inputPin.length(); i++) {
		inputPin[i] = inputPin[i] - 2;
	}
	
	int decryptedPin = stoi(inputPin);
	
	return decryptedPin;
}


