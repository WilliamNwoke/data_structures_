// Sheila Oh
// File: IntList.cpp
// Date: 9/15/20

#include "IntList.h"
#include <sstream>

IntList::IntList(int cap) {
    list = new int[cap];
    capacity = cap;
    numElements = 0;
}

IntList::~IntList() {
    delete [] list;
}

IntList::IntList(const IntList &obj) {
    // assign numElements and capacity (from obj)
    capacity = obj.capacity;
    numElements = obj.numElements;

    // allocate memory based on new capacity
    list = new int[capacity];

    // copy over elements (from obj)
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}

IntList& IntList::operator=(const IntList &obj) {
    if (this != &obj) { // checks if the list memory is the same as the list passed in.
        // deallocate memory // list1 = list2
        delete [] list; // object to delete is list1, the calling operator

        // assign numElements and capacity (from obj)
        capacity = obj.capacity;
        numElements = obj.numElements;

        // allocate memory based on new capacity
        list = new int[capacity];

        // copy over elements (from obj)
        for (int i = 0; i < numElements; i++)
            list[i] = obj.list[i];
    }
    return *this;
}

void IntList::add(int el) {
    if (numElements >= capacity)
        resize();
    list[numElements] = el;
    numElements++;
}

int IntList::get(int el) const {
    for (int i = 0; i < numElements; i++) {
        if (list[i] == el)
            return i;
    }
    return -1;
}

bool IntList::empty() const {
    return numElements == 0;
}

int IntList::size() const {
    return numElements;
}

string IntList::to_string() const {
    stringstream ss;
    for (int i = 0; i < numElements; i++)
        ss << list[i] << " ";
    return ss.str();
}

void IntList::resize() {
    // update capacity
    capacity *= 2;

    // create new array based on updated capacity
    int * tempArr = new int[capacity];

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)
        tempArr[i] = list[i];

    // delete old array
    delete [] list;

    // reassign old array to new array
    list = tempArr;
}