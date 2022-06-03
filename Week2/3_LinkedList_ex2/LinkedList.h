// Sheila Oh
// File: LinkedList.h
// Date: 9/22/20

#ifndef C5910_CODE_LINKEDLIST_H
#define C5910_CODE_LINKEDLIST_H

#include <string>
using namespace std;

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void appendNode(int);
    void insertNode(int);
    void deleteNode(int);
    string to_string() const;
private:
    struct Node {
        int data;
        Node * next;
    };
    Node * head;
};


#endif //C5910_CODE_LINKEDLIST_H
