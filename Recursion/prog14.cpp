//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
//here before proceeding to the queston , we need to be clear about n i.e. if its values can be negative or not 
 #include <iostream>
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0; //Initialize the result to 1. This will store your final answer.
    long long nn = n; //n is an integer.But n can be negative, especially INT_MIN, which causes issues when you do -n.So, we use long long to safely store and work with it even if it’s negative.
    if (nn < 0) nn = -1 * nn; //If the exponent is negative, we’ll make it positive for now and remember it's negative.At the end, we’ll take the reciprocal of the result.
    while (nn) {
        if (nn % 2) {
            ans = ans * x;
            nn = nn - 1;
        } else {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0) ans = 1.0 / ans;
    return ans;
}
int main() {
    double base;
    int exponent;
    cout << "Enter base (x): ";
    cin >> base;
    cout << "Enter exponent (n): ";
    cin >> exponent;
    double result = myPow(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;
    return 0;
}
