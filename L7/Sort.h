//
// Created by Kevin Lundeen on 10/29/20.
// For Seattle University, CPSC 5005, Session 8.
//

#pragma once

#include <algorithm>

/**
 * Collection of classic sorting algorithms:
 * - Naive O(n^2):
 *      o Bubble Sort
 *      o Selection Sort
 *      o Insertion Sort
 * - Fast O(nlogn):
 *      o Heap Sort
 *      o Merge Sort
 *      o Quicksort
 *
 * @tparam T element type to be sorted. Must support operator> and operator<.
 */
template<typename T>
struct Sort {
    /**
     * Classic O(n^2) bubble sort.
     * Sort is stable.
     * @param array to sort
     * @param size  of array
     * @post        array[lo]..array[size-1] sorted ascending order
     * @post        stable: for any two equal values in array, their
     *              relative order in the array is preserved after the sort
     */
    static void bubble(T *array, int size) {
        for (int i = size - 1; i > 0; i--)
            for (int j = 0; j < i; j++)
                if (array[j] > array[j + 1])
                    std::swap(array[j], array[j + 1]);
    }

    /**
     * Classic O(n^2) selection sort.
     * Not stable as written (but could be made so by changing > to >= in test
     * for changing k).
     * @param array to sort
     * @param size  of array
     * @post        array[lo]..array[size-1] sorted ascending order
     */
    static void selection(T *array, int size) {
        for (int i = size - 1; i > 0; i--) {
            int k = 0;
            for (int j = 1; j <= i; j++)
                if (array[j] > array[k])
                    k = j;
            std::swap(array[k], array[i]);
        }
    }

    /**
     * Classic O(n^2) insertion sort.
     * Sort is stable.
     * @param array to sort
     * @param size  of array
     * @post        array[lo]..array[size-1] sorted ascending order
     * @post        stable: for any two equal values in array, their
     *              relative order in the array is preserved after the sort
     */
    static void insertion(T *array, int size) {
        for (int i = 1; i <= size - 1; i++)
            for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--)
                std::swap(array[j], array[j + 1]);
    }

    /**
     * Classic O(n log n) heap sort.
     * Sort is not stable.
     * @param array to sort
     * @param size  of array
     * @post        array[lo]..array[size-1] sorted ascending order
     */
    static void heap(T *array, int size) {
        heapify(array, size);
        for (int heapsize = size; heapsize > 1; heapsize--)
            dequeue(array, heapsize);
    }

    /**
     * Classic O(n log n) merge sort.
     * Space is O(n).
     * Sort is stable and suitable for external sorts.
     * @param array to sort
     * @param size  of array
     * @post        array[lo]..array[size-1] sorted ascending order
     * @post        stable: for any two equal values in array, their
     *              relative order in the array is preserved after the sort
     */
    static void merge(T *array, int size) {
        mergesort(array, 0, size - 1);
    }

    /**
     * Classic O(n log n) quicksort.
     * Sort is unstable.
     * Worst case (unusual) is O(n^2).
     * @param array to sort
     * @param size  of array
     * @post        array[lo]..array[size-1] sorted ascending order
     */
    static void quick(T *array, int size) {
        quicksort(array, 0, size - 1);
    }

    /**
     * C++ STL O(n log n) introsort (modified quicksort).
     * Sort is unstable.
     * [Space is O(n) since we're copying into a std::vector.]
     * Worst case is O(n log n) by using heapsort eventually.
     * @param array to sort
     * @param size  of array
     * @post        array[lo]..array[size-1] sorted ascending order
     */
    static void introspective(T *array, int size) {
        // copy into a std::vector (since we haven't implemented iterators)
        std::vector<T> v(array, array + size);
        // use STL unstable sort (introspection sort)
        std::sort(v.begin(), v.end());
        // copy back
        for (int i = 0; i < size; i++)
            array[i] = v[i];
    }

