//roman to integer
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            int currValue = roman[s[i]];

            // If a smaller value precedes a larger one, subtract it
            if (currValue < prevValue) {
                total -= currValue;
            } else {
                total += currValue;
            }

            prevValue = currValue;
        }

        return total;
    }
};

int main() {
    Solution sol;
    string roman;
    cout << "Enter a Roman numeral (e.g. MCMXCIV): ";
    cin >> roman;

    int number = sol.romanToInt(roman);
    cout << "Integer value: " << number << endl;

    return 0;
}
