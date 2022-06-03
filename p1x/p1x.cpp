//
// Created by Uchenna on 4/21/22.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"

/**
 * Initial options to pick from when you launch the application
 * @return an integer between 1 - 4
 */
static int firstScreen();

/**
 * displays opening menu
 * and controls choices
 * @param b BookList object containing BookList
 * @param m MemberList object containing MemberList
 * @param r RatingList object containing RatingList
 */
static void startingDriver(BookList &b, MemberList &m, RatingList &r);

/**
 * Driver of the program handles a user to logged in
 * displays logged in menu and controls choices
 * @param b BookList object containing book data
 * @param m MemberList object containing member data
 * @param r RatingList object containing rating data
 * @param memberId the member iD of the logged in user
 * @param the choice made from the logged in menu
 */
static void signInDriver(BookList &b, MemberList &m, RatingList &r,
                           int memberId, int choice);

/**
 * Displays the menu for a logged in user lets them make a choice
 * of options
 * @param b BookList object containing book data
 * @param m MemberList object containing member data
 * @param r RatingList object containing rating data
 * @return integer choice made from the menu
 */
static int loggedInScreen(BookList &b, MemberList &m, RatingList &r);

/**
 * Method that asks a user for their member id and logs them in
 * @param m Member object containing member data
 * @return the member id of the logged in member
 */
static int memberLogin(MemberList &m);

/**
 * Logs a user out
 * @param m Member object containing member data
 * @param memberId of the user to be logged out
 */
static void memberLogout(MemberList &m, int memberId);

/**
 * Method than asks for info of a new member and adds them to the
 * member object
 * @param m Member object containing member data
 */
static void addMember(MemberList &m);

/**
 * Method than asks for info of a new book and adds it to the
 * BookList object
 * @param b BookList object containing book data
 */
static void addBook(BookList &b);

/**
 * Method that displays all of a user's book ratings
 * @param b BookList object containing book data
 * @param m MemberList object containing member data
 * @param r RatingList object containing rating data
 * @param memberId of the user who's ratings will be displayed
 */
static void displayUserRatings(BookList &b, MemberList &m,
                               RatingList &r, int memberId);

/**
 * Method to find a user's most similar member, display their name,
 * and display the most similar member's liked and really liked books
 * @param b BookList object containing book data
 * @param m MemberList object containing member data
 * @param r RatingList object containing rating data
 * @param memberId of the user who's recommendations are to be found
 */
static void displayRecommendations(BookList &b, MemberList &m,
                                   RatingList &r, int memberId);

/**
 * Method to allow a user to rate or re-rate a book
 * @param b BookList object containing book data
 * @param m MemberList object containing member data
 * @param r RatingList object containing rating data
 * @param memberId of the user who will rate a book
 */
static void rateBook(BookList &b, MemberList &m, RatingList &r, int memberId);

/**
 * Method that displays the application's goodbye message
 */
static void exitProgram();

/**
 * Function to load all books from a file and store them in a passed-in
 * BookList object
 * @param fileName - name of the file containing book info
 * @param book - address of a BookList object
 */
void loadBooks(const std::string &fileName, BookList &book) ;

/**
 * This function will load data from a member-rating file.
 * File needs to be formatted as such:
*     Member name
*     List of space separated ratings (i.e. 0 3 4 3 2 1)
 * @param fileName - name of the file containing member and rating data
 * @param member - address of a Member object
 * @param rating - address of a Rating object
 */
void loadMemberRatingData(const std::string &fileName, MemberList &member,
                          RatingList &rating);


/**
 * Function to write all book, member, and rating data to a file
 * @param b Book object containing book data
 * @param m Member object containing member data
 * @param r rating object containing rating data
 */
void writeDataToFile(BookList &b, MemberList &m, RatingList &r);
/**
 * Main function of the program. gets the file from a user
 * @return 0 if the program runs with no errors
 */
