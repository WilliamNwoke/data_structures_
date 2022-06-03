// Ogechukwu Ossai
// BST.h
// Binary search tree implementation
// class makes extensive use of Node** to fill a pointer with data,
// or to null a pointer

#ifndef BST_BST_H
#define BST_BST_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void findWords(std::vector<std::string>& words, const std::string& content);
// as described in p2ees.cpp

template <typename T>
class BST
{
public:
    BST() = default;

    // copy constructor uses create helper function
    BST(const BST& other)
    {
        create(other.root);
    }

    ~BST()
    {
        destroy(&root);
    }

    BST& operator=(const BST& rhs)
    {
        // create a copy of the tree in rhs
        // swap copy's root and this root pointers
        // since this.root is null, copy will become null
        // thus copy's destructor will simply do nothing
        // and this now contains same tree as rhs.
        auto copy {rhs};
        std::swap(this->root, copy.root);
        return *this;
    }

    /* following are public functions that do not add any functionality
     * not already described above, except stated otherwise they merely
     * act as public interface for outside user
    */
    void insert(const T& element)
    {
        insert(&root, element);
    }

    bool contains(const T& element)
    {
        std::stringstream ss;
        int lvl{};
        return contains(root, ss, lvl, element);
    }

    void remove(const T& element)
    {
        remove(&root, element);
    }

    bool empty() { return root == nullptr; }

    std::string getInOrderTraversal()
    {
        std::stringstream ss;
        getInOrderTraversal(root, ss);
        return ss.str();
    }

    std::string getPreOrderTraversal()
    {
        std::stringstream ss;
        getPreOrderTraversal(root, ss);
        return ss.str();
    }

    std::string getPostOrderTraversal()
    {
        std::stringstream ss;
        getPostOrderTraversal(root, ss);
        return ss.str();
    }

    // in addition to using contains to get the ancestors of the element
    // this function reverses the order of ancestors as per assignment specification
    std::string getAncestors(const T& element)
    {
        std::stringstream ss;
        int lvl{};
        if (contains(root, ss, lvl, element))
        {
            std::vector<std::string> strings;
            findWords(strings, ss.str()); // extract words
            std::string temp{};
            // work through the vector backwards
            // adding each element to the string that's to be returned
            for (int i = 0; i < strings.size(); ++i)
            {
                temp += strings[strings.size() - (1 + i)];
                temp += " ";
            }

            return temp;
        }
        else
        {
            return "";
        }
    }

    int getLevel(const T& element)
    {
        std::stringstream ss;
        int lvl{};
        // if value is contained in the tree
        if (contains(root, ss, lvl, element))
        {
            return lvl;
        }
        else
        {
            // per assignment specification
            return -1;
        }
    }

    int getLeafCount()
    {
        size_t count{};
        getLeafCount(root, count);
        return count;
    }

    size_t getHeight()
    {
        return getHeight(root);
    }

    size_t size()
    {
        return size(root);
    }
private:
    // Node nested class
    struct Node
    {
        T value{};
        Node* left{};
        Node* right{};
    };

    Node* root{};

    // recursively delete all nodes that exist in tree
    // used by destructor
    void destroy(Node** pNode)
    {
        if (*pNode != nullptr)
        {
            destroy(&(*pNode)->left);
            destroy(&(*pNode)->right);
            delete *pNode;
            *pNode = nullptr;
        }
    }

    // recursively create all nodes that exist in tree
    // used by copy constructor, node is usually the root
    // node of another tree
    void create(Node* node)
    {
        if (node != nullptr)
        {
            insert(node->value);
            create(node->left);
            create(node->right);
        }
    }

    // inserts an element into the tree
    void insert(Node** node, const T& element)
    {
        if (*node == nullptr) // we've reached the required leaf node
        {
            *node = new Node { element, nullptr, nullptr };
        }
            // search left and right of *node for a leaf node
        else if ((*node)->value < element)
        {
            insert(&(*node)->right, element);
        }
        else
        {
            insert(&(*node)->left, element);
        }
    }

