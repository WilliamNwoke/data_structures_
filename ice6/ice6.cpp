//
// Created by Uchenna on 4/21/22.
//

#include <iostream>
#include <string>
#include "DynamicList.h"

void printListState(const DynamicList<int> &);
void printIndex(int, int);


int main() {
    const int SIZE = 5;
    DynamicList<int> numbers (SIZE);

    printListState(numbers);

    for (int i =0; i <= SIZE; i++)
        numbers.add(i);

    printListState(numbers);

    int val = 5;
    int index = numbers.get(val);
    printIndex(val, index);
    index = numbers.get(SIZE);
    printIndex(SIZE, index);

    DynamicList<int> numbers2(numbers);
    DynamicList<int> numbers3(SIZE);
    numbers3 = numbers;

    numbers = numbers;

    return 0;
}


void printListState(const DynamicList<int> &obj) {
    if (obj.empty())
        cout << "List is empty";
    else
        cout << "List is not empty";
    cout << " and has a size of " << obj.size() << endl;
}

void printIndex(int val, int index) {
    if (index == -1)
        cout << val << " not found!" << endl;
    else
        cout << val << " found at index " << index << endl;
}
