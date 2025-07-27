//Construct Binary Tree from Preorder and Inorder Traversal
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class that contains the logic to build the binary tree
class Solution {
public:
    // Main function to be called with preorder and inorder vectors
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each node value in the inorder traversal
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        // Initialize index for preorder traversal
        int preIndex = 0;

        // Call recursive helper to build the tree
        return build(preorder, inorderIndex, preIndex, 0, inorder.size() - 1);
    }

private:
    // Recursive function to construct the tree
    TreeNode* build(const vector<int>& preorder, unordered_map<int, int>& inorderIndex,
                    int& preIndex, int inStart, int inEnd) {
        // Base case: if start index exceeds end index, return null (no subtree)
        if (inStart > inEnd)
            return nullptr;

        // Get the current root value from preorder and increment the index
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root value in inorder traversal
        int mid = inorderIndex[rootVal];

        // Recursively build the left subtree
        root->left = build(preorder, inorderIndex, preIndex, inStart, mid - 1);

        // Recursively build the right subtree
        root->right = build(preorder, inorderIndex, preIndex, mid + 1, inEnd);

        // Return the root of this subtree
        return root;
    }
};

// Utility function to print inorder traversal of the constructed tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);          // Traverse left subtree
    cout << root->val << " ";          // Visit node
    printInorder(root->right);         // Traverse right subtree
}

int main() {
    Solution solution;

    // Sample input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Construct the tree
    TreeNode* root = solution.buildTree(preorder, inorder);

    // Print inorder traversal of the constructed tree to verify correctness
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);  // Expected output: 9 3 15 20 7
    cout << endl;

    return 0;
}
