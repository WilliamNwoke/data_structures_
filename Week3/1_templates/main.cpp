// overloaded functions (input, swap, print)
#include <iostream>
using namespace std;

void input(double &, double &);
void input(int &, int &);
void swap(double &, double &);
void swap(int &, int &);
void print(double, double);
void print(int, int);

int main() {
    double x, y;
    int num1, num2;

    // get user input & print
    input(x, y);
    print(x, y);

    // test swap of doubles - pass by ref
    cout << "swap doubles by ref\n";
    swap(x, y);
    print(x, y);

    // separate output
    cout << endl;

    // get user input & print
    input(num1, num2);
    print(num1, num2);

    // test swap of strings - pass by ref
    cout << "swap integers by ref\n";
    swap(num1, num2);
    print(num1, num2);
}

void input(double &x, double &y) {
    cout << "Enter two doubles separated by space: ";
    cin >> x >> y;
}

void input(int &num1, int &num2) {
    cout << "Enter two integers separated by space: ";
    cin >> num1 >> num2;
}

void swap(double &x, double &y) {
    double temp = x;
    x = y;
    y = temp;
}

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void print(double x, double y) {
    cout << "first double: " << x << ", second double: " << y << endl;
}

void print(int num1, int num2) {
    cout << "first integer: " << num1 << ", second integer: " << num2 << endl;
}
