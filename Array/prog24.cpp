//longest subarray with given sum
// concept used -prefix sum of a subarray ending at index i simply means the sum of all the elements of that subarray.
/*
declare a map to store the prefix sums and their counts.
set the value of 0 as 1 on the map.
run a loop(say i) from index 0 to n-1(n = size of the array).
For each index i:
add the current element i.e. arr[i] to the prefix sum.
calculate the prefix sum i.e. x-k, for which we need the occurrence.
add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
store the current prefix sum in the map increasing its occurrence by 1.
*/


#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    map mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}


