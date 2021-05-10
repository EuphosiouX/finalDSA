#include <iostream>
#include "hashtable.h"

using namespace std;

int main(void) {
	HashTable hashTable;
	
	hashTable.insertItem(2003, "vania", "12345vania", 2435, 3450.9);
	hashTable.insertItem(3006, "mikey", "12345mikey", 2435, 3450.9);
	hashTable.displayHash();
	
	hashTable.deleteItem(3007);
	hashTable.deleteItem(2003);
	hashTable.displayHash();
	
	return 0;
}
