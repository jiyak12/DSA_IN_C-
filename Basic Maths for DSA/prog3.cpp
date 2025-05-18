// print true if a number is palindrome and false if not

//logic- reverse the number and then compare it with existing no but n can be zero so we need to take a dupe variable that stores n
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int revNum = 0;
    int dup = n;

    while(n > 0) {
        int ld = n % 10;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }

    cout << "Reversed number: " << revNum << endl;

    if(dup == revNum) {
        cout << "True" << endl;  // It's a palindrome
    } else {
        cout << "False" << endl; // Not a palindrome
    }

    return 0;
}
