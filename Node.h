#pragma once
#include <string>
using namespace std;

class Node {
	public:
		Node();
	    Node(string, int);
	    void setKey(string);
		string getKey();
		void setValue(int);
		int getValue();
		int* getValuePtr();
		void setPrev(Node*);
		Node* getPrev();
		void setNext(Node*);
		Node* getNext();
	private:
		string key;
		int value;
		Node* prev;
		Node* next;
};