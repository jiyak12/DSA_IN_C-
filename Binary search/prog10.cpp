//A peak element in an array refers to the element that is greater than both of its neighbors. Basically, if arr[i] is the peak element, arr[i] > arr[i-1] and arr[i] > arr[i+1].

/*
 Edge Cases:
Array Size = 1 (n == 1): The only element is the peak.   Return index 0.
First Element (i == 0) : No arr[i-1] exists.  Treat arr[-1] as negative infinity.   Check: arr[0] > arr[1]
Last Element (i == n - 1) : No arr[i+1] exists.  Treat arr[n] as negative infinity.   Check: arr[n-1] > arr[n-2]
*/



#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}



