//
// Created by Uchenna on 5/13/22.
//

#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include "Sort.h"
#include <ctime>


void testTime(long sz, bool isLarge = false);
uint randomNum();
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

    return 0;
}

void myShuffle(vector<long> &vec){
    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle(vec.begin(), vec.end(),
                        default_random_engine(seed));
}

uint randomNum(){
    // Using C++ 11 randomness
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type>
            distribution(0,9999999);
    return distribution(rng);
}


void testTime(long sz, bool isLarge) {
    clock_t t;
    std::vector<long> v;
    v.reserve(sz);
    for (int i =0; i < sz; i++)
        v.push_back(randomNum());

    std::cout << "Sorting " << sz << " values: " << std::endl;

    myShuffle(v);
    t = clock();
    mergesort(v.begin(), v.end());
    t = clock() - t;
    printf("It took me %lu clocks ( %f seconds ) for MergeSort.\n",t, ((float)t)/CLOCKS_PER_SEC);

    myShuffle(v);
    t = clock();
    heapsort(v.begin(), v.end());
    t = clock() - t;
    printf("It took me %lu clocks ( %f seconds ) for HeapSort.\n",t, ((float)t)/CLOCKS_PER_SEC);

    myShuffle(v);
    t = clock();
    quicksort(v.begin(), v.end());
    t = clock() - t;
    printf("It took me %lu clocks ( %f seconds ) for QuickSort.\n",t, ((float)t)/CLOCKS_PER_SEC);


    myShuffle(v);
    t = clock();
    sort(v.begin(), v.end());
    t = clock() - t;
    printf("It took me %lu clocks ( %f seconds ) for STL's IntroSort.\n",t, ((float)t)/CLOCKS_PER_SEC);


    // only run insertion sort if isLarge is true
    if (isLarge) {
        myShuffle(v);
        t = clock();
        heapsort(v.begin(), v.end());
        t = clock() - t;
        printf("It took me %lu clocks ( %f seconds ) for Insertion Sort.\n",t, ((float)t)/CLOCKS_PER_SEC);
    }

    cout << endl;

}
