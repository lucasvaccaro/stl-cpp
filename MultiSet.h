#include <string>
#include "Array.h"
#include "LinkedList.h"
#include "Hash.h"
using namespace std;

class MultiSetArray {
    public:
        void insert(string key);
        bool is_in(string key);
        int count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_empty();
        string draw_random();
    private:
        Array set;
};

class MultiSetLinkedList {
    public:
        void insert(string key);
        bool is_in(string key);
        int count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_empty();
        string draw_random();
    private:
        LinkedList set;
};

class HashMultiSet{
    public:
        HashMultiSet();
        void insert(string key);
        bool is_in(string key);
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_empty();
        string draw_random();
    private:
        LinkHash *set;
};