//intersection of 2 sorted array 
// optimal approach is by using two pointers


#include <bits/stdc++.h>
using namespace std;
vector<int> findArrayIntersection(vector<int> &A,int n, vector<int> &B, int m){
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<A[i]){
            j++;
        }
        else{
            ans.push_back(A[i]);
                i++;
                j++;
            }
        }
    return ans;
}
int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {2, 4, 6, 8};

    vector<int> result = findArrayIntersection(A, A.size(), B, B.size());

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
