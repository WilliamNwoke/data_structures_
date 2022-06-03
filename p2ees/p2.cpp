#include <iostream>
#include "BST1.h"
#include <fstream>

using namespace std;

/**
 * Tests the has method of BST
 * @param bst    an instance of BST
 * @param has    an array of values that should be contained
 * @param hasNot an array of values that should not be contained
 * @param n      number of values in has and hasNot
 */
template <class T>
void testContains(const T *has, const T *hasNot, const BST<T> &bst, int n) {

    for(int i = 0; i < n; i++) {
        cout << "has(" << has[i] << "): ";
        cout << (bst.contains(has[i]) ? "true" : "false");
        cout << endl;
    }

    for(int i = 0; i < n; i++) {
        cout << "has(" << hasNot[i] << "): ";
        cout << (bst.contains(hasNot[i]) ? "true" : "false");
        cout << endl;
    }
}

/**
 * prints out basic data of a tree, i.e. # nodes, # leaves, height, and empty
 * @param bst an instance of BST
 */
template <class T>
void printTreeData(const BST<T> bst) {
    cout << "# of nodes:  " << bst.size() << endl;
    cout << "# of leaves: " << bst.getLeafCount() << endl;
    cout << "BST height:  " << bst.getHeight() << endl;
    cout << "BST empty?   " <<
         (bst.empty() ? "true" : "false") << endl;
}

/**
 * Prints the traversals of a tree
 * @param bst an instance of BST
 */
template <class T>
void printTraversals(const BST<T> bst) {
    cout << "pre-order:   " << bst.getPreOrderTraversal() << endl;
    cout << "in-order:    " << bst.getInOrderTraversal() << endl;
    cout << "post-order:  " << bst.getPostOrderTraversal() << endl;
}

/**
 * Removes an array of items from a bst and prints data about the tree
 * @param toRemove an array of items to remove from the bst
 * @param n        the length of the array
 * @param bst      an instance of BST
 */
template <class T>
void testRemove(const T *toRemove, int n, BST<T> &bst) {
    cout << "Removing in this order: ";
    for (int i = 0; i < n; ++i) {
        cout << toRemove[i] << " ";
        bst.remove(toRemove[i]);
    }
    cout << endl;

    printTreeData(bst);
    printTraversals(bst);
}

/**
 * tests the insertion of an array of elements into a bst and prints data
 * about the bst
 * @param toInsert an array of elements to insert
 * @param n        the number of elements in the array
 * @param bst      an instance of BST
 */
template <class T>
void testInsert(const T *toInsert, int n, BST<T> bst) {
    cout << "Inserting in this order: ";
    for (int i = 0; i < n; ++i) {
        cout << toInsert[i] << " ";
        bst.insert(toInsert[i]);
    }
    cout << endl;

    printTreeData(bst);
    printTraversals(bst);
}

/**
 * The main driver function to test an integer binary search tree
 */
void integerBstTest() {

    cout << "******************************" << endl;
    cout << "* INTEGER BINARY SEARCH TREE *" << endl;
    cout << "******************************" << endl;
    cout << endl;

    cout << "** CREATE BST **" << endl;

    BST<int> bTree;

    printTreeData(bTree);

    cout << endl;
    string filepath;
    cout << "Enter integer file: ";
    cin >> filepath;
    cout << endl;

    string nextInt;
    ifstream inFile;

    // attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        cout << "** TEST INSERT **" << endl;
        cout << "Inserting in this order: ";
        // proceed while lines are being read from the file
        while (getline(inFile, nextInt)) {
            cout << nextInt << " ";

            int x = stoi(nextInt);
            bTree.insert(x);
        }
        cout << endl;
    } else {
        // File name was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }

    printTreeData(bTree);

    cout << endl;
    cout << "** TEST TRAVERSALS **" << endl;
    printTraversals(bTree);

    cout << endl;
    cout << "** TEST CONTAINS **" << endl;
    int hasInts[] = {20, 40, 10, 70};
    int notHasInts[] = {99, -2, 59, 43};
    testContains(hasInts, notHasInts, bTree, 4);

    cout << endl;
    cout << "** TEST REMOVE **" << endl;
    int remAndInsrt[] = {20, 40, 10, 70, 99, -2, 59, 43};
    testRemove(remAndInsrt, 8, bTree);

    cout << endl;
    cout << "** TEST INSERT (again) **" << endl;
    testInsert(remAndInsrt, 8, bTree);


}

/**
  * The main driver function to test a string binary search tree
  */
void stringBstTest() {

    cout << "********************" << endl;
    cout << "* test string BST  *" << endl;
    cout << "********************" << endl;
    cout << endl;

    cout << "** CREATE BST **" << endl;

    BST<string> bTree;

    printTreeData(bTree);

    cout << endl;
    string filepath;
    cout << "Enter string file: ";
    cin >> filepath;
    cout << endl;

    string nextStr;
    ifstream inFile;

    // attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        cout << "** TEST INSERT **" << endl;
        cout << "Inserting in this order: ";
        // proceed while lines are being read from the file
        while (getline(inFile, nextStr)) {
            cout << nextStr << " ";

            bTree.insert(nextStr);
        }
        cout << endl;
    } else {
        // File name was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }

    printTreeData(bTree);

    cout << endl;
    cout << "** TEST TRAVERSALS **" << endl;
    printTraversals(bTree);

    cout << endl;
    cout << "** TEST CONTAINS **" << endl;
    string hasStr[] = {"gene", "mary", "bea", "uma"};
    string notHasStr[] = {"yan", "amy", "ron", "opal"};
    testContains(hasStr, notHasStr, bTree, 4);

    cout << endl;
    cout << "** TEST REMOVE **" << endl;
    string remAndInsrt[] = {"gene", "mary", "bea", "uma", "yan", "amy", "ron", "opal"};
    testRemove(remAndInsrt, 8, bTree);

    cout << endl;
    cout << "** TEST INSERT (again) **" << endl;
    testInsert(remAndInsrt, 8, bTree);
}

int main() {
    cout << "Welcome, this is Uchenna' implementation " << endl;
    cout << "of a templated binary search tree!" << endl;
    cout << endl << endl;

    integerBstTest();
    cout << endl << endl;
    stringBstTest();

    return EXIT_SUCCESS;
}