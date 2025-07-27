//flatten a binary tree to linked list
#include <iostream>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* prev = nullptr; // class member to retain value across recursion

public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        flatten(root->right);  // Flatten right subtree first
        flatten(root->left);   // Then flatten left subtree

        root->right = prev;    // Point current node's right to previous node
        root->left = nullptr;  // Set left to NULL
        prev = root;           // Update prev to current node
    }
};

// Utility to print the flattened tree (linked list)
void printRightLinkedList(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Example tree: [1,2,5,3,4,null,6]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree: ";
    printRightLinkedList(root);  // Expected: 1 2 3 4 5 6

    return 0;
}
