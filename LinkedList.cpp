#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    this->head = NULL;
    this->numItems = 0;
}

LinkedList::~LinkedList() {
	if (this->head == NULL) {
		return;
	}
	Node* currNode = this->head;
	Node* nextNode;
	while (currNode != NULL) {
		nextNode = currNode->getNext();
		delete currNode;
		currNode = nextNode;
	}
}

void LinkedList::insert(string key, int value) {
	Node* new_node = new Node(key, value);
	if (this->head == NULL) {
		this->head = new_node;
	} else {
		Node* temp = this->head;
		while (temp->getNext() != NULL) {
			temp = temp->getNext();
		}
		new_node->setPrev(temp);
		temp->setNext(new_node);
	}
	this->numItems++;
}

void LinkedList::remove(string key) {
	if (this->head == NULL) {
		return;
	}
	Node* temp = this->search(key);
	if (temp == NULL) {
		return;
	} else if (temp == this->head) {
	    if (this->numItems == 1) {
	        this->head = NULL;
	    } else {
	        this->head = this->head->getNext();
	        this->head->setPrev(NULL);
	    }
	} else {
		temp->getPrev()->setNext(temp->getNext());
		if (temp->getNext() != NULL) {
			temp->getNext()->setPrev(temp->getPrev());
		}
	}
	delete temp;
	this->numItems--;
}

Node* LinkedList::search(string key) {
	if (this->head == NULL) {
		return NULL;
	}
	Node* temp = this->head;
	while (temp != NULL) {
		if (temp->getKey() == key) {
			return temp;
		}
		temp = temp->getNext();
	}
	return NULL;
}

Node* LinkedList::searchAll(string key) {
	int count = this->count(key);
	if (count == 0) {
		return NULL;
	}
	Node* nodes = new Node[count];
	Node* temp = this->head;
	int i = 0;
	while (temp != NULL) {
		if (temp->getKey() == key) {
			nodes[i] = *temp;
			i++;
		}
		temp = temp->getNext();
	}
	return nodes;
}

int LinkedList::getNumItems() {
	return this->numItems;
}

int LinkedList::count(string key) {
	if (this->head == NULL) {
		return 0;
	}
	int count = 0;
	Node* temp = this->head;
	while (temp != NULL) {
		if (temp->getKey() == key) {
			count++;
		}
		temp = temp->getNext();
	}
	return count; 
}

string LinkedList::getKey(int elemNum) {
	Node* temp = this->head;
	for (int i = 0; i < elemNum; i++) {
		temp = temp->getNext();
	}
	
	return temp->getKey();
}