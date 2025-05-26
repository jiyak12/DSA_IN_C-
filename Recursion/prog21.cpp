/* combination sum II where:
Each number may be used at most once
avoid duplicate combinations
Input must be sorted before applying the duplicate check logic (arr[i] == arr[i-1])
*/
#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(target==0){
            ans.push_back(ds);
        return;
        }
   //pick up the element 
    for(int i = ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        findCombination(ind+1 ,target-arr[i], arr, ans, ds);
        ds.pop_back();
    }
   
}
int main(){
    vector<int> candidates ={10,1,2,7,6,1,5};
    int target =8;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    cout << "Combinations that sum to " << target << ":\n";
    for (auto comb : ans){
        cout << "[";
        for(int num : comb){
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}

    