int main() {
    BookList b;
    MemberList m;
    RatingList r(30);

    std::ifstream inFile;
    std::string bookFile = "../books-updated.txt";
    std::string ratingsFile = "../ratings-updated.txt";

    inFile.open(bookFile);
    if (!inFile){
        std::cout << "Please enter the name of a book file: ";
        std::cin >> bookFile;
    }
    inFile.clear();
    inFile.open(ratingsFile);
    if (!inFile){
        std::cout << "Please enter the name of a ratings file: ";
        std::cin >> ratingsFile;
    }


    // Load books and rating file
    loadBooks(bookFile, b);
    loadMemberRatingData(ratingsFile, m, r);

    // Starts the program
    startingDriver(b, m, r);
    writeDataToFile(b,m,r);

    return 0;
}


void loadBooks(const std::string &fileName, BookList &book) {
    auto *currentBook = new std::string[4];
    int isbn = 1;

    std::string filepath = "../" + fileName;
    std::string bookLine;
    std::ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        // Proceed while lines are being read from file
        while (getline(inFile, bookLine)) {
            std::istringstream ss(bookLine);

            // Add the isbn as the position in the list
            // The isbn being index + 1 is an implementation decision
            currentBook[0] = std::to_string(isbn++);

            // Add the author, title, and year to currentBook
            // in positions 1, 2, 3.
            int i = 0;
            std::string bookInfo;
            while (getline(ss, bookInfo, ',')) {
                currentBook[++i] = bookInfo;
            }

            // Add the book to the list the Book's list
            book.addBook(currentBook[0], currentBook[1],
                         currentBook[2], currentBook[3]);
        }
    } else {
        // File name was invalid, exit application
        std::cout << "ERROR: cannot open file";
        return;
    }

    // Perform cleanup
    inFile.close();
    delete[] currentBook;
}

void loadMemberRatingData(const std::string &fileName, MemberList &member,
                          RatingList &rating) {

    // numMembers will keep track of memberId's
    int numMembers = 0;
    int numBooks;
    std::string filepath = "../" + fileName;

    std::string name;
    std::string memberRatings;
    std::ifstream inFile;

    // Attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        // Proceed while lines are being read from file
        while (getline(inFile, name)) {
            member.addMember(name);

            // After a name is read, next line is the member's book ratings
            if (getline(inFile, memberRatings)) {
                std::istringstream ss(memberRatings);
                numBooks = -1;

                // While there is data in the input stream
                while (ss) {
                    int currRating;
                    ss >> currRating;
                    // Assign the rating to the associated member's
                    // rating array
                    rating.addRating(numMembers, ++numBooks, currRating);
                }
            }
            numMembers++;
        }
    } else {
        // Filepath was invalid, exit application
        std::cout << "ERROR: cannot open file";
        return;
    }

    std::cout << "# of books: " << numBooks << std::endl;
    std::cout << "# of members: " << numMembers << std::endl;
    std::cout << std::endl;

    // Perform cleanup
    inFile.close();
}

int firstScreen() {
    std::cout << "************** MENU **************" << std::endl;
    std::cout << "* 1. Add a new member            *" << std::endl;
    std:: cout << "* 2. Add a new book              *" << std::endl;
    std::cout << "* 3. Login                       *" << std::endl;
    std::cout << "* 4. Quit                        *" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << std::endl;

    // Get user choice
    int response;
    std::cout << "Enter a menu option: ";
    std::cin >> response;

    // Do not allow invalid choices
    while (response < 1 || response > 4) {
        std::cout << "That is not a valid selection. ";
        std::cout << "Please enter a menu option: ";
        std::cin >> response;
    }

    std::cout << std::endl;
    return response;
}


void startingDriver(BookList &b, MemberList &m, RatingList &r) {
    int memberId;
    int choice;
    std::ofstream outdata;
    switch (firstScreen()) {
        case 1:
            addMember(m);
            startingDriver(b, m, r);
            break;
        case 2:
            addBook(b);
            startingDriver(b, m, r);
            break;
        case 3:
            memberId = memberLogin(m);
            choice = loggedInScreen(b, m, r);
            signInDriver(b, m, r, memberId, choice);
            break;
        case 4:
            outdata.open("books-updated.txt");
            exitProgram();
            return;
    }
}

