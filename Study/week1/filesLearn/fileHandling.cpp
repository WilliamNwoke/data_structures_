//
// Created by Uchenna on 4/4/22.
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// Create a file
void createFile(){
    // create and open a text file
     ofstream MyFile ("filename.txt");

     /// Write to files
     MyFile << "Files can be tricky mate";

     MyFile.close();
}

// read a file
void readFile () {
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        cout << myText;
    }

    // Close the file
    MyReadFile.close();
}

// file reading
const string FILEN = "path to file";
int main() {
    ifstream inFile;
    int num;
    inFile.open(FILEN); // FILENAME is reserved word :: Opens the file

    if (!inFile.fail()){ // check if file opens
        // file is ready to use
        // rest of program can go here
        while (inFile >> num){
            // do something with num -> read file ::  start/end
            // ready to read the next
        }
        inFile.close(); // close the file
    }

}

