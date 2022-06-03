// overloaded functions (input, swap, print)
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void input(T &, T &, string);

template <typename T>
void swapVars(T &, T &);

template <typename T>
void print(T, T, string);

void something();

int main() {
    double x, y;
    int num1, num2;
    string name = "double";

    // get user input & print
    input(x, y, name);
    print(x, y, name);

    // test swap of doubles - pass by ref
    cout << "swap doubles by ref\n";
    swapVars(x, y);
    print(x, y, name);

    // separate output
    cout << endl;

    // get user input & print
    name = "integer";
    input(num1, num2, name);
    print(num1, num2, name);

    // test swap of strings - pass by ref
    cout << "swap integers by ref\n";
    swapVars(num1, num2);
    print(num1, num2, name);
}

template <typename T>
void input(T &x, T &y, string name) {
    cout << "Enter two " << name << "s separated by space: ";
    cin >> x >> y;
}

template <typename T>
void swapVars(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
void print(T x, T y, string name) {
    cout << "first " << name << " : " << x
         << ", second " << name << " : " << y << endl;
}

void something() {
    cout << "hello";
}
