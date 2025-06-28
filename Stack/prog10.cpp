//implement min stack
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {}

    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                st.push(2 * val - mini);  // Encode previous min
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        long long top = st.top();
        st.pop();
        if (top < mini) {
            mini = 2 * mini - top;  // Restore previous minimum
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long top = st.top();
        return (top < mini) ? mini : top;
    }

    int getMin() {
        if (st.empty()) return -1;
        return mini;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    cout << "Current Min: " << ms.getMin() << endl;  // 3
    ms.pop();
    cout << "Top: " << ms.top() << endl;             // 3
    cout << "Current Min: " << ms.getMin() << endl;  // 3
    ms.pop();
    cout << "Current Min: " << ms.getMin() << endl;  // 5
    return 0;
}
