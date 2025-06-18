/*There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
*/



#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with deleteNode function.
class Solution {
public:
// Deletes the given node (except the tail) from the linked list.
    // node represents the node to be deleted.
    void deleteNode(ListNode* node) {
       // This function assumes that the node to delete is not the tail
        // and that we are not handling edge cases where node could be null.

        // Copy the value from the next node to the current node.
        if (node == nullptr || node->next == nullptr) return; // safety check
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

int main() {
    vector<int> values = {4, 5, 1, 9};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    // Let's delete node with value 5 (assuming we have a pointer to it)
    ListNode* nodeToDelete = head->next; // This is node with value 5
    Solution().deleteNode(nodeToDelete);

    cout << "After deleting node 5: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
