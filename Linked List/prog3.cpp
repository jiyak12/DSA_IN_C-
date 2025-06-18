//converting array to linked list
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;         // Data stored in the node
        Node* next;       // Pointer to the next node in the linked list
        // Constructors
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
        // Constructor
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};
        Node* convertArr2LL(vector<int> &arr){
            Node* head = new Node(arr[0]);
            Node* mover = head;
            for( int i = 1; i< arr.size(); i++){
                Node* temp = new Node(arr[i]);
                mover-> next = temp;
                mover = temp;
            }
            return head;
        }
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    cout << head-> data;
    
}
