#include <string>
#include "Array.h"
#include "LinkedList.h"
#include "Hash.h"
using namespace std;

class SetArray {
    public:
        //~SetArray();
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();
    private:
        Array set;
};

class SetLinkedList {
    public:
        //~SetLinkedList();
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();
    private:
        LinkedList set;
};

class HashSet{
    public:
        HashSet();
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();
    private:
        LinkHash *set;
};