//
// Created by Uchenna on 4/8/22.
//
// This program reads and populates 1D dynamic array of strings
// And a 2D dynamic array of integers using the ratings.txt
// then prints to standard out
//
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/// Prints the values of the ratings.txt file
void lab1(const std::string &fileName);

int main() {

    // Prompts for a file to enter
    std::string filePath;
    std::cout << "Enter a rating file: ";
    std::cin >> filePath;

    // passes the filename for processing
    lab1(filePath);

    return 0;
}

/**
 * function takes a file name and populates two arrays and prints to standard out
 * @param fileName name of the file
 */
void lab1(const std::string &fileName) {
    std::string *members;
    int **ratings;
    int membersCount =0;
    int booksCount;
    int size =100;


    // Allocate memory for the 1D array and 2D array
    members = new std::string[size];
    ratings = new int*[size];
    for (int i= 0; i<size; i++) {
        ratings[i] = new int[size];
    }

    std::string name;
    std::string memberRatings;
    std::ifstream inFile;

    // Try to open file
    inFile.open(fileName);

    // If the file successfully opened
    if (inFile.is_open()) {
        // reads the name of the file
        while (getline(inFile, name)) {
            members[membersCount] = name;

            // reads the ratings for the name
            if (getline(inFile, memberRatings)) {
                std::istringstream ss(memberRatings);
                booksCount = -1;

                // Assigns the rating for the member's rating array
                while (ss) {
                    int rating;
                    ss >> rating;
                    ratings[membersCount][++booksCount] = rating;
                }
            }
            membersCount++;
        }
    } // If the file is invalid
    else
    {
        std::cout << "ERROR: file not found";
        return;
    }

    std::cout << "# of books: " << booksCount << "\n";
    std::cout << "# of members: " << membersCount << "\n\n";


    for (int i=0; i< membersCount; i++ ){
        std::cout << members[i] << "\n";
        for (int j = 0; j< booksCount; j++){
            std::cout << ratings[i][j] << " ";
        }
        std::cout << "\n";
    }

    inFile.close();
    for (int i=0; i< size; i++){
        delete[] ratings[i];
    }

    delete[] ratings;

    ratings = NULL;
}