#include "BST.h"

// TODO: remove these when we update traversals
#include <iostream>
using namespace std;

BST::BST() {
	root = nullptr;
}

BST::~BST() {
	destroyTree(root);
}

void BST::destroyTree(Node *&ptr) {
	if (ptr != nullptr) {
		destroyTree(ptr->left);
		destroyTree(ptr->right);
		delete ptr;
	}
	ptr = nullptr;
}

bool BST::contains(int item) {
	Node * ptr = root;
	while (ptr != nullptr) {
		if (ptr->data == item)
			return true;
		else if (ptr->data > item)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	} 
	return false;
}

void BST::insert(int item) {
	Node * newNode = new Node;
	newNode->data = item;
	newNode->left = newNode->right = nullptr;

	insert(root, newNode);
}

void BST::insert(Node *& ptr, Node *& newNode) {
	if (ptr == nullptr)
		ptr = newNode;
	else if (ptr->data > newNode->data)
		insert(ptr->left, newNode);
	else
		insert(ptr->right, newNode);
} 

void BST::remove(int item) {
	remove(root, item);
}

void BST::remove(Node *& ptr, int item) {
	if (ptr != nullptr) {
		if (ptr->data > item)
			remove(ptr->left, item);
		else if (ptr->data < item)
			remove(ptr->right, item);
		else
			makeDeletion(ptr, item);
	}
}

void BST::makeDeletion(Node *& ptr, int item) {
	Node * curr = nullptr;
	if (ptr != nullptr) {
		if (ptr->left == nullptr) {
			curr = ptr;
			ptr = ptr->right;
			delete curr;
		} else if (ptr->right == nullptr) {
			curr = ptr;
			ptr = ptr->left;
			delete curr;
		} else {
			curr = ptr->right;
			while (curr->left != nullptr)
				curr = curr->left;
			ptr->data = curr->data;
			remove(ptr->right, curr->data);
		}
	}
}

void BST::displayPreOrder() {
	displayPreOrder(root);
}

void BST::displayPreOrder(Node * ptr) {
	if (ptr != nullptr) {
		cout << ptr->data << endl;
		displayPreOrder(ptr->left);
		displayPreOrder(ptr->right);
	}
}

// TODO: try to write displayInOrder and displayPostOrder






