// This is a program to test the runtimes of various
// sorting algorithms
// @author Kramer Johnson
// Course CPSC 5910-03
// 11/07/2020 (Fall Quarter 2020)

#include <iostream>
#include <chrono>
#include "RandomArray.h"
#include "Sort.h"
using namespace std;
using namespace std::chrono;

/**
 * Function to time different sorting algorithms for a given array size
 * @param n         number of elements in the random integer array
 * @param insrtFlag true if insertion sort should be tested, false otherwise
 */
void testAndTime(int n, bool insrtFlag = false) {
    // create random array of n elements
    RandomArray ra(n);

    // create timing objects
    high_resolution_clock::time_point start, end;
    milliseconds ms;

    cout << "sorting " << n << " values:" << endl;

    // time and display merge sort
    start = high_resolution_clock::now();
    Sort<int>::merge(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "merge sort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    ra.shuffle(); // reshuffle array

    // time and display heap sort
    start = high_resolution_clock::now();
    Sort<int>::heap(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "heap sort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    ra.shuffle();

    // time and display quicksort
    start = high_resolution_clock::now();
    Sort<int>::quick(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "quicksort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    ra.shuffle();

    // time and display introsort
    start = high_resolution_clock::now();
    Sort<int>::introspective(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "STL's introsort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    // only run insertion sort if insrtFlag is true
    if (insrtFlag) {

        ra.shuffle();

        // time and display insertion sort
        start = high_resolution_clock::now();
        Sort<int>::insertion(ra.array, ra.size);
        end = high_resolution_clock::now();
        ms = duration_cast<milliseconds>(end - start);
        cout << "insertion sort elapsed time: ";
        cout << ms.count() << "ms" << endl;
    }

    cout << endl;
}

/**
 * Main entry point of sorting tests.
 * @return EXIT_SUCCESS
 */
int main() {

    testAndTime(40000, true);

    testAndTime(80000, true);

    testAndTime(160000, true);

    testAndTime(320000, true);

    testAndTime(640000);

    testAndTime(1280000);

    testAndTime(2560000);

    testAndTime(5120000);

    testAndTime(10240000);

    testAndTime(20480000);


    return EXIT_SUCCESS;
}
