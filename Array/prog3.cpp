//check if the array is sorted
//an array is sorted if a[i]>=a[i-1]
#include <bits/stdc++.h>
using namespace std;
bool sortedArray(vector<int> &a, int n){
    for(int i=1; i<n; i++){
        if(a[i]>=a[i-1]){
    }else return false;
    }
    return true;
}    
 
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    
    if (sortedArray(a, n)) {
        cout << "The array is sorted in non-decreasing order.\n";
    } else {
        cout << "The array is not sorted.\n";
    }

    return 0;
    }
}
