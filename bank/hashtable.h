#include <bits/stdc++.h>

using namespace std;

struct Values {
    int key; // original ID
    string name;
    string password;
    int pin;
    double balance;
    Values *next;
};

class HashTable{
    private:
        static const int max_hash_size = 50;
        list<Values> hashTable[max_hash_size];
        int hashValue; // hashFunction(key)
    public:
        HashTable();
        void insertItem(int key, string name, string password, int pin, double balance);
        void deleteItem(int key);
        int hashFunction(int key);
        void searchHash(int key);
};
