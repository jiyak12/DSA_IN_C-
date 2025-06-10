//Maximum Nesting Depth of the Parentheses

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int curr = 0;
        for (char& c : s) {
            if (c == '(')
                res = max(res, ++curr);
            if (c == ')')
                curr--;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Maximum Depth: " << sol.maxDepth(s) << endl;

    return 0;
}
