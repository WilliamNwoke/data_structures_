//
// Created by Uchenna on 5/28/22.
//

#ifndef SRC_HASHTABLE_H
#define SRC_HASHTABLE_H



class HashTable {
public:
    /**
     * Ctor for hash table
     */
    HashTable(int);
    /**
     * Dtor for hash table
     */
    ~HashTable();
    /**
     * Associates a value with a key in the hash table
     * @param key key that is fed to hash function
     * @param value value to be associated with key
     * @return old value of the hash table
     */
    int put(int key, int value);
    /**
     * Gets a value associated with a key
     * @param key key associated with value
     * @return value of the key
     */
    int get(int key);
    /**
     * returns a bool if the key exist in the hashTable
     * @param key key to search for
     * @return true or false || o or 1 for some reason
     */
    bool contains(int key);

    /**
     * gets the size of the hash table
     * @return
     */
    int size() const;
    /**
     * checks if the hash table is empty
     * @return
     */
    bool empty() const;
private:
    struct Bucket {
        int key;
        int value;
    };
    // struct Bucket *tableArr;
    Bucket * tableArr;
    int cap;
    int count;
    /**
     * Hash function
     * @return index for the array
     */
    int hashFunction(int, int) const;
    /**
     * returns the index for the key
     * @return index
     */
    int getIndex(int);
    // add private helper methods and attributes
    // do not use STL; use dynamic array to hold the buckets
};

HashTable::HashTable(int capacity) {
    cap = capacity ;
    count = 0;
    tableArr = new Bucket[cap];
    for (int i =0; i<cap; i++){
        tableArr[i].key = -1;
        tableArr[i].value = -1;
    }
}

HashTable::~HashTable() {
    delete [] tableArr;
}

int HashTable::put(int key, int value){
    int temp;
    int index = getIndex(key);
    temp = tableArr[index].value;
    tableArr[index].value = value;
    count++;
    return temp;
}

int HashTable::get(int key){
    int probing = 0;
    int index = hashFunction(key, probing);

    if (key < 1) {
        return -1;
    }
    if (tableArr[index].key == key)
        return tableArr[index].value;

    while ((tableArr[index].key != key)){
        if (tableArr[index].key == -1)
            break;
        probing++;
        index = hashFunction(key, probing);
    }

    return tableArr[index].value;
}

bool HashTable::contains(int key) {
    int probing = 0;
    int index = hashFunction(key, probing);
    bool res = false;

    if (key < 1) {
        return res;
    }
    while ((tableArr[index].key != key)) {
        if (tableArr[index].key == -1)
            break;
        probing++;
        index = hashFunction(key, probing);
    }
    if (tableArr[index].key == key) {
        res = true;
        return res;
    }
    return res;
}

int HashTable::getIndex(int key) {
    int probing = 0;
    int index = hashFunction(key, probing);
    if (key == tableArr[index].key){
        return index;
    }
    while (tableArr[index].key != key){
        if (tableArr[index].key == -1)
            break;
        probing++;
        index = hashFunction(key,probing);
    }
    return index;
}

int HashTable::size() const {
    return count;
}
bool HashTable::empty() const{
    return count==0;
}

int HashTable::hashFunction(int key, int probing) const{
    // cap -1 because 0 % cap = cap, which is index-out of bounds
    return ((key + probing) % (cap));
}
#endif //SRC_HASHTABLE_H
