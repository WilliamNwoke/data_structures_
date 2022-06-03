//
// Created by Uchenna on 4/8/22.
//
#include <iostream>

using namespace std;

int main(){
    int size =6;
    int *myArray = new int[size];

    for (int i=0; i<size; i++) {
        myArray[i] = i*2+1;
    }

    for (int i=0; i<size; i++) {
        // cout << myArray[i] << "  ";
        cout << *(myArray + i) << "  ";
    }

    delete [] myArray;

    return 0;
}