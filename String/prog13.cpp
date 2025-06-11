//longest palindrome substring
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(const string& s) {
        int n = s.size();
        if (n < 2) return s;

        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);     // odd-length palindrome
            expand(i, i + 1); // even-length palindrome
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string: ";
    cin >> input;

    string result = sol.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
