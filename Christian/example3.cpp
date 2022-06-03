//
// Created by Uchenna on 4/14/22.
//

// What does the output look like?

#include <iostream>
using namespace std;

void mystery(int);
int main() {
    mystery(25);
    return 0;
}

void mystery(int n)
 {
     if (n <= 1)
        cout << " ";
     else
     {
        cout << n % 2 << " ";
        mystery(n / 2);
        cout << n << " ";
    }
 }