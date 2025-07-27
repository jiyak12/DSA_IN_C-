// Construct Binary Tree from Inorder and Postorder Traversal
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class to construct the tree
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a hashmap for quick lookup of root index in inorder
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndex[inorder[i]] = i;

        // Start from the last element in postorder (which is the root)
        int postIndex = postorder.size() - 1;

        // Recursively build the tree
        return build(inorder, postorder, inorderIndex, postIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int, int>& inorderIndex,
                    int& postIndex, int inStart, int inEnd) {
        // Base case: no elements to construct subtree
        if (inStart > inEnd)
            return nullptr;

        // The current root is the last element in postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Get the index of the root from inorder
        int mid = inorderIndex[rootVal];

        // Build right subtree first (because postorder is Left, Right, Root)
        root->right = build(inorder, postorder, inorderIndex, postIndex, mid + 1, inEnd);

        // Build left subtree
        root->left = build(inorder, postorder, inorderIndex, postIndex, inStart, mid - 1);

        return root;
    }
};

// Utility function to print inorder traversal for verification
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution solution;

    // Sample input
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Build the binary tree
    TreeNode* root = solution.buildTree(inorder, postorder);

    // Print inorder traversal of constructed tree to verify
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);  // Expected: 9 3 15 20 7
    cout << endl;

    return 0;
}
