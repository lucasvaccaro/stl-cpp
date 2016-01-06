#include <string>
#include "Set.h"
using namespace std;

// ARRAY

void SetArray::insert(string key) {
    if (!this->is_in(key)) {
        this->set.insert(key, false);
    }
}

bool SetArray::is_in(string key) {
    return this->set.search(key) >= 0;
}

void SetArray::remove(string key) {
    this->set.remove(key);
}

bool SetArray::is_empty() {
    return this->set.getNumItems() == 0;
}

// LINKED LIST

void SetLinkedList::insert(string key) {
    if (!this->is_in(key)) {
        this->set.insert(key, false);
    }
}

bool SetLinkedList::is_in(string key) {
    return this->set.search(key) != NULL;
}

void SetLinkedList::remove(string key) {
    this->set.remove(key);
}

bool SetLinkedList::is_empty() {
    return this->set.getNumItems() == 0;
}

// HASH TABLE

HashSet::HashSet(){
    set = new LinkHash(1000);
}

void HashSet::insert(string key){
    if(set->contains(key)){
        cout << "Already contained" << endl;
        return;
    }
    set->addKey(key);
}

bool HashSet::is_empty(){
    return set->isEmpty();
}

bool HashSet::is_in(string key){
    return set->contains(key);
}

void HashSet::remove(string key){
    set->removeKey(key);
}