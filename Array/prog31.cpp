//max prod subarray in an array
/*
  Initially store 0th index value in prod1, prod2 and result.
Traverse the array from 1st index. 
For each element, update prod1 and prod2.
Prod1 is max(current element, current*prod1, current*prod2)
Prod2 is min(current element, current*prod1, current*prod2)
Return maximum of result and prod1
*/

#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}


