#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <list>

using namespace std;

// HashTable class
class HashTable{
    private:
        static const int max_hash_size = 50;
        // Linkedlist class
        class linkedList {
        	public:
        		int key; // original ID
			    string name;
			    string password;
			    int pin;
			    double balance;
			    linkedList *next;
			    list<double> withdrawRecords;
			    list<double> depositRecords;
        			
		};
		linkedList* hashTable[max_hash_size];
		int hashValue;
		list<int> keyRecords;
    public:
        HashTable();
        void insertItem(int key, string name, string password, int pin, double balance);
        void deleteItem(int key);
        int hashFunction(int key);
        void displayHash(int key);
        void changePassword(int key, string oldPassword, string newPassword);
        void withdrawal(int key, int pin, double amt);
        void deposit(int key, int pin, double amt);
        void getWithdrawRecords(int key);
        void getDepositRecords(int key);
        bool checkCustomerAuth(int key, string password);
};

// Encrypt Decrypt class
class EncryptDecrypt {
	public:
		EncryptDecrypt();
		string encryptPassword(string password);
		int encryptPin(int pin);
		string decryptPassword(string password);
		int decryptPin(int pin);
};

#endif
