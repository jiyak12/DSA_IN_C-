//Find a way to convert the number into the maximum possible value (by replacing a digit with 9).
//Find a way to convert the number into the minimum possible value (by replacing a digit with 0 or something small—but no leading zeros).

/*
Convert the number to a string for easy digit manipulation.
To form the maximum, replace the first digit that’s not 9 with 9 in all its occurrences.
To form the minimum, replace:
If the first digit ≠ 1, replace all its occurrences with 1.
Else, replace the first non-0/1 digit (from index 1) with 0 to avoid leading zero.
Convert both results to integers and return the difference.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // Create the maximum number by replacing the first non-9 digit with '9'
        string maxNum = s;
        for (char c : s) {
            if (c != '9') {
                replace(maxNum.begin(), maxNum.end(), c, '9');
                break;
            }
        }

        // Create the minimum number
        string minNum = s;
        if (s[0] != '1') {
            replace(minNum.begin(), minNum.end(), s[0], '1');
        } else {
            for (int i = 1; i < s.length(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    replace(minNum.begin(), minNum.end(), s[i], '0');
                    break;
                }
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};

int main() {
    Solution sol;
    int num = 555;
    cout << "Maximum Difference: " << sol.maxDiff(num) << endl;
    return 0;
}
