#pragma once
#include "Node.h"
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;
class LinkHash{
    private:
        unsigned short seed;
        unsigned long SIZE;
        string* keysAdded; //list needed for HashMultiSet::draw_random()
        int keysAddedSize; //how large is keys list array?
        int numKeys; //needed for draw_random()
        Node *myList;
        //Private method block that takes in more parameters
        //AKA where the magic happens
        void removeKey(const string &key, int value, bool valueMatters);
        void addKey(const string &key, int value, bool valueMatters);
        bool contains(const string &key, int value, bool valueMatters);
        int countElems(const string &key, int value, bool valueMatters);
    public:
        ~LinkHash();
        //Creates a HashTable with a given size
        LinkHash(unsigned long size);
        LinkHash(unsigned long size, unsigned int seed);
        //Hash function
        unsigned int FNVHash(const std::string &str);
        //Calls the Complicated hash function and turns that into something within the bounds of the table
        int hash(const string &key);
        
        //Prints the collisions for a given key
        void printCollisions(const string &key);
        
        //Adds a key to the table, overloaded with or without a value given
        void addKey(const string &key);
        void addKey(const string &key, int value);
        
        //Removes a key from the table, overloaded with or without a value given
        void removeKey(const string &key);
        void removeKey(const string &key, int value);
        
        //Checks to see if a key/key,value pair is in the table
        bool contains(const string &key, int value);
        bool contains(const string &key);
        
        //Checks if the table is empty
        bool isEmpty();
        
        //Returns a value for a given key, returns second parameter if not found
        int getValue(const string &key, int notFound);
        //Returns the pointer of the value of a given key
        int* getValueByRef(const string &key);
        //Returns an array of ints given a key
        int *getValues(const string &key);
        //Returns a key
        string getKey(int);
        
        
        //Counts all of the elements in the table
        int countElems();
        //Counts all of the key/key,value pairs in the table 
        int countElems(const string &key);
        int countElems(const string &key, int value);
        //for draw_random
        int getNumKeys();
};