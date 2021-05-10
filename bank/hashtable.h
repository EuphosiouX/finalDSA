#include <iostream>
#include <set>
#include <map>
using namespace std;

struct Values {
	int key; // original ID
	string name;
	string password;
	int pin;
	double balance;
};

class HashTable{
	private:
		static const int max_hash_size = 50;
		map<int, Values> hashTable;
		int hashValue; // hashFunction(key)
	public:
		HashTable();
		void insertItem(int key, string name, string password, int pin, double balance);
		void deleteItem(int key);
		int hashFunction(int key);
		void displayHash();
};
