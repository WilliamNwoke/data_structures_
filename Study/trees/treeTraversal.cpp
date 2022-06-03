//
// Created by Uchenna on 4/27/22.
//
//Helper func
#include <iostream>

using namespace std;
struct Node {
    int data;
    Node * next;
};


void Inset (int x) {
    Node *head = new Node;
    inset(head, x);
}

// Recursion func
void inset (Node * ptr, int x) {
    if(ptr->next == nullptr)
    {
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        ptr->next = newNode;
    } else {
        inset(ptr->next, x);
    }
}



//Insert in a tree
struct TNode {
    int data;
    Node *left;
    Node *right;
};

void insert ();
if

int main() {
     return 0;
    }