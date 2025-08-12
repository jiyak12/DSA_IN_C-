//inorder successor/predecessor in BST
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> succPredBST(TreeNode* root, int key) {
        TreeNode* successor = NULL;
        TreeNode* predecessor = NULL;
        TreeNode* curr = root;

        // Single traversal to find both predecessor and successor
        while (curr != NULL) {
            if (curr->val == key) {
                // Predecessor: max in left subtree
                if (curr->left) {
                    TreeNode* temp = curr->left;
                    while (temp->right) temp = temp->right;
                    predecessor = temp;
                }
                // Successor: min in right subtree
                if (curr->right) {
                    TreeNode* temp = curr->right;
                    while (temp->left) temp = temp->left;
                    successor = temp;
                }
                break;
            }
            else if (key < curr->val) {
                successor = curr; // potential successor
                curr = curr->left;
            }
            else {
                predecessor = curr; // potential predecessor
                curr = curr->right;
            }
        }

        return {predecessor ? predecessor->val : -1,
                successor ? successor->val : -1};
    }
};

// Helper function to insert nodes in BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main() {
    TreeNode* root = NULL;
    vector<int> keys = {50, 30, 20, 40, 70, 60, 80};

    // Build BST
    for (int k : keys) {
        root = insert(root, k);
    }

    Solution sol;
    int key = 65;
    vector<int> ans = sol.succPredBST(root, key);

    cout << "Key: " << key << "\n";
    cout << "Predecessor: " << ans[0] << "\n";
    cout << "Successor: " << ans[1] << "\n";

    return 0;
}
