#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : trivial backtracking
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }

    bool dfs(vector<vector<char>>& board, int pos) {
        if (pos == 9 * 9) return true;

        const int row = pos / 9;
        const int col = pos % 9;
        if (board[row][col] != '.') return dfs(board, pos+1);
        for (char c = '1'; c <= '9'; ++c) {
            board[row][col] = c;
            if (valid(board, row, col) && dfs(board, pos+1)) return true;
            board[row][col] = '.';
        }
        return false;
    }

    bool valid(const vector<vector<char>>& board, int row, int col) {
        for (int i = 0; i < 9; ++i) if (i != row && board[i][col] == board[row][col]) return false;
        for (int j = 0; j < 9; ++j) if (j != col && board[row][j] == board[row][col]) return false;
        const int sr = 3*(row/3), sj = 3*(col/3);
        for (int i = sr; i < sr+3; ++i) {
            for (int j = sj; j < sj+3; ++j) {
                if (i != row && j != col && board[i][j] == board[row][col]) return false;
            }
        }
        return true;
    }
};


// Here is a much faster solution
// https://leetcode.com/problems/sudoku-solver/discuss/15748/Sharing-my-2ms-C%2B%2B-solution-with-comments-and-explanations.


int main() {
    return 0;
}
