//
// Created by Uchenna on 4/20/22.
//

#include "MemberList.h"
#include <sstream>

MemberList::MemberList() {
    capacity = CAPACITY;
    count = 0;
    memberArray = new MemberInfo[capacity];
}

MemberList::~MemberList() {
    delete[] memberArray;
}

MemberList::MemberList(const MemberList &other) {
    // Copy elements
    capacity = other.capacity;
    count = other.count;

    // Allocate memory with new capacity
    memberArray = new MemberInfo[capacity];
    for (int index = 0; index < count; ++index)
        memberArray[index] = other.memberArray[index];

}

MemberList &MemberList::operator = (const MemberList &rightSide){
    if (this != &rightSide){
        // Deallocate memory
        delete[] this->memberArray;

        // Assign count and capacity from rightSide
        this->capacity = rightSide.capacity;
        this->count = rightSide.count;

        // Allocate memory and copy over elements
        this->memberArray = new MemberInfo[capacity];
        for (int index =0; index < count; ++index)
            this->memberArray[index] = rightSide.memberArray[index];


    }
    // return myself
    return *this;
}

int MemberList::addMember(std::string accountName) {
    // Checks if we need resize
    if (count >= capacity)
        resize();

    // create a new Member
    MemberInfo newMember = {count + 1000, accountName, false};

    memberArray[count++] = newMember;

    // return the member ID
    return count -1;
}

std::string MemberList::findName(int memberID) const {
    // checks and returns member if exist
    if (memberID < count && memberID >=0)
        return memberArray[memberID].name;

    // Empty if member doesn't exist
    return "No such member";
}

bool MemberList::login(int memberID){
    // Checks if the user exist and returns true
    if (memberID < count && memberID >= 0){
        memberArray[memberID].loggedIn = true;
        return true;

    }
    return false;
}

bool MemberList::logout(int memberID) {
    // Check if the user is exist and return true
    if (memberID < count && memberID >= 0) {
        memberArray[memberID].loggedIn = false;
        return true;
    }
    return false;
}


int MemberList::size() const {
    return count;
}

void MemberList::resize() {
    // Double the capacity
    capacity *= 2;
    // Create a temp array with new capacity
    auto *temp = new MemberInfo[capacity];

    // Copy old elements to temp
    for (int i = 0; i < count; ++i)
        temp[i] = memberArray[i];

    // Deallocate old member Array
    delete[] memberArray;

    // Reassign old array to new
    memberArray = temp;
}