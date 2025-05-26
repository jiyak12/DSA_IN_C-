//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }

    void func(int index, string s, vector<string> &path, vector<vector<string>> &res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string input = "aab";
    vector<vector<string>> result = sol.partition(input);

    cout << "Palindrome partitions of \"" << input << "\":" << endl;
    for (const auto &partition : result) {
        cout << "[ ";
        for (const auto &str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}
