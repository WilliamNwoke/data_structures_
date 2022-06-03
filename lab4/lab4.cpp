//
// Created by Uchenna on 4/30/22.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * Testing function for the getLastNegative method
 * @tparam ArrType a numeric type for the array passed in
 * @tparam T a numeric type for the list elements
 * @param arr      an array of numeric elements
 * @param llObj       a LinkedList object
 * @param n        the number of elements in arr
 */
template <class ArrType, class T>
void testLastNegative(ArrType *arr, LinkedList<T> &llObj, int n) {
    cout << "Linked list values: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << "  ";
        llObj.appendNode(arr[i]);
    }
    cout << endl;

    cout << "Last negative number: ";
    cout << llObj.getLastNegative() << endl;
}

int main() {
    LinkedList<int> llObj;
    LinkedList<double> llObj2;

    int intArr[] = {3, -2, 5, 12, -2, -4, 5};
    double dblArr[] = {-3.2, 2.14, -5.7, -12.01, -2.99, 4.6, 5.2};

    testLastNegative(intArr, llObj, 7);
    testLastNegative(dblArr, llObj2, 7);

    return 0;
}