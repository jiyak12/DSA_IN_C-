//Find out how many times the array has been rotated
/*
Initialize Two Pointers: low at the start, high at the end of the array.
Binary Search Loop: Compute mid = (low + high) / 2. Check If Subarray Is Sorted: If arr[low] <= arr[high], the whole subarray is sorted.
Pick arr[low] as the minimum. Update ans and index if arr[low] < ans. Break as we've found the minimum.
Determine Sorted Half: If arr[low] <= arr[mid] (left half is sorted): Check arr[low] < ans → update ans and index.
Eliminate left half: low = mid + 1. Else (right half is sorted): Check arr[mid] < ans → update ans and index.
Eliminate right half: high = mid - 1.
  */




#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}

