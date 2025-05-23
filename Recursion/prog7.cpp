/* The functional recursion approach involves defining a recursive function without any additional parameters.
The function simply calls itself with a modified argument until it reaches the base case. */
// print the sum of first n numbers using functional recursion approach


#include <iostream>
using namespace std;
int sum(int n)
{
	if (n==0) return 0;
	return n + sum(n-1);
}
int main()
{
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<sum(n);
	return 0;
}
