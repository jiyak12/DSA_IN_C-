//deleting head
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr; // safety check
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main() {
    vector<int> arr = {12, 3, 5, 8, 78};

    // Build linked list from array
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    // Delete head and print
    head = deleteHead(head);
    print(head);  // Should print: 3 5 8 78

    return 0;
}
