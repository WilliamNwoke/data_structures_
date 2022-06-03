//
// Created by Uchenna on 4/26/22.
//
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <algorithm>

/**
 * Welcome and goodbye message function
 * @param string type of message to print
 */
void greetings(const std::string&);

/**
 * takes a string, converts to lower case and removes whitespaces
 * @param text string to check if it is a palindrome
 * @return true if its a palindrome else false
 */
bool isPalindrome(std::string);

/**
 * Validates that the string entered is indeed a valid palindrom
 * @param text substring of the string
 * @return
 */
bool isValid(std::string, int);

/**
 * runs the palindrome program
 */
void run();

int main() {
    // Call run to start the palindrome application
    run();
    return 0;
}

void greetings(const std::string& msg) {
    if (msg == "welcome")
        std::cout << "\nWelcome to the palindrome testing program!" << std::endl;

    if (msg == "goodbye")
        std::cout << "Thanks for using the palindrome tester!";
}

bool isPalindrome(std::string text){
    // remove white spaces
    text.erase(remove_if(text.begin(), text.end(),
                              ::isspace), text.end());

    // converts to lower case
    transform(text.begin(), text.end(),
                   text.begin(), ::tolower);
    return isValid(text,1);
}

bool isValid(std::string s, int next){
    // gets the last and the first index of the string
    int l = 0;
    int r = s.length() -1;

    // checks if we are close or at the middle
    // checks if the end and begining are the same.
    // if they are different, calls isValid, and set next to 0, then returns
    // false
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else if ( next > 0) {
            return isValid(s.substr(l+1, r+1), next -1)
            || isValid(s.substr(l,r),next -1);
        } else {
            return false;
        }
    }
    return true;
}

void run(){
    // strings and fstream object defined
    std::fstream inFile;
    std::string fileName;
    std::string text;
    greetings("welcome");

    // gets the name of the file
    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    std::cout << std::endl;

    // Attempts to open file, then read file
    inFile.open(fileName);
    if (inFile.is_open()){

        // while not EOF, pass the lind to text. check if the line read is a
        // palindrome and print
        while (getline(inFile, text)){
            if (isPalindrome(text)){
                std::cout << text <<" is a palindrome!\n";
            } else {
                std::cout << text << " is Not a palindrome!\n";
            }

        }
        std::cout << std::endl;
    } else {
        // If file wasn't read
        std::cout << "Error opening file\n";
    }
    // close file and goodbye
    inFile.close();
    greetings("goodbye");
}