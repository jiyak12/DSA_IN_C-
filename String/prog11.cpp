//integer to roman
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Define Roman numeral symbols and their corresponding values
        int values[] =    {1000, 900, 500, 400, 100, 90,  50, 40,  10, 9,   5, 4,  1};
        string symbols[] ={"M",  "CM","D", "CD","C", "XC","L","XL","X","IX","V","IV","I"};

        string roman = "";

        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                roman += symbols[i];
                num -= values[i];
            }
        }

        return roman;
    }
};

int main() {
    Solution sol;
    int number;
    cout << "Enter an integer (1 to 3999): ";
    cin >> number;

    if (number < 1 || number > 3999) {
        cout << "Invalid input. Enter a number between 1 and 3999." << endl;
    } else {
        string romanNumeral = sol.intToRoman(number);
        cout << "Roman numeral: " << romanNumeral << endl;
    }

    return 0;
}
