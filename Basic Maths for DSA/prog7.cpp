//GCD or HCF

//logic- Euclidean algo: gcd(a,b) = gcd(a-b, b) where a>b continue till either a-b or b gets zero. the other will become factor
//gcd(a,b) = gcd(a%b,b) till either of the terms become zero here a >b

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << "GCD is: " << gcd(x, y) << endl;
    return 0;
}
