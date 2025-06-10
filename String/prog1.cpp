//Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
//Primitive: A valid parentheses string that cannot be broken further into smaller valid parts.
#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    string result = "";
    int depth = 0;

    for (char c : s) {
        if (c == '(') {
            if (depth > 0) result += c;  // skip outermost '('
            depth++;
        } else {
            depth--;
            if (depth > 0) result += c;  // skip outermost ')'
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a valid parentheses string: ";
    cin >> s;

    string output = removeOuterParentheses(s);
    cout << "After removing outermost parentheses: " << output << endl;

    return 0;
}
