// Sheila Oh
// File: LinkedList.h
// Date: 9/22/20

#include "LinkedList.h"
#include <sstream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node * curr;
    while (head != nullptr) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

void LinkedList::appendNode(int d) {
    Node * curr;	// helper Node that allows me to traverse the list
    Node * newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;

    if (head == nullptr)
        head = newNode;
    else {
        curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode;
    }
}

void LinkedList::insertNode(int d) {
    Node * curr;
    Node * prev;
    Node * newNode = new Node;
    newNode->data = d;

    if (head == nullptr) {
        head = newNode;
        newNode->next = nullptr;
    } else {
        prev = nullptr;
        curr = head;
        while (curr != nullptr && curr->data < d) {
            prev = curr;
            curr = curr->next;
        }
        // add to beginning of list; otherwise, end or between nodes
        if (prev == nullptr) {
            head = newNode;
            newNode->next = curr;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void LinkedList::deleteNode(int d) {
    Node * curr;
    Node * prev;
    if (head != nullptr) {
        if (head->data == d) {
            curr = head;
            head = head->next;
            delete curr;
        } else {
            curr = head;
            while (curr != nullptr && curr->data != d) {
                prev = curr;
                curr = curr->next;
            }
            // only delete if d is in the list
            if (curr != nullptr) {
                prev->next = curr->next;
                delete curr;
            }
        }
    }
}

string LinkedList::to_string() const {
    stringstream ss;
    Node * curr = head;
    while (curr != nullptr) {
        ss << curr->data << " ";
        curr = curr->next;
    }
    ss << "\n";
    return ss.str();
}