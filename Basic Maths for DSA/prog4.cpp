// Armstrong number

//logic- 153= 1^3 + 5^3 + 3^3 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int original = n;

    while (n > 0) {
        int ld = n % 10;
        sum = sum + (ld * ld * ld);
        n = n / 10;
    }

    if (sum == original) {
        cout << "Given input is an Armstrong number." << endl;
    } else {
        cout << "Given input is not an Armstrong number." << endl;
    }

    return 0;
}
