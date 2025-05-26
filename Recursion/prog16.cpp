/* 
generateBinaryStrings(n, current) keeps building the string current recursively.
When current.length() == n, it prints the string.
At each step, it branches into two recursive calls: one adding '0', and one adding '1'.
*/


#include <iostream>
using namespace std;

void generateBinaryStrings(int n, string current = "") {
    // Base case: if the current string has length n, print it
    if (current.length() == n) {
        cout << current << endl;
        return;
    }

    // Recursive case: add '0' and '1' at each step
    generateBinaryStrings(n, current + "0");
    generateBinaryStrings(n, current + "1");
}

int main() {
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;
    cout << "All binary strings of length " << n << ":\n";
    generateBinaryStrings(n);
    return 0;
}
