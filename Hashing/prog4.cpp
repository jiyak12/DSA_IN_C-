/* 
ordered maps are used for storing :
Large numbers (e.g., 1e9)
Negative numbers (array indices can't be negative)
Non-integer types (like strings, pairs, etc.)
*/
//syntax of map -   map<key_type, value_type> map_name;
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin >> arr[i];
	}
	// precompute 
	map<int, int> mpp;
	for(int i =0; i<n; i++){
	    mpp[arr[i]]++;
	}
	for(auto it : mpp){
	    cout << it.first << "->" << it.second << endl;
	}
	int q;
	cin>> q;
	while(q--) {
	    int number;
	    cin >> number;
	    // fetch
	    cout << mpp[number] << endl;
	}
	return 0;
}
