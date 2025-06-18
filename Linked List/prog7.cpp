//deleting tail of LL
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

Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr; // Handle empty or single-node list
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next; // delete the last node
    temp->next = nullptr; // set second-last node's next to null
    return head;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    // Creating linked list from vector
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    cout << "Original list: ";
    print(head);

    head = deleteTail(head);

    cout << "After deleting tail: ";
    print(head);

    // Optional: Free remaining memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
