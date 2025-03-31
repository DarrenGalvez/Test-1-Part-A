#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>

#pragma once

class binarytree {
    // First forward declare the Node structure
    struct Node;
    
public:
    using NodePtr = Node*;  // Public type alias for Node pointer
    
    binarytree();
    ~binarytree();
    void insert(int value);
    bool search(int value);
    void deleteNode(int value);
    void inorder();
    void preorder();
    void postorder();
    void levelOrder();
    int countNodes();
    int findHeight();
    void clear();
    NodePtr getRoot() const { return root; }  // Simplified declaration
    
private:
    // Now define the Node structure
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root; // tree root node

    // Helper functions
    Node* insertHelper(Node* node, int value);
    bool searchHelper(Node* node, int value);
    Node* deleteHelper(Node* node, int value);
    Node* findMin(Node* node);
    void inorderHelper(Node* node);
    void preorderHelper(Node* node);
    void postorderHelper(Node* node);
    int countNodesHelper(Node* node);
    int heightHelper(Node* node);
    void clearHelper(Node* node);
};

#endif