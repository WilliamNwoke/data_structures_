//
// Created by Uchenna on 6/5/22.
//

#ifndef SRC_HUFFMAN_H
#define SRC_HUFFMAN_H

#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <bitset>
#include "BST.h"


using namespace std;

class CharFreq {
public:
    CharFreq() : letter('\0'), frequency(0), encoding("") { }
    CharFreq(unsigned char l, float f) :letter(l), frequency(f), encoding("") { }

    unsigned char letter;
    float frequency;
    string encoding;

    bool operator>(const CharFreq &rhs) const {
        return frequency > rhs.frequency;
    }
};


class Huffman : BST<CharFreq> {
public:
    Huffman() {}
    bool createCodeTree(string filename);
    bool encodeFile(string originalFilename, string outputFilename);
    bool decodeFile(string filename);
    void displayCode(ostream &out);
private:
    inline int traverseAndPrint(string &bits, int i) {
        return traverseAndPrint(bits, i, root);
    }
    int traverseAndPrint(string &bits, int i, BSTNode *cur);
};

ostream& operator<<(ostream &out, Huffman &code);


#endif //SRC_HUFFMAN_H
