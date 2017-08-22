#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : trivial backtracking
class Solution_1 {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return {};
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n, res);
        return res;
    }
    
    void dfs(vector<string>& board, int row, int n, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j < n; ++j) {
            board[row][j] = 'Q';
            if (valid(board, row, j, n)) dfs(board, row+1, n, res);
            board[row][j] = '.';
        }
    }
    
    bool valid(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < row; ++i) if (board[i][col] == 'Q') return false;
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) if (board[i][j] == 'Q') return false;
        for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j) if (board[i][j] == 'Q') return false;
        return true;
    }
};


// Solution 2 : dfs + bitmask
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> flag(n + (2*n-1) + (2*n-1), 1);
        dfs(0, n, flag, board, res);
        return res;
    }

    void dfs(int row, int n, vector<bool>& flag, vector<string>& board, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (flag[col] && flag[n+row+col] && flag[4*n-2+col-row]) {
                flag[col] = flag[n+row+col] = flag[4*n-2+col-row] = false;
                board[row][col] = 'Q';
                dfs(row+1, n, flag, board, res);
                board[row][col] = '.';
                flag[col] = flag[n+row+col] = flag[4*n-2+col-row] = true;
            }
        }
    }
};


int main() {
    return 0;
}
