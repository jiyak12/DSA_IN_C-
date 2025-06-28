//infix to prefix
/*Reverse the infix expression. Note while reversing each '(' will become ')' and each ')' becomes '('.
Convert the reversed infix expression to postfix expression.
Initialize an empty stack to store operators and an empty string for the postfix expression.
Scan the infix expression from left to right.
If the character is an operand, append it to the postfix expression.
If the character is '(', push it onto the stack.
If the character is ')', pop from the stack and append to the postfix expression until '(' is found, then pop '(' without appending.
If the character is an operator, pop and append operators from the stack until the stack is empty or a lower precedence operator is found, then push the current operator onto the stack.
After scanning the expression, pop and append all remaining operators from the stack to the postfix expression.
Reverse the postfix expression and return it.*/
// C++ program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

// Check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || 
    ch == '*' || ch == '/' || ch == '^');
}

// Get precedence of operators
int operatorPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Convert infix expression to postfix notation
string convertInfixToPostfix(string s) {
    stack<char> st;
    string res;
    int sz = s.size();

    for (int i = 0; i < sz; i++) {
        if (isalnum(s[i])) {
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && operatorPrecedence(s[i]) <= 
            operatorPrecedence(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

// Convert infix expression to prefix notation
string convertToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string postfix = convertInfixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string s = "(a-b/c)*(a/k-l)";
    cout << convertToPrefix(s) << endl;
    return 0;
}
