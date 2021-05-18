#include <iostream>
#include "hashtable.h"

using namespace std;

int main(void) {
    HashTable hashTable;

    hashTable.insertItem(2003, "vania", "12345vania", 2435, 3450.9);
    hashTable.searchHash(2003);
    hashTable.changePassword(2003, "vania123");
    hashTable.searchHash(2003);
//    hashTable.insertItem(3006, "mikey", "12345mikey", 2435, 3450.9);
//    hashTable.insertItem(3006, "mikey", "12345mikey", 2435, 3450.9);
//    hashTable.insertItem(2006, "mikey", "12345mikey", 2435, 3450.9);
    hashTable.insertItem(4006, "asdf", "asdfasdfadf", 2435, 345.9);
    hashTable.insertItem(4000, "asdf", "asdfasdfadf", 2435, 345.9);
    hashTable.insertItem(4001, "asdf", "asdfasdfadf", 2435, 345.9);
    hashTable.deleteItem(2006);
	hashTable.searchHash(4006);
    hashTable.withdraw(4006, "asdfasdfadf", 2435, 340.3);
    hashTable.withdraw(4006, "asdfasdfadf", 2435, 1.3);
    hashTable.searchHash(4006);
    hashTable.withdrawRecords(4006);

//    hashTable.deleteItem(3005);
//    hashTable.deleteItem(2006);
//    hashTable.deleteItem(4006);
//    hashTable.displayHash();

    return 0;
}
