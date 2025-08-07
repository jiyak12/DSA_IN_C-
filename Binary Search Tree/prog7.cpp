//check if a atree is a BST or BT

#include <iostream>
#include <climits> // for LONG_MIN and LONG_MAX

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Main function to check if BST is valid
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX); // start with full range
    }

private:
    // Helper function that checks the BST property using range
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;

        // If node value violates the min/max constraint, not a BST
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Check left and right subtrees recursively with updated bounds
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};

// Utility function to build a sample BST
TreeNode* createSampleBST() {
    //      10
    //     /  \
    //    5    15
    //        /  \
    //       12   20
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    return root;
}

// Utility function to build an invalid BST (for testing)
TreeNode* createInvalidBST() {
    //      10
    //     /  \
    //    5    8   <- invalid because 8 < 10, but in right subtree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(8);
    return root;
}

// Main function to run the program
int main() {
    Solution sol;

    // Test 1: Valid BST
    TreeNode* validRoot = createSampleBST();
    if (sol.isValidBST(validRoot))
        cout << "Test 1: Valid BST ✅" << endl;
    else
        cout << "Test 1: Invalid BST ❌" << endl;

    // Test 2: Invalid BST
    TreeNode* invalidRoot = createInvalidBST();
    if (sol.isValidBST(invalidRoot))
        cout << "Test 2: Valid BST ✅" << endl;
    else
        cout << "Test 2: Invalid BST ❌" << endl;

    return 0;
}
