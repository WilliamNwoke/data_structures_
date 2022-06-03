//
// Created by Uchenna on 4/20/22.
//

#ifndef SRC_RATINGLIST_H
#define SRC_RATINGLIST_H

/**
 * Holds the list of ratings for all the books for all members indexed by bookID
 * and memberID
 */
class RatingList {
public:
    /**
     * Constructor
     * @param initialBookCapacity
     */
    RatingList(int initialBookCapacity);

    /**
     * Destructor
     */
    ~RatingList();

    /**
     * Copy constructor
     * @param other Ratings to copy
     */
    RatingList (const RatingList &other);

    /**
     * Overloaded equals operator
     * @param rightSide Ratings from the RatingList we want to copy
     * @return myself
     */
    RatingList &operator = (const RatingList &rightSide);

    /**
     * Adds a rating to a book
     * @param memberID Members ID
     * @param bookID Book to rate
     * @param rating rating of the book
     */
    void addRating(int memberID, int bookID, int rating);

    /**
     * returns the rating of a book to requesting member
     * @param memberID members ID
     * @param bookID book ID to get the book
     * @return rating of the book
     */
    int getRating(int memberID, int bookID);

    /**
     * Recommended books from other ratings
     * @param memberID ID of the member
     * @return id of the most similar or your ID if there is none
     */
    int similar(int memberID);

private:
    const static int INITIAL_MEMBER_CAPACITY =20;
    int **ratingArray;
    int memberCapacity;
    int bookCapacity;

    /**
     * Function to enlarge bookCapacity is books max out
     */
    void resizeColumn();

    /**
     * Function to enlarge room for members if it fills up
     */
    void resizeRow();

    /**
     * Function to deallocate memory of the 2D dynamic array
     */
    void clear();

};

#endif //SRC_RATINGLIST_H
