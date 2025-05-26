/* find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/





#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int k, int n, vector<vector<int>> &ans, vector<int> &ds){
        if(k==0 && n==0){
            ans.push_back(ds);
        return;
        }
   //pick up the element 
    if(k==0 && n<=0) return;
    for(int i = ind;i<=9;i++){
        ds.push_back(i);
        findCombination(i+1 ,k-1, n-i, ans, ds);
        ds.pop_back();
    }
   
}
int main(){
    int k=3;
    int n=9;
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(1, k, n, ans, ds);
    cout << "Combinations that sum to " << k <<"numbers that sum to"<< n << ":\n";
    for (auto& comb : ans){
        cout << "[";
        for(int num : comb){
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}

    
