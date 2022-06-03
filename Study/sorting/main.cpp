//
// Created by Uchenna on 5/24/22.
//

#include "main.h"
#include <iostream>
#include <algorithm>

void insertionSort(int array[], int len){
    for (int i = 1; i < len; i++) {
        int temp = array[i];
        int j;
        for (j = i; j >0; j--){
            array[j] = array[j-1];
            if (temp > array[j-1]) break;
        }
        array[j] = temp;
    }
}

void mergeSort(int array[], int p, int r){
    if (p >r){
        return;
    }
    int q = (p +r)/2;
    mergeSort(array,p,q );
    mergeSort(array, q+1, r);
//    std::inplace_merge(array, p, q, r);
}