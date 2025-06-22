//Add two numbers represented as Linked Lists
/*
Create a dummy node which is the head of new linked list.
Create a node temp, initialise it with dummy.
Initialize carry to 0.
Loop through lists l1 and l2 until you reach both ends, and until carry is present.
Set sum=l1.val+ l2.val + carry.
Update carry=sum/10.
Create a new node with the digit value of (sum%10) and set it to temp node's next, then advance temp node to next.
Advance both l1 and l2.
Return dummy's next node.
  */
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    int carry = 0;

    while ((l1 != nullptr || l2 != nullptr) || carry) {
        int sum = 0;

        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;

        ListNode *node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }

    return dummy->next;
}

// Helper function to create linked list from an array
ListNode* createList(int arr[], int size) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {2, 4, 3}; // Represents 342
    int arr2[] = {5, 6, 4}; // Represents 465

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    ListNode* result = addTwoNumbers(l1, l2); // Should be 7 -> 0 -> 8 (807)

    cout << "Result: ";
    printList(result);

    return 0;
}
