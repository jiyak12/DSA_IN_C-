//count the subsequences with the sum k
/* logic- in the base case , return 1 if condition satisfies else return 0
  call the left function;then call the right function return the sum of left and right
*/
#include <bits/stdc++.h>
using namespace std;

int printS(int ind, int s, int sum, int arr[], int n){
    if(ind == n){
        //condition satisfied
        if(s==sum) return 1;
        else return 0;
    }//pick
    
    s+= arr[ind];
    
    int l =printS(ind+1, s, sum, arr, n);
    
    //not pick
    s-= arr[ind];
   
    
   int r=printS(ind+1, s, sum, arr, n);
    return l+r;
}

int main() {
    int arr[]={1,2,1,3,2,4};
    int n =6;
    int sum=4;
    
    cout <<printS(0,0,sum,arr,n);
    return 0;
}
