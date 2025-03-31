#include "binarytree.h"
#include <iostream>
#include <queue>
using namespace std;

// Constructor
binarytree::binarytree() : root(nullptr) {}

// Destructor
binarytree::~binarytree() {
    clear();
}

// Recursive function to delete all nodes
void binarytree::clearHelper(Node* node) {
    if (!node) return;
    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
}

// Clear tree
void binarytree::clear() {
    clearHelper(root);
    root = nullptr;
}

// Insert function
binarytree::Node* binarytree::insertHelper(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->data)
        node->left = insertHelper(node->left, value);
    else if (value > node->data)
        node->right = insertHelper(node->right, value);
    return node;
}

void binarytree::insert(int value) {
    root = insertHelper(root, value);
}

// Search function
bool binarytree::searchHelper(Node* node, int value) {
    if (!node) return false;
    if (node->data == value) return true;
    return (value < node->data) ? searchHelper(node->left, value) : searchHelper(node->right, value);
}

bool binarytree::search(int value) {
    return searchHelper(root, value);
}

// Find the minimum value in a subtree
binarytree::Node* binarytree::findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Delete function
binarytree::Node* binarytree::deleteHelper(Node* node, int value) {
    if (!node) return nullptr;
    if (value < node->data)
        node->left = deleteHelper(node->left, value);
    else if (value > node->data)
        node->right = deleteHelper(node->right, value);
    else {
        // Case 1 & 2: Node has 0 or 1 child
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Node has 2 children
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteHelper(node->right, temp->data);
    }
    return node;
}

void binarytree::deleteNode(int value) {
    root = deleteHelper(root, value);
}

// Inorder traversal (Left -> Root -> Right)
void binarytree::inorderHelper(Node* node) {
    if (!node) return;
    inorderHelper(node->left);
    cout << node->data << " ";
    inorderHelper(node->right);
}

void binarytree::inorder() {
    inorderHelper(root);
    cout << endl;
}

// Preorder traversal (Root -> Left -> Right)
void binarytree::preorderHelper(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
}

void binarytree::preorder() {
    preorderHelper(root);
    cout << endl;
}

// Postorder traversal (Left -> Right -> Root)
void binarytree::postorderHelper(Node* node) {
    if (!node) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << node->data << " ";
}

void binarytree::postorder() {
    postorderHelper(root);
    cout << endl;
}

// Level order traversal (BFS)
void binarytree::levelOrder() {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Count number of nodes
int binarytree::countNodesHelper(Node* node) {
    if (!node) return 0;
    return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
}

int binarytree::countNodes() {
    return countNodesHelper(root);
}

// Find height of tree
int binarytree::heightHelper(Node* node) {
    if (!node) return -1;
    return 1 + max(heightHelper(node->left), heightHelper(node->right));
}

int binarytree::findHeight() {
    return heightHelper(root);
}