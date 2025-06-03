/*Create a 2D vector triangle with numRows rows.

Loop through each row index i:

Resize the ith row to have i + 1 elements.

Set the first and last elements of the row to 1.

For each middle element (j from 1 to i-1), compute:

Copy
Edit
triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
Return the completed triangle.
*/




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; i++) {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;

            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};

int main() {
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    Solution sol;
    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle up to " << numRows << " rows:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
