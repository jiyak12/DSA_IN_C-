//remove k digits

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();

        // Build a monotonic increasing stack
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If k > 0, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result string
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Remove leading zeroes
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') {
            idx++;
        }

        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }
};

int main() {
    Solution sol;
    string num = "1432219";
    int k = 3;
    cout << "Result after removing " << k << " digits: " << sol.removeKdigits(num, k) << endl;
    return 0;
}
