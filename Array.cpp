#include <string>
#include <iostream>
#include "Array.h"
using namespace std;

Array::Array() {
    this->numItems = 0;
    this->capacity = 1;
    this->pairs = new pair[this->capacity];
}

Array::~Array() {
    delete[] this->pairs;
}

void Array::resize(int newSize) {
    pair* newPairs = new pair[newSize];
    for (int i = 0; i < this->numItems; i++) {
        newPairs[i] = this->pairs[i];
    }
    delete[] this->pairs;
    this->pairs = newPairs;
    this->capacity = newSize;
}

void Array::insert(string key, int value){
    if (this->numItems >= this->capacity) {
        this->resize(2*(this->capacity));
    }
    int index;
    // if the key already exists, insert in its values, otherwise create new pair
    int possible_index = this->search(key);
    if (possible_index >= 0) {
        index = possible_index;
    } else {
        index = this->numItems;
        this->numItems++;
    }
    this->pairs[index].insert(key, value);
};

void Array::remove(string key) {
    int i = this->search(key);
    if (i >= 0) {
        if (this->numItems > 1) {
            // shift elements
            for (; i < this->numItems - 1; i++) {
                this->pairs[i] = this->pairs[i+1];
            }
            this->pairs[this->numItems].reset();
        }
        if (this->numItems > 0) { //if statement probably unnecessary, but just in case
            this->numItems--;
        }
    }
}

void Array::removeOne(string key) {
    int i = this->search(key);
    if (i >= 0) {
        this->pairs[i].removeOne();
    }
}

// returns index of array where key is first found
int Array::search(string key) {
    for (int i = 0; i < this->numItems; i++) {
        if (this->pairs[i].key == key) {
            return i;
        }
    }
    return -1;
}

int* Array::getValues(string key) {
    int i = this->search(key);
    if (i >= 0) {
        return this->pairs[i].getValues();
    }
    return NULL;
}

int* Array::getValuesRef(string key) {
    int i = this->search(key);
    if (i >= 0) {
        return this->pairs[i].getValuesRef();
    }
    return NULL;
}

int Array::getNumItems() {
    return this->numItems;
}

int Array::count(string key) {
    for (int i = 0; i < this->numItems; i++) {
        if (this->pairs[i].key == key) {
            return this->pairs[i].getNumItems();
        }
    }
    return 0;
}

string Array::getKey(int element) {
    return this->pairs[element].key;
}