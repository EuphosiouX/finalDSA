#include <iostream>
#include "hashtable.h"

using namespace std;

// Welcome introduction
void intro() {
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
	cout << " ____________________________________________________ " << endl;
	cout << "|                   Night Owl's Bank                 |" << endl;
	cout << "|____________________________________________________|" << endl;
	cout << "|____________________Customer Menu___________________|" << endl;
	cout << "|    1. Deposit                                      |" << endl;
        cout << "|    2. Withdraw                                     |" << endl;
        cout << "|    3. Display Balance                              |" << endl;
        cout << "|    4. Change Password                              |" << endl;
        cout << "|    5. Search Deposit Record                        |" << endl;
        cout << "|    6. Search Withdrawal Record                     |" << endl;
        cout << "|    7. Back                                         |" << endl;
        cout << "|____________________________________________________|" << endl;

}

// Main function
int main(void) {
	// Instantiate the class
    HashTable hashTable;
    EncryptDecrypt ende;
    
    // Variable input in the menu
    int answer;
    int adminAnswer;
    int custAnswer;
    
    // Admin variable
    string name, password;
	int key, pin, key2, key3, key4, key5;
	double balance;
	string adminPass = "12345admin";
	string adminPassInput;
	
	// Customer variable
	int custPin, custPin2;
	string oldPass, newPass;
	double amt, amt2;
	int custKeyAuth;
	string custPassAuth;
	
	
	do {
		intro();
		cin >> answer;
		switch(answer){
    		// ADMIN MENU
	    	case(1): {
	    		// Enter admin password 
	    		cout << "Enter your admin password:					" << endl;
	    		cin >> adminPassInput;
	    		// If true, authenticated to access admin menu
	    		if (adminPass == adminPassInput) {
	    			do {
	    				// Call admin menu
		    			adminFunction();
		    			cin >> adminAnswer;
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
					} while (adminAnswer != 6); // if true, go back to main menu
				} 
				// Else, not authenticate to access admin menu
				else{
					cout << "You are not allowed to access admin menu!" << endl;
					break;
				}  		
				break;
			} 
	    		
			// CUSTOMER MENU
			case(2): {
				// Enter customer's ID and password
				cout << "Enter your ID number:												" << endl;
				cin >> custKeyAuth;
				cout << "Enter your password:												" << endl;
				cin >> custPassAuth;
				// Check if customer have an account, if yes, authenticated to access customer's menu
				if (hashTable.checkCustomerAuth(custKeyAuth, ende.encryptPassword(custPassAuth))) {
					do {
						// Call customer menu
						custFunction();
						cin >> custAnswer;
						switch(custAnswer) {
							// 1. Deposit
					    	case(1): {
					    		// Get customer input: customerPin, amount of money
					    		cout << "Insert your pin: 										" << endl;
					    		cin >> custPin;
					    		cout << "Insert the amount of money you want to deposit: 		" << endl;
								cin  >> amt;
								
								// Encrypt pin to authenticate
								int encryptedPin = ende.encryptPin(custPin);
								
								// Deposit
								hashTable.deposit(custKeyAuth, encryptedPin, amt);
								
								break;
							}
							// 2. Withdraw
							case(2): {
								// Get customer input: customerPin, amount of money
					    		cout << "Insert your pin: 										" << endl;
					    		cin >> custPin2;
					    		cout << "Insert the amount of money you want to withdraw: 		" << endl;
								cin  >> amt2;
								
								// Encrypt pin to authenticate
								int encryptedPin2 = ende.encryptPin(custPin2);
								
								// Withdraw
								hashTable.withdrawal(custKeyAuth, encryptedPin2, amt2);
					    		
								break;
							}
							// 3. Display balance
							case(3): {		
						   		// Display account balance
					    		hashTable.displayHash(custKeyAuth);
					    		
								break;
							}
							// 4. Change password
							case(4): {
								// Get customer input: oldPassword, newPassword
					    		cout << "Insert old password: 										" << endl;
					    		cin >> oldPass;
					    		cout << "Insert new password: 										" << endl;
					    		cin >> newPass;
					    		
					    		// Encrypt old password
					    		string encryptedOldPassword = ende.encryptPassword(oldPass);
					    		
					    		// Encrypt new password
					    		string encryptedNewPassword = ende.encryptPassword(newPass);
					    		
					    		// Change to new password
					    		hashTable.changePassword(custKeyAuth, encryptedOldPassword, encryptedNewPassword);
					    		
								break;
							}
							// 5. Search deposit record
							case(5): {
					    		// Display the withdrawal record of current customer
					    		hashTable.getDepositRecords(custKeyAuth);
					    		
								break;
							}
							// 6. Search withdrawal record
							case(6): {
					    		// Display the withdrawal record of current customer
					    		hashTable.getWithdrawRecords(custKeyAuth);
					    		
								break;
							}
						}  		
					} while (custAnswer != 7); // If 7, go back to the main menu
				}
				// Else, not authorized to access customer menu
				else {
					cout << "You are not authorized to access customer menu" << endl;
					break;
				}	
				break;	
			}		
		}
	} while (answer != 3); // if 3, terminate the program
	
	cout << "Thankyou for using Night Owl's Bank!!!" << endl;
    
    return 0;
}
