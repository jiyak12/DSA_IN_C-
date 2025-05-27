//in an array if asked how many times an element occurs in the array ..this first approach that comes to mind is using for loop
//can iterate through entire array and update counter to check no of times an element appears for this the TC- O(Q x n)
//hashing is pre stroing and fetching . It simplifies the task of fetching and reduces time complexity.
//logic-  Use an array (or map) to keep count of occurrences of elements. use the value of the element as an index in this array.


//code for performing hash operation to count the number of elements appearing in a text.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n]; // Read the size of the array n and then read n elements into the array arr.
	for(int i =0; i<n;i++){
	    cin >> arr[i];//Input all the elements of the array 
	}
	// precompute 
	int hash[13] ={0};
	for(int i =0; i<n; i++){
	    hash[arr[i]] +=1;//For each number in the input array, increase the count at the index arr[i].
	    
	}
	int q;
	cin>> q;
	while(q--) {
	    int number;
	    cin>> number;
	    // fetch
	    cout << hash[number]<< endl;
	}
	return 0;
}
