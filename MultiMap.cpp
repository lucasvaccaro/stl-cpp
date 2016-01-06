#include <string>
#include "MultiMap.h"
using namespace std;

// ARRAY

void MultiMapArray::set(string key, int value) {
    this->map.insert(key, value);
}

void MultiMapArray::removeAll(string key) {
    this->map.remove(key);
}

int MultiMapArray::count(string key) {
    return this->map.count(key);
}

int* MultiMapArray::getAll(string key) {
    int* values = this->map.getValues(key);
    if (values != false) {
        return values;
    }
    return NULL;
}

// LINKED LIST

void MultiMapLinkedList::set(string key, int value) {
    this->map.insert(key, value);
}

void MultiMapLinkedList::removeAll(string key) {
    int count = this->count(key);
    for (int i = 0; i < count; i++) {
        this->map.remove(key);
    }
}

int MultiMapLinkedList::count(string key) {
    return this->map.count(key);
}

int* MultiMapLinkedList::getAll(string key) {
    int count = this->map.count(key);
    if (count > 0) {
        Node* nodes = this->map.searchAll(key);
        int* values = new int[count];
        for (int i = 0; i < count; i++) {
            values[i] = nodes[i].getValue();
        }
        return values;
    }
    return NULL;
}

//HashTable
HashMultiMap::HashMultiMap(){
    assocSet = new LinkHash(1000);
}

void HashMultiMap::set(string key, int value){
    assocSet->addKey(key, value);
}

void HashMultiMap::removeAll(string key){
    while(assocSet->contains(key)){
        assocSet->removeKey(key);
    }
}

int HashMultiMap::count(string key){
    return assocSet->countElems(key);
}

int* HashMultiMap::getAll(string key){
    return assocSet->getValues(key);
}