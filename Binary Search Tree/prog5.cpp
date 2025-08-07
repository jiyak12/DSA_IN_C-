//delete a node in BST
#include <iostream>
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
    // Function to delete a node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        // If the node to be deleted is found at root
        if (root->val == key) return helper(root);

        TreeNode* dummy = root; // Store original root to return later

        while (root != NULL) {
            if (root->val > key) {
                // Move to the left subtree
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                // Move to the right subtree
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy; // Return original root
    }

private:
    // Helper function to delete a node and rearrange children
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        }

        // Both left and right children exist
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild; // Attach right subtree to rightmost of left
        return root->left;
    }

    // Finds the rightmost node in the left subtree
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) return root;
        return findLastRight(root->right);
    }
};

// Utility function to insert a node in BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// In-order traversal to print BST
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Driver Code
int main() {
    Solution sol;
    TreeNode* root = NULL;

    // Creating BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Original BST (In-order): ";
    inorder(root);
    cout << endl;

    int key = 50;
    root = sol.deleteNode(root, key);

    cout << "BST after deleting " << key << " (In-order): ";
    inorder(root);
    cout << endl;

    return 0;
}
