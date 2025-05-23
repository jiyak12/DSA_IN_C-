/* Print name  N times using recursion */

#include <iostream>
using namespace std;
void printName(int i,int n)
{
    if (i>n) return;
    cout<<"My name is Khan"<<endl;
    printName(i+1,n);
    
}
int main()
{
    int n;
    cout << "Enter how many times to print: ";
    cin>>n;
    printName(1,n);
    return 0;
}
