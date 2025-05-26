//solve the sudoku puzzle
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);// calls the recursive helper solve() to fill the Sudoku board.
    }

/* fill each empty cell (denoted by '.') with digits '1' to '9' For each number, it checks if the placement is valid using the isValid() function.
If valid, it places the number and recursively solves the rest of the board. If it leads to a dead end, it backtracks by resetting the cell to '.'.
Returns true when the entire board is filled correctly. */
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c;
                            if (solve(board)== true) return true;
                            board[row][col] = '.';  // backtrack
                        }
                    }
                    return false;  // no valid number found
                }
            }
        }
        return true;  // all cells filled
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            // Check row
            if (board[row][i] == c) return false; //for checking in the row, the row remains same but the column increases
            // Check column
            if (board[i][col] == c) return false;//for checking in col , the col remains same but row increases
            // Check 3x3 box
            int boxRow = 3 * (row / 3) + i / 3;//row / 3 and col / 3 integer-divide the row and column into blocks of 3 (i.e., 0, 1, or 2).
            int boxCol = 3 * (col / 3) + i % 3;//Multiplying by 3 gives the starting index of that 3×3 subgrid.
          //i / 3 gives the row offset (0 to 2)         i % 3 gives the column offset (0 to 2)
            if (board[boxRow][boxCol] == c) return false;
        }
        return true;
    }
};


int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solver;
    solver.solveSudoku(board);

    cout << "Solved Sudoku:\n";
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}
