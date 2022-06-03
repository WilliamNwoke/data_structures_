#include <iostream>
#include "Date.h"

/**
 * The main function creates a pointer object date,
 * we try our date header file, so we can get the date and season!
 * @return 0, then the program runs with no errors
 */
int main() {
    Date *date1 = new Date(6,20,2015);

    cout << date1->getDate() + "\n";
    cout << date1->getSeason() + "\n";

    return 0;
}
