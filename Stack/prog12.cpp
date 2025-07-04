//next smaller element
#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    vector < int > nextSmallerElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nse(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nse[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nse;
    }
};
int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextSmallerElements(v);
  cout << "The next smaller elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
