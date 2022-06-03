#ifndef L4_LINKEDLIST_H
#define L4_LINKEDLIST_H

#include <string>

template<class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &other);
    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    void add(const T &key, const std::string &payload);

    /**
     * Returns the last negative value contained in the list
     * @precon the list must contain at least one negative value
     * @return the last negative value of type T
     */
    T getLastNegative() const;

private:
    struct ListElem {
        T key;  // T is the template argument
        std::string payload;
        ListElem *next;

        // convenience ctor
        ListElem(T k, std::string p, ListElem *n) {
            key = k;
            payload = p;
            next = n;
        }
    };
    ListElem *head;

    void clear();
    static ListElem *copy(ListElem *headToCopy);

    /**
     * Recursive helper function for getLastNegative()
     * @param me     current list element
     * @param result a T variable to store a result if found
     * @return       the T value of the last negative element in the list
     */
    static T getLastNegative(ListElem *me, T result);
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
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
    head = copy(other.head);
}

template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    if (&rhs != this) {
        clear();
        head = copy(rhs.head);
    }
    return *this;
}

template <class T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        ListElem *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

template <class T>
typename LinkedList<T>::ListElem *LinkedList<T>::
copy(LinkedList::ListElem *headToCopy) {
    ListElem anchor(0, "", nullptr), *source, *tail;
    tail = &anchor;
    for (source = headToCopy; source != nullptr; source = source->next) {
        tail->next = new ListElem(source->key, source->payload, nullptr);
        tail = tail->next;
    }
    return anchor.next;
}

template <class T>
void LinkedList<T>::add(const T &key, const std::string &payload) {
    head = new ListElem(key, payload, head);
}

template <class T>
T LinkedList<T>::getLastNegative() const {
    T result = 0;
    return getLastNegative(head, result);
}

template <class T>
T LinkedList<T>::getLastNegative(ListElem *me, T result) {
    if (me == nullptr)
        return result;
    else if (me->key < 0)
        result = me->key;
    return getLastNegative(me->next, result);
}


#endif L4_LINKEDLIST_H