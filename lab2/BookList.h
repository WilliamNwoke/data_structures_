//
// Created by Uchenna on 4/8/22.
//

#ifndef SRC_BOOKLIST_H
#define SRC_BOOKLIST_H
#include <string>


/**
 * The BookList object holds a list of book structs.
 *
 */
class BookList {
public:
    /**
     * Constructor
     */
    BookList();

    /**
     * Destructor
     */
    ~BookList();

    /**
     * Copy constructor
     * @param copiedBook Book to copy
     */
    BookList(const BookList &);

    /**
     * Assignment operator
     * @param btCopy book to copy
     * @return self/this
     */
    BookList& operator=(const BookList &btCopy);

    /**
     * Adds a book to the list
     * @param isbn of book
     * @param author of book
     * @param title of book
     * @param year of book
     * @return Id of the book
     */
    int addBook(std::string isbn, std::string author,
                std::string title, std::string year);

    /**
     * Finds a book in the book list
     * @param isbn of book
     * @return bookID of the book or -1
     */
    int findISBN(const std::string& isbn) const;

    /**
     * returns book from the array
     * @param bookID
     * @return string to print out
     */
    std::string getBook(int bookID) const;

    /**
     * gets the size of books
     * @return size of books
     */
    int size() const;

    /**
     * returns the current size of the array
     * @return size of array
     */
    int getCapacity() const;

private:
    // Initial size of the array
    static const int CAPACITY = 50;
    struct Book {
        std::string isbn;
        std::string author;
        std::string title;
        std::string year;
    };
    Book *bookArray;
    int count;
    int capacity;

    /**
     * Increases the size of the array should it max out.
     */
    void resize();

};

#endif //SRC_BOOKLIST_H
