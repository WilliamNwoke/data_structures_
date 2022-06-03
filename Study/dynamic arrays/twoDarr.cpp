//
// Created by Uchenna on 4/8/22.
//
#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cout << "rows, cols" ;
    cin >> rows >> cols;

    // pointer to array of pointers
    int** table = new int*[rows];

    //inner arrays' pointer to values
    for (int i=0; i<rows; i++) {
        table[i] = new int[cols];
    }

    // deallocating the memory of inner array
    for (int i=0; i<rows; i++){
        delete[] table[i];
    }

    // deallocating the memory of pointer for pointer array
    delete[] table;

    // removing the memory address of the pointer
    table = NULL;


    return 0;
}