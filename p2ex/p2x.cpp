// Name: Uchenna
// This program is designed to create a BSTx with basic
//  functionalities of displaying BSTx info and manipulating the BSTx.
// The files will be read, inserted into a BSTx where various
// methods called from the main driver will display information as
// well as manipulate the BSTx.


#include <iostream>
#include <fstream>
#include "BSTx.h"

void welcome() {

    //Prints out the welcome message
    std::cout << "\nWelcome to Uchenna's BSTx application, we look forward to launch" << std::endl;
}

void goodbye(){

    //Prints out goodbye message
    std::cout << "\nGoodbye.";
}

std::string getStringDotdat() {

    //Prompts for the integer file name
    std::string intFile;
    std::cout << "\nEnter integer file:";
    std::cin >> intFile;
    return intFile;
}

std::string promptStringFile() {

    //Prompts for the string file name
    std::string stringFile;
    std::cout << "\nEnter string file:";
    std::cin >> stringFile;
    return stringFile;
}

void storeIntTree(const std::string& filename, BSTx<int> & intBST) {

    //Read the string to the value variable
    std::string value;

    //Store the converted string to int variable
    int valueInt;

    //Create ifstream to read the file and open the file
    std::ifstream infile;
    infile.open(filename);

    //Read the file and store the data into the BSTx
    if(infile) {
        while(getline(infile, value, '\n' )) {
            valueInt = stoi(value);
            intBST.insert(valueInt);
        }
    } else {
        std::cout << "Error opening the file\n";
    }

    //Close the file
    infile.close();

}
std::string convertToLower(std::string readLine) {

    //Storage for the new modified string
    std::string lowerString;

    //Length of the string.
    int length = readLine.length();

    //For loop that converts each character into lowercase and eliminate the
    // space in between the words.
    for(int i = 0; i < length; i++) {
        if (readLine[i] != ' ') {
            lowerString += tolower(readLine[i]);
        }
    }
    //Returns the modified string.
    return lowerString;
}

void storeStringTree(const std::string& filename, BSTx<std::string> & stringBST) {

    //Read the string to the value variable
    std::string value;

    //Create if-stream to read the file and open the file
    std::ifstream infile;
    infile.open(filename);

    //Read the file and store the data into the BSTx
    if(infile) {
        while(getline(infile, value, '\n' )) {
            value = convertToLower(value);
            stringBST.insert(value);
        }
    } else {
        std::cout << "Error opening the file\n";
    }

    //Close the file
    infile.close();

}
template<typename T>
void printBSTStats(BSTx<T> & bstObj) {


    //Print out the number of nodes
    std::cout << "# of nodes:" << " " << bstObj.size() << std::endl;

    //Print out the number of leaves
    std::cout << "# of leaves:" << " " << bstObj.getLeafCount() << std::endl;

    //Print out the height of tree
    std::cout << "tree height:" << " " <<bstObj.getHeight() << std::endl;

    std::cout << "tree width:" << " " << bstObj.getWidth() << std::endl;

    //Print out if the BSTx is empty, returns one hence the boolalpha
    std::cout << "tree empty?" << " " << std::boolalpha << bstObj.empty() << std::endl;

}


void printIntIntro(BSTx<int> & intBST) {

    //Print the banners
    std::cout << "******************************" << std::endl
              << "* INTEGER BINARY SEARCH TREE *" << std::endl
              << "******************************\n" << std::endl;

    std::cout << "** CREATE BSTx **" << std::endl;

    //Print initial stats for the intBST.
    printBSTStats(intBST);
}

void printStringIntro(BSTx<std::string> & stringBST) {

    //Print the banners
    std::cout << std::endl
              << "******************************" << std::endl
              << "* STRING BINARY SEARCH TREE *" << std::endl
              << "******************************\n" << std::endl;

    std::cout << "** CREATE BSTx **" << std::endl;

    //Print initial stats for the intBST.
    printBSTStats(stringBST);
}


template<typename T>
void printTestTraversals(BSTx<T> & bstObj) {

    //Print the different traversals
    std::cout << "\n** TEST TRAVERSALS **" << std::endl;
    std::cout << "pre-order:" << "   " << bstObj.getPreOrderTraversal() << std::endl;
    std::cout << "in-order:" << "    " << bstObj.getInOrderTraversal() << std::endl;
    std::cout << "post-order:" << "  " << bstObj.getPostOrderTraversal() << std::endl;
    std::cout << "level-order" << "  " << bstObj.getLevelOrder() << std::endl;
}





void printLevelAncestorInt(BSTx<int> & intBST) {

    //Prints out the banner
    std::cout << std::endl << "** TEST LEVEL & ANCESTORS **" << std::endl;

    //Read the preorder traversal and store it in an int
    std::string preOrderString = intBST.getPreOrderTraversal();
    std::string storedInt;
    std::stringstream stringStream(preOrderString);
    int correctInt;

    //Read each int from the preorder string
    while((stringStream >> storedInt)) {
        correctInt = stoi(storedInt);
        std::cout << "level(" << correctInt << "):" << " " <<
                  intBST.getLevel(correctInt) << ",     "   <<
                  "ancestor(" << correctInt << "):" << intBST.getAncestors(correctInt)
                  << std::endl;
    }

}

void printLevelAncestorString(BSTx<std::string> & stringBST) {

    //Prints out the banner
    std::cout << std::endl << "** TEST LEVEL & ANCESTORS **" << std::endl;
    std::string preOrderString = stringBST.getPreOrderTraversal();

    //Read the preorder traversal and store it in a string
    std::string storedString;
    std::istringstream stringStream(preOrderString);

    //Read each string line from the preorder string
    while((stringStream >> storedString)) {
        std::cout << "level(" << storedString << "):" << " " << stringBST.getLevel
                (storedString)        << ",     "   <<
                  "ancestor(" << storedString<< "):" <<
                  stringBST.getAncestors(storedString) << std::endl;
    }

}

