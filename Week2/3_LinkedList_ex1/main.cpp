// Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

void appendNode(Node *&, int);
void insertNode(Node *&, int);
void deleteNode(Node *&, int);
void deleteList(Node *&);
void printList(Node *);


int main() {
    Node * head = nullptr;

    // add to list (can call append instead, but LL will be in different order)
    cout << "Adding 3, 5, 2, 7, -4, 6, 0...\n";
    insertNode(head, 3);
    insertNode(head, 5);
    insertNode(head, 2);
    insertNode(head, 7);
    insertNode(head, -4);
    insertNode(head, 6);
    insertNode(head, 0);

    // print list
    cout << "Linked list contents: ";
    printList(head);

    // delete 7 and 2
    cout << "Deleting 7 and 2...\n";
    deleteNode(head, 7);
    deleteNode(head, 2);

    // print list
    cout << "Linked list contents: ";
    printList(head);

    // deallocate memory
    deleteList(head);
}

void appendNode(Node *&h, int d) {
    Node * curr;	// helper Node that allows me to traverse the list
    Node * newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;

    if (h == nullptr)
        h = newNode;
    else {
        curr = h;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode;
    }
}

void insertNode(Node *&h, int d) {
    Node * curr;
    Node * prev;
    Node * newNode = new Node;
    newNode->data = d;

    if (h == nullptr) {
        h = newNode;
        newNode->next = nullptr;
    } else {
        prev = nullptr;
        curr = h;
        while (curr != nullptr && curr->data < d) {
            prev = curr;
            curr = curr->next;
        }
        // add to beginning of list; otherwise, end or between nodes
        if (prev == nullptr) {
            h = newNode;
            newNode->next = curr;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void deleteNode(Node *&h, int d) {
    Node * curr;
    Node * prev;
    if (h != nullptr) {
        if (h->data == d) {
            curr = h;
            h = h->next;
            delete curr;
        } else {
            curr = h;
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

void deleteList(Node *&h) {
    Node * curr;
    while (h != nullptr) {
        curr = h;
        h = h->next;
        delete curr;
    }
}

void printList(Node * h) {
	Node * curr = h;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
    cout << endl;
}