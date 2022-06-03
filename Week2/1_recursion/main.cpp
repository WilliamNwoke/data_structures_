// recursion examples

#include <iostream>
using namespace std;

int expI(int, int);
int expR(int, int);
int factI(int);
int factR(int);
int fibI(int);
int fibR(int);

int main() {
	cout << "2^5 - iterative: " << expI(2, 5) << endl;
    cout << "2^5 - recursive: " << expR(2, 5) << endl << endl;

    cout << "5! - iterative: " << factI(5) << endl;
    cout << "5! - recursive: " << factR(5) << endl << endl;

    cout << "fib(10) - iterative: " << fibI(10) << endl;
    cout << "fib(10) - recursive: " << fibR(10) << endl << endl;
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

	return 0;
}

int expI(int x, int n) {
    int result = 1;
    for (int i = 1; i < n; i++)
        result *= x;
    return result;
}

int expR(int x, int n) {
    if (n == 1)
        return x;
    return expR(x, n - 1) * x;
}

int factI(int n) {
    int result = 1;
    for (int i = 1; i < n; i++)
        result *= i;
    return result;
}

int factR(int n) {
    if (n == 0 || n == 1)
        return 1;
    return factR(n - 1) * n;
}

int fibI(int n){
    int a = 0, b = 1, c = 1;
    for (int k = 2; k <= n; k++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int fibR(int n) {
    if (n <= 1)
        return n;
    return fibR(n - 1) + fibR(n - 2);
}