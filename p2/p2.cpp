// Name: Uchenna
// This program is designed to create a BST with basic
//  functionalities of displaying BST info and manipulating the BST.
// The files will be read, inserted into a BST where various
// methods called from the main driver will display information as
// well as manipulate the BST.


#include <iostream>
#include <fstream>
#include "BST.h"

void welcome() {

    //Prints out the welcome message
    std::cout << "\nWelcome to Uchenna's BST application, we look forward to launch" << std::endl;
}

void goodbye(){

    //Prints out goodbye message
    std::cout << "\nGoodbye.";
}

std::string getIntdotDat() {

    //Prompts for the integer file name
    std::string intFile;
    std::cout << "\nEnter integer file:";
    std::cin >> intFile;
    return intFile;
}

std::string getStrdotDat() {

    //Prompts for the string file name
    std::string stringFile;
    std::cout << "\nEnter string file:";
    std::cin >> stringFile;
    return stringFile;
}

void storeIntTree(const std::string& filename, BST<int> & intBST) {

    //Read the string to the value variable
    std::string value;

    //Store the converted string to int variable
    int valueInt;

    //Create ifstream to read the file and open the file
    std::ifstream infile;
    infile.open(filename);

    //Read the file and store the data into the BST
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

void storeStringTree(const std::string& filename, BST<std::string> & stringBST) {

    //Read the string to the value variable
    std::string value;

    //Create if-stream to read the file and open the file
    std::ifstream infile;
    infile.open(filename);

    //Read the file and store the data into the BST
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
void printBSTStats(BST<T> & BSTAny) {


    //Print out the number of nodes
    std::cout << "# of nodes:" << " " << BSTAny.size() << std::endl;

    //Print out the number of leaves
    std::cout << "# of leaves:" << " " << BSTAny.getLeafCount() << std::endl;

    //Print out the height of tree
    std::cout << "tree height:" << " " <<BSTAny.getHeight() << std::endl;

    //Print out if the BST is empty, returns one hence the boolalpha
    std::cout << "tree empty?" << " " << std::boolalpha << BSTAny.empty() << std::endl;

}


void printIntIntro(BST<int> & intBST) {

    //Print the banners
    std::cout << "******************************" << std::endl
              << "* INTEGER BINARY SEARCH TREE *" << std::endl
              << "******************************\n" << std::endl;

    std::cout << "** CREATE BST **" << std::endl;

    //Print initial stats for the intBST.
    printBSTStats(intBST);
}

void printStringIntro(BST<std::string> & stringBST) {

    //Print the banners
    std::cout << std::endl
              << "******************************" << std::endl
              << "* STRING BINARY SEARCH TREE *" << std::endl
              << "******************************\n" << std::endl;

    std::cout << "** CREATE BST **" << std::endl;

    //Print initial stats for the intBST.
    printBSTStats(stringBST);
}


template<typename T>
void printTestTraversals(BST<T> & BSTAny) {

    //Print the different traversals
    std::cout << "\n** TEST TRAVERSALS **" << std::endl;
    std::cout << "pre-order:" << "   " << BSTAny.getPreOrderTraversal() << std::endl;
    std::cout << "in-order:" << "    " << BSTAny.getInOrderTraversal() << std::endl;
    std::cout << "post-order:" << "  " << BSTAny.getPostOrderTraversal() << std::endl;
}





void printLevelAncestorInt(BST<int> & intBST) {

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

void printLevelAncestorString(BST<std::string> & stringBST) {

    //Prints out the banner
    std::cout << std::endl << "** TEST LEVEL & ANCESTORS **" << std::endl;
    std::string preOrderString = stringBST.getPreOrderTraversal();

    //Read the preorder traversal and store it in an string
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
void printPreOrderOnly(BST<T> & BSTAny) {

    //Print strings about the insert method and the preorder traversal string.
    std::cout << std::endl << "** TEST INSERT **" << std::endl;
    std::cout << "Inserting in this order:" << "  " <<
              BSTAny.getPreOrderTraversal() << std::endl;
}


template <typename T>
void printRemove(BST<T> & anyBST, T * arr) {

    //Print strings about the remove method while removing the nodes (if
    // found inside the BST)
    std::cout << "\n** TEST REMOVE **" << std::endl;
    std::cout << "Removing in this order:" << "  ";

    int sizeOfArr = sizeof(arr);

    for(int i = 0; i < sizeOfArr; i++) {
        std::cout << arr[i] << " ";
        anyBST.remove(arr[i]);
    }
    std::cout << std::endl;

    //Print the BST basic stats
    printBSTStats(anyBST);

    //Prints out the traversals.
    std::cout << "pre-order:" << "   " << anyBST.getPreOrderTraversal() << std::endl;
    std::cout << "in-order:" << "    " << anyBST.getInOrderTraversal() << std::endl;
    std::cout << "post-order:" << "  " << anyBST.getPostOrderTraversal() << std::endl;

}

template <typename T>
void printInsert(BST<T> & anyBST, T * arr) {

    //Print strings about the insert method while inserting the nodes (from
    // the hard coded array in main)
    std::cout << "\n** TEST INSERT (again) **" << std::endl;
    std::cout << "Inserting in this order:" << "  ";

    int sizeOfArr = sizeof(arr);

    for(int i = 0; i < sizeOfArr; i++) {
        std::cout << arr[i] << " ";
        anyBST.insert(arr[i]);
    }
    std::cout << std::endl;

    //Print the BST basic stats
    printBSTStats(anyBST);

    //Prints out the traversals.
    std::cout << "pre-order:" << "   " << anyBST.getPreOrderTraversal() << std::endl;
    std::cout << "in-order:" << "    " << anyBST.getInOrderTraversal() << std::endl;
    std::cout << "post-order:" << "  " << anyBST.getPostOrderTraversal() << std::endl;
}

template<typename T>
void printTestContain(BST<T> &anyBST, T *arr) {

    //Print out if a particular node is included in the BST or not
    std::cout << std::endl << "** TEST CONTAINS **" << std::endl;

    int sizeOfArr = sizeof(arr);

    //Runs through the hard-coded array to check if it is included in the
    // anyBST
    for(int i = 0; i < sizeOfArr; i++) {
        std::cout << "contains(" << arr[i] << "):" << " " <<
                  anyBST.contains(arr[i]) << std::endl;
    }
}

template <typename T>
void combinedIntBSTFunctions(BST<T> & intBST, T * arr) {

    //Prints the test insert banner and the preorder
    printPreOrderOnly(intBST);

    //Prints out the BST stats
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
void combinedStringBSTFunctions(BST<T> & stringBST, T * arr) {

    //Prints the test insert banner and the preorder
    printPreOrderOnly(stringBST);

    //Prints out the BST stats
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

    //Create the int BST
    BST<int> intBST;

    //Print out the int BST intro
    printIntIntro(intBST);

    //Prompt for file name
    std::string intFile = getIntdotDat();

    //Store the data read into the BST
    storeIntTree(intFile, intBST);

    //A function that combines multiple functions that will print out various
    // information as well as modifies the BST.
    combinedIntBSTFunctions(intBST, arrInt);

    //Hard coded string array to test
    std::string arrString[8] = {"gene", "mary", "bea", "uma",
                           "yan", "amy", "ron", "opal"};

    //Create the string BST
    BST<std::string> stringBST;

    //Print out the string BST intro
    printStringIntro(stringBST);

    //Prompt for file name
    std::string stringFile = getStrdotDat();

    //Store the data read into the BST
    storeStringTree(stringFile, stringBST);

    //A function that combines multiple functions that will print out various
    // information as well as modifies the BST.
    combinedStringBSTFunctions(stringBST, arrString);

    //Prints the goodbye message
    goodbye();

}
