// m x n grid of characters board and a string word, return true if word exists in the grid.The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
//word search problem
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
//this function looops through every cell in the grid. if the cell matches the first letter of the word, it calls dfs() to explore that path
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;// checks if the current index has reached the end of the word

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false; //checks if the character doesn't match the current letter in the word
        }

        char temp = board[i][j];
        board[i][j] = '#';//marking the current cell as visited to avoid revisiting the same path
        // calling dfs function in all the directions
        bool found = dfs(board, word, i + 1, j, idx + 1) || //up
                     dfs(board, word, i - 1, j, idx + 1) || //down
                     dfs(board, word, i, j + 1, idx + 1) || //left
                     dfs(board, word, i, j - 1, idx + 1); //right

        board[i][j] = temp;

        return found;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED"; // Try changing this to test other words

    Solution sol;
    bool result = sol.exist(board, word);

    cout << "Word \"" << word << "\" exists in the board: " << (result ? "Yes" : "No") << endl;

    return 0;
}
