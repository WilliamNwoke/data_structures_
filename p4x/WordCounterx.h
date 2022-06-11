//
// Created by Uchenna on 6/8/22.
//

#ifndef SRC_WORDCOUNTERX_H
#define SRC_WORDCOUNTERX_H
#include <string>
#include <cmath>


class WordCounterx {
public:
    // hash table is an array of linkedlist
    // Each index holds the head of a linkedlist
    WordCounterx();
    WordCounterx(int cap);
    ~WordCounterx();
    WordCounterx(const WordCounterx &other);
    WordCounterx &operator=(const WordCounterx &rhs);
    int addWord(const std::string &word);
    bool removeWord(const std::string &word);
    int getWordCount(const std::string &word) const;
    int getCapacity() const;
    double getLoadFactor() const;
    int getUniqueWordCount() const;
    int getTotalWordCount();
    bool empty() const;
private:
    static const int DEFAULT_CAP = 101;
    int uniqueWordCount;
    int totalWordCount;
    int capacity;

    struct HashEntry {
        int wordCount;
        std::string value;
        HashEntry *next;

        explicit HashEntry(std::string newVal,
                           HashEntry *newNext= nullptr) {
            wordCount = 1;
            value = newVal;
            next = newNext;
        }
    };

    HashEntry **table;

    int hashWord(const std::string &word) const;

    int hashWord(const std::string &word, int size) const;

    static bool isPrime(int n);

    static int getNextPrime(int n);
};

/**
 * Default constructor sets size to 101.
 */
WordCounterx::WordCounterx() {
    uniqueWordCount =0;
    totalWordCount = 0;
    capacity = DEFAULT_CAP;
    table = new HashEntry *[capacity];

    for (int i =0; i <capacity; i++)
        table[i] = nullptr;
}


/**
 * Destructor
 */
WordCounterx::~WordCounterx() {
    delete [] table;
}
/**
 * Constructor that takes in a size.
 * Will converrt size to next prime number after size
 *
 * @param cap preferred size of the word table
 */
WordCounterx::WordCounterx(int cap) {
    uniqueWordCount = 0;
    totalWordCount = 0;
    if(isPrime(cap))
        capacity =cap;
    else
        capacity = getNextPrime(cap);

    table = new HashEntry*[capacity];
    for (int i= 0; i <capacity; i++){
        table[i]= nullptr;
    }
}

/**
 * Copy constructor
 * @param other WorcCounter to copy
 */
WordCounterx::WordCounterx(const WordCounterx &other) {
    uniqueWordCount = other.uniqueWordCount;
    totalWordCount = other.totalWordCount;
    capacity = other.capacity;

    table = new HashEntry * [capacity];

    for (int i=0; i < capacity; i++){
        *table[i] = *other.table[i];
    }

}

/**
 * Overload Assignment operator
 * @param rhs Word Counter to copy
 * @return pointer to this WordCounterx
 */
WordCounterx &WordCounterx::operator=(const WordCounterx &rhs){
    if (this != &rhs) {
        delete[] this->table;

        this->uniqueWordCount = rhs.uniqueWordCount;
        this->totalWordCount = rhs.totalWordCount;
        this->capacity=rhs.capacity;

        this->table = new HashEntry*[capacity];

        for (int i = 0; i <capacity; i++){
            *this->table[i] = *rhs.table[i];
        }
    }
    return *this;
}

/**
 * Adds a word to WordCounterx if it does not exist.
 * If it does, increment count of that word
 * @param word
 * @return
 */
int WordCounterx::addWord(const std::string & word) {
    int result =0;
    totalWordCount++;
    if(getWordCount(word) == 0){
        int index = hashWord(word);

        if (table[index] != nullptr) {
            HashEntry* temp = table[index];
            table[index] = new HashEntry(word);
            table[index]->next = temp;
        } else {
            table[index] = new HashEntry(word);
        }
        uniqueWordCount++;
        result = table[index]->wordCount;
    }
    else {
        int index = hashWord(word);
        HashEntry* curr = table[index];
        while (curr->value != word)
            curr = curr->next;
        result = curr->wordCount+1;
        curr->wordCount++;
    }
    return result;
}

/**
 * Removes a word from word counter
 * @param word to be removed from the table
 * @return true if word is found, false otherwise
 */
bool WordCounterx::removeWord(const std::string &word) {
    if (getWordCount(word) == 0)
        return false;
    int index = hashWord(word);
    HashEntry* curr = table[index];

    if (curr->value==word) {
        totalWordCount = totalWordCount - curr->wordCount;
        table[index] = curr->next;
    }
    else {
        HashEntry * prev = curr;
        while (curr->value != word) {
            prev = curr;
            curr= curr->next;
        }
        totalWordCount = totalWordCount-curr->wordCount;
        prev->next = curr->next;
    }
    uniqueWordCount--;
    return true;
}

/**
 * get the number of occurrences of a word
 * @param word word to count
 * @return the occurrences
 */

int WordCounterx::getWordCount(const std::string &word) const {
    int result =0;
    int index = hashWord(word);
    HashEntry* curr = table[index];
    while( curr != nullptr) {
        if ( curr->value== word) {
            result = curr->wordCount;
            break;
        }
        curr = curr->next;
    }
    return result;
}

/**
 * Returns the load factor
 * @return load factor
 */
double WordCounterx::getLoadFactor() const {
    return (round(uniqueWordCount * 1000) / 1000.0) / capacity;
}

/**
 * gets unique word counts from world counter
 * @return unique word count
 */
int WordCounterx::getUniqueWordCount() const {
    return uniqueWordCount;
}

/**
 * Gets the total word count
 * @return total word count
 */
int WordCounterx::getTotalWordCount() {
    return totalWordCount;
}

/**
 * if WordCounterx is empty
 * @return
 */
bool WordCounterx::empty() const {
    return totalWordCount ==0;
}

/**
 * Hash Function
 * @param word to hash
 * @return where hash is placed
 */
int WordCounterx::hashWord(const std::string &word) const {
    std::hash<std::string> h;
    int index = h(word) % capacity;
    return index;
}
/**
 * Determines if a number is prime
 * @param n an integer
 * @return  true if n is prime, false otherwise
 */
bool WordCounterx::isPrime(int n) {
    if (n <=1)
        return false;
    if (n ==2)
        return true;

    for (int i =2; i<sqrt(n); i++){
        if (n% i == 0)
            return false;
    }
    return true;
}
/**
  * Gets the next closest prime number after n
  * @precon  n is not a prime number
  * @param n a non-prime integer
  * @return  the next prime number occuring after n
  */
int WordCounterx::getNextPrime(int n) {
    while (!isPrime(n))
        n++;

    return n;
}

/**
 * Gets the capacity of Word Counter
 * @return
 */
int WordCounterx::getCapacity() const {
    return capacity;
}

#endif //SRC_WORDCOUNTERX_H
