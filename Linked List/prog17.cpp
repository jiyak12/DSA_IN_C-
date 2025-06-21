//segregate odd and even nodes in LL
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to rearrange nodes: all odd-indexed first, then even-indexed
ListNode* oddEvenList(ListNode* head) {
    // Base case: if the list has 0 or 1 node, it's already valid
    if (!head || !head->next) return head;

    ListNode* odd = head;             // Start of odd-positioned nodes
    ListNode* even = head->next;      // Start of even-positioned nodes
    ListNode* evenHead = even;        // Save even head to connect later

    // Loop through while there are at least 2 nodes ahead
    while (even && even->next) {
        odd->next = even->next;       // Point current odd to the next odd node
        odd = odd->next;              // Move odd pointer forward

        even->next = odd->next;       // Point current even to the next even node
        even = even->next;            // Move even pointer forward
    }

    odd->next = evenHead;             // Connect end of odd list to start of even list
    return head;
}

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
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
    // Sample input array
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list from array
    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    // Apply odd-even reordering
    head = oddEvenList(head);

    cout << "Reordered List (Odd-Even): ";
    printList(head);

    return 0;
}
