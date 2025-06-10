/*find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
a1 has an odd frequency in the string. a2 has an even frequency in the string. Return this maximum difference. */
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int> freq(26, 0);

        for (char &ch : s) {
            freq[ch - 'a']++;
        }

        int maxOdd = 0;
        int minEven = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            if (freq[i] % 2 == 0) {
                minEven = min(minEven, freq[i]);
            } else {
                maxOdd = max(maxOdd, freq[i]);
            }
        }

        // Handle edge case: if no even frequency exists
        if (minEven == INT_MAX) minEven = 0;

        return maxOdd - minEven;
    }
};

int main() {
    Solution sol;
    string input = "aabbcccdddeee";
    cout << "Max Difference: " << sol.maxDifference(input) << endl;
    return 0;
}
