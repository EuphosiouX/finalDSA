#include <iostream>
#include <list>
using namespace std;

class HashTable{
	private:
		static const int hashGroups = 50;
		list<pair<int, string>> table[hashGroups];
};
