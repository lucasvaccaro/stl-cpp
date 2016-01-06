#include "Node.h"

Node::Node() {
    this->next = this->prev = NULL;
}

Node::Node(string key, int value) {
    this->next = this->prev = NULL;
    this->key = key;
    if (value != false) {
        this->value = value;
    }
}

void Node::setKey(string key) {
    this->key = key;
}

string Node::getKey() {
    return this->key;
}

void Node::setValue(int value) {
    this->value = value;
}

int Node::getValue() {
	return this->value;
}

int* Node::getValuePtr() {
    //returns a pointer that's used to get a reference higher up the chain
    return &(this->value);
}

void Node::setPrev(Node* node) {
    this->prev = node;
}

Node* Node::getPrev() {
    return this->prev;
}

void Node::setNext(Node* node) {
    this->next = node;
}

Node* Node::getNext() {
    return this->next;
}