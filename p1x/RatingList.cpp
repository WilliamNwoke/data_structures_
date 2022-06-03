//
// Created by Uchenna on 4/20/22.
//
#include <climits>
#include "RatingList.h"

RatingList::RatingList(int initialBookCapacity) {
    memberCapacity = INITIAL_MEMBER_CAPACITY;
    bookCapacity = initialBookCapacity;

    // Allocate new memory for Array
    ratingArray = new int *[memberCapacity];
    for (int i =0; i < memberCapacity; ++i)
        ratingArray[i] = new int[bookCapacity];

    // Initiate ratings for all member to 0
    for (int i =0; i < memberCapacity; ++i)
        for (int j =0; j < bookCapacity; ++j)
            ratingArray[i][j] = 0;
}

/// Destructor, called by compiler
RatingList::~RatingList() {
    clear();
}


RatingList::RatingList(const RatingList &other) {
    // Copy elements
    memberCapacity = other.memberCapacity;
    bookCapacity = other.bookCapacity;

    // Allocate memory for copied array
    ratingArray = new int *[memberCapacity];
    for (int i =0; i < memberCapacity; ++i)
        ratingArray[i] = new int[bookCapacity];

    // copy the values from the 2D array
    for (int i =0; i < memberCapacity; ++i)
        for (int j =0; j < bookCapacity; ++j)
            ratingArray[i][j] = other.ratingArray[i][j];


}


RatingList &RatingList::operator=(const RatingList &rightSide) {
    if (this != &rightSide) {

        // Deallocate memory
        clear();

        // get capacity from the rightSide and assign it
        this->bookCapacity = rightSide.bookCapacity;
        this->memberCapacity = rightSide.memberCapacity;

        // Allocate new memory
        this->ratingArray = new int *[memberCapacity];
        for (int i = 0; i < memberCapacity; ++i)
            ratingArray[i] = new int[bookCapacity];

        // Copy over elements from rightSide
        for (int i = 0; i < memberCapacity; ++i)
            for (int j = 0; j < bookCapacity; ++j)
                ratingArray[i][j] = rightSide.ratingArray[i][j];
    }

    return *this;
}

void RatingList::addRating(int memberID, int bookID, int rating) {
    // Checks if the memberID and bookID are greater than the current arrays
    // Resizes to accommodate ratings
    if (memberID >= memberCapacity)
        resizeRow();
    if(bookID >= bookCapacity)
        resizeColumn();
    ratingArray[memberID][bookID] = rating;
}

int RatingList::getRating(int memberID, int bookID) {
    // Check if memberID and bookID exist
    if (memberID < memberCapacity && bookID < bookCapacity)
        return ratingArray[memberID][bookID];

    //returns 0 if books does not exist
    return 0;
}

int RatingList::similar(int memberID) {
    int maxProd = INT_MIN;
    // Keep track of most similar member
    int mostSimilar = 0;
    // Keep track of current product
    int currProd = 0;

    // Loop through the ratings array
    for (int i = 0; i < memberCapacity; ++i) {

        // Skip comparing member against self
        if (i == memberID) continue;

        for (int j = 0; j < bookCapacity; ++j) {

            // Calculate dot product of two member's ratings
            currProd += ratingArray[memberID][j] * ratingArray[i][j];

        }

        // Check if current dot product is the highest yet found
        if (currProd > maxProd) {
            maxProd = currProd;
            mostSimilar = i;
        }
        currProd = 0;
    }

    // Return the most similar member's id
    return mostSimilar;
}

void RatingList::resizeColumn() {
    // Store the new capacity temporarily
    int newBookCapacity = bookCapacity * 2;

    // Create temp 2D array with new capacity
    auto **temp = new int *[memberCapacity];
    for (int i = 0; i < memberCapacity; ++i) {
        temp[i] = new int[newBookCapacity];
    }

    // Copy old values to temp
    for (int i = 0; i < memberCapacity; ++i) {
        for (int j = 0; j < bookCapacity; ++j) {
            temp[i][j] = ratingArray[i][j];
        }
    }

    // Initialize all new book ratings to 0
    int newValuesStart = newBookCapacity - bookCapacity;
    for (int i = 0; i < memberCapacity; ++i) {
        for (int j = newValuesStart; j < newBookCapacity; ++j) {
            temp[i][j] = 0;
        }
    }

    // Deallocate old ratingArray
    clear();

    // Update actual capacity
    bookCapacity = newBookCapacity;
    // Reassign old array to new
    ratingArray = temp;
}

void RatingList::resizeRow() {
    // Store the new capacity temporarily
    int newMemberCapacity = memberCapacity * 2;

    // Create temp 2D array with new capacity
    auto **temp = new int *[newMemberCapacity];
    for (int i = 0; i < newMemberCapacity; ++i) {
        temp[i] = new int[bookCapacity];
    }

    // Copy old values to temp
    for (int i = 0; i < memberCapacity; ++i) {
        for (int j = 0; j < bookCapacity; ++j) {
            temp[i][j] = ratingArray[i][j];
        }
    }

    // Initialize all new member ratings to 0
    int newValuesStart = newMemberCapacity - memberCapacity;
    for (int i = newValuesStart; i < newMemberCapacity; ++i) {
        for (int j = 0; j < bookCapacity; ++j) {
            temp[i][j] = 0;
        }
    }

    // Deallocate old ratingArray
    clear();

    // Update actual capacity
    memberCapacity = newMemberCapacity;
    // Reassign old array to new
    ratingArray = temp;
}

void RatingList::clear() {
    // Cleanup ratingArray memory
    for (int i = 0; i < memberCapacity; ++i) {
        delete[] ratingArray[i];
    }
    delete[] ratingArray;
}

