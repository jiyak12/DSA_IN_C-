//maximal rectangle
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Histogram helper function to compute max rectangle area in histogram
    int histogram(vector<int> row) {
        int maxi = 0;
        int n = row.size();
        int nse = 0;
        int pse = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && row[st.top()] > row[i]) {
                int element = row[st.top()];
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                int area = element * (nse - pse - 1);
                maxi = max(maxi, area);
            }
            st.push(i);
        }

        // Process remaining elements in the stack
        while (!st.empty()) {
            nse = n;
            int element = row[st.top()];
            st.pop();
            pse = st.empty() ? -1 : st.top();
            int area = element * (nse - pse - 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }

    // Main function to find maximal rectangle of 1s
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int columns = matrix[0].size();

        // Convert matrix into histogram height matrix
        vector<vector<int>> presum(rows, vector<int>(columns, 0));

        for (int i = 0; i < columns; i++) {
            int sum = 0;
            for (int j = 0; j < rows; j++) {
                if (matrix[j][i] == '1') sum++;
                else sum = 0;
                presum[j][i] = sum;
            }
        }

        int maxi = 0;
        for (int i = 0; i < rows; i++) {
            maxi = max(maxi, histogram(presum[i]));
        }

        return maxi;
    }
};

int main() {
    Solution sol;

    // Example input matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = sol.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;

    return 0;
}
