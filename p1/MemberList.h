//
// Created by Uchenna on 4/20/22.
//

#ifndef SRC_MEMBERLIST_H
#define SRC_MEMBERLIST_H

#include <string>

/**
 * MemberList class holds a list of current members.
 * Members are uniquely identified by a member ID.
 */
class MemberList {
public:
    /// Constructor
    MemberList();

    /// Destructor
    ~MemberList();

    /**
     * Copy constructor
     * @param other Member to copy
     */
    MemberList(const MemberList &other);

    /**
     * Overloaded Assignment operator
     * @param rightSide MemberList object to copy
     * @return myself
     */
    MemberList &operator = (const MemberList &rightSide);

    /**
     * Adds a new member
     * @param member name of member to add
     * @return memberID for the new member
     */
    int addMember (std::string member);

    /**
     * Gets the name of the a given member by memberID
     * @param memberID ID of the member
     * @return name of the member
     */
    std::string findName(int memberID) const;

    /**
     * Login to account
     * @param memberID to login
     * @return true if member exist
     */
    bool login(int memberID);

    /**
     * Logout of account
     * @param memberID to logout
     * @return true if logged out
     */
    bool logout(int memberID);

    /**
     * get the cardinality of the list
     * @return count of add
     */
    int size() const;



private:
    static const int CAPACITY = 25;
    struct MemberInfo {
        int account;
        std::string name;
        bool loggedIn;
    };
    MemberInfo *memberArray;
    int count;
    int capacity;

    // Function to double the size of the array if its full
    void resize();

};

#endif //SRC_MEMBERLIST_H
