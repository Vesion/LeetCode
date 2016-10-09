#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
// When reach [row, col], the column is col, the 45° diagonal is row+col and the 135° diagonal is n-1+col-row. 
class Solution_2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> path(n, string(n, '.'));
        /*
		flag[0] to flag[n - 1] to indicate if the column had a queen before.
		flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
		flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
		*/
        vector<int> flag(5*n-2, 1);
        dfs(result, path, flag, 0, n);
        return result;
    }
private:
    void dfs(vector<vector<string>>& result, vector<string>& path, vector<int>& flag, int row, int n) {
        if (row == n) {
            result.push_back(path);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (flag[col] && flag[n+row+col] && flag[4*n-2+row-col]) {
                flag[col] = flag[n+row+col] = flag[4*n-2+row-col] = 0;
                path[row][col] = 'Q';
                dfs(result, path, flag, row+1, n);
                path[row][col] = '.';
                flag[col] = flag[n+row+col] = flag[4*n-2+row-col] = 1;
            }
        }
    }
};

int main() {
    Solution_1 s;
    auto result = s.solveNQueens(4);
    for (auto v : result) {
        for (auto s : v) {
            cout << s << endl;
        }
        cout << endl;
    }
}
