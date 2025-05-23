// print linearly from 1 to n using backtracking

#include <iostream>
using namespace std;
void printNumbers(int i,int n)
{
    if (i<1) return;
    printNumbers(i-1,n);
    cout<<i<<""<<endl;
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    printNumbers(n,n);
    return 0;
}
