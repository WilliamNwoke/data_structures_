// Sheila Oh
// File: main.cpp
// Date: 9/15/20

#include "DynamicList.h"
#include <iostream>
using namespace std;

template <typename T>
void printListState(const DynamicList<T> &);

template <typename T>
void printIndex(T, int);

int main() {
    const int SIZE = 5;

    // create a list of integers
    cout << "*** Testing dynamic integer list ***\n";
    DynamicList<int> numbers(SIZE);

    // print List state
    printListState(numbers);

    // populate array
    for (int x = 1; x <= SIZE; x++)
        numbers.add(x);

    // print List state again
    printListState(numbers);

    // find value 5 and 20
    int val = 5;
    int index = numbers.contains(val);
    printIndex(val, index);
    index = numbers.contains(SIZE);
    printIndex(SIZE, index);

    DynamicList<int> numbers2(numbers); // calls the copy constructor
    DynamicList<int> numbers3(SIZE);    // calls constructor
    numbers3 = numbers;        // calls the overloaded = operator

    // now, create a list of doubles
    cout << "\n*** Testing dynamic string list ***\n";
    DynamicList<string> names(SIZE);
    string name;

    // print List state
    printListState(names);

    // populate array
    for (int x = 1; x <= SIZE; x++) {
        cout << "Enter a name: ";
        getline(cin, name);
        names.add(name);
    }

    // print List state
    printListState(names);

    // find value "Sheila"
    name = "Sheila";
    index = names.contains(name);
    printIndex(name, index);

    // the destructor is automatically called when the DynamicList object
    // goes out of range; you cannot and should not call the destructor!

    return 0;
}

template <typename T>
void printListState(const DynamicList<T> &obj) {
    if (obj.empty())
        cout << "List is empty";
    else
        cout << "List is not empty";
    cout << " and has a size of " << obj.size() << endl;
}

template <typename T>
void printIndex(T val, int index) {
    if (index == -1)
        cout << val << " not found!" << endl;
    else
        cout << val << " found at index " << index << endl;
}
