//remove dupes from sorted array
// modify and return the unique elements by using set data structure

#include <bits/stdc++.h>
using namespace std;

// Removes duplicates from sorted array and returns new size
int duplicateElements(vector<int> &a, int n) {
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (a[i] != a[j]) {
            i++;
            a[i] = a[j];
        }
    }
    return i + 1; // size of array after removing duplicates
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array before removing duplicates
    sort(a.begin(), a.end());

    int newSize = duplicateElements(a, n);

    cout << "The sorted array after removing duplicate elements is:\n";
    for (int i = 0; i < newSize; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
