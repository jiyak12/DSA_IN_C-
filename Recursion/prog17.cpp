//print all the subsequences with sum as k
#include <bits/stdc++.h>
using namespace std;

void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
  // It checks if the ind (current index) has reached the end of the array (n). If ind is equal to n, it means we have considered all elements in the array.
  //Inside the base case, if ind == n, this condition checks if the current sum of the subsequence s is equal to the target sum.
    if(ind == n){
        if(s==sum){
            for(auto it : ds) //this loop iterates through each element (it) in the ds (the current subsequence). 
              cout<< it <<" ";//prints each element of the subsequence followed by a space.
            cout << endl;
        }
        return; //After checking the sum and printing if it matches, the function returns, ending the current recursive call.
    }//pick
    ds.push_back(arr[ind]); // adds the element at the current index arr[ind] to the ds (current subsequence).
    s+= arr[ind]; // current sum s is updated by adding the picked element arr[ind]
    
    printS(ind+1 , ds, s, sum, arr, n);
    //not pick
    s-= arr[ind]; // Before exploring the "not pick" path, we undo the changes made by the "pick" path. We subtract arr[ind] from s to revert the sum to what it was before picking the current element.
    ds.pop_back();
    //we remove the arr[ind] element from the ds vector. This is crucial for backtracking: it ensures that when we explore the "not pick" path, the ds doesn't contain the element that was just considered in the "pick" path
    printS(ind+1 , ds, s, sum, arr, n);
    
}

int main() {
    int arr[]={1,2,1,3,2,4};
    int n =6;
    int sum=4;
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
    return 0;
}