private:
/*
 * =======================================================================
 * quicksort helpers:
 * - quicksort is recursive sorting routine
 * - partition picks a pivot and moves elements to the right or left of it
 * - median3 does pivot conditioning
 * =======================================================================
 */
    /**
     * Recursive part of quicksort sorts a given section of the array
     * recursively.
     * @param a   array to work on
     * @param lo  minimum index of section to sort, e.g., 0
     * @param hi  maximum index of section to sort, e.g., size - 1
     * @post      array[lo]..array[hi] sorted ascending order
     */
    static void quicksort(int *a, int lo, int hi) {
        if (hi - lo > 10) {
            int pivotPosition = partition(a, lo, hi);
            quicksort(a, lo, pivotPosition - 1);
            quicksort(a, pivotPosition + 1, hi);
        } else {
            insertion(a + lo, (hi - lo) + 1);  // a + lo is &a[lo]
        }
    }

    /**
     * Partition the array around a chosen pivot.
     * Hoare partition scheme.
     * @param a   array to work on
     * @param lo  minimum index of section to partition, e.g., 0
     * @param hi  maximum index of section to partition, e.g., size - 1
     * @return    index of chosen pivot
     * @post      array[lo]..array[pivot-1] all <= array[pivot] and
     *            array[pivot+1]..array[hi] all >= array[pivot]
     */
    static int partition(int *a, int lo, int hi) {
        median3(a, lo, hi);
        int i = lo, j = hi - 1;
        int pivot = a[j]; // as left there by median3
        while (i < j) {
            while (a[++i] < pivot); // move i forward to first "wrong" value
            while (pivot < a[--j]); // move j backward to first "wrong" value
            if (i < j)
                std::swap(a[i], a[j]); // swap the two "wrong" values
        }
        // finally, move the pivot back in place from where it was stashed by
        // median3
        std::swap(a[i], a[hi - 1]);
        return i;
    }

    /**
     * Look at first, middle, and last element in the given portion of the
     * array. Then sort them such that they are in order and choose the
     * middle one as the pivot. But before returning stash the pivot out of
     * the way at a[hi-1].
     * @param a   array to work on
     * @param lo  minimum index of section to partition, e.g., 0
     * @param hi  maximum index of section to partition, e.g., size - 1
     * @post      array[lo] <= array[hi-1] <= array[hi]
     */
    static void median3(int *a, int lo, int hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] < a[lo])
            std::swap(a[lo], a[mid]);
        if (a[hi] < a[lo])
            std::swap(a[lo], a[hi]);
        if (a[hi] < a[mid])
            std::swap(a[mid], a[hi]);
        // temporarily stash pivot at position hi-1
        std::swap(a[mid], a[hi - 1]);
    }

/*
 * =======================================================================
 * merge sort helpers:
 * - mergesort is recursive sorting routine
 * - mergeTwoSorted merges two sorted sublists
 * =======================================================================
 */
    /**
     * Recursive part of merge sort sorts a given section of the array
     * recursively.
     * @param a   array to work on
     * @param lo  minimum index of section to sort, e.g., 0
     * @param hi  maximum index of section to sort, e.g., size - 1
     * @post      array[lo]..array[hi] sorted ascending order
     */
    static void mergesort(int *array, int lo, int hi) {
        // base case is if segment of array is length one, i.e. hi - lo == 0
        if (hi - lo > 0) {
            int mid = (lo + hi) / 2;
            mergesort(array, lo, mid);
            mergesort(array, mid + 1, hi);
            mergeTwoSorted(array, lo, hi);  // linear
        }
    }

    /**
     * Merge two contiguous parts of the array that are already sorted.
     * Uses temporary storage equivalent the to size of a[lo]..a[hi].
     * @param a   array to work on
     * @param lo  minimum index of section to sort, e.g., 0
     * @param hi  maximum index of section to sort, e.g., size - 1
     * @pre       array[lo]..array[(lo+hi)/2] is sorted ascending and
     *            array[1+(lo+hi)/2]..array[hi] is sorted ascending
     * @post      array[lo]..array[hi] sorted ascending order
     */
    static void mergeTwoSorted(int *a, int lo, int hi) {
        int mid = (lo + hi) / 2;

        // set up temporary scratch space
        int scratchLength = hi - lo + 1;
        int *scratch = new int[scratchLength];
        int k = 0; // index int scratch space

        // copy from each as appropriate to scratch
        int i = lo;       // index into left sorted half
        int j = mid + 1;  // index into right sorted half
        while (i <= mid && j <= hi)
            if (a[i] < a[j])
                scratch[k++] = a[i++];
            else
                scratch[k++] = a[j++];

        // pick up the remains of whichever one has elements left in it
        // (one of the two loops will always do nothing)
        while (i <= mid)
            scratch[k++] = a[i++];
        while (j <= hi)
            scratch[k++] = a[j++];

        // copy back scratch contents to original array
        for (k = 0; k < scratchLength; k++)
            a[lo + k] = scratch[k];

        delete[] scratch;
    }

