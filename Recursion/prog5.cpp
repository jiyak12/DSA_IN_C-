// print n to 1 using backtracking

#include <iostream>
using namespace std;
void printNumbersBacktracking(int i,int n)
{
	if (i>n) return;
    printNumbersBacktracking(i+1,n);
	cout<<i<<""<<endl;
}
int main()
{
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	printNumbersBacktracking(1,n);
	return 0;
}
