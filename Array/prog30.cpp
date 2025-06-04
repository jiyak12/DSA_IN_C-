//merging two sorted arrays 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;        // Last index of nums1's valid elements
        int j = n - 1;        // Last index of nums2
        int k = m + n - 1;    // Last index of nums1 (including extra space)

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 has remaining elements
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};  // Initial nums1 (size m + n)
    int m = 3;  // Number of initialized elements in nums1

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
