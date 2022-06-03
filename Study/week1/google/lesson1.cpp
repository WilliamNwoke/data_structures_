// hello.cpp: Maggie Johnson
// Description: a program that prints the immortal saying "hello world"

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    /** Example 1
    // set up cout to right-align
    cout <<  setiosflags(ios::left);
    for (int j = 0; j <6; j++) {
        for (int i = 0; i < 4; i++) {
            // prints hello world to screen 4 times
            cout << setw(1) << "Hello World! ";
        }
        // creates a new line
        cout << endl;
    }
     */

    /* Example 2: get some input */
    int input_var = 0;
    // Enter the do while loop and stay there until either
    // a non-numeric is entered, or -1 is entered. Note that
    // cin will accept any integer, 4, 40, 400, etc.
    do {
        cout << "Enter a number (-1 = quit): ";
        // The following line accepts input from the keyboard into
        // variable input_var.
        // cin returns false if an input operation fails, that is, if
        // something other than an int (the type of input_var) is entered.
        if (!(cin >> input_var)) {
            cout << "You entered a non-numeric. Exiting..." << endl;
            break;
            // exit the do while loop
        }
        if (input_var != -1) {
            cout << "You entered " << input_var << endl;
        }
    } while (input_var != -1);
    cout << "All done." << endl;
    return 0;
}