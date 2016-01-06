#include <string>
#include "Map.h"
using namespace std;

// ARRAY

void MapArray::set(string key, int value) {
    this->map.insert(key, value);
}

void MapArray::remove(string key) {
    this->map.remove(key);
}

int MapArray::get(string key) {
    int* values = this->map.getValues(key);
    if (values != false) {
        return values[0];
    }
    return false;
}

int& MapArray::operator[](string key) {
    return *(this->map.getValuesRef(key));
}


// LINKED LIST

void MapLinkedList::set(string key, int value) {
    this->map.insert(key, value);
}

void MapLinkedList::remove(string key) {
    this->map.remove(key);
}

int MapLinkedList::get(string key) {
    Node* node = this->map.search(key);
    if (node != NULL) {
        return node->getValue();
    }
    return false;
}

int* MapLinkedList::getPtr(string key) { //a little messy but it should work
    if (this->map.search(key) != NULL) {
        return this->map.search(key)->getValuePtr();
    }
    return NULL;
}

int& MapLinkedList::operator[](string key) {
    return *(this->getPtr(key));
}

//HashTable
HashMap::HashMap(){
    assocSet = new LinkHash(1000);
}

void HashMap::set(string key, int value){
    if(assocSet->contains(key)){
        assocSet->removeKey(key);
        assocSet->addKey(key,value);
        return;
    }
    assocSet->addKey(key,value);
}

void HashMap::remove(string key){
    assocSet->removeKey(key);
}

int HashMap::get(string key){
    return assocSet->getValue(key, -1);
}

int& HashMap::operator[](string key){
    return *(assocSet->getValueByRef(key));
}