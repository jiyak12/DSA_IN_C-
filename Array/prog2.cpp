//the find the second largest and second smallest in an array
#include <bits/stdc++.h>
using namespace std;
int secondLargest(vector<int> &a, int n){
    int largest = a[0];
    int slargest =-1;
    for(int i=1;i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest =a[i];
        }else if(a[i]<largest && a[i]>slargest){
            slargest=a[i];
        }
        }
    return slargest;    
}

int secondSmallest(vector<int> &a, int n){
    int smallest = a[0];
    int ssmallest =-1; //initializing ssmallest = -1 could produce wrong results if all array elements are positive. It should be initialized to something like INT_MAX .
    for(int i=1;i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest =a[i];
        }else if(a[i]>smallest && a[i]<ssmallest){
            ssmallest=a[i];
        }
        }
    return ssmallest;    
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

    int result1 = secondLargest(a,n);
    cout << "The second largest element is: " << result1 << endl;
    
    int result2 = secondSmallest(a,n);
    cout << "The second smallest element is: " << result2 << endl;
    return 0;
}
