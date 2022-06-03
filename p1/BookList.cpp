//
// Created by Uchenna on 4/8/22.
//

#include "BookList.h"

/// Constructor
BookList::BookList(){
    capacity = CAPACITY;
    count = 0;
    bookArray = new Book[capacity];
}

/// Destructor
BookList::~BookList() {
    delete [] bookArray;
}

/**
 * Copy constructor
 * @param copiedBook  books to copy
 */
BookList::BookList(const BookList &copiedBook) {
    // Copy elements
    capacity = copiedBook.capacity;
    count = copiedBook.count;

    // Set memory with new size/capacity
    bookArray = new Book[capacity];

    // Copy elements from copiedBook
    for (int value= 0; value<count; ++value)
        bookArray[value] = copiedBook.bookArray[value];
}

/**
 *
 * @param btCopy book to copy
 * @return self/this
 */
BookList& BookList::operator=(const BookList &btCopy) {
    if (this != &btCopy) {

        // Deallocate memory
        delete [] this ->bookArray;

        // Assign capacity and count from btCopy
        this->capacity = btCopy.capacity;
        this->count = btCopy.count;

        // Allocate memory with new capacity
        this->bookArray = new Book[capacity];

        // Copy element from btCopy
        for (int value = 0; value < count; ++value)
            this->bookArray[value] = btCopy.bookArray[value];
    }
    // Return this
    return *this;
}

/// Adds books to the list
int BookList::addBook(std::string isbn, std::string author, std::string title,
                      std::string year) {
    // Checks if the size is at max
    if(count>=capacity)
        resize();

    // Creates a book data for book added to the booklist
    Book newBook = {std::move(isbn), std::move(author),
                    std::move(title), std::move(year)};

    // adds new book and increase the count
    bookArray[count++] = newBook;

    // Returns the index
    return count -1;

}

/// Finds a book in the  list using ISBN
int BookList::findISBN(const std::string& isbn) const {
    // Loop through the list to find book
    for (int value=0; value<count; ++value){
        if (bookArray[value].isbn == isbn)
            return value;
    }
    // -1 if book is not found
    return -1;
}

/// Returns a string info for book to print
std::string BookList::getBook(int bookID) const {
    // gets book from bookArray
    Book myBook = bookArray[bookID];

    // Concats the books properties to string
    std::string book = myBook.isbn + ", " + myBook.author + ", " + myBook.title +
            ", " + myBook.year;

    // returns string to print
    return book;
}

/// returns count for the books
int BookList::size() const { return count; }

/// returns the capacity of the array
int BookList::getCapacity() const { return capacity; }

void BookList::resize() {
    // update capacity
    capacity *=2;

    // Create temp array with new capacity
    Book *temp = new Book[capacity];

    // copy old values to temp array
    for (int value = 0; value < count; ++value)
        temp[value] = bookArray[value];

    // delete old array
    delete [] bookArray;

    // Re-assigns old array to new array
    bookArray = temp;
}

