//Maximum Difference Between Increasing Elements


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxDiff = -1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minSoFar) {
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            } else {
                minSoFar = nums[i];
            }
        }
        return maxDiff;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {7, 1, 5, 4};  // Sample input
    int result = sol.maximumDifference(nums);

    cout << "Maximum Difference: " << result << endl;
    return 0;
}
