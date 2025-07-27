//insert a given node in BST
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with insertIntoBST method
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If root is null, return a new node as root
        if (root == nullptr) return new TreeNode(val);

        TreeNode* cur = root;

        while (true) {
            if (val > cur->val) {
                if (cur->right != nullptr) {
                    cur = cur->right;
                } else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if (cur->left != nullptr) {
                    cur = cur->left;
                } else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

// Utility function to print inorder traversal of BST
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    // Create initial BST
    TreeNode* root = new TreeNode(4);
    sol.insertIntoBST(root, 2);
    sol.insertIntoBST(root, 7);
    sol.insertIntoBST(root, 1);
    sol.insertIntoBST(root, 3);

    // Insert new value
    sol.insertIntoBST(root, 5);

    // Print inorder traversal of BST to verify correctness
    cout << "Inorder traversal of BST after insertion: ";
    printInorder(root);  // Expected Output: 1 2 3 4 5 7
    cout << endl;

    return 0;
}
