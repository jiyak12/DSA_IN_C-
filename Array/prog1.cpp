// all elements in the array should be of the same data type
//if an array is defined globally i.e before int main , the values of all the elements becomes equal to the globally defined value.
//the max size of array which can be declared inside int main function is 10^6 while the global value is 10^7
//in an array the first index is 0 and last index is n-1.
//accessing an array by an address is not possible though the elemnts of array are stored in contigous memory location.
#include <bits/stdc++.h>
using namespace std;

int largestElement(int n, vector<int> &arr) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = largestElement(n, arr);
    cout << "The largest element is: " << result << endl;

    return 0;
}
