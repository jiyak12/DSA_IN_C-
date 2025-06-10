// Largest odd number in string
#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);  // include up to the last odd digit
        }
    }
    return "";
}

int main() {
    string num;
    cout << "Enter a numeric string: ";
    cin >> num;

    string result = largestOddNumber(num);
    if (!result.empty()) {
        cout << "Largest odd number from left: " << result << endl;
    } else {
        cout << "No odd-numbered prefix found." << endl;
    }

    return 0;
}
