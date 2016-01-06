#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Set.h"
#include "MultiSet.h"
#include "Map.h"
#include "MultiMap.h"
#include "TimeTesting.h"

using namespace std;

string str1 = "str1";
string str2 = "str2";
string str3 = "str3";
string str4 = "str4";
string str5 = "str5";

int val1 = 11;
int val2 = 12;
int val3 = 13;
int val4 = 14;
int val5 = 15;

// Set Tests

void testSetArray() {
    cout << "Testing SetArray" << endl << endl;
    
    SetArray set;
    
    cout << "Is empty? " << set.is_empty() << endl;
    cout << "Inserting " << str1 << endl;
    set.insert(str1);
    cout << "Is empty? " << set.is_empty() << endl;
    cout << "Inserting " << str2 << endl;
    set.insert(str2);
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Removing " << str2 << endl;
    set.remove(str2);
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    
    cout << "Inserting " << str2 << endl;
    set.insert(str2);
    cout << "Inserting " << str3 << endl;
    set.insert(str3);
    
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Is " << str3 << " in? " << set.is_in(str3) << endl;
    cout << "Is " << str4 << " in? " << set.is_in(str4) << endl;
    
    cout << "Removing " << str2 << endl;
    set.remove(str2);
    cout << "Removing " << str3 << endl;
    set.remove(str3);
    
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Is " << str3 << " in? " << set.is_in(str3) << endl;
}

void testSetLinkedList() {
    cout << "Testing SetLinkedList" << endl << endl;
    
    SetLinkedList set;
    
    cout << "Is empty? " << set.is_empty() << endl;
    cout << "Inserting " << str1 << endl;
    set.insert(str1);
    cout << "Is empty? " << set.is_empty() << endl;
    cout << "Inserting " << str2 << endl;
    set.insert(str2);
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Removing " << str2 << endl;
    set.remove(str2);
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    
    cout << "Inserting " << str2 << endl;
    set.insert(str2);
    cout << "Inserting " << str3 << endl;
    set.insert(str3);
    
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Is " << str3 << " in? " << set.is_in(str3) << endl;
    cout << "Is " << str4 << " in? " << set.is_in(str4) << endl;
    
    cout << "Removing " << str2 << endl;
    set.remove(str2);
    cout << "Removing " << str3 << endl;
    set.remove(str3);
    
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Is " << str3 << " in? " << set.is_in(str3) << endl;
}

void testHashSet(){
    cout << "Testing HashSet: " << endl << endl;
    
    HashSet set;
    
    cout << "Is empty? " << set.is_empty() << endl;
    cout << "Inserting " << str1 << endl;
    set.insert(str1);
    cout << "Is empty? " << set.is_empty() << endl;
    cout << "Inserting " << str2 << endl;
    set.insert(str2);
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Removing " << str2 << endl;
    set.remove(str2);
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    
    cout << "Inserting " << str2 << endl;
    set.insert(str2);
    cout << "Inserting " << str3 << endl;
    set.insert(str3);
    
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Is " << str3 << " in? " << set.is_in(str3) << endl;
    cout << "Is " << str4 << " in? " << set.is_in(str4) << endl;
    
    cout << "Removing " << str2 << endl;
    set.remove(str2);
    cout << "Removing " << str3 << endl;
    set.remove(str3);
    
    cout << "Is " << str2 << " in? " << set.is_in(str2) << endl;
    cout << "Is " << str3 << " in? " << set.is_in(str3) << endl;
}

// MultiSet Tests

void testMultiSetArray() {
    cout << "Testing MultiSetArray: " << endl << endl;
    
    MultiSetArray mset;
    cout << "Is empty? " << mset.is_empty() << endl;
    cout << "Inserting " << str1 << endl;
    mset.insert(str1);
    cout << "Is empty? " << mset.is_empty() << endl;
    cout << "Inserting " << str2 << " 3 times" << endl;
    mset.insert(str2);
    mset.insert(str2);
    mset.insert(str2);
    cout << "Counting " << str2 << ": " << mset.count(str2) << endl;
    
    cout << "Drawing 3 random:" << endl;
    cout << mset.draw_random() << endl;
    cout << mset.draw_random() << endl;
    cout << mset.draw_random() << endl;
    
    cout << "Remove one " << str2 << endl;
    mset.removeOne(str2);
    cout << "Counting str2: " << mset.count(str2) << endl;
    cout << "Remove all " << str2 << endl;
    mset.removeAll(str2);
    cout << "Counting str2: " << mset.count(str2) << endl;
}

