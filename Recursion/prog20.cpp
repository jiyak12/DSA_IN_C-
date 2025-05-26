//combination sum

#include <bits/stdc++.h>
using namespace std;
/* void findCombination(...): This declares a recursive function named findCombination that returns nothing (void). This function is the core of the backtracking algorithm.
int ind: Represents the current index of the arr array that the function is considering. It helps in iterating through the candidates.
int target: Represents the remaining sum that needs to be achieved. This value decreases as elements are picked.
vector<int> &arr: A reference to the candidates array. It's passed by reference (&) to avoid costly copying in each recursive call.
vector<vector<int>> &ans: A reference to a vector of vectors of integers. This will store all the valid combinations (subsequences) that sum up to the target. It's passed by reference so the function can add found combinations to it.
vector<int> &ds: A reference to a vector of integers named ds (short for "data structure" or "dynamic subsequence"). This stores the current combination being built during the recursion. It's also passed by reference to avoid copying and to allow backtracking (adding/removing elements).
*/
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(ind == arr.size()){
      //if the ind (current index) has reached the end of the arr array (arr.size()). If true, it means all elements in the candidates array have been considered.
        if(target==0){ //if(target==0): If, after considering all elements, the target has been reduced exactly to 0, it means the ds (current combination) sums up to the original target.
            ans.push_back(ds);
        }
        return;
    }
   //pick up the element 
   if(arr[ind] <= target){
     // If arr[ind] is greater than target, picking it would immediately make target negative, leading to an invalid combination.
       ds.push_back(arr[ind]);
       findCombination(ind ,target-arr[ind], arr, ans, ds);
       ds.pop_back();
   }
   findCombination(ind+1 ,target, arr, ans, ds);
}
int main(){
    vector<int> candidates ={2,3,6,7};
    int target =7;
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

    
