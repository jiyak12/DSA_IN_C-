//generate all possible subsets, but avoid duplicates (since the input array nums may contain duplicates).
//logic- think of a recursive solution that lets to use if to select or not select an element at a particular index

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        result.push_back(temp);
        
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicates

            temp.push_back(nums[i]);
            backtrack(i + 1, nums, temp, result);
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(0, nums, temp, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Unique subsets are:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
