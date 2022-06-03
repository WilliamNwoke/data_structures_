#ifndef P3_BST_H
#define P3_BST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

template<class T>
class BST {
public:
    BST();

    ~BST();

    BST(const BST<T> &other);

    BST<T> &operator=(const BST<T> &rhs);

    void insert(const T &key);

    bool contains(const T &key) const;

    void remove(const T &key);

    bool empty() const;

    int size() const;

    int getLeafCount() const;

    int getHeight() const;

    std::string getInOrderTraversal() const;


    std::string getPreOrderTraversal() const;


    std::string getPostOrderTraversal() const;

    std::string getAncestor( );
private:
    struct Node {
        T key;
        Node *left;
        Node *right;

        // convenience ctor
        explicit Node(const T &newKey, Node *lch = nullptr, Node *rch = nullptr) {
            key = newKey;
            left = lch;
            right = rch;
        }

        /**
         * Find the maximum node's value.
         *
         * @return  key of the right-most node in this subtree
         */
        T findMax() const;

        /**
         * Determine if this node is a leaf
         *
         * @return true if this node is a leaf, false otherwise
         */
        bool isLeaf() const;
    };

    Node *root;

    /**
     * Recursive helper method for contains.
     * @param me   sub-BST in which to look for key
     * @param key  key to search for
     * @return     true if found, false otherwise
     */
    static bool contains(Node *me, const T &key);

    /**
     * Recursive helper method for insert.
     * @param me      sub-BST to which to insert key
     * @param newKey  key to insert
     * @return        me, or if me is nullptr, the new Node with newKey
     */
    static Node *insert(Node *me, const T &newKey);

    /**
     * Recursive helper method for remove.
     * @param me   sub-BST from which to remove key
     * @param key  key to remove
     * @return     me, or my replacement if I get deleted (could be nullptr
     *             if I'm it and also a leaf)
     */
    static Node *remove(Node *me, const T &key);

    /**
     * Recursive helper method to delete a subtree.
     * @param me the root of the subtree to delete
     */
    static void clear(Node *me);

    /**
     * Recursive helper method to copy a subtree.
     * @param me the root of the subtree to copy
     * @return   a fresh copy of the subtree
     */
    static Node *copy(Node *me);

    /**
     * Recursive helper method for size.
     * @param me   sub-BST in which to count size
     * @return     int size of the tree
     */
    static int size(Node *me);

    /**
     * Recursive helper method for getLeafCount.
     * @param me   sub-BST in which to count leaves
     * @return     int number of leaves in the tree
     */
    static int getLeafCount(Node *me);

    /**
     * Recursive helper method for getHeight.
     * @param me   sub-BST in which to count height
     * @return     int height of the tree
     */
    static int getHeight(Node *me);

    /**
     * Recursive helper method for getInOrderTraversal.
     * @param me  sub-BST in which to traverse
     * @param ss  a stringstream that contains the result
     * @return    string representation of in-order set
     */
    static void getInOrderTraversal(Node *me, std::stringstream &ss);

    /**
     * Recursive helper method for getPreOrderTraversal.
     * @param me  sub-BST in which to traverse
     * @param ss  a stringstream that contains the result
     * @return    string representation of in-order set
     */
    static void getPreOrderTraversal(Node *me, std::stringstream &ss);

    /**
     * Recursive helper method for getPostOrderTraversal.
     * @param me  sub-BST in which to traverse
     * @param ss  a stringstream that contains the result
     * @return    string representation of in-order set
     */
    static void getPostOrderTraversal(Node *me, std::stringstream &ss);

    static int getLevel(const T &key);

    static std::string getAncestors(const T &key);



};

template <class T>
BST<T>::BST() : root(nullptr) {}

template <class T>
BST<T>::~BST<T>() {
    clear(root);
}

template <class T>
BST<T>::BST(const BST<T> &other) {
    root = copy(other.root);
}

