/*The parameterized recursion approach involves passing additional parameters to the recursive function 
to keep track of the current sum and the current number being considered.*/

//print sum of n numbers using recursion
#include <iostream>
using namespace std;
void sumNumbers(int i,int sum)
{
	if (i<1){
	  cout<<sum<<" "<<endl;  
	 return;
	}
    sumNumbers(i-1,sum+i);
}
int main()
{
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	sumNumbers(n,0);
	return 0;
}

