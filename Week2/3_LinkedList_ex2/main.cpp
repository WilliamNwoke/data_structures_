// Linked List

#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;

    // add to list (can call append instead, but LL will be in different order)
    cout << "Adding 3, 5, 2, 7, -4, 6, 0...\n";
    list.insertNode(3);
    list.insertNode(5);
    list.insertNode(2);
    list.insertNode(7);
    list.insertNode(-4);
    list.insertNode(6);
    list.insertNode(0);

    // print list
    cout << "Linked list contents: " << list.to_string();

    // delete 7 and 2
    cout << "Deleting 7 and 2...\n";
    list.deleteNode(7);
    list.deleteNode(2);

    // print list
    cout << "Linked list contents: " << list.to_string();
}