void testMultiSetLinkedList() {
    cout << "Testing MultiSetLinkedList: " << endl << endl;
    
    MultiSetLinkedList mset;
    cout << "Is empty? " << mset.is_empty() << endl;
    cout << "Inserting " << str1 << endl;
    mset.insert(str1);
    cout << "Is empty? " << mset.is_empty() << endl;
    cout << "Inserting " << str2 << " 3 times" << endl;
    mset.insert(str2);
    mset.insert(str2);
    mset.insert(str2);
    cout << "Counting " << str2 << ": " << mset.count(str2) << endl;
    
    cout << "Drawing 3 random:" << endl;
    cout << mset.draw_random() << endl;
    cout << mset.draw_random() << endl;
    cout << mset.draw_random() << endl;
    
    cout << "Remove one " << str2 << endl;
    mset.removeOne(str2);
    cout << "Counting str2: " << mset.count(str2) << endl;
    cout << "Remove all " << str2 << endl;
    mset.removeAll(str2);
    cout << "Counting str2: " << mset.count(str2) << endl;
}

void testHashMultiSet() {
    cout << "Testing HashMultiSet: " << endl << endl;
    
    HashMultiSet mset;
    
    cout << "Is empty? " << mset.is_empty() << endl;
    cout << "Inserting " << str1 << endl;
    mset.insert(str1);
    cout << "Is empty? " << mset.is_empty() << endl;
    cout << "Inserting " << str2 << " 3 times" << endl;
    mset.insert(str2);
    mset.insert(str2);
    mset.insert(str2);
    cout << "Counting " << str2 << ": " << mset.count(str2) << endl;
    
    cout << "Drawing 3 random:" << endl;
    cout << mset.draw_random() << endl;
    cout << mset.draw_random() << endl;
    cout << mset.draw_random() << endl;
    
    cout << "Remove one " << str2 << endl;
    mset.removeOne(str2);
    cout << "Counting str2: " << mset.count(str2) << endl;
    cout << "Remove all " << str2 << endl;
    mset.removeAll(str2);
    cout << "Counting str2: " << mset.count(str2) << endl;
}

// Map Tests

void testMapArray() {
    cout << "Testing MapArray: " << endl << endl;
    
    MapArray map;
    cout << "Setting " << val1 << " to key " << str1 << endl;
    map.set(str1, val1);
    cout << "Setting " << val2 << " to key " << str2 << endl;
    map.set(str2, val2);
    cout << "Getting value of key " << str1 << ":" << endl;
    cout << map.get(str1) << endl;
    cout << "Getting value of key " << str2 << ":" << endl;
    cout << map.get(str2) << endl;
    cout << "Removing " << str2 << endl;
    map.remove(str2);
    cout << "Getting value of key " << str2 << ":" << endl;
    int x = map.get(str2);
    if (x == false || x < 0) {
        cout << "Key not found";
    } else {
        cout << x;
    }
    cout << endl;
    cout << "Getting value of key " << str1 << " using brackets [] :" << endl;
    cout << map[str1] << endl;
    cout << "Changing value of key " << str1 << " to " << val5 <<  " using brackets []" << endl;
    map[str1] = val5;
    cout << "Getting value of key " << str1 << " using brackets [] :" << endl;
    cout << map[str1] << endl;
}

void testMapLinkedList() {
    cout << "Testing MapLinkedList: " << endl << endl;
    
    MapLinkedList map;
    cout << "Setting " << val1 << " to key " << str1 << endl;
    map.set(str1, val1);
    cout << "Setting " << val2 << " to key " << str2 << endl;
    map.set(str2, val2);
    cout << "Getting value of key " << str1 << ":" << endl;
    cout << map.get(str1) << endl;
    cout << "Getting value of key " << str2 << ":" << endl;
    cout << map.get(str2) << endl;
    cout << "Removing " << str2 << endl;
    map.remove(str2);
    cout << "Getting value of key " << str2 << ":" << endl;
    int x = map.get(str2);
    if (x == false || x < 0) {
        cout << "Key not found";
    } else {
        cout << x;
    }
    cout << endl;
    cout << "Getting value of key " << str1 << " using brackets [] :" << endl;
    cout << map[str1] << endl;
    cout << "Changing value of key " << str1 << " to " << val5 <<  " using brackets []" << endl;
    map[str1] = val5;
    cout << "Getting value of key " << str1 << " using brackets [] :" << endl;
    cout << map[str1] << endl;
}

