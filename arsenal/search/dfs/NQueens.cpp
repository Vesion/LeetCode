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


// Solution 2 : dfs + bitmask
// The number of columns is n, the number of 45° diagonals is 2*n-1, the number of 135° diagonals is also 2*n-1. 
// When reach [row, col], the 45° diagonal is row+col and the 135° diagonal is n-1+col-row. 
class Solution_2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        /*
		flag[0] to flag[n - 1] to indicate if the column had a queen before.
		flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
		flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
		*/
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
