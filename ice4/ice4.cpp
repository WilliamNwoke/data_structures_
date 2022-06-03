//
// Created by Uchenna on 4/14/22.
//
#include <iostream>
int binarySearchR(int[], int, int);
int binarySearch(int arr[], int lo, int hi, int key);


int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearchR(arr,n,  x);
    (result == -1)
    ? std::cout << "Element is not present in array"
    : std::cout << "Element is present at index " << result;
    return 0;
}

int binarySearchR(int arr[], int size, int x ){
    int lo = 0;
    int hi = size -1;
    return binarySearch(arr, lo, hi, x);
}



int binarySearch(int *arr, int lo, int hi, int key) {
    if (hi >=1){
        int mid = lo + (hi-1) /2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, lo,mid -1 , key);

        return binarySearch(arr, mid+1 , hi, key);
    }
    return -1;
}
