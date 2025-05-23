// print from n to 1 (counting in bakcwards order)

#include <iostream>
using namespace std;
void printNumbers(int i,int n)
{
    if (i<1) return;
    cout<<i<<""<<endl;
    printNumbers(i-1,n);
    
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    printNumbers(n,n);
    return 0;
}
