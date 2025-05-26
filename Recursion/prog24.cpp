//N-queens problem
//concept used- hashing, backtracking
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n); 
        string s(n, '.'); //s: a row with n dots (.) indicating empty cell
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }//The entire board is initialized with dots (.).

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
/* leftRow[row]: checks if row is safe.
lowerDiagonal[row + col]: represents / diagonals.
upperDiagonal[n - 1 + col - row]: represents \ diagonals.
All initialized to 0 (safe)
*/
private:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
              /* We check if placing a queen at (row, col) is safe by verifying:
               Row is not occupied
               Neither diagonal is occupied */
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                //place the queen and mark that row and both diagonals as occupied.
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                 //move to next column
                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;// undo all the placement 
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter value of N (number of queens): ";
    cin >> n;

    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);

    cout << "\nAll possible solutions:\n";
    for(int i = 0; i < result.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for(const string& row : result[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
