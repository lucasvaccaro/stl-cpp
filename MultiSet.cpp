#include <string>
#include <stdlib.h>
#include "MultiSet.h"
using namespace std;

// ARRAY

void MultiSetArray::insert(string key) {
    this->set.insert(key, false);
}

bool MultiSetArray::is_in(string key) {
    return this->set.search(key) >= 0;
}

int MultiSetArray::count(string key) {
    return this->set.count(key);
}

void MultiSetArray::removeOne(string key) {
    this->set.removeOne(key);
}

void MultiSetArray::removeAll(string key) {
    int count = this->count(key);
    for (int i = 0; i < count; i++) {
        this->set.remove(key);
    }
}

bool MultiSetArray::is_empty() {
    return this->set.getNumItems() == 0;
}

string MultiSetArray::draw_random() {
    int numKeys = this->set.getNumItems();
    
    if (numKeys > 0) {
        //srand seed is created in main.cpp
        int elem = 0;
        elem += rand() % numKeys; // 0 - (numKeys - 1)
 
        return this->set.getKey(elem);
    }
    
    return "No keys in MultiSet";
}

// LINKED LIST

void MultiSetLinkedList::insert(string key) {
    this->set.insert(key, false);
}

bool MultiSetLinkedList::is_in(string key) {
    return this->set.search(key) != NULL;
}

int MultiSetLinkedList::count(string key) {
    return this->set.count(key);
}

void MultiSetLinkedList::removeOne(string key) {
    this->set.remove(key);
}

void MultiSetLinkedList::removeAll(string key) {
    int count = this->count(key);
    for (int i = 0; i < count; i++) {
        this->set.remove(key);
    }
}

bool MultiSetLinkedList::is_empty() {
    return this->set.getNumItems() == 0;
}


string MultiSetLinkedList::draw_random() {
    int numKeys = this->set.getNumItems();
    
    if (numKeys > 0) {
        //srand seed is created in main.cpp
        int elem = 0;
        elem += rand() % numKeys; // 0 - (numKeys - 1)
        
        return this->set.getKey(elem);
    }
    
    return "No keys in MultiSet";
}

//HashTable
HashMultiSet::HashMultiSet(){
    set = new LinkHash(1000);
}

void HashMultiSet::insert(string key){
    set->addKey(key);
}

bool HashMultiSet::is_in(string key){
    return set->contains(key);
}

unsigned long HashMultiSet::count(string key){
    return (unsigned long)abs(set->countElems(key));
}

void HashMultiSet::removeOne(string key){
    set->removeKey(key);
}

void HashMultiSet::removeAll(string key){
    while(set->contains(key)){
        set->removeKey(key);
    }
}

bool HashMultiSet::is_empty(){
    return set->isEmpty();
}

string HashMultiSet::draw_random() {
    int numKeys = this->set->getNumKeys();
    
    if (numKeys > 0) {
        //srand seed is created in main.cpp
        int elem = 0;
        elem += rand() % numKeys; // 0 - (numKeys - 1)
        
        //cout << "Random number: " << elem << endl;
 
        return this->set->getKey(elem);
    }
    
    return "No keys in MultiSet";
}