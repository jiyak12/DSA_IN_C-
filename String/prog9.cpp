// sort characters by frequency
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Create a vector of pairs and sort based on frequency
        vector<pair<char, int>> chars(freq.begin(), freq.end());
        sort(chars.begin(), chars.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result;
        for (auto &[ch, count] : chars) {
            result += string(count, ch);
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "tree";
    cout << "Sorted by frequency: " << sol.frequencySort(s) << endl;
    return 0;
}
