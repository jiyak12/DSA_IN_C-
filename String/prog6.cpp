//check if string is rotated or not
//check if the length of main string and goal string is true or not. in case it is true , concat mainStr + mainStr and search for goal string in the concatenated string if it matches , return true else return false.
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string concat = s + s;

        // Check if goal exists as a substring of s + s
        if (concat.find(goal) == string::npos)
            return false;

        return true;
    }
};

int main() {
    string s, goal;
    cout << "Enter the original string (s): ";
    cin >> s;

    cout << "Enter the goal string: ";
    cin >> goal;

    Solution sol;
    bool result = sol.rotateString(s, goal);

    if (result)
        cout << "Yes, '" << goal << "' is a rotation of '" << s << "'." << endl;
    else
        cout << "No, '" << goal << "' is not a rotation of '" << s << "'." << endl;

    return 0;
}
