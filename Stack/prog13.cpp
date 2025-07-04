//trapping rainwater

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefix(n), suffix(n);

        // Build prefix max array
        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        // Build suffix max array
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            waterTrapped += min(prefix[i], suffix[i]) - height[i];
        }

        return waterTrapped;
    }
};

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter bar heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution sol;
    int result = sol.trap(height);

    cout << "Total trapped rainwater: " << result << " units" << endl;
    return 0;
}
