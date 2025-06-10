//longest common prefix
// to solve this problem , first sort the string, now compare the first and last string.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    sort(strs.begin(), strs.end());  // Sort the array lexicographically

    string first = strs[0];
    string last = strs[strs.size() - 1];
    string ans = "";

    for (int i = 0; i < first.size(); ++i) {
        if (first[i] != last[i]) break;
        ans += first[i];
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
