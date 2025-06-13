//Maximum Difference Between Adjacent Elements in a Circular Array
//Given a circular array nums, find the maximum absolute difference between adjacent elements. Note: In a circular array, the first and last elements are adjacent.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = abs(nums[0] - nums[n - 1]);  // Circular difference
        for (int i = 1; i < n; i++) {
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {1, 3, 10, 6, 4};

    int result = sol.maxAdjacentDistance(nums);

    cout << "Maximum adjacent distance: " << result << endl;

    return 0;
}
