//divide a string into grouos of size k
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;  // grouped string
        int n = s.size();
        int curr = 0;  // starting index of each group
        // split string
        while (curr < n) {
            res.push_back(s.substr(curr, k));
            curr += k;
        }
        // try to fill in the last group
        if (!res.empty() && res.back().length() < k) {
            res.back() += string(k - res.back().length(), fill);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcdefghi";
    int k = 3;
    char fill = 'x';

    vector<string> result = sol.divideString(s, k, fill);

    cout << "Divided strings: ";
    for (const string& str : result) {
        cout << "\"" << str << "\" ";
    }
    cout << endl;

    return 0;
}