void signInDriver(BookList &b, MemberList &m, RatingList &r, int memberId, int choice) {
    switch (choice) {
        case 1:
            addMember(m);
            choice = loggedInScreen(b, m, r);
            signInDriver(b, m, r, memberId, choice);
            break;
        case 2:
            addBook(b);
            choice = loggedInScreen(b, m, r);
            signInDriver(b, m, r, memberId, choice);
            break;
        case 3:
            rateBook(b, m, r, memberId);
            choice = loggedInScreen(b, m, r);
            signInDriver(b, m, r, memberId, choice);
            break;
        case 4:
            displayUserRatings(b, m, r, memberId);
            choice = loggedInScreen(b, m, r);
            signInDriver(b, m, r, memberId, choice);
            break;
        case 5:
            displayRecommendations(b, m, r, memberId);
            choice = loggedInScreen(b, m, r);
            signInDriver(b, m, r, memberId, choice);
            break;
        default:
            memberLogout(m, memberId);
            startingDriver(b, m, r);
    }
}

int loggedInScreen(BookList &b, MemberList &m, RatingList &r) {
    std::cout << "************** MENU **************" << std::endl;
    std::cout << "* 1. Add a new member            *" << std::endl;
    std::cout << "* 2. Add a new book              *" << std::endl;
    std::cout << "* 3. Rate a book                 *" << std::endl;
    std::cout << "* 4. View ratings                *" << std::endl;
    std::cout << "* 5. See recommendations         *" << std::endl;
    std::cout << "* 6. Logout                      *" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << std::endl;

    // Get user choice
    int response;
    std::cout << "Enter a menu option: ";
    std::cin >> response;

    // Do not allow invalid choices
    while (response < 1 || response > 6) {
        std::cout << "That is not a valid selection. ";
        std::cout << "Please enter a menu option: ";
        std::cin >> response;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return response;
}

int memberLogin(MemberList &m) {
    int memberId;

    // Get users member Id
    std::cout << "Enter member account: ";
    std::cin >> memberId;
    std::cout << std::endl;

    // Do not allow invalid member id
    while (memberId >= m.size()) {
        std::cout << "That is not a valid member Id. ";
        std::cout << "Please enter the correct id: ";
        std::cin >> memberId;
        std::cout << std::endl;
    }

    // Log the user in and notify
    m.login(memberId);
    std::cout << m.findName(memberId) << ", you are logged in!" << std::endl;
    std::cout << std::endl;

    return memberId;
}


void memberLogout(MemberList &m, int memberId) {
    // Log user out
    m.logout(memberId);
    std::cout << std::endl;
}

void addMember(MemberList &m) {

    // Get new member name
    std::string newName;
    std::cout << "Enter the name of the new member :";
    std::cin >> newName;

    // Add member to Member object
    int memberId = m.addMember(newName);

    // Notify user than new member has been added
    std::cout << m.findName(memberId);
    std::cout << " (member Id: " << memberId;
    std::cout << ") was added." << std::endl;
    std::cout <<std::endl;
}

void addBook(BookList &b) {
    std::string author;
    std::string title;
    std::string year;

    // set isbn
    std::string isbn = std::to_string(b.size() + 1);

    // Remove the hanging newline character
    std::cin.get();

    // Get info about new book
    std::cout << "Enter the author of the new book: ";
    getline(std::cin, author);

    std::cout << "Enter the title of the new book: ";
    getline(std::cin, title);

    std::cout << "Enter the year (or range of years) of the new book: ";
    getline(std::cin, year);
    std::cout << std::endl;

    // Add book to Book object
    b.addBook(isbn, author, title, year);

    // Newest book will always have a bookId(index) of one less than the size
    // Always the last item in the bookArrray
    std::cout << b.getBook(b.size() - 1);
    std::cout << " was added." << std::endl;
    std::cout << std::endl;
}

void displayUserRatings(BookList &b, MemberList &m, RatingList &r, int memberId) {
    // Displays the user ratings
    std::cout << m.findName(memberId) << "'s ratings..." << std::endl;

    for (int i = 0; i < b.size(); ++i) {
        std::cout << b.getBook(i);
        std::cout << " => rating: " << r.getRating(memberId, i);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void displayRecommendations(BookList &b, MemberList &m, RatingList &r, int memberId) {

    // Get most similar member
    int mostSimilar = r.similar(memberId);

    // Notify user of their most similar member
    std::cout << "You have similar taste in books as ";
    std::cout << m.findName(mostSimilar) << "!" << std::endl;
    std::cout << std::endl;

    // Display mostSimilar's books with rating of 5
    std::cout << "Here are the books they really liked:" << std::endl;
    for (int i = 0; i < b.size(); ++i) {
        if (r.getRating(mostSimilar, i) == 5) {
            std::cout << b.getBook(i);
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    // Display mostSimilar's books with rating of 3
    std::cout << "And here are the books they liked:" << std::endl;
    for (int i = 0; i < b.size(); ++i) {
        if (r.getRating(mostSimilar, i) == 3) {
            std::cout << b.getBook(i);
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void rateBook(BookList &b, MemberList &m, RatingList &r, int memberId) {

    // Get isbn
    int isbn;
    std::cout << "Enter the ISBN for the book you'd like to rate: ";
    std::cin >> isbn;

    // Isbn == (index in bookArray) + 1
    while (isbn < 1 || isbn > b.size()) {
        std::cout << "That is an invalid isbn.  Please enter an ISBN: ";
        std::cin >> isbn;
    }
    std::cout << "\n";

    // Get the book id from the isbn
    int bookId = b.findISBN(std::to_string(isbn));

    // Check if the book has already been rated
    if (r.getRating(memberId, bookId) != 0) {
        std::cout << "Your current rating for ";
        std::cout << b.getBook(bookId);
        std::cout << " => rating: " << r.getRating(memberId, bookId) << std::endl;

        std::cout << "Would you like to re-rate this book (y/n)? ";
        std::string reRate;
        std::cin >> reRate;

        // Require y or n response
        while (reRate != "y" && reRate != "n") {
            std::cout << "Please enter (y/n): ";
            std::cin >> reRate;
        }

        // Exit if response is 'n'
        if (reRate == "n") {
            std::cout << std::endl;
            return;
        }
    }

    // Let user rate the book
    int rating;
    std::cout << "Enter your rating: ";
    std::cin >> rating;
    std::cout << std::endl;

    // Require valid rating
    while (
            rating != -5 &&
            rating != -3 &&
            rating != 3 &&
            rating != 5 &&
            rating != 1
            ) {
        std::cout << "    ____ ______________________" << std::endl;
        std::cout << "   | -5 | Hated it!            |" << std::endl;
        std::cout << "   | -3 | Didn't like it       |" << std::endl;
        std::cout << "   |  1 | neither hot nor cold |" << std::endl;
        std::cout << "   |  3 | Liked it!            |" << std::endl;
        std::cout << "   |  5 | Really liked it!     |" << std::endl;
        std::cout << "    ---------------------------" << std::endl;
        std::cout << "Please enter a valid rating: " << std::endl;
        std::cin >> rating;
        std::cout << std::endl;
    }

    // Display the user's book and rating
    r.addRating(memberId, bookId, rating);
    std::cout << "Your new rating for ";
    std::cout << b.getBook(bookId);
    std::cout << " => rating: " << rating << std::endl;

    std::cout << std::endl;
}


void writeDataToFile(BookList &b, MemberList &m, RatingList &r) {
    std::string bookFile = "../books-updated.txt";
    std::string ratingsFile = "../ratings-updated.txt";

    std::ofstream updatedBooks;
    std::ofstream updatedRatings;

    updatedBooks.open(bookFile);
    updatedRatings.open(ratingsFile);

    if (updatedBooks) {
        for (int i = 0; i < b.size(); ++i) {
            updatedBooks << b.getBookString(i) + "\n";
        }
    } else {
        // Filepath was invalid, exit application
        std::cout << "ERROR: cannot open/create updated book file";
        return;
    }

    if (updatedRatings) {
        for (int i = 0; i < m.size(); ++i) {
            updatedRatings << m.findName(i) + "\n";
            for (int j = 0; j < b.size(); ++j) {
                updatedRatings << std::to_string(r.getRating(i, j)) + " ";
            }
            updatedRatings << "\n";
        }
    } else {
        // Filepath was invalid, exit application
        std::cout << "ERROR: cannot open/create updated book file";
        return;
    }

    // Cleanup
    updatedBooks.close();
    updatedRatings.close();
}

void exitProgram() {
    std::cout << "Thank you for using the Book Recommendation Program!"
              << std::endl;
}