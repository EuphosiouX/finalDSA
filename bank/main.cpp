#include <iostream>
#include "hashtable.h"

using namespace std;

// Welcome introduction
void intro() {
	system("cls");
	
	cout << " ____________________________________________________ " << endl;
	cout << "|                   Night Owl's Bank                 |" << endl;
	cout << "|____________________________________________________|" << endl;
	cout << "|________________________Menu________________________|" << endl;
	cout << "|    1. Admin                                        |" << endl;
    cout << "|    2. Customer                                     |" << endl;
    cout << "|    3. Exit                                         |" << endl;
    cout << "|____________________________________________________|" << endl;
}

// For admin introduction
void adminFunction() {	
	system("cls");
	
	cout << " ____________________________________________________ " << endl;
	cout << "|                   Night Owl's Bank                 |" << endl;
	cout << "|____________________________________________________|" << endl;
	cout << "|_____________________Admin Menu_____________________|" << endl;
	cout << "|    1. Add Customer                                 |" << endl;
    cout << "|    2. Delete Customer                              |" << endl;
    cout << "|    3. Search Customer                              |" << endl;
    cout << "|    4. Search Deposit Record                        |" << endl;
    cout << "|    5. Search Withdrawal Record                     |" << endl;
    cout << "|    6. Back                                         |" << endl;
    cout << "|____________________________________________________|" << endl;
    
}

// For customer introduction
void custFunction() {
	system("cls");
	
	cout << " ____________________________________________________ " << endl;
	cout << "|                   Night Owl's Bank                 |" << endl;
	cout << "|____________________________________________________|" << endl;
	cout << "|____________________Customer Menu___________________|" << endl;
	cout << "|    1. Deposit                                      |" << endl;
    cout << "|    2. Withdraw                                     |" << endl;
    cout << "|    3. Display Balance                              |" << endl;
    cout << "|    4. Change Password                              |" << endl;
    cout << "|    5. Search Withdrawal Record                     |" << endl;
    cout << "|    6. Back                                         |" << endl;
    cout << "|____________________________________________________|" << endl;

}

// Main function
int main(void) {
    HashTable hashTable;
    EncryptDecrypt ende;
    int answer;
    int adminAnswer;
    int custAnswer;
    
    // Admin
    string name, password;
	int key, pin, key2, key3, key4, key5;
	double balance;
	
	// Customer
	int custKey, custPin, custKey2, custPin2, custKey3, custKey4, custKey5;
	string pass;
	double amt, amt2;
	
	do {
		intro();
		cin >> answer;
		switch(answer){
    		// ADMIN
	    	case(1): {
	    		do {
	    			adminFunction();
	    			cin >> adminAnswer;
	    			// Call admin welcome introduction
		    		switch(adminAnswer) {
		    			// 1. Add customer
				    	case(1): {
				    		// Get admin input: customerKey, name, password, pin, balance
				    		cout << "Insert customer's key: 		" << endl;
				    		cin >> key;
				    		cout << "Insert customer's name:    	" << endl;
				    		cin >> name;
				    		cout << "Insert customer's password: 	" << endl;
				    		cin >> password;
				    		cout << "Insert customer's pin:			" << endl;
				    		cin >> pin;
				    		cout << "Insert customer's balance: 	" << endl;
				    		cin >> balance;
				    		
				    		// Encrypt pin and password
				    		int encryptedPin = ende.encryptPin(pin);
				    		string encryptedPassword = ende.encryptPassword(password);
				    		
				    		// Adding new customer into the hashtable
				    		hashTable.insertItem(key, name, encryptedPassword, encryptedPin, balance);
				    		
							break;
						}
						// 2. Delete customer
						case(2): {
							// Get admin input: customerKey
							cout << "Insert customer's key: 		" << endl;
							cin  >> key2;
							
							// Delete customer from hashtable
							hashTable.deleteItem(key2);
				    		
							break;
						}
						// 3. Search customer
						case(3): {
							// Get admin input: customerKey
							cout << "Insert customer's key: 		" << endl;
							cin  >> key3;
							
							// Display the customer details: key, name, balance
							hashTable.displayHash(key3);
								
							break;
						}
						// 4. Search deposit record
						case(4): {
							// Get admin input: customerKey
							cout << "Insert customer's key: 		" << endl;
							cin  >> key4;
							
							// Display all the deposit record of that customer
							hashTable.getDepositRecords(key4);
				    		
							break;
						}
						// 5. Search withdrawal record
						case(5): {
							// Get admin input: customerKey
							cout << "Insert customer's key: 		" << endl;
							cin  >> key5;
							
							// Display all the withdrawal record of that customer
							hashTable.getWithdrawRecords(key5);	
							break;
						}
					}	
					break;
				} while (adminAnswer != 6);
				break;
			} 
	    		
			// CUSTOMER
			case(2): {
				do {
					custFunction();
					cin >> custAnswer;
					// Call customer welcome introduction
					switch(custAnswer) {
						// 1. Deposit
				    	case(1): {
				    		// Get customer input: customerKey, customerPin, amount of money
				    		cout << "Insert your key: 										" << endl;
				    		cin >> custKey;
				    		cout << "Insert your pin: 										" << endl;
				    		cin >> custPin;
				    		cout << "Insert the amount of money you want to deposit: 		" << endl;
							cin  >> amt;
							
							// Encrypt pin to authenticate
							int encryptedPin = ende.encryptPin(custPin);
							
							// Deposit
							hashTable.deposit(custKey, encryptedPin, amt);
							
							break;
						}
						// 2. Withdraw
						case(2): {
							// Get customer input: customerKey, customerPin, amount of money
							cout << "Insert your key: 										" << endl;
				    		cin >> custKey2;
				    		cout << "Insert your pin: 										" << endl;
				    		cin >> custPin2;
				    		cout << "Insert the amount of money you want to withdraw: 		" << endl;
							cin  >> amt2;
							
							// Encrypt pin to authenticate
							int encryptedPin2 = ende.encryptPin(custPin2);
							
							// Withdraw
							hashTable.withdrawal(custKey2, encryptedPin2, amt2);
				    		
							break;
						}
						// 3. Display balance
						case(3): {
							// Get customer input: customerKey
							cout << "Insert your key: 										" << endl;
				    		cin >> custKey3;
				    		
				    		// Display account balance
				    		hashTable.displayHash(custKey3);
				    		
							break;
						}
						// 4. Change password
						case(4): {
							// Get customer input: customerKey, newPassword
							cout << "Insert your key: 											" << endl;
				    		cin >> custKey4;
				    		cout << "Insert new password: 										" << endl;
				    		cin >> pass;
				    		
				    		// Encrypt password
				    		string encryptedNewPassword = ende.encryptPassword(pass);
				    		
				    		// Change to new password
				    		hashTable.changePassword(custKey4, encryptedNewPassword);
				    		
							break;
						}
						// 5. Search withdrawal record
						case(5): {
							// Get customer input: customerKey
							cout << "Insert your key: 											" << endl;
				    		cin >> custKey5;
				    		
				    		// Display the withdrawal record of current customer
				    		hashTable.getWithdrawRecords(custKey5);
				    		
							break;
						}
					}  		
					break;
				} while (custAnswer != 6);
				break;
			}		
		}
	} while (answer != 3);
	
	cout << "Thankyou for using Night Owl's Bank!!!" << endl;
    
    return 0;
}
