#pragma once
#include <iostream>
#include <string>
using namespace std;

class Array {
    public:
        Array();
        ~Array();
        void insert(string, int);
        void remove(string);
        void removeOne(string);
        int search(string);
        int* getValues(string); // Returns a copy
        int* getValuesRef(string); /* Returns a reference using a special version
                                      of pair.getValues() called pair.getValuesRef()*/
        int getNumItems();
        int count(string);
        string getKey(int);
    private:
        // the pair struct contains a key and an array of values
        struct pair {
            string key;
            pair() {
                init();
            }
            ~pair() {
                //delete[] this->values;
            }
            pair(string key, int value) {
                init();
                insert(key, value);
            }
            void insert(string newKey, int newValue) {
                if (index == size) {
                    resize();
                }
                key = newKey;
                values[index] = newValue;
                index++;
            }
            void removeOne() {
                index--;
            }
            int getNumItems() {
                return index;
            }
            int* getValues() {
                int* returnValues = new int[index];
                for (int i = 0; i < size; i++) {
                    returnValues[i] = values[i];
                }
                return returnValues;
            }
            int* getValuesRef() {
                int i = 0;
                if (i < size) {
                    int* ptrToVal = &values[0];
                    return ptrToVal;
                }
                //doesn't make a copy, heck, do we even need the other version?
            }
            void reset() {
                delete[] values;
                init();
            }
            private:
                int* values;
                int index;
                int size;
                void init() {
                    index = 0;
                    size = 1;
                    values = new int[size];
                }
                void resize() {
                    int newSize = size*2;
                    int* newValues = new int[newSize];
                    for (int i = 0; i < size; i++) {
                        newValues[i] = values[i];
                    }
                    values = newValues;
                    size = newSize;
                }
        };
        pair* pairs;
        int capacity;
        int numItems;
        void resize(int newSize);
};