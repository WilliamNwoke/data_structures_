//
// Created by Uchenna on 4/8/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include "BookList.h"

/**
 *
 * @param fileN name/path of the file
 * @param book object of the bookList class
 */
void lab2(const std::string &fileN, BookList &book);


int main() {
    // bookList object and bookHandler func
    BookList bookList;
    lab2("lab2/books.txt", bookList);

    // Test that addBook returns a bookID
    BookList bookList2;
    int bookId = bookList2.addBook("1", "Dr. Peon", "Elon musk vs  Forest Gourd", "2023");
    assert(bookId == 0);
    bookId = bookList2.addBook("2", "William ShakeSpear", "The spear and the milkshake", "1998");
    assert(bookId == 1);

    // Test that resize() doubles the initial capacity
    assert(bookList.getCapacity() == 100);

    // Test that we get a -1 if a book is not found
    assert(bookList.findISBN("56") == -1);

    // Copy constructor test
    BookList copiedBook(bookList);
    assert(copiedBook.size() == 55);

    // Test for assignment operator
    BookList assignedBook;
    assignedBook = bookList;
    assert(assignedBook.size() == 55);

    return 0;
}

/// Takes a filename and bookList object
void lab2(const std::string &fileN, BookList &bookList) {
    auto *currentBook = new std::string[4];
    int isbn = 1;

        std::string filepath = "../" + fileN;
        std::string bookLine;
        std::ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    // True if the file opened
    if (inFile.is_open()) {
        // readlines of the books.txt
        while(getline(inFile, bookLine)) {
            std::istringstream ss(bookLine);

            // Add the isbn as the position in the list
            currentBook[0] = std::to_string(isbn++);

            // Add the author, title, and year to currentBook
            int i = 0;
            std::string book;
            while (getline(ss, book, ',')) {
                currentBook[++i] = book;
            }

            // Add the book to the bookList
            bookList.addBook(currentBook[0], currentBook[1],
                currentBook[2], currentBook[3]);
        }
    } else  {
        // File name was invalid, stop running
        std::cout << "ERROR: cannot open file";
        return;
    }
    // Output
    std::cout <<"\n" << "# of books: " << bookList.size() << "\n";
    std::cout << "\n";

    // Print the info of the books
    for (int i = 1; i <= bookList.size(); ++i) {
        int bookId = bookList.findISBN(std::to_string(i));
        std::cout << bookList.getBook(bookId) << "\n";
    }

    // Close the file and delete
    inFile.close();
    delete [] currentBook;
}