template <class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    if (this != &rhs) {
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

template <class T>
bool BST<T>::contains(const T &key) const {
    return contains(root, key);
}

template <class T>
void BST<T>::insert(const T &newKey) {
    root = insert(root, newKey);
}

template <class T>
void BST<T>::remove(const T &key) {
    root = remove(root, key);
}

template <class T>
T BST<T>::Node::findMax() const {
    if (right == nullptr)
        return this->key;
    else
        return right->findMax();
}

template <class T>
bool BST<T>::Node::isLeaf() const {
    if (left == nullptr && right == nullptr)
        return true;
    else
        return false;
}

template <class T>
bool BST<T>::contains(Node *me, const T &key) {
    if (me == nullptr)
        return false; // not found
    if (key < me->key)
        return contains(me->left, key);
    else if (key > me->key)
        return contains(me->right, key);
    else  // key == me->key
        return true;
}

template <class T>
typename BST<T>::Node *BST<T>::insert(Node *me, const T &newKey) {
    if (me == nullptr)
        me = new Node(newKey);
    else if (newKey < me->key)
        me->left = insert(me->left, newKey);
    else if (newKey > me->key)
        me->right = insert(me->right, newKey);
    // else do nothing since newKey is already in the set
    return me;
}

template <class T>
typename BST<T>::Node *BST<T>::remove(Node *me, const T &key) {
    if (me == nullptr)
        return nullptr; // key is not in the BST so nothing to do nothing

    if (key < me->key) {
        // recurse down the left, possibly changing its root
        me->left = remove(me->left, key);
        return me;  // no change to me

    } else if (key > me->key) {
        // recurse down the right, possibly changing its root
        me->right = remove(me->right, key);
        return me;  // no change to me

    } else {
        // FOUND IT. key == rootlet.key, so remove this one
        if (me->left == nullptr) {
            Node *myReplacement = me->right;
            delete me;
            return myReplacement;

        } else if (me->right == nullptr) {
            // In this case the left subtree should just be elevated
            // to replace me; and delete me, too
            Node *myReplacement = me->left;
            delete me;
            return myReplacement;

        } else {
            // In this case there are nodes to both my right and left
            // so I have to do something more clever!
            // Here we just swap with predecessor node
            // which is the max value from left (equally could use
            // successor node: min value from right)
            me->key = me->left->findMax();
            // and then remove the node that had the predecessor
            me->left = remove(me->left, me->key);
            return me;
        }
    }
}

template <class T>
void BST<T>::clear(BST<T>::Node *me) {
    if (me != nullptr) {
        clear(me->left);
        clear(me->right);
        delete me;
    }
}

template <class T>
typename BST<T>::Node *BST<T>::copy(BST<T>::Node *me) {
    if (me == nullptr)
        return nullptr; // nothing to do
    else
        return new Node(me->key, copy(me->left), copy(me->right));
}

template <class T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <class T>
int BST<T>::size() const {
    return size(root);
}

template <class T>
int BST<T>::getLeafCount() const {
    return getLeafCount(root);
}

template<class T>
int BST<T>::getHeight() const {
    return getHeight(root);
}

template <class T>
int BST<T>::size(BST<T>::Node *me) {
    if (me == nullptr)
        return 0;
    else
        return 1 + size(me->left) + size(me->right);
}

template <class T>
int BST<T>::getLeafCount(BST<T>::Node *me) {
    if (me == nullptr)
        return 0;
    else if (me->isLeaf())
        return 1;
    else
        return getLeafCount(me->left) + getLeafCount(me->right);
}

template<class T>
int BST<T>::getHeight(BST::Node *me) {
    if (me == nullptr)
        return 0;
    else
        return 1 + std::max(getHeight(me->left), getHeight(me->right));
}

template<class T>
std::string BST<T>::getInOrderTraversal() const {
    std::stringstream ss;
    getInOrderTraversal(root, ss);
    return ss.str();
}

template<class T>
void BST<T>::getInOrderTraversal(BST::Node *me, std::stringstream &ss) {
    if (me != nullptr) {
        getInOrderTraversal(me->left, ss);
        ss << me->key << " ";
        getInOrderTraversal(me->right, ss);
    }
    else
        return;
}

template<class T>
std::string BST<T>::getPreOrderTraversal() const {
    std::stringstream ss;
    getPreOrderTraversal(root, ss);
    return ss.str();
}

template<class T>
void BST<T>::getPreOrderTraversal(BST::Node *me, std::stringstream &ss) {
    if (me != nullptr) {
        ss << me->key << " ";
        getPreOrderTraversal(me->left, ss);
        getPreOrderTraversal(me->right, ss);
    }
    else
        return;
}

template<class T>
std::string BST<T>::getPostOrderTraversal() const {
    std::stringstream ss;
    getPostOrderTraversal(root, ss);
    return ss.str();
}

template<class T>
void BST<T>::getPostOrderTraversal(BST::Node *me, std::stringstream &ss) {
    if (me != nullptr) {
        getPostOrderTraversal(me->left, ss);
        getPostOrderTraversal(me->right, ss);
        ss << me->key << " ";
    }
    else
        return;
}


template <typename T>
std::string BST<T>::getAncestors(T item) {

    //Create a stringstream
    std::stringstream ancestorString;

    //Call the helper method getAncestors
    return getAncestors(root, item, ancestorString);
}


template <typename T>
string BST<T>::getAncestors(Node *& ptr, T item, stringstream &
ancestorString) {

    //Check if the item is in the tree before trying to get the ancestor
    if(contains(item)) {

        //Return the string of where it currently is. If it is the first
        // node, it is an empty string. Add the ancestorString as more and
        // more nodes are traversed. getAncestors is called recursively.
        if (ptr->data == item) {
            return ancestorString.str();
        } else if (ptr->data < item) {
            getAncestors(ptr->right, item, ancestorString);
            ancestorString << ptr->data << " ";
            return ancestorString.str();

        } else if (ptr->data > item) {
            getAncestors(ptr->left, item, ancestorString);
            ancestorString << ptr->data << " ";
            return ancestorString.str();
        }
    }

    //Catch all that will return empty string if the node doesn't exist
    return "";


}



template<class T>
int BST<T>::getLevel(const T &key) {
    std::stringstream ss;
    int lev{};
    if(contains(key)){
        return lev;
    } else {
        return -1;
    }
}




#endif //P3_BST_H