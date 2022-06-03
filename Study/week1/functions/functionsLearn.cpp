//
// Created by Uchenna on 4/4/22.
//
#include <iostream>
#include <string>

using namespace std;

void swapNums(int &x,int &y){
    int z = x;
    x = y;
    y = z;
}

int main(){
    // Passing values by reference
    int firstNum = 10;
    int secondNum = 20;

    cout << "Before Swap: " << "\n";
    cout << firstNum << secondNum << "\n";

    // Calling the swap function
    swapNums(firstNum,secondNum);

    cout << "After Swap: " << "\n";
    cout << firstNum << secondNum << "\n";

    int *ptr = &firstNum;

    cout << "Pointers" << "\n";
    // returns the address of the reference variable
    cout << ptr << "\n";
    // returns the value of the reference variable
    cout << *ptr << "\n";
    // returns the address of the pointer
    cout << &ptr << "\n";



    return 0;
}