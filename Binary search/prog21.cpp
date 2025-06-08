/*You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.*/


/* First, sort the given stalls[] array.
Place the 2 pointers i.e. low(1) and high(stalls[n-1]-stalls[0]  As the ‘stalls[]’ is sorted, ‘stalls[n-1]’ refers to the maximum, and ‘stalls[0]’ is the minimum element.
Calculate mid’: mid = (low+high) // 2 ( ‘//’ refers to integer division)
Eliminate the halves based on the boolean value returned by canWePlace():
pass the potential distance, represented by the variable 'mid', to the ‘canWePlace()' function. This function will return true if it is possible to place all the cows with a minimum distance of ‘mid’.
If the returned value is true: On satisfying this condition, ‘mid’ is one of our possible answers. for max no, eliminate the left half and consider the right half(i.e. low = mid+1).
Otherwise, the value mid is greater than the distance we want. This means the numbers greater than ‘mid’ should not be considered and the right half of ‘mid’ consists of such numbers. So,eliminate the right half and consider the left half(i.e. high = mid-1).
Finally, outside the loop, return the value of high as the pointer will be pointing to the answer. */





#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

