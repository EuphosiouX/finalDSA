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
    // Create a pointer on the first element of the index
    linkedList *temp = hashTable[hashValue];
    // Create a pointer to make new linkedList
    linkedList *head = new linkedList;

    // Set the value
    head->key = key;
    head->name = name;
    head->password = password;
    head->pin = pin;
    head->balance = balance;
    head->next = nullptr;

    // First element in the index
    if (temp->key == 0 && temp->name=="empty" && temp->password=="empty" && temp->pin==0 && temp->balance==0.0 && temp == nullptr){
    	// Check for duplicated ID
    	for (auto i=keyRecords.begin(); i!=keyRecords.end(); ++i) {
            if (*i == key) {
                cout << "Duplicated ID" << endl;
                return;
            }
   	 	}
        temp = head;
        hashTable[hashValue] = temp; 
        keyRecords.push_back(key);
        cout << "Successfuly insert user ID " << key << endl;
    }

    // If not, create a new element at the end of the linked list
    else 
    {
    	// Check for duplicated ID
    	for (auto i=keyRecords.begin(); i!=keyRecords.end(); ++i) {
            if (*i == key) {
                 cout << "Duplicated ID" << endl;
                 return;
            }
   		}
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head; 
        keyRecords.push_back(key);
        cout << "Successfuly insert user ID " << key << endl;
    }
}

