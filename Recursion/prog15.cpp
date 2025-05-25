/* 
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. 
However, "3245" is not good because 3 is at an even index but is not even.
  */


//the total number of good digit strings of length n

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
// Define a constant modulo value = 10^9+ 7 =1000000007
//This is used to take results under modulo (as required by the problem) to avoid integer overflow.


// Function to compute (base^exp) % MOD using binary exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int countGoodNumbers(long long n) {
    long long even_positions = (n + 1) / 2;  // indices: 0, 2, 4,...
    long long odd_positions = n / 2;         // indices: 1, 3, 5,...

    long long even_choices = modPow(5, even_positions, MOD);
    long long odd_choices = modPow(4, odd_positions, MOD);

    return (even_choices * odd_choices) % MOD;
}

int main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Good digit strings of length " << n << ": " << countGoodNumbers(n) << endl;
    return 0;
}

