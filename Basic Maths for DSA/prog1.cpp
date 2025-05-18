//Count the number of digits in a number//

//logic- eg: 4456 >0 count-1 ,4456/10=445 > 0 count-2, 445/10=44 >0 count-3, 44/10=4 >0 count-4
#include <bits/stdc++.h>
using namespace std;

int count(int n) {
    int count = 0;
    while(n > 0) {
        count = count + 1;
        n = n / 10;
    }
    return count;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int digits = count(number);
    cout << "Number of digits: " << digits << endl;

    return 0;
}

//NOTE- TIME COMPLEXITY WHEN THERE IS A DIVISON IS IN LOG TO THE BASE DIVISOR

