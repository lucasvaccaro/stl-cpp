#include <string>
#include "Array.h"
#include "LinkedList.h"
#include "Hash.h"
using namespace std;

class MultiMapArray {
    public:
        void set(string, int);
        void removeAll(string);
        int count(string);
        int* getAll(string);
    private:
        Array map;
};

class MultiMapLinkedList {
    public:
        void set(string, int);
        void removeAll(string);
        int count(string);
        int* getAll(string);
    private:
        LinkedList map;
};

class HashMultiMap{
    public:
        HashMultiMap();
        void set(string, int);
        void removeAll(string);
        int count(string);
        int* getAll(string);
    private:
        LinkHash *assocSet;
};