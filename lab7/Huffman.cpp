//
// Created by Uchenna on 6/5/22.
//

#include "Huffman.h"
#include "Huffman.h"

bool Huffman::createCodeTree(string filename) {
    std::priority_queue<
            BST<CharFreq>::BSTNode*,
            std::vector<BST<CharFreq>::BSTNode*>,
            BST<CharFreq>::FrequencyCompare
    > myPriorityQ;
    string str;
    string allText = "";
    ifstream infile;
    infile.open(filename.c_str());
    if (!infile.is_open()) {
        cout << "ERROR loading file!\n";
        return false;
    }
    while (!infile.eof()) {    // To get you all the lines.
        getline(infile,str); // Saves the line in STRING.
        allText += str + "\n";
    }
    infile.close();

    // **************************************************************
    // TODO: createCodeTree - add code here
    //  1. Count occurrences of every letter or symbol that you care about in
    //     allText (consider spaces ' ', newlines '\n', periods, commas, question
    //     marks, quotation marks, etc.
    //  2. Use myPriorityQ to build a tree, as described in the assignment.
    //  3. Set root (inherited from BST) to the final item in myPriorityQ
    //     (in other words, when there is a single tree in myPriorityQ).



    // **************************************************************

    return true;
}

bool Huffman::encodeFile(string originalFilename, string outputFilename) {
    string str;
    string allText = "", currentStream = "";
    ifstream infile;
    const int WRITE_SIZE = 8;

    infile.open(originalFilename.c_str());
    if( !infile.is_open() ) {
        cout << "ERROR loading file!\n";
        return false;
    }
    while (!infile.eof()) {        // To get you all the lines.
        getline(infile, str);   // Saves the line in string.
        allText += str + "\n";
    }
    infile.close();

    std::ofstream outStream(outputFilename.c_str(), std::ios::binary);
    if (!outStream.is_open()) {
        cout << "ERROR creating output file!\n";
        return false;
    }

    for (int i = 0; i < (int)allText.length(); i++) {
        // **************************************************************
        // TODO: encodeFile - add your code here
        //  add the appropriate encoding for allText[i] to currentStream

        currentStream += ""; // may need to update this line



        // **************************************************************

        while ((int)currentStream.length() > WRITE_SIZE) {
            string byte = currentStream.substr(0, WRITE_SIZE);
            bitset<8> set(byte);
            const char toWrite = (unsigned char)((unsigned int)set.to_ulong());
            outStream.write(&toWrite,sizeof(char));
            currentStream = currentStream.substr(WRITE_SIZE,
                                                 currentStream.length() - WRITE_SIZE);
        }
    }

    outStream.close();
    return false;
}

bool Huffman::decodeFile(string filename) {
    int i = 0; string bitStream = "";
    ifstream encodedfile;

    encodedfile.open(filename.c_str(), ios::binary);
    if (!encodedfile.is_open()) {
        cout << "ERROR opening encoded file!\n";
        return false;
    }

    encodedfile >> std::noskipws;
    while (!encodedfile.eof()) {
        unsigned char readMe;
        encodedfile >> readMe;
        bitset<8> set((unsigned long)readMe);
        bitStream += set.to_string();
    }

    encodedfile.close();

    while (i != -1)
        i = traverseAndPrint(bitStream, i);
    return false;
}

int Huffman::traverseAndPrint(string &bits, int i, BSTNode *cur) {
    if(i >= (int)bits.length())
        return -1;
    // **************************************************************
    // TODO: traverseAndPrint - add your code here
    //  Write this function using recursion. This is essentially your decode
    //  function.  You need to step through the tree based on reading 0 or 1
    //  and when you reach a leaf, print (using cout) the appropriate character.
    //  - i represents your current location in the string
    //  - cur represents the cur node in your tree
    //  Don't forget that you need to keep going after printing out a character
    //  (which means restarting at the top of the tree)
a

    // **************************************************************

    return -1;
}

void Huffman::displayCode(ostream &out) {
    // **************************************************************
    // TODO: displayCode - add your code here
    //  Print out each letter and its code, you might want to check for
    //  special cases (space, newline, etc.)



    // **************************************************************
}

ostream& operator<<(ostream &out, Huffman &code) {
    code.displayCode(out);
    return out;
}
