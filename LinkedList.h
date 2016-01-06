#pragma once
#include <string>
#include "Node.h"
using namespace std;

class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		void insert(string, int);
		void remove(string);
		Node* search(string);
		Node* searchAll(string);
		int getNumItems();
		int count(string);
		string getKey(int);
	private:
		Node* head;
		int numItems;
};