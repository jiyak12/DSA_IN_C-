//prime no check

//logic- only two factors 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cnt++;
        }
    }

    if (cnt == 2) {
        cout << "true";  // It's a prime number
    } else {
        cout << "false"; // Not a prime number
    }

    return 0;
}
