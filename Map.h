#include <string>
#include "Array.h"
#include "LinkedList.h"
#include "Hash.h"
using namespace std;

class MapArray {
    public:
        void set(string, int);
        void remove(string);
        int get(string);
        int& operator[](string);
    private:
        Array map;
};

class MapLinkedList {
    public:
        void set(string, int);
        void remove(string);
        int get(string);
        int* getPtr(string); //this is a little messy but it should work
        int& operator[](string);
    private:
        LinkedList map;
};

class HashMap{
    public:
        HashMap();
        void set(string key, int);
        void remove(string);
        int get(string);
        int& operator[](string);
    private:
        LinkHash *assocSet;
};