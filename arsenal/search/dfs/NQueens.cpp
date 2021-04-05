#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;


// N-Queens is a very classical dfs/backtracking problem


// Solution 1 : standard (naive) dfs
class Solution_1 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        dfs(result, board, 0, n);
        return result;
    }

private:
    void dfs(vector<vector<string>> &result, vector<string> &board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(board, row, i, n)) {
                board[row][i] = 'Q';
                dfs(result, board, row + 1, n);
                board[row][i] = '.';
            }
        }
    }

    bool check(vector<string> &board, int row, int column, int n) {
        for (int i = 0; i < row; ++i) { // check column
            if (board[i][column] == 'Q')
                return false;
        }
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; --i, --j) { // check 45' diagonal
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = column + 1; i >= 0 && j < n; --i, ++j) { // check 135' diagonal
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};


// Solution 2 : mark col, left_diagonal, right_diagonal
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



// Solutions below just return number of valid N-Queens, do not output whole solution
// More consice and tricky solutions are:
// https://www.zhihu.com/question/28543312

// Solution 3 : bitmask, use bit to represent board, maybe the fastest solution!
// http://blog.csdn.net/xadillax/article/details/6512318
class Solution_3 {
public:
    int totalNQueens(int n) {
        int res = 0;
        dfs(0, 0, 0, (1<<n)-1, res);
        return res;
    }
    void dfs(int row, int ld, int rd, int board, int& res) {
        if (row == board) {
            ++res;
            return;
        }
        int valid = board & ~(row|ld|rd); // get all available postion
        while (valid) { // try each position
            int pos = valid & -valid; // get the lowest bit position
            dfs(row|pos, (ld|pos)<<1, (rd|pos)>>1, board, res);
            valid -= pos;
        }
    }
};

int main() {
    Solution_3 s3;
    cout << s3.totalNQueens(8) <<endl;;
    return 0;
}
