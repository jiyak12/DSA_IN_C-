/*  A subsequence is a sequence that can be derived by deleting zero or more elements without changing the order of the remaining elements.

For example, for an array [1, 2, 3], the subsequences are:
[ ], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
There are 2^n subsequences for an array of size n.
*/


/* 
Core Logic (Include/Exclude Strategy)
At each index of the array, you have two choices:
-Include the current element in your subsequence.
-Exclude the current element and move on.
*/


//print all the subsequences
#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(int index, vector<int> &arr, vector<int> &subseq) 
/* This is a recursive function to generate all subsequences of the array.
index tracks the current position in the original array arr.
arr is the original array.
subseq stores the current subsequence being formed.
& means both vectors are passed by reference to avoid copying and to allow modification.*/
{
    if (index == arr.size()) {
        for (int num : subseq) // range-based for loop 
        {
            cout << num << " ";
          //Loop through the current subseq and print each number.
        }
        cout << endl;
        return;
    }

    subseq.push_back(arr[index]); //Include the current element arr[index] in the subsequence.push_back() adds an element to the end of the vector.
    printSubsequences(index + 1, arr, subseq);

    subseq.pop_back(); //Backtrack: remove the element we just added to try the exclude path.This step is crucial to undo the previous inclusion before trying the next path.
    printSubsequences(index + 1, arr, subseq);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> subseq;

    printSubsequences(0, arr, subseq);

    return 0;
}
