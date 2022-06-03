//
// Created by Uchenna on 4/6/22.
//

#include <iostream>
#include <string>

using namespace std;

void getName(string &name);
void displayName(string name);


int main(){
    /*
    int num1, num2;
    cout << "Enter number 1: ";
    cin >> num1;

    cout << "\nEnter number 2: ";
    cin >> num2;

    int sum = num1 + num2;
    cout << "sum is: " << sum << "\n";



    // Regular strings
    string firstName;
    string lastName;
    cout << "Enter first name and last name seperated by space: ";
    cin >> firstName;
    cin >> lastName;


    cout << "Name is: " << firstName + "" + lastName;


    // Strings with spaces
    string firstName;
    string middleAndlast;
    cout << "What is your first name";
    cin >> firstName;
    // cin.ignore to ingore the "\n" from the buffer and read the string
    cin.ignore();
    cout << "What is your middle name and last name";
    getline(cin, middleAndlast);

    cout << "Full name is " + firstName + " " +  middleAndlast;
     */
    /*
    string name = getName();
    displayName(name);
    */
    string name;

    string fullName[3];
    for (auto & i : fullName) {
        getName(i);
    }
    cout << fullName[0] + fullName[1] + fullName[2];



    return 0;
}
void getName(string &name){
    cout << "Enter a name: ";
    cin >> name;
}

void displayName(string &name){
    cout << "Full name is : " << name;
}

