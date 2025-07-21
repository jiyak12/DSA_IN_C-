#include <iostream>
#include <queue>
#include <vector>
#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        } else if (left != nullptr) {
            return left;
        } else {
            return right;
        }
    }
};

TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }
    TreeNode* foundLeft = findNode(root->left, val);
    if (foundLeft != nullptr) {
        return foundLeft;
    }
    return findNode(root->right, val);
}

int main() {
    std::vector<int> nodes1 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root1 = buildTree(nodes1);
    TreeNode* p1 = findNode(root1, 5);
    TreeNode* q1 = findNode(root1, 1);
    TreeNode* lca1 = Solution().lowestCommonAncestor(root1, p1, q1);
    std::cout << "LCA of " << (p1 ? std::to_string(p1->val) : "NULL") << " and "
              << (q1 ? std::to_string(q1->val) : "NULL") << " is: "
              << (lca1 ? std::to_string(lca1->val) : "NULL") << std::endl;

    TreeNode* p2 = findNode(root1, 5);
    TreeNode* q2 = findNode(root1, 4);
    TreeNode* lca2 = Solution().lowestCommonAncestor(root1, p2, q2);
    std::cout << "LCA of " << (p2 ? std::to_string(p2->val) : "NULL") << " and "
              << (q2 ? std::to_string(q2->val) : "NULL") << " is: "
              << (lca2 ? std::to_string(lca2->val) : "NULL") << std::endl;

    TreeNode* p3 = findNode(root1, 6);
    TreeNode* q3 = findNode(root1, 99);
    TreeNode* lca3 = Solution().lowestCommonAncestor(root1, p3, q3);
    std::cout << "LCA of " << (p3 ? std::to_string(p3->val) : "NULL") << " and "
              << (q3 ? std::to_string(q3->val) : "NULL") << " is: "
              << (lca3 ? std::to_string(lca3->val) : "NULL") << std::endl;

    std::vector<int> nodes4 = {1, 2, 3};
    TreeNode* root4 = buildTree(nodes4);
    TreeNode* p4 = findNode(root4, 2);
    TreeNode* q4 = findNode(root4, 3);
    TreeNode* lca4 = Solution().lowestCommonAncestor(root4, p4, q4);
    std::cout << "LCA of " << (p4 ? std::to_string(p4->val) : "NULL") << " and "
              << (q4 ? std::to_string(q4->val) : "NULL") << " is: "
              << (lca4 ? std::to_string(lca4->val) : "NULL") << std::endl;

    delete root1->left->left;
    delete root1->left->right->left;
    delete root1->left->right->right;
    delete root1->left->right;
    delete root1->left;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->right;
    delete root1;

    delete root4->left;
    delete root4->right;
    delete root4;

    return 0;
}
