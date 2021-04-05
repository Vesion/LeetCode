#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// naive
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


// mark col, left_diagonal, right_diagonal
class Solution {
public:
    vector<vector<string>> res;
    vector<bool> col, ld, rd;
    vector<string> board;

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false);
        ld.resize(2*n-1, false);
        rd.resize(2*n-1, false);
        board.resize(n, string(n, '.'));
        dfs(0, n);
        return res;
    }

    void dfs(int i, int n) {
        if (i == n) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j < n; ++j) {
            int l = i+n-1-j;
            int r = i+j;
            if (col[j] || ld[l] || rd[r]) continue;
            col[j] = ld[l] = rd[r] = true;
            board[i][j] = 'Q';
            dfs(i+1, n);
            board[i][j] = '.';
            col[j] = ld[l] = rd[r] = false;
        }
    }
};


int main() {
    return 0;
}
