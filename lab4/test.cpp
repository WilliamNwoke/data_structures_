//
// Created by Uchenna on 5/13/22.
//

#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include "../lab5/Sort.h"


void testTime(long sz, bool isLarge = false);
int randomm();
void myShuffle(std::vector<long> &);

using namespace std;
using namespace std::chrono;



int main(){
    testTime(40000, true);
    testTime(80000, true);
    testTime(160000, true);
    testTime(320000, true);
    testTime(640000, true);
    testTime(1280000);
    testTime(2560000);
    testTime(5120000);
    testTime(10240000);
    testTime(20480000);
    return EXIT_SUCCESS;
}

void myShuffle(vector<long> &vec){
    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle(vec.begin(), vec.end(),
            default_random_engine(seed));
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
int randomm(){
    // Using C++ 11 randomness
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type>
            distribution(0,100);
    return distribution(rng);
}
#pragma clang diagnostic pop


void testTime(long sz, bool isLarge) {
    std::vector<long> v;
    v.reserve(sz);
    for (int i =0; i < sz; i++)
        v.push_back(randomm());

    high_resolution_clock::time_point start, end;
    milliseconds ms;

    std::cout << "Sorting " << sz << " values: " << std::endl;

    // time and display quicksort
    start = high_resolution_clock::now();
    quicksort(v.begin(), v.end());
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "It took me ( ";
    cout << ms.count() /1000<< " seconds ) for QuickSort." << endl;

    myShuffle(v);
    // time and display heap sort
    start = high_resolution_clock::now();
    heapsort(v.begin(), v.end());
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "It took me ( ";
    cout << ms.count() /1000<< " seconds ) for HeapSort." << endl;

    myShuffle(v);
    // time and display merge sort
    start = high_resolution_clock::now();
    mergesort(v.begin(), v.end());
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "It took me ( ";
    cout << ms.count() /1000 << " seconds ) for MergeSort." << endl;

    myShuffle(v);
    // time and display introsort
    start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "It took me ( ";
    cout << ms.count() /1000 << " seconds ) for STL IntroSort." << endl;

    // only run insertion sort if isLarge is true
    if (isLarge) {

        myShuffle(v);
        // time and display insertion sort
        start = high_resolution_clock::now();
        insertionSort(v.begin(), v.end());
        end = high_resolution_clock::now();
        ms = duration_cast<milliseconds>(end - start);
        cout << "It took me ( ";
        cout << ms.count() /1000 << " seconds ) for Insertion Sort. " << endl;
    }

    cout << endl;

}
