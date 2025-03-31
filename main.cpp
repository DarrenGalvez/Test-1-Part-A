#include "binarytree.h"
#include "binarytree.cpp"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

void displayLevelOrderByLevel(binarytree& tree) {
    if (tree.countNodes() == 0) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<binarytree::NodePtr> q;  // Use the public alias
    q.push(tree.getRoot());
    
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            binarytree::NodePtr current = q.front();
            q.pop();
            cout << current->data << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
}

void displayMenu() {
    cout << "\nBinary Search Tree Operations:\n";
    cout << "1. Insert a value\n";
    cout << "2. Search for a value\n";
    cout << "3. Delete a value\n";
    cout << "4. Display Inorder Traversal\n";
    cout << "5. Display Preorder Traversal\n";
    cout << "6. Display Postorder Traversal\n";
    cout << "7. Display Level Order Traversal (single line)\n";
    cout << "8. Display Level Order (level by level)\n";
    cout << "9. Count nodes in tree\n";
    cout << "10. Find tree height\n";
    cout << "11. Clear the tree\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: " << endl;
}

int main() {
    binarytree tree;
    int choice, value;

    cout << "Binary Search Tree Interactive Program\n";

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Insert
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << value << " inserted.\n";
                break;
                
            case 2: // Search
                cout << "Enter value to search: ";
                cin >> value;
                cout << value << ": " << (tree.search(value) ? "Found" : "Not Found") << endl;
                break;
                
            case 3: // Delete
                cout << "Enter value to delete: ";
                cin >> value;
                if (tree.search(value)) {
                    tree.deleteNode(value);
                    cout << value << " deleted.\n";
                } else {
                    cout << value << " not found in tree.\n";
                }
                break;
                
            case 4: // Inorder
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
                
            case 5: // Preorder
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
                
            case 6: // Postorder
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
                
            case 7: // Level Order (single line)
                cout << "Level Order Traversal: ";
                tree.levelOrder();
                break;
                
            case 8: // Level Order (level by level)
                cout << "Level Order Traversal (by level):\n";
                displayLevelOrderByLevel(tree);
                break;
                
            case 9: // Count nodes
                cout << "Number of nodes: " << tree.countNodes() << endl;
                break;
                
            case 10: // Tree height
                cout << "Tree height: " << tree.findHeight() << endl;
                break;
                
            case 11: // Clear tree
                tree.clear();
                cout << "Tree cleared.\n";
                break;
                
            case 12: // Exit
                cout << "Exiting program.\n";
                return 0;
                
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}