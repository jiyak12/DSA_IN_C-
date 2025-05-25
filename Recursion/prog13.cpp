/* 
atoi() stands for ASCII to Integer, and it's a function that converts a numeric string like "1234" to an integer 1234.

In this prog, we need to convert a string of digits into a number one character at a time recursively.
*/

#include <iostream>
#include <string>
using namespace std;

int atoi_recursive(string s) {
    if (s.length() == 0) return 0; // Base case

    char lastChar = s.back();      // Last character
    s.pop_back();                  // Remove last character

    int digit = lastChar - '0';    // Convert char to digit
    int smallAns = atoi_recursive(s); // Recursively get integer for rest of string
    return smallAns * 10 + digit;
}

int main() {
    string s = "1234";
    int result = atoi_recursive(s);
    cout << "Integer is: " << result << endl;
    return 0;
}

/*  
int digit = lastChar - '0'; Characters in C++ are stored using ASCII values.
'0' has ASCII value 48, '1' is 49, ..., '9' is 57.       So: '3' - '0' = 51 - 48 = 3

 int smallAns = atoi_recursive(s);  This line recursively calls the function on the remaining part of the string (after popping the last character)
if s = "1234" After popping the last char '4', now s = "123" 
  after this process process: '1', '2', '3' → returns 123

  return smallAns * 10 + digit; This line adds the last digit back into the full number at the correct place.
Let’s say: smallAns = 123   digit = 4 smallAns * 10 + digit = 123 * 10 + 4 = 1234
*/

