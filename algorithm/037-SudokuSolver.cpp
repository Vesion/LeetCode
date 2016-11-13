#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// common backtracking solution
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k) { // choose a number from 1...9
                        board[i][j] = '1' + k;
                        if (valid(board, i, j) && dfs(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool valid(vector<vector<char>>& board, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][col] == board[row][col]) return false; // check row
            if (i != col && board[row][i] == board[row][col]) return false; // check col
            int si = 3*(row/3) + i/3, sj = 3*(col/3) + i%3;
            if (si != row && sj != col && board[si][sj] == board[row][col]) return false; // check square
        }
        return true;
    }
};



// Here is a much faster solution
// https://discuss.leetcode.com/topic/7195/sharing-my-2ms-c-solution-with-comments-and-explanations

int main() {
    Solution s;
    return 0;
}

