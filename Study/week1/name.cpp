//
// Created by Uchenna on 4/4/22.
//
#include <iostream>
#include <string>

using namespace std;

int main(){
    // Getting string with spaces
    string fullName;
    cout << "Enter your full name: ";
    getline(cin, fullName);
    cout << "\nFull name is " + fullName;

    // Trick to getline() after using regular cin
    string input1, input2;
    cout << "\nEnter string: ";
    cin >> input1;
    cout <<"\n" + input1 <<"\nEnter second string: ";
    cin.ignore();
    getline(cin, input2);
    cout << "\n" + input2;
    return 0;
}
