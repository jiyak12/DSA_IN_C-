//Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        inorder(root, a);
        int i = 0, j = a.size() - 1;
        while (i < j) {
            int sum = a[i] + a[j];
            if (sum == k) return true;
            (sum < k) ? i++ : j--;
        }
        return false;
    }

private:
    void inorder(TreeNode* root, vector<int>& a) {
        if (root == NULL) return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }
};

// Helper to create a simple BST for testing
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main() {
    // Create sample BST
    TreeNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);

    Solution sol;
    int k = 9;

    if (sol.findTarget(root, k))
        cout << "Found two elements with sum " << k << endl;
    else
        cout << "No such elements found." << endl;

    return 0;
}
