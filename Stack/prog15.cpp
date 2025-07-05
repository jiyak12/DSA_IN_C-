/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        // ---------- STEP 1: Calculate contribution as maximum ----------
        // For each element, calculate how many subarrays it is the maximum of
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            // Use sentinel value: when i == n, treat nums[i] as INT_MAX to clear stack
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top();    // Element that is now being "closed"
                st.pop();
                int left = st.empty() ? -1 : st.top();  // Previous greater element
                int right = i;         // Next greater element
                // Count of subarrays where nums[mid] is the maximum
                long long count = (mid - left) * 1LL * (right - mid);
                // Add its total contribution
                sum += count * nums[mid];
            }
            st.push(i);
        }

        // ---------- STEP 2: Calculate contribution as minimum ----------
        while (!st.empty()) st.pop();  // Clear the stack

        for (int i = 0; i <= n; ++i) {
            // Use sentinel value: when i == n, treat nums[i] as INT_MIN to clear stack
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top();    // Element that is now being "closed"
                st.pop();
                int left = st.empty() ? -1 : st.top();  // Previous less element
                int right = i;         // Next less element
                // Count of subarrays where nums[mid] is the minimum
                long long count = (mid - left) * 1LL * (right - mid);
                // Subtract its total contribution
                sum -= count * nums[mid];
            }
            st.push(i);
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // Example input
    long long result = sol.subArrayRanges(nums);
    cout << "Sum of Subarray Ranges: " << result << endl;  // Output: 4
    return 0;
}

