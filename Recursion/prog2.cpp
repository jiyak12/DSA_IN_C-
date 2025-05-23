//print numbers from 1 to n
#include <iostream>
using namespace std;
void printNumbers(int i,int n)
{
    if (i>n) return;
    cout<<i<<""<<endl;
    printNumbers(i+1,n);
    
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    printNumbers(1,n);
    return 0;
}
