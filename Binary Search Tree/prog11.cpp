// given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class
class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        helper(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }

private:
    void helper(TreeNode* node) {
        if (!node) return;
        helper(node->left);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;

        helper(node->right);
    }
};

// Helper to create a BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Helper to print inorder traversal
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    /*
        Example:
        Correct BST inorder: 1 2 3 4
        Swapped: 1 3 2 4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before recovery (inorder): ";
    inorderPrint(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "After recovery (inorder): ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
