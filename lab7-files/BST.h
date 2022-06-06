//  BST.h

#ifndef BST_h
#define BST_h

template<typename TYPE>
class BST
{
protected : public:
    class BSTNode {
    public:
        TYPE data;
        BSTNode(TYPE cf) : data(cf), left(nullptr), right(nullptr) { }
        BSTNode(BSTNode *l, BSTNode *r, TYPE cf) : data(cf), left(l), right(r) { }
        BSTNode *left, *right;
    };

    class FrequencyCompare {
    public:
        FrequencyCompare() { }
        bool operator() (const BSTNode *lhs, const BSTNode *rhs) const {
            // Changing the comparison will change the priority queue ordering
            // (min vs max)
            return lhs->data > rhs->data;
        }
    };

    BSTNode *root;

    void eraseTree(BSTNode* cur) {
        if (cur != nullptr) {
            eraseTree(cur->left);
            eraseTree(cur->right);
            delete cur;
        }
    }

public:
    BST() :root(nullptr) {}
    virtual ~BST() { eraseTree(root); }
};

#endif
