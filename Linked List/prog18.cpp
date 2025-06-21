//remove nth node from the end
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with removeNthFromEnd method
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;

        // Step 1: Count the number of nodes
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        // Step 2: If head node is to be deleted
        if (n == cnt) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Traverse to the node before the one to be deleted
        int res = cnt - n;
        temp = head;
        for (int i = 1; i < res; ++i) {
            temp = temp->next;
        }

        // Step 4: Delete the nth node from the end
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; ++i) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Sample list: [1, 2, 3, 4, 5]
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    int k = 2; // remove 2nd node from the end

    head = solution.removeNthFromEnd(head, k);

    cout << "List after removing " << k << "th node from the end: ";
    printList(head);

    return 0;
}
