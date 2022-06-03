//
// Created by Uchenna on 4/13/22.
//
// ice3.cpp
// assume n >= 1
#include <iostream>
#include <string>
using namespace std;
int sumI(int);
int sumR(int);
int sumI(int, int);
int sumR(int, int);
int findMinI(int [], int);
int findMin(int [], int, int);
int findMinR(int [], int);
int findSumI(int [], int);
int findSumR(int [], int);
int findSum(int [], int, int);

int main() {
    const int SIZE = 4;
    int arr[] = {2, 4, 1, 5};
    cout << "array contents: ";
    for (int i : arr)
        cout << i << " ";
    cout << "\narray size: " << SIZE << endl;
    cout << "\niterative tests:\n";
    cout << "sum(5) = " << sumI(5) << endl;
    cout << "sum(5, 7) = " << sumR(5, 7) << endl;
    cout << "findMinR(a, 4) = " << findMinR(arr, SIZE) << endl;
    cout << "findSum(a, 4) = " << findSumI(arr, SIZE) << endl;
    cout << "\nrecursive tests:\n";
    cout << "sum(5) = " << sumR(5) << endl;
    cout << "sum(5, 7) = " << sumR(5, 7) << endl;
    cout << "findMin(a, 4) = " << findMinR(arr, SIZE) << endl;
    cout << "findSum(a, 4) = " << findSumR(arr, SIZE) << endl;
}
int sumI(int n) {
    int sum = 1;
    for (int i = 2; i <= n; i++)
        sum += i;
    return sum;
}
int sumR(int n) {
    if (n == 1)
        return 1;

    return n + sumR(n-1);

}
int sumI(int a, int b) {
    int sum = a;
    for (int i = a + 1; i <= b; i++)
        sum += i;
    return sum;
}
int sumR(int a, int b) {
    if (a == b) {
        return b;
    } else {
        return a + sumR(a+1,b);
    }
}
int findMinI(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
int findMinR(int arr[], int n) {
    int minimum = arr[n-1];
    return findMin(arr,n-1, minimum);
}


int findMin(int arr[], int n, int mini) {
    if (n == 1) {
        return min(arr[n - 1], mini);
    }
    return min(arr[n-1], findMin(arr, n-1, mini));

}
int findSumI(int arr[], int n) {
    int sum = arr[0];
    for (int i = 1; i < n; i++)
        sum += arr[i];
    return sum;
}
int findSumR(int arr[], int n) {
    int count = 0;
    return findSum(arr, n, count);
}

int findSum(int arr[], int n, int count) {
    if (count ==  n) {
        return 0;
    }
    return arr[count] + findSum(arr, n, count+1);
    string s;

    if (s.substr(0, n2).compare(str2) == 0)
        return countSubstrig(str1.substr(1), str2) + 1;
}