template <typename T>
void printPreOrderOnly(BSTx<T> & bstObj) {

    //Print strings about the insert method and the preorder traversal string.
    std::cout << std::endl << "** TEST INSERT **" << std::endl;
    std::cout << "Inserting in this order:" << "  " <<
              bstObj.getPreOrderTraversal() << std::endl;
}


template <typename T>
void printRemove(BSTx<T> & bstObj, T * arr) {

    //Print strings about the remove method while removing the nodes (if
    // found inside the BSTx)
    std::cout << "\n** TEST REMOVE **" << std::endl;
    std::cout << "Removing in this order:" << "  ";

    int sizeOfArr = sizeof(arr);

    for(int i = 0; i < sizeOfArr; i++) {
        std::cout << arr[i] << " ";
        bstObj.remove(arr[i]);
    }
    std::cout << std::endl;

    //Print the BSTx basic stats
    printBSTStats(bstObj);

    //Prints out the traversals.
    std::cout << "pre-order:" << "   " << bstObj.getPreOrderTraversal() << std::endl;
    std::cout << "in-order:" << "    " << bstObj.getInOrderTraversal() << std::endl;
    std::cout << "post-order:" << "  " << bstObj.getPostOrderTraversal() << std::endl;
    std::cout << "level-order" << "  " << bstObj.getLevelOrder() << std::endl;

}

template <typename T>
void printInsert(BSTx<T> & bstObj, T * arr) {

    //Print strings about the insert method while inserting the nodes (from
    // the hard coded array in main)
    std::cout << "\n** TEST INSERT (again) **" << std::endl;
    std::cout << "Inserting in this order:" << "  ";

    int sizeOfArr = sizeof(arr);

    for(int i = 0; i < sizeOfArr; i++) {
        std::cout << arr[i] << " ";
        bstObj.insert(arr[i]);
    }
    std::cout << std::endl;

    //Print the BSTx basic stats
    printBSTStats(bstObj);

    //Prints out the traversals.
    std::cout << "pre-order:" << "   " << bstObj.getPreOrderTraversal() << std::endl;
    std::cout << "in-order:" << "    " << bstObj.getInOrderTraversal() << std::endl;
    std::cout << "post-order:" << "  " << bstObj.getPostOrderTraversal() << std::endl;
    std::cout << "level-order" << "  " << bstObj.getLevelOrder() << std::endl;
}

template<typename T>
void printTestContain(BSTx<T> &bstObj, T *arr) {

    //Print out if a particular node is included in the BSTx or not
    std::cout << std::endl << "** TEST CONTAINS **" << std::endl;

    int sizeOfArr = sizeof(arr);

    //Runs through the hard-coded array to check if it is included in the
    // bstObj
    for(int i = 0; i < sizeOfArr; i++) {
        std::cout << "contains(" << arr[i] << "):" << " " <<
                  bstObj.contains(arr[i]) << std::endl;
    }
}

template <typename T>
void combinedIntBSTFunctions(BSTx<T> & intBST, T * arr) {

    //Prints the test insert banner and the preorder
    printPreOrderOnly(intBST);

    //Prints out the BSTx stats
    printBSTStats(intBST);

    //Prints out the different traversals
    printTestTraversals(intBST);

    //Prints out the levels and ancestors
    printLevelAncestorInt(intBST);

    //Prints out the contain test
    printTestContain(intBST, arr);

    //Prints out the remove test
    printRemove(intBST, arr);

    //Prints out the insert test
    printInsert(intBST, arr);
}

template <typename T>
void combinedStringBSTFunctions(BSTx<T> & stringBST, T * arr) {

    //Prints the test insert banner and the preorder
    printPreOrderOnly(stringBST);

    //Prints out the BSTx stats
    printBSTStats(stringBST);

    //Prints out the different traversals
    printTestTraversals(stringBST);

    //Prints out the levels and ancestors
    printLevelAncestorString(stringBST);

    //Prints out the test contain test
    printTestContain(stringBST, arr);

    //Prints out the remove test
    printRemove(stringBST, arr);

    //Prints out the insert test
    printInsert(stringBST, arr);
}




int main() {

    //Print the introduction string
    welcome();

    //Hard coded int array to test
    int arrInt[8] = {20, 40, 10, 70, 99, -2, 59, 43};

    //Create the int BSTx
    BSTx<int> intBST;

    //Print out the int BSTx intro
    printIntIntro(intBST);

    //Prompt for file name
    std::string intFile = getStringDotdat();

    //Store the data read into the BSTx
    storeIntTree(intFile, intBST);

    //A function that combines multiple functions that will print out various
    // information as well as modifies the BSTx.
    combinedIntBSTFunctions(intBST, arrInt);

    //Hard coded string array to test
    std::string arrString[8] = {"gene", "mary", "bea", "uma",
                           "yan", "amy", "ron", "opal"};

    //Create the string BSTx
    BSTx<std::string> stringBST;

    //Print out the string BSTx intro
    printStringIntro(stringBST);

    //Prompt for file name
    std::string stringFile = promptStringFile();

    //Store the data read into the BSTx
    storeStringTree(stringFile, stringBST);

    //A function that combines multiple functions that will print out various
    // information as well as modifies the BSTx.
    combinedStringBSTFunctions(stringBST, arrString);

    //Prints the goodbye message
    goodbye();

}
