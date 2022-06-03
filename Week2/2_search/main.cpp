// binary search

#include <iostream>
using namespace std;

int binarySearchI(int [], int, int);
int binarySearchR(int [], int, int);
int binarySearchR(int [], int, int, int);
void printResult(int, int);

int main() {
    const int SIZE = 8;
    int arr[] = {-2, 0, 1, 3, 4, 7, 11, 15};
    int key, index;

    // get key
    cout << "Enter a search key: ";
    cin >> key;

    // binary search
    cout << "Binary search (iterative): ";
    index = binarySearchI(arr, SIZE, key);
    printResult(key, index);

    cout << "Binary search (recursive): ";
    index = binarySearchR(arr, SIZE, key);
    printResult(key, index);
    return 0;
}

int binarySearchI(int arr[], int size, int key) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchR(int arr[], int size, int key) {
    return binarySearchR(arr, 0, size - 1, key);
}

int binarySearchR(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearchR(arr, mid + 1, right, key);
        else
            return binarySearchR(arr, left, mid - 1, key);
    }
    return -1;
}

/**
 * Alternate version with base case at the top
 *
int binarySearchR(int arr[], int left, int right, int key) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchR(arr, mid + 1, right, key);
    else
        return binarySearchR(arr, left, mid - 1, key);
}
*/

void printResult(int key, int index) {
    if (index == -1)
        cout << key << " was not found\n";
    else
        cout << key << " was found at index " << index << endl;
}