    // verifies that an element is in the tree
    // streamOut stores all ancestors of the node if it's contained in the tree and returns true
    // level stores level of the node if it's contained in the tree and returns true
    // if return value is false, ignore streamOut and level
    bool contains(Node* node, std::stringstream& streamOut, int& level, const T& element)
    {
        if (node == nullptr)
        {
            // element not found
            return false;
        }

        level += 1; // for every search we make, we assume the element will be found and add 1 to level

        if (node->value == element)
        {
            return true;
        }
        else if (node->value < element)
        {
            // for every search we make, we assume the element will be found
            // and add the current as and ancestor of element
            streamOut << " " << node->value;
            return contains(node->right, streamOut, level,element);
        }
        else
        {
            streamOut << " " << node->value;
            return contains(node->left, streamOut, level,element);
        }
    }

    // used to remove a node that has two children
    // on the first call to this function, node is the right node of the node to delete
    // on subsequent calls, it is the left node of every node in the recursive calls
    // per deletion algorithm
    void switchSuccessor(Node** node, Node* nodeToDelete)
    {
        if ((*node)->left)
        {
            switchSuccessor(&(*node)->left, nodeToDelete);
        }
        else
        {
            // found a successor node, then swap successor node
            // and node to delete values
            nodeToDelete->value = (*node)->value;
            // if it has a right child, right child becomes
            // successor node, delete successor node
            // else just delete successor node
            if ((*node)->right)
            {
                Node* temp = *node;
                *node = (*node)->right;
                delete temp;
            }
            else
            {
                delete (*node);
                (*node) = nullptr;
            }

        }
    }

    // removes and element from the tree, if element doesn't exist,
    // does nothing
    void remove(Node** node, const T& element)
    {
        if (*node == nullptr)
        {
            // element not found
            return;
        }

        // recursive calls
        if ((*node)->value < element)
        {
            remove(&(*node)->right, element);
        }
        else if ((*node)->value > element)
        {
            remove(&(*node)->left, element);
        }
        else
        {
            // element found, follow deletion algorithm as specified
            Node* temp{};
            if ((*node)->left == nullptr)
            {
                temp = *node;
                *node = (*node)->right;
                delete temp;
                temp = nullptr;
            }
            else if ((*node)->right == nullptr)
            {
                temp = *node;
                *node = (*node)->left;
                delete temp;
                temp = nullptr;
            }
            else
            {
                // find successor node if it has both left and right children
                switchSuccessor(&(*node)->right, *node);
            }
        }
    }

    // next three functions use recursion to transverse the tree
    // they follow the inorder, preorder and postorder algorithm
    void getInOrderTraversal(Node* node, std::stringstream& streamOut)
    {
        if (node == nullptr)
        {
            return;
        }
        getInOrderTraversal(node->left, streamOut);
        streamOut << node->value << " ";
        getInOrderTraversal(node->right, streamOut);
    }

    void getPreOrderTraversal(Node* node, std::stringstream& streamOut)
    {
        if (node == nullptr)
        {
            return;
        }
        streamOut << node->value << " ";
        getPreOrderTraversal(node->left, streamOut);
        getPreOrderTraversal(node->right, streamOut);
    }

    void getPostOrderTraversal(Node* node, std::stringstream& streamOut)
    {
        if (node == nullptr)
        {
            return;
        }
        getPostOrderTraversal(node->left, streamOut);
        getPostOrderTraversal(node->right, streamOut);
        streamOut << node->value << " ";
    }

    // recursively get the count of nodes that are leaf nodes
    // node is usually the root node, count stores the result
    void getLeafCount(Node* node, size_t& count)
    {
        if (node->left)
        {
            getLeafCount(node->left, count);
        }
        if (node->right)
        {
            getLeafCount(node->right, count);
        }
        else
        {
            // node has no left or right child, increment count
            count += 1;
        }
    }

    // recursively calculates the height of a tree
    size_t getHeight(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            // the height of a node is 1 + max the height of its children if any
            // recursively sum the returned max.
            return 1 + std::max<size_t>(getHeight(node->left), getHeight(node->right));
        }
    }

    // The sum of all nodes in the tree
    size_t size(Node* node)
    {
        if (node == nullptr) // node doesn't exist
        {
            return 0;
        }
        else
        {
            // node exists, recursively calculate result for children
            return 1 + size(node->left) + size(node->right);
        }
    }
};

#endif //BST_BST_H