/*
 * =======================================================================
 * heap sort helpers:
 * - dequeue from maxheap (and place result at end of array)
 * - heapify a maxheap
 * - percolateDown fixes a maxheap after replacement of an element
 * - parent, left, right - tree navigation calculations
 * - hasLeft, hasRight - limit checking against size of the maxheap
 * =======================================================================
 */
    /**
     * Remove the maximum element from the heap and place it directly after
     * the realm of the smaller heap. (Thus putting it into the right spot in
     * ascending order of the section of the array we are sorting.)
     * @param a         to work on
     * @param heapsize  current size of the maxheap
     * @post            a[heapsize-1] is >= to everything in a[0]..a[heapsize-2]
     */
    static void dequeue(T *a, int heapsize) {
        // trick to get dequeue to put max item in correct spot
        std::swap(a[0], a[heapsize - 1]);
        // then repair the invariants as usual
        percolateDown(a, 0, heapsize - 1);
    }

    /**
     * Turn an arbitrary order of elements
     * @param array     to work on
     * @param heapsize  current size of the maxheap
     * @post array[0]..array[heapsize-1] is a maxheap
     */
    static void heapify(T *array, int heapsize) {
        for (int index = heapsize / 2; index >= 0; index--)
            percolateDown(array, index, heapsize);
    }

    /**
     * Repairs possible violation of heap invariant where a too-small value
     * is put into the tree by swapping it down to suitable level.
     * @param array     to work on
     * @param index     location of possible violation of heap invariant
     * @param heapsize  current size of the maxheap
     * @post array[0]..array[heapsize-1] is a maxheap
     */
    static void percolateDown(T *array, int index, int heapsize) {
        if (hasLeft(index, heapsize)) {
            int child = left(index);
            if (hasRight(index, heapsize)) {
                int r = right(index);
                if (array[r] > array[child])
                    child = r;
            }
            if (array[child] > array[index]) {
                std::swap(array[index], array[child]);
                percolateDown(array, child, heapsize);
            }
        }
    }

    /**
     * Get index in array-implementation of a complete binary tree of the
     * parent of the given location. (Root is at 0.)
     * @param childIndex of element of which to get the parent
     * @return           parent index
     */
    static int parent(int childIndex) {
        return (childIndex - 1) / 2;
    }

    /**
     * Get index in array-implementation of a complete binary tree of the
     * left child of the given location. (Root is at 0.)
     * @param childIndex of element of which to get the left child
     * @return           left child index
     */
    static int left(int parentIndex) {
        return parentIndex * 2 + 1;
    }

    /**
     * Get index in array-implementation of a complete binary tree of the
     * right child of the given location. (Root is at 0.)
     * @param childIndex of element of which to get the right child
     * @return           right child index
     */
    static int right(int parentIndex) {
        return left(parentIndex) + 1;
    }

    /**
     * Check if the left child of the given position is still in the heap.
     * @param parentIndex of element of which to check
     * @param heapsize    number of elements currently in the heap
     */
    static bool hasLeft(int parentIndex, int heapsize) {
        return left(parentIndex) < heapsize;
    }

    /**
     * Check if the right child of the given position is still in the heap.
     * @param parentIndex of element of which to check
     * @param heapsize    number of elements currently in the heap
     */
    static bool hasRight(int parentIndex, int heapsize) {
        return right(parentIndex) < heapsize;
    }
};
