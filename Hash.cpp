#include "Hash.h"
#include <string>
using namespace std;
LinkHash::~LinkHash(){
    delete[] this->myList;
    delete[] this->keysAdded;
}
LinkHash::LinkHash(unsigned long size){
    SIZE = size;
    myList = new Node[SIZE];
    srand(time(NULL));
    seed = (unsigned short)(abs(rand()));
    
   keysAdded = new string[SIZE];
   keysAddedSize = SIZE;
   numKeys = 0;
}

LinkHash::LinkHash(unsigned long size, unsigned int seed){
    SIZE = size;
    myList = new Node[SIZE];
    this->seed = seed;
    
    keysAdded = new string[SIZE];
    keysAddedSize = SIZE;
    numKeys = 0;
}
//Statistically the best one we could find
unsigned int LinkHash::FNVHash(const std::string& str){
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash *= fnv_prime;
      hash ^= str[i];
   }
   hash ^= seed;
   return hash;
}

int LinkHash::getValue(const string &key, int notFound){
    if(contains(key)){
        int index = hash(key);
        if(!myList[index].getKey().empty()){
            Node *curNode = &myList[index];
            while(!curNode->getKey().empty()){
                if(curNode->getKey().compare(key) == 0)
                    return curNode->getValue();
                curNode = curNode->getNext();
            }
        }
    }
    return notFound;
}

int* LinkHash::getValueByRef(const string &key){
    if(contains(key)){
        int index = hash(key);
        if(!myList[index].getKey().empty()){
            Node *curNode = &myList[index];
            while(!curNode->getKey().empty()){
                if(curNode->getKey().compare(key) == 0)
                    return curNode->getValuePtr();
                curNode = curNode->getNext();
            }
        }
    }
    return NULL;
}

int* LinkHash::getValues(const string &key){
    int *retArray = NULL;
    if(contains(key)){
        int size = countElems(key);
        int index = hash(key);
        int curIndex = 0;
        retArray = new int[size];
        Node* curNode = &myList[index];
        while(!curNode->getKey().empty()){
            if(curNode->getKey().compare(key) == 0){
                retArray[curIndex] = curNode->getValue();
                curIndex++;
            }
            curNode = curNode->getNext();
        }
        return retArray;
    }
    return retArray;
}

bool LinkHash::isEmpty(){
    for(int y = 0; y < SIZE; y++){
        if(!myList[y].getKey().empty())
            return false;
        else{
            continue;
        }
    }
    return true;
    
}

int LinkHash::countElems(){
    int elems = 0;
    for(int y = 0; y < SIZE; y++){
        if(!myList[y].getKey().empty()){
            Node* curNode = &myList[y];
            while(!curNode->getKey().empty()){
                elems++;
                curNode = curNode->getNext();
            }
        }
        else{
            continue;
        }
    }
    return elems;
}

int LinkHash::countElems(const string &key, int value, bool valueMatters){
    int elems = 0;
    for(int y = 0; y < SIZE; y++){
        if(!myList[y].getKey().empty()){
            Node* curNode = &myList[y];
            while(!curNode->getKey().empty()){
                if(valueMatters){
                    if((curNode->getKey().compare(key) == 0) && (curNode->getValue() == value))
                        elems++;
                }
                else{
                    if(curNode->getKey().compare(key) == 0){
                        elems++;
                    }
                }
                curNode = curNode->getNext();
            }
        }
        else{
            continue;
        }
    }
    return elems;
}

int LinkHash::countElems(const string &key, int value){
    return countElems(key, value, true);
}

int LinkHash::countElems(const string &key){
    return countElems(key, false, false);
}

int LinkHash::hash(const string &key){
    unsigned int complicated = FNVHash(key);
    return complicated % SIZE;
}

void LinkHash::addKey(const string &key){
    addKey(key,false, false);
}

void LinkHash::addKey(const string &key, int value){
    addKey(key, value, true);
}

