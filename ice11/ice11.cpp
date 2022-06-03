// This program demonstrates the FeetInches class's overloaded
// relational operators.
#include <iostream>
#include "FeetInches.h"
using namespace std;

int main() {
    int feet, inches;  // To hold input for feet and inches

    // Create two FeetInches objects. The default arguments
    // for the constructor will be used.
    FeetInches first, second, sumFI, diffFI, incFI;

    // Get a distance from the user.
    cout << "Enter a distance in feet and inches: ";
    cin >> feet >> inches;

    // Store the distance in first.
    first.setFeet(feet);
    first.setInches(inches);

    // Get another distance.
    cout << "Enter another distance in feet and inches: ";
    cin >> feet >> inches;

    // Store the distance in second.
    second.setFeet(feet);
    second.setInches(inches);

    // Print object info.
    cout << "Printing object info...\n";
    cout << "first: " << first.to_string();
    cout << "second: " << second.to_string();

    // Compare the two objects.
    cout << "\nComparing objects (==, >, or <): ";
    if (first == second)
        cout << "first is equal to second.\n";
    if (first > second)
        cout << "first is greater than second.\n";
    if (first < second)
        cout << "first is less than second.\n";

    // Add two objects.
    sumFI = first + second;
    cout << "Adding objects (first + second): " << sumFI.to_string();

    // Subtract two objects.
    diffFI = first - second;
    cout << "Subtracting objects (first - second): " << diffFI.to_string();

    // Prefix increment
    cout << "\nPrefix increment of first object (incFI = ++first):\n";
    incFI = ++first;
    cout << "first: " << first.to_string();
    cout << "incremented: " << incFI.to_string();

    // Postfix increment
    cout << "\nPostfix increment of first object (incFI = first++):\n";
    incFI = first++;
    cout << "first: " << first.to_string();
    cout << "incremented: " << incFI.to_string();

    return 0;
}