// Delete item from hash tables by key
void HashTable::deleteItem(int key) {
    // Get the index of hashtable
    hashValue = hashFunction(key);

    // Create a pointer at the first element of the index
    linkedList *temp = hashTable[hashValue];
    linkedList *prev = nullptr;

	// Check if the index of the hashtable not equal to zero
    if (hashValue != 0) {
        // If the first element of the index is null
        if (temp == nullptr) {
            cout <<"ID " << key << " does not exist" << endl;
            return;
        }
        // If the first element of linked list matches key 
        if (temp->key == key) {
            prev = temp;
            temp = temp->next;
            keyRecords.remove(key); 
            delete prev;
            hashTable[hashValue] = temp;
            cout<< "ID " << key << " deleted" << endl;
            return;
        }
        else {
        	// While temp haven't reached end of linked list
            while (temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
                if (prev->next == nullptr){
                    // If the first element of the index is not null
                    if (prev->key != key){
                        cout <<"ID " << key << " does not exist" << endl;
                        return;
                    }
                }
                // Else if ID match
                else if (temp->key == key) {
                    prev->next = temp->next;
                    temp->next = nullptr;
                    keyRecords.remove(key); 
                    cout<< "ID " << key << " deleted" << endl;
                    return;
                }
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
        // Check if temp is empty
        if (temp == nullptr){
            cout<< "Error when displaying ID " << key << endl;
            return;
        }
        // While haven't reach the end of the linkedList
        while (temp != nullptr) {
            // Check if input key is equal to the value key stored
            if (temp->key == key) {
                cout << "ID: " << temp->key << "\n";
                cout << "Name: " << temp->name << "\n";
                cout << "Balance: " << temp->balance << "\n";
                return;
            } 
            // Else if input key is not equal to the value key stored
            // and check if it has reached the end of the linkedlist
			else if (temp->key != key && temp->next == nullptr) {
                cout<< "Error when displaying ID " << key << endl;
                return;
            }
            temp = temp->next;
        }
    } 
}

// Function for customer to change Password
void HashTable::changePassword(int key, string oldPassword, string newPassword) {
    // Get the index of hashtable
    hashValue = hashFunction(key);

    // Check if the index of the hashtable not equal to zero
    if(hashValue!=0) {
        // Create a temp pointer at the first element of the index
        linkedList *temp = hashTable[hashValue];
        // Check if temp is empty
        if (temp == nullptr) {
            cout << "No Element found at ID " << key <<endl;
            return; 
        }
        // While haven't reach the end of the linkedList
        while (temp != nullptr) {
            // Check if input key is equal to the value key stored
            if (temp->key == key) {
            	// Check if input old password is equal to the value password stored
            	// If equal, change password with the one inputted
                if (temp->password == oldPassword) {
                    temp->password = newPassword;
                    cout << "Password successfully updated" << endl;
                    return;
                } 
                // Else if password doesn't match with the value password stored, not allowed to change
				else if (temp->password != oldPassword) {
                    cout << "You are not authenticated to change password" << endl;
                    return;
                }
            }
            // Else if input key is not equal to the value key stored
            // and check if it has reached the end of the linkedlist
            else if (temp->key != key && temp->next == nullptr){
                cout << "No Element found at ID " << key <<endl;
                return;
            }
            temp = temp->next;
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
		// Check if temp is empty
		if (temp == nullptr) {
			cout << "No Element found at ID " << key <<endl;
			return;	
		} 
		// While haven't reach the end of the linkedList
		while(temp != nullptr) {
			// Check if input key is equal to the value key stored
			if (temp->key == key) {
				// Check if inputted pin is equal to the value pin stored by the key
				if (temp->pin == pin) {
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
				// Else if inputted pin doesn't match with the value pin stored
				else if (temp->pin != pin) {
					cout << "You are not allowed to withdraw" << endl;
					return;
				}
			} 
			//  Check if the inputed key doesn't match with stored one
			// and check if it has reached the end of the linkedlist
			else if (temp->key != key && temp->next == nullptr) {
				cout << "You're not allowed to withdraw " << key <<endl;
				return; 
			}
			temp = temp->next;
		}	
	}
}

// Function for customer to deposit 
void HashTable::deposit(int key, int pin, double amt) {
	// Get the index of hashtable
	hashValue = hashFunction(key);
	
	// Check if the index of the hashtable not equal to zero
	if (hashValue != 0) {
		// Create a temp pointer at the first element of the index
		linkedList *temp = hashTable[hashValue];
		// Check if temp is empty
		if (temp == nullptr) {
			cout << "No Element found at ID " << key <<endl;
			return;	
		} 
		// While haven't reach the end of the linkedList
		while(temp != nullptr) {
			// Check if input key is equal to the value key stored
			if (temp->key == key) {
				// Check if inputted pin is equal to the value pin stored by the key
				if (temp->pin == pin) {
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
				// Else if inputted pin doesn't match with the value pin stored
				else if (temp->pin != pin) {
					cout << "You are not allowed to deposit" << endl;
					return;
				}
				
			}
			//  Check if the inputed key doesn't match with stored one
			// and check if it has reached the end of the linkedlist
			else if (temp->key != key && temp->next == nullptr) {
				cout << "You're not allowed to deposit " << key <<endl;
				return; 
			}
			temp = temp->next;
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
		// Check if temp is empty
		if (temp == nullptr) {
			cout << "No Element found at ID " << key <<endl;
			return; 
		}	
		// While haven't reach the end of the linkedList
		while(temp != nullptr) {
			// Check if input key is equal to the value key stored
			if (temp->key == key) {
				cout << "Withdraw records: [";
				for(auto i = temp->withdrawRecords.begin(); i!= temp->withdrawRecords.end(); ++i) {
					cout << "$" << *i << ","; 
				}
			cout << "]" << endl;
			return;
			}
			//  Check if the inputed key doesn't match with stored one
			// and check if it has reached the end of the linkedlist
			else if (temp->key != key && temp->next == nullptr) {
				cout << "You're not allowed to get the withdraw records " << key <<endl;
				return; 
			}	
			temp = temp->next;
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
		// Check if temp is empty
		if (temp == nullptr) {
			cout << "No Element found at ID " << key <<endl;
			return; 
		} 		
		// While haven't reach the end of the linkedList
		while(temp != nullptr) {
			// Check if input key is equal to the value key stored
			if (temp->key == key) {
				cout << "Deposit records: [";
				for(auto i = temp->depositRecords.begin(); i!= temp->depositRecords.end(); ++i) {
					cout << "$" << *i << ","; 
				}
				cout << "]" << endl;
				return;
			}
			//  Check if the inputed key doesn't match with stored one
			// and check if it has reached the end of the linkedlist
			else if (temp->key != key && temp->next == nullptr) {
				cout << "You're not allowed to get the deposit records  " << key <<endl;
				return; 
			}
			temp = temp->next;
		}
	}
}

// Function to get the index of the hashtable
int HashTable::hashFunction(int key) {
 	return key % max_hash_size;
}

// Function to check customer authentication to access customer menu
bool HashTable::checkCustomerAuth(int key, string password) {
	// Get the index of hashtable
 	hashValue = hashFunction(key);
 	
 	// Check if the index of the hashtable not equal to zero
    if(hashValue!=0) {
        // Create a temp pointer at the first element of the index
        linkedList *temp = hashTable[hashValue];
        // Check if temp is empty
        if (temp == nullptr) {
            cout << "No Element found at ID " << key <<endl;
            return false;
        }
        // While haven't reach the end of the linkedList
		while(temp != nullptr) {
			// Check if input key is equal to the value key stored
			if (temp->key == key) {
				// Check if input password is equal to the value password stored
				if (temp->password == password) {
					cout << "Welcome!" << endl;
					return true;
				}
				// Else if input password doesn't match with the value password stored, show error
				else if (temp->password != password) {
					cout << "Wrong password! Try again!" << endl;
					return false;
				}
				
			}
			//  Check if the inputed key don't match with stored one
			// and check if it has reached the end of the linkedlist
			else if (temp->key != key && temp->next == nullptr) {
				cout << "No Element found at ID " << key << endl;
				return false;
			}
			temp = temp->next;
		}
    } 	
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
	
	// Encrypted pin
	int encryptedPin = stoi(inputPin);
	
	return encryptedPin;
}

// Decrypt pin to ASCII 
int EncryptDecrypt::decryptPin(int pin) {
	string inputPin = to_string(pin);
	for (int i = 0; i < inputPin.length(); i++) {
		inputPin[i] = inputPin[i] - 2;
	}
	
	// Decrypted pin
	int decryptedPin = stoi(inputPin);
	
	return decryptedPin;
}