void LinkHash::addKey(const string &key, int value, bool valueMatters){
    int index = hash(key);
    if(!myList[index].getKey().empty()){
        Node* curNode = &myList[index];
        Node* prevNode = curNode;
        while(!curNode->getKey().empty()){
            prevNode = curNode;
            curNode = curNode->getNext();
        }
        curNode->setKey(key);
        if(valueMatters){
            curNode->setValue(value);
        }
        curNode->setNext(new Node());
        curNode->setPrev(prevNode);
        
    }
    else{
        myList[index].setKey(key);
        myList[index].setValue(value);
        myList[index].setNext(new Node());
    }
    
    //resize keys list if getting too small
    if (numKeys >= keysAddedSize - 1) {
        string* resizedArr = new string[keysAddedSize + SIZE];
        for (int i = 0; i < keysAddedSize; i++) {
            resizedArr[i] = keysAdded[i];
        }
        
        delete[] keysAdded;
        keysAdded = resizedArr;
        keysAddedSize += SIZE;
    }
    
    *(keysAdded + numKeys) = key; //if 0 put at 0th element
    numKeys++;
}

void LinkHash::removeKey(const string &key, int value, bool valueMatters){
    int index = hash(key);
    if(!myList[index].getKey().empty()){
        Node* curNode = &myList[index];
        
        Node* head = curNode;
        Node* sucNode = curNode;
        Node* prevNode = curNode;
        
        while(!curNode->getKey().empty()){
            if(valueMatters){
                if( (curNode->getKey().compare(key) == 0) && (curNode->getValue() == value)){
                    break;
                }
            }
            else{
                if(curNode->getKey().compare(key) == 0)
                    break;
            }
            prevNode = curNode;
            curNode = curNode->getNext();
            sucNode = curNode->getNext();
        }
        
        if(curNode->getKey().empty()){
            return;
        }
        else if(curNode == head){
            sucNode = curNode->getNext();
            myList[index] = *sucNode;
        }
        else{
            prevNode->setNext(sucNode);
            sucNode->setPrev(prevNode);
        }
        if(sucNode->getKey().empty()){
                sucNode->setNext(new Node());
        }
    }
    
    //remove from keys list
    for (int i = 0; i <= numKeys; i++) {
        if (*(keysAdded + i) == key) {
            for (int j = i; j <= numKeys; j++) {
                *(keysAdded + j) = *(keysAdded + (j+1));
            }
            
            break;
        }
    }
    
   numKeys--;
}

void LinkHash::removeKey(const string &key){
    removeKey(key,false, false);
}

void LinkHash::removeKey(const string &key, int value){
    removeKey(key,value, true);
}

bool LinkHash::contains(const string &key, int value, bool valueMatters){
    int index = hash(key);
    if(!myList[index].getKey().empty()){
        Node *curNode = &myList[index];
        while(!curNode->getKey().empty()){
            if(valueMatters){
                if((curNode->getKey().compare(key) == 0) && (curNode->getValue() == value)){
                    return true;
                }
            }
            else{
                if(curNode->getKey().compare(key) == 0)
                    return true;
            }
            curNode = curNode->getNext();
        }
    }
    return false;
}

bool LinkHash::contains(const string &key, int value){
    return contains(key,value,true);
}

bool LinkHash::contains(const string &key){
    return contains(key,false,false);
}

void LinkHash::printCollisions(const string &key){
    int index = hash(key);
    if(!myList[index].getKey().empty()){
        Node *curNode = &myList[index];
        while(!curNode->getKey().empty()){
            cout << curNode->getKey() << ": " << curNode->getValue() << "| ";
            curNode = curNode->getNext();
        }
        cout << endl;
    }
}


int LinkHash::getNumKeys() {
    return this->numKeys;
}

string LinkHash::getKey(int i) {
    return *(this->keysAdded + i);
}