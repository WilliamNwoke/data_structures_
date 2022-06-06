//
// Created by Uchenna on 6/5/22.
//

//  lab7.cpp

// TODO: Analysis (extra credit)
//  1. Book from Project Gutenberg: [TITLE] by [AUTHOR]
//  2. Encoded file size: [ADD SIZE]
//     Original file size: [ADD SIZE]
//     Percent savings: [ADD PERCENT]% savings
//  3. gzip compressed book size: [ADD SIZE]
//     The gzip compressed file is the [SMALLER/LARGER] than the encoded book

#include "Huffman.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    Huffman hc;
    string inputFile, outputFile;

    cout << "Please enter the input filename: ";
    cin >> inputFile;
    cout << "Please enter the output file: ";
    cin >> outputFile;

    // create code tree
    hc.createCodeTree(inputFile);

    // encode file
    hc.encodeFile(inputFile, outputFile);

    // decode file
    hc.decodeFile(outputFile);

    // print
    cout << hc;

    return 0;
}