void testHashMap() {
    cout << "Testing HashMap: " << endl << endl;
    
    HashMap map;
    cout << "Setting " << val1 << " to key " << str1 << endl;
    map.set(str1, val1);
    cout << "Setting " << val2 << " to key " << str2 << endl;
    map.set(str2, val2);
    cout << "Getting value of key " << str1 << ":" << endl;
    cout << map.get(str1) << endl;
    cout << "Getting value of key " << str2 << ":" << endl;
    cout << map.get(str2) << endl;
    cout << "Removing " << str2 << endl;
    map.remove(str2);
    cout << "Getting value of key " << str2 << ":" << endl;
    int x = map.get(str2);
    if (x == false || x < 0) {
        cout << "Key not found";
    } else {
        cout << x;
    }
    cout << endl;
    cout << "Getting value of key " << str1 << " using brackets [] :" << endl;
    cout << map[str1] << endl;
    cout << "Changing value of key " << str1 << " to " << val5 <<  " using brackets []" << endl;
    map[str1] = val5;
    cout << "Getting value of key " << str1 << " using brackets [] :" << endl;
    cout << map[str1] << endl;
}

// MultiMap Tests

void testMultiMapArray() {
    cout << "Testing MultiMapArray: " << endl << endl;
    
    MultiMapArray mmap;
    
    cout << "Setting " << val1 << " to key " << str1 << endl;
    mmap.set(str1, val1);
    cout << "Counting values of key " << str1 << ": " << mmap.count(str1) << endl;
    cout << "Setting " << val1 << " to key " << str2 << endl;
    mmap.set(str2, val1);
    cout << "Setting " << val2 << " to key " << str2 << endl;
    mmap.set(str2, val2);
    int count = mmap.count(str2);
    cout << "Counting values of key " << str2 << ": " << count << endl;
    int* values = mmap.getAll(str2);
    cout << "Values of key " << str2 << ": ";
    for (int i = 0; i < count; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    cout << "Removing all values of key " << str2 << endl;
    mmap.removeAll(str2);
    cout << "Counting values of key " << str2 << ": " << mmap.count(str2) << endl;
}

void testMultiMapLinkedList() {
    cout << "Testing MultiMapLinkedList: " << endl << endl;
    
    MultiMapLinkedList mmap;
    
    cout << "Setting " << val1 << " to key " << str1 << endl;
    mmap.set(str1, val1);
    cout << "Counting values of key " << str1 << ": " << mmap.count(str1) << endl;
    cout << "Setting " << val1 << " to key " << str2 << endl;
    mmap.set(str2, val1);
    cout << "Setting " << val2 << " to key " << str2 << endl;
    mmap.set(str2, val2);
    int count = mmap.count(str2);
    cout << "Counting values of key " << str2 << ": " << count << endl;
    int* values = mmap.getAll(str2);
    cout << "Values of key " << str2 << ": ";
    for (int i = 0; i < count; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    cout << "Removing all values of key " << str2 << endl;
    mmap.removeAll(str2);
    cout << "Counting values of key " << str2 << ": " << mmap.count(str2) << endl;
}

void testHashMultiMap() {
    cout << "Testing HashMultiMap: " << endl << endl;
    
    HashMultiMap mmap;
    
    cout << "Setting " << val1 << " to key " << str1 << endl;
    mmap.set(str1, val1);
    cout << "Counting values of key " << str1 << ": " << mmap.count(str1) << endl;
    cout << "Setting " << val1 << " to key " << str2 << endl;
    mmap.set(str2, val1);
    cout << "Setting " << val2 << " to key " << str2 << endl;
    mmap.set(str2, val2);
    int count = mmap.count(str2);
    cout << "Counting values of key " << str2 << ": " << count << endl;
    int* values = mmap.getAll(str2);
    cout << "Values of key " << str2 << ": ";
    for (int i = 0; i < count; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    cout << "Removing all values of key " << str2 << endl;
    mmap.removeAll(str2);
    cout << "Counting values of key " << str2 << ": " << mmap.count(str2) << endl;
}

int main() {
    //this needs to be seeded here for draw_random to be "random"
    srand (time(NULL));
    //I know there is a seed in Hash.cpp too, ideally we only need to do this
    //once per program execution ever
    
    testSetArray();
    cout << endl << endl;
    testSetLinkedList();
    cout << endl << endl;
    testHashSet();
    cout << endl << endl;
    testMultiSetArray();
    cout << endl << endl;
    testMultiSetLinkedList();
    cout << endl << endl;
    testHashMultiSet();
    cout << endl << endl;
    testMapArray();
    cout << endl << endl;
    testMapLinkedList();
    cout << endl << endl;
    testHashMap();
    cout << endl << endl;
    testMultiMapArray();
    cout << endl << endl;
    testMultiMapLinkedList();
    cout << endl << endl;
    testHashMultiMap();
    cout << endl << endl;
    
    printTimeTests();
    
    return 0;
}