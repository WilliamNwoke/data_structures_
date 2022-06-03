// Sheila Oh
// File: IntList.h
// Date: 9/15/20

#ifndef WEEK1_INTLIST_H
#define WEEK1_INTLIST_H

#include <string>
using namespace std;

class IntList {
public:
    IntList(int);           // Constructor
    ~IntList();             // Destructor
    IntList(const IntList &);               // Copy constructor
    IntList& operator=(const IntList &);    // Overloaded = operator
    void add(int);          // add element to array
    int get(int) const;     // find element in array; return index
                            // where found or -1 if not found
    bool empty() const;     // determines if list is empty or not
    int size() const;       // number of elements in array
    string to_string() const;   // returns string representation of
                                // of the IntList class
private:
    int * list;             // Pointer to the array
    int capacity;           // capacity of array
    int numElements;        // Number of elements
    void resize();          // resize array (when full)
};

#endif //WEEK1_INTLIST_H
