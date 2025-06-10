//isomorphic string - Two strings s and t are isomorphic if the characters in s can be replaced to get t. All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map_s[128] = {0};
        char map_t[128] = {0};
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (map_s[s[i]] != map_t[t[i]]) return false;
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    string s, t;
    cout << "Enter first string (s): ";
    cin >> s;
    cout << "Enter second string (t): ";
    cin >> t;

    Solution sol;
    bool result = sol.isIsomorphic(s, t);

    if (result)
        cout << "The strings are isomorphic." << endl;
    else
        cout << "The strings are not isomorphic." << endl;

    return 0;
}
