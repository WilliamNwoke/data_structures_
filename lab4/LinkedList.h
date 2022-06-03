//
// Created by Uchenna on 4/30/22.
//

#ifndef SRC_LINKEDLIST_H
#define SRC_LINKEDLIST_H


#include <string>
#include <sstream>

template<class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void appendNode(T);
    std::string to_string() const;

    // void add(const T &data, const std::string &payload);

    /**
     * Returns the last negative value contained in the list
     * @precon the list must contain at least one negative value
     * @return the last negative value of type T
     */
    T getLastNegative() const;

private:
    struct Node {
        T data;  // T is the template argument
        Node *next;
    };
    Node *head;

    void clear();

    /**
     * Recursive helper function for getLastNegative()
     * @param me     current list element
     * @param result a T variable to store a result if found
     * @return       the T value of the last negative element in the list
     */
    static T getLastNegative(Node *me, T result);
};



template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <class T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}


template <class T> void LinkedList<T>::appendNode(T data) {
    Node * curr;
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
        head = newNode;
    else {
        curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode;
    }

}

template <class T>
std::string LinkedList<T>::to_string() const {
    std::stringstream ss;
    Node * curr = head;
    while (curr != nullptr) {
        ss << curr->data << " ";
        curr = curr->next;
    }
    ss << "\n";
    return ss.str();
}


template <class T>
T LinkedList<T>::getLastNegative() const {
    T result = 0;
    return getLastNegative(head, result);
}

template <class T>
T LinkedList<T>::getLastNegative(Node *me, T result) {
    if (me == nullptr)
        return result;
    else if (me->data < 0)
        result = me->data;
    return getLastNegative(me->next, result);
}


#endif //SRC_LINKEDLIST_H