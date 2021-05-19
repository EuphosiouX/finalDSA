//#include <iostream>
//#include <string>
//#include "hashtable.h"
//
//using namespace std;
//
//int main(void) {
//	HashTable hashTable;
//    EncryptDecrypt ende;
//    int answer;
//    int adminAnswer;
//    int custAnswer;
//    string ans;
//    
//    // Admin
//    string name, password;
//	int key, pin, key2, key3, key4, key5;
//	double balance;
//	
//	// Customer
//	int custKey, custPin, custKey2, custPin2, custKey3, custKey4, custKey5;
//	string pass;
//	double amt, amt2;
//	
//	menu:
////		system("cls");
//	
//		cout << " ____________________________________________________ " << endl;
//		cout << "|                   Night Owl's Bank                 |" << endl;
//		cout << "|____________________________________________________|" << endl;
//		cout << "|________________________Menu________________________|" << endl;
//		cout << "|    1. Admin                                        |" << endl;
//	    cout << "|    2. Customer                                     |" << endl;
//	    cout << "|    3. Exit                                         |" << endl;
//	    cout << "|____________________________________________________|" << endl;
//	    
//	    cout << ">> ";
//	    cin >> answer;
//	    
//	    switch (answer) {
//	    	case (1):
//	    		admin:
////	    			system("cls");
//	
//					cout << " ____________________________________________________ " << endl;
//					cout << "|                   Night Owl's Bank                 |" << endl;
//					cout << "|____________________________________________________|" << endl;
//					cout << "|_____________________Admin Menu_____________________|" << endl;
//					cout << "|    1. Add Customer                                 |" << endl;
//				    cout << "|    2. Delete Customer                              |" << endl;
//				    cout << "|    3. Search Customer                              |" << endl;
//				    cout << "|    4. Search Deposit Record                        |" << endl;
//				    cout << "|    5. Search Withdrawal Record                     |" << endl;
//				    cout << "|    6. Back                                         |" << endl;
//				    cout << "|____________________________________________________|" << endl;
//				    
//				    cout << ">> ";
//				    cin >> adminAnswer;
//				    
//				    switch(adminAnswer) {
//				    	case (1): {
//							
//						
//				    		// Get admin input: customerKey, name, password, pin, balance
//				    		cout << "Insert customer's key: 		" << endl;
//				    		cin >> key;
//				    		cout << "Insert customer's name:    	" << endl;
//				    		cin >> name;
//				    		cout << "Insert customer's password: 	" << endl;
//				    		cin >> password;
//				    		cout << "Insert customer's pin:			" << endl;
//				    		cin >> pin;
//				    		cout << "Insert customer's balance: 	" << endl;
//				    		cin >> balance;
//				    		
//				    		// Encrypt pin and password
//				    		int encryptedPin = ende.encryptPin(pin);
//				    		string encryptedPassword = ende.encryptPassword(password);
//				    		
//				    		// Adding new customer into the hashtable
//				    		hashTable.insertItem(key, name, encryptedPassword, encryptedPin, balance);
//				    		
//    		                cout<<"Continue? (Y/N): "; 
//							cin>> ans;
//                            if(ans=="Y"||"y")
//                            {
//                                goto admin;
//                            }
//                            else if(ans=="N"||"n")
//                            {
//                                goto menu;
//                            }             	
//							break;
//						} 
//						case (2): {
//				
//							// Get admin input: customerKey
//							cout << "Insert customer's key: 		" << endl;
//							cin  >> key2;
//							
//							// Delete customer from hashtable
//							hashTable.deleteItem(key2);
//							
//							cout<<"Continue? (Y/N): "; 
//							cin>> ans;
//                            if(ans=="Y"||"y")
//                            {
//                                goto admin;
//                            }
//                            else if(ans=="N"||"n")
//                            {
//                                goto menu;
//                            }        
//				    		
//							break;
//						}
//						case (3): {
//				
//							// Get admin input: customerKey
//							cout << "Insert customer's key: 		" << endl;
//							cin  >> key3;
//							
//							// Display the customer details: key, name, balance
//							hashTable.displayHash(key3);
//							
//							cout<<"Continue? (Y/N): "; 
//							cin>> ans;
//                            if(ans=="Y"||"y")
//                            {
//                                goto admin;
//                            }
//                            else if(ans=="N"||"n")
//                            {
//                                goto menu;
//                            }      
//								
//							break;
//						}
//							
//					}
//				
//				break;
//				    
//			case (2):
//				customer:
//					system("cls");
//	
//					cout << " ____________________________________________________ " << endl;
//					cout << "|                   Night Owl's Bank                 |" << endl;
//					cout << "|____________________________________________________|" << endl;
//					cout << "|____________________Customer Menu___________________|" << endl;
//					cout << "|    1. Deposit                                      |" << endl;
//				    cout << "|    2. Withdraw                                     |" << endl;
//				    cout << "|    3. Display Balance                              |" << endl;
//				    cout << "|    4. Change Password                              |" << endl;
//				    cout << "|    5. Search Withdrawal Record                     |" << endl;
//				    cout << "|    6. Back                                         |" << endl;
//				    cout << "|____________________________________________________|" << endl;
//				    
//				    cout << ">> ";
//				    cin >> custAnswer;
//				    
//				    
//	    	
//	    		break;
//	    	
//	    	
//	    	
//		}
//
//	
//	
//	
//	
//	
//	
//	
//	return 0;
//}
