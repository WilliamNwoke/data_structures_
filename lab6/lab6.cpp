
// Created by Uchenna on 5/28/22.
//
#include <string>
#include <iostream>
#include <random>
#include "HashTable.h"


using namespace std;

/**
 * unique random number generator
 * @return
 */
unsigned int randomNum();
/**
 * welcome message
 */
void welcome();
/**
 * goodbye message
 */
void goodbye();
/**
 * Output formatting function for hash.contains
 */
void testContains(HashTable &, int);

/**
 * output formatting function for hash.get
 */
void testGet(HashTable &,int);
/**
 * output formatting function for hash.put
 */
void testPut(HashTable &, int, int);

int main(){
    welcome();

    std::cout <<"Creating a new HashTable with capacity 4093 and inserting \n"
                "4083 random key-value pairs with unique keys.. done."<< endl;

    int capacity = 4093;
    HashTable hash(capacity);
    for (int i =0; i< capacity-10; i++){
        int key = randomNum();
        int value  = key * 2;
        hash.put(key, value);
    }

    cout << "\nHash table size is : " << hash.size() << endl;
    cout << endl;

    std::cout << "Inserting 10 additional key-values..";
    // TODO: create function to help with the output message
    testPut(hash, 1179, 120);
    testPut(hash, 9702, 121);
    testPut(hash, 7183, 122);
    testPut(hash, 50184, 123);
    testPut(hash, 4235, 124);
    testPut(hash, 644, 125);
    testPut(hash, 77, 126);
    testPut(hash, 3077,127);
    testPut(hash, 23477, 128);
    testPut(hash, 90777,129);

    cout << endl;

    // Issues with contains method where it returns 0's and 1's in clion instead
    // of true or false
    std::cout << "Testing contains.."<< std::endl;
    testContains(hash, 50184);
    testContains(hash, 77);
    testContains(hash, 0);
    testContains(hash, -1);

    cout << endl;

    std::cout << "Testing get.."<< std::endl;
    testGet(hash, 50184);
    testGet(hash, 77);
    testGet(hash, 0);
    testGet(hash, -1);


    goodbye();
}

void goodbye(){
        std::cout << "\nThanks for using the HashTable testing program. Goodbye.";
}

void welcome(){
    std::cout << "Welcome to the HashTable testing program.\n";
}

unsigned int randomNum(){
    // Using C++ 11 randomness
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type>
            distribution(0,7);
    return distribution(rng);
}

void testContains(HashTable &hash, int key){
    std::cout<< "contains(" << key << " ): " << hash.contains(key) << std::endl;
}

void testGet(HashTable &hash, int key){
    cout<< "get(" << key << " ): ";
    cout << hash.get(key) << endl;
}


void testPut(HashTable &hash, int key, int value){
    std::cout << "(" << key << " , " << value << ")" << endl;
    hash.put(key, value);
}