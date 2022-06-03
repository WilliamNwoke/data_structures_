// Name: Uchenna
//The header file and the implementation of the BSTx class. Contains the
// framework to create a BSTx and methods for BSTx functionalities.
#ifndef SRC_BSTX_H
#define SRC_BSTX_H

#include <sstream>
#include <string>
#include <queue>


template <typename T>
class BSTx {

public:
    BSTx() {

        //Set the root node to nullptr.
        root = nullptr;

    }

    ~BSTx() {

        //Calls the destroyTree method to destroy the whole entire tree.
        destroyTree(root);
    }


    BSTx(const BSTx<T> &rhs) {

        //Set the new tree root to nullptr
        root = nullptr;

        //Copy the information from one to this new tree
        copyTree(root, rhs.root);

    }

    BSTx<T>& operator=(const BSTx &rhs){

        //Checks if this object is the same as the other object that is on the
        // other side of the operator
        if(this != &rhs) {

            //If it is delete the current tree
            destroyTree(root);

            //Then create a new tree and point the root pointer at the new copied
            // tree
            copyTree(root, rhs.root);
        }

        //Return the pointer of the now copied tree
        return * this;
    }

    void insert(T item) {

        //Creates a new node
        Node * newNode = new Node;

        //Stores the data as the inputted item
        newNode -> data = item;

        //Sets the left and right to nullptr
        newNode->left = newNode ->right = nullptr;

        //Calls the helper insert method
        insert(root, newNode);
    }

    bool contains(T item) {

        //Calls the helper function
        return contains(item, root);

    }


    void remove(T item) {

        //Checks to see if the item is in the tree
        if(contains(item)) {

            //If the item is in the tree, call the helper remove method
            remove(root, item);
        }
    }

    bool empty() {
        //If the root points to nullptr it means the tree is empty.
        if(root == nullptr) {
            return true;
        }
        return false;
    }

    int size() {

        //Initialize an int variable to be passed onto the helper function.
        int nodeCount = 0;

        //Calls the helper size method.
        return size(nodeCount, root);
    }

    int getLeafCount() {

        //Call the helper getLeafCount method
        return getLeafCount(root);
    }

    int getHeight() {

        //Call the helper getHeight method
        return getHeight(root);
    }

    int getLevel(T item){

        //Check first if the tree contains the item to get the level
        if(contains(item)) {

            //Call the helper getLevel method
            return getLevel(root, item, 0);
        }

        //Catch all for if the node is not present
        return -1;

    }

    std::string getPreOrderTraversal() {

        //Create a std::stringstream
        std::stringstream ss;

        //Call the helper method getPreOrderTraversal
        return getPreOrderTraversal(root, ss);
    }

    std::string getInOrderTraversal() {

        //Create a std::stringstream
        std::stringstream ss;

        //Call the helper method getInOrderTraversal
        return getInOrderTraversal(root,ss);
    }

    std::string getPostOrderTraversal() {

        //Create a std::stringstream
        std::stringstream ss;

        //Call the helper method getPostOrderTraversal
        return getPostOrderTraversal(root, ss);
    }

    std::string getAncestors(T item) {

        //Create a std::stringstream
        std::stringstream ancestorStr;

        //Call the helper method getAncestors
        return getAncestors(root, item, ancestorStr);
    }

    int getWidth() {

        //Call the get width function
        return getWidth(root);
    }

    std::string getLevelOrder() {

        //Initialize a stringstream object
        std::stringstream ss;

        //Calls the getLevelOrder helper function
        return getLevelOrder(root, ss);
    }


private:

    struct Node {
        T data;
        Node * left;
        Node * right;
    };
    Node * root;



    void insert(Node *& key, Node *& newNode) {

        // Anytime a key reaches a point where it is pointing to nothing, insert
        // the node there. Traverses the tree by comparing the data value and the
        // value of the new node to be inserted. If new node is less than
        // current key, then move to the left, otherwise, right.
        if (key == nullptr) {
            key = newNode;
        } else if (key->data > newNode->data) {
            insert(key->left, newNode);
        } else {
            insert(key->right, newNode);
        }
    }


    void remove(Node *& key, T item) {

        //Check if the key is not a null pointer, traverse through the tree by
        // comparing the current key data to that of the item. If it matches call
        // the make deletion method.
        if (key != nullptr) {
            if (key->data > item)
                remove(key->left, item);
            else if (key->data < item)
                remove(key->right, item);
            else
                makeDeletion(key);
        }
    }

    void makeDeletion(Node *& key) {

        //initialize a curr pointer
        Node *curr;
        if (key != nullptr) {

            // Case where the left is null, one child set the node on the right as
            // the new node to join. Same thing applies for the right side when
            // null.
            if (key->left == nullptr) {
                curr = key;
                key = key->right;
                delete curr;
            } else if (key->right == nullptr) {
                curr = key;
                key = key->left;
                delete curr;
            } else {

                //This is the case where there are two children
                curr = key->right;
                while (curr->left != nullptr) {
                    curr = curr->left;
                }

                //Slowly inch down to the next inorder successor
                key->data = curr->data;
                remove(key->right, curr->data);
            }
        }
    }

    void destroyTree(Node *& key) {

        //Traverses through the node and delete the node.
        if(key != nullptr) {
            destroyTree(key->left);
            destroyTree(key->right);
            delete key;
        }

        //Set the pointer to nullptr
        key = nullptr;
    }

    bool contains(T item, Node *& key) {

        //This helper function will be used to check if the item inputted as an
        // argument is contained in the tree or not
        if(key == nullptr) {

            //Return false if key reaches null which means the BSTx doesn't
            // contain the specified item.
            return false;
        }

        //If the requested node item is found return true. Traverse through the
        // tree until the item is found or returns false if not found.
        if(key-> data == item) {
            return true;
        } else if (key -> data > item) {
            return contains(item, key->left);
        } else if (key -> data < item){
            return contains(item, key->right);
        }

        //Catch all statement
        return false;

    }



    int getLeafCount(Node *& key){

        //If the key is now pointing to nullptr return zero.
        if(key == nullptr) {
            return 0;
        }

        //If both the left and the right are pointing at nullptr that means it is
        // a leaf node and return one. Traverse through the tree on the left side
        // and the right side and add up all the leaf nodes.
        if(key -> left == nullptr && key ->right == nullptr) {
            return 1;
        } else {
            return getLeafCount(key->left) + getLeafCount(key -> right);
        }
    }


    std::string getPreOrderTraversal(Node * key, std::stringstream& ss) {

        //Traverse down the tree using the preorder of root, left, right,
        // recursively
        if(key) {
            ss << key->data << " ";
            getPreOrderTraversal(key->left, ss);
            getPreOrderTraversal(key->right, ss);
        }

        //return the std::string
        return ss.str();
    }

    std::string getInOrderTraversal(Node* key, std::stringstream& ss) {

        //Traverse down the tree using the inorder of left, root, right,
        // recursively
        if (key) {
            getInOrderTraversal(key->left, ss);
            ss << key->data<<" ";
            getInOrderTraversal(key->right, ss);
        }

        //return the std::string
        return ss.str();
    }


    std::string getPostOrderTraversal(Node*key, std::stringstream& ss) {

        //Traverse down the tree using the inorder of left, right, root,
        // recursively
        if(key) {
            getPostOrderTraversal(key->left, ss);
            getPostOrderTraversal(key->right, ss);
            ss << key->data <<" ";

        }
        //return the std::string
        return ss.str();
    }

    int getHeight(Node *& key) {

        //If the key is pointing to nullptr returns 0.
        if (key == nullptr) {
            return 0;
        } else {

            //Traverse through the tree recursively calling this function.
            int heightLeft = getHeight(key->left);
            int heightRight = getHeight(key->right);

            //If one side of the tree is higher than the other side return the
            // higher side of the tree.
            if (heightLeft > heightRight) {
                return (heightLeft + 1);
            } else {
                return (heightRight + 1);
            }
        }
    }

    int getLevel(Node *& key, T item, int level) {

        //If the key is null key that means that
        if (key == nullptr) {
            return -1;
        }

        //Goes through the tree until the item is found and returns the level.
        // Each time it goes down it will increment a level.
        if (key->data == item) {
            return level;
        } else if (key->data > item) {
            return getLevel(key->left, item, level + 1);
        } else if (key->data < item) {
            return getLevel(key->right, item, level + 1);
        }

        //Catch all to return the level
        return level;
    }

    std::string getAncestors(Node *& key, T item, std::stringstream &
    ancestorStr) {

        //Check if the item is in the tree before trying to get the ancestor
        if(contains(item)) {

            //Return the std::string of where it currently is. If it is the first
            // node, it is an empty std::string. Add the ancestorstd::String as more and
            // more nodes are traversed. getAncestors is called recursively.
            if (key->data == item) {
                return ancestorStr.str();
            } else if (key->data < item) {
                getAncestors(key->right, item, ancestorStr);
                ancestorStr << key->data << " ";
                return ancestorStr.str();

            } else if (key->data > item) {
                getAncestors(key->left, item, ancestorStr);
                ancestorStr << key->data << " ";
                return ancestorStr.str();
            }
        }

        //Catch all that will return empty std::string if the node doesn't exist
        return "";


    }

    int size(int& nodeCount, Node * key) {

        //As long as the key does not equal nullptr count each time a node is
        // traversed and recursively call the size function to traverse through
        // the tree.
        if(key !=nullptr) {
            nodeCount += 1;
            size(nodeCount, key->left);
            size(nodeCount, key->right);
        }

        //Return the amount of nodes in the tree.
        return nodeCount;
    }

    void copyTree(Node*& thisTree, const Node * nextTree ) {

        //Checks if the current node of the other tree is null or not
        if (nextTree != nullptr) {

            //If the node is not null create a new node with the same data as the
            // node we are trying to copy
            thisTree = new Node;
            thisTree->data = nextTree->data;
            thisTree->right = nullptr;
            thisTree->left = nullptr;

            //Recursively go through the tree until we copy all the nodes
            copyTree(thisTree->left, nextTree->left);
            copyTree(thisTree->right, nextTree->right);
        }
    }

    int getWidth(Node * ptr) {

        //If the tree is empty it has zero width
        if (ptr == nullptr)
            return 0;

        //Set maxwidth to zero
        int maxWidth = 0;

        //Use level order traversal and queue system. Each level will translate
        // to a queue. We get the size of that queue to and compare it with the
        // previous queue. Every time we move to another level the queue is
        // cleared.
        std::queue<Node*> levelOrderQueue;

        //Put the root onto the queue
        levelOrderQueue.push(root);

        //Check if the queue is empty
        while (!levelOrderQueue.empty()) {

            //Get the width of the level by getting the size of the queue, at
            // root there is only one element on the queue
            int levelWidth = levelOrderQueue.size();

            //Compare to the previous maxWidth with current level width
            maxWidth = std::max(levelWidth, maxWidth);

            //This while loop will dequeue the nodes in the level as well as
            // add the children nodes of each dequeued node every time. The
            // levelWidth keeps track of how many times the queue is dequeued, so
            // it doesn't dequeue the children nodes.
            while (levelWidth--) {

                //Keeps track of current level temporary nodes and then dequeue them
                Node* currLevelTemp = levelOrderQueue.front();
                levelOrderQueue.pop();

                //Check to make sure that each node's children is on the queue as
                // well.
                if (currLevelTemp->left != nullptr)
                    levelOrderQueue.push(currLevelTemp->left);
                if (currLevelTemp->right != nullptr)
                    levelOrderQueue.push(currLevelTemp->right);
            }
        }

        //Return the maxWidth of a tree
        return maxWidth;
    }

    std::string getLevelOrder(Node * ptr, std::stringstream & ss) {

        //If the ptr which is currently root, return an empty string
        if (ptr == nullptr)
            return ss.str();

        //Use level order traversal and queue system. Each node is read level by
        // level.
        std::queue<Node*> levelOrderQueue;

        //Push the root node onto the queue
        levelOrderQueue.push(ptr);

        //While the queue is not empty
        while (levelOrderQueue.empty() == false) {

            //Set the node pointer curr to the front of the queue
            Node* curr = levelOrderQueue.front();

            //Store the data in the stringstream.
            ss << curr->data << " ";

            //Pope the front of the queue
            levelOrderQueue.pop();

            //So we have to enqueue the left first and then the right children of
            // the current node. It doesn't go down any further, only just one
            // level down. Each time the while-loop loops it only cares about the
            // current node at the front of the queue. And then only the children
            // down one level. It does not traverse through the tree the whole
            // entire way, just level by level.
            if (curr->left != nullptr)
                levelOrderQueue.push(curr->left);

            //Enqueue the right child of the current node
            if (curr->right != nullptr)
                levelOrderQueue.push(curr->right);
        }

        //Return the string.
        return ss.str();
    }

};




#endif //SRC_BSTX_H

