// Print all divisors of a number

//logic-take a for loop of i integers and check if n% i = 0 ,if its true then divisor is obtained. note - the smallest divisor of a no is 1 and largest is the number itself.
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
void printDivisors(int n) {
for(int i=1; i<=n; i++) {
if(n % i == 0){
cout << i << " ";
}
}
}
int main() {
int n;
cin >> n;
printDivisors(n);
return 0;
}
