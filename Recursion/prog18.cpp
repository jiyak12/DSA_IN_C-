//print any one subsequence is the sum

//technique to print only one answer
/* in the base case condition if the condition is satisfied ,return true. If not return false.
  if function call is true then no need to look for other answers , just return with the obtained answer. */
#include <bits/stdc++.h>
using namespace std;

bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
  //This boolean return value is the key to signaling whether a valid subsequence has been found down that particular recursive path.
    if(ind == n){
        //condition satisfied
        if(s==sum){
            for(auto it : ds) cout<< it <<" ";
            cout << endl;
            return true;
          //This is crucial. It immediately signals back up the call stack that a solution has been found.
        }
        else return false;
      // If s is not equal to sum at the end of the array, this path did not lead to a solution, so false is returned.
    }//pick
    ds.push_back(arr[ind]);
    s+= arr[ind];
    
    if (printS(ind+1 , ds, s, sum, arr, n)==true) {
        return true;
      //This is the core of the "find one and stop" technique. If the recursive call returns true (meaning a solution was found further down that path), then the current function call also immediately returns true. 
      //This effectively stops further exploration down other branches once a solution is confirmed.
    }
    //not pick
    s-= arr[ind];
    ds.pop_back();
    
    if (printS(ind+1 , ds, s, sum, arr, n)== true) return true;
  // Again, if this recursive call returns true, it means a solution was found. The current function immediately returns true to propagate this information up.
    return false;
  //If neither the "pick" path nor the "not pick" path originating from ind found a solution (i.e., both recursive calls returned false), then this current call printS(ind, ...) also returns false, signaling that no solution was found from this point onwards.
}

int main() {
    int arr[]={1,2,1,3,2,4};
    int n =6;
    int sum=4;
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
    return 0;
}
