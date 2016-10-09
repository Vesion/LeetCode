#include <iostream>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

// Solution 0 : naive dfs
class Solution_0 {
public:
    bool check(vector<string> &board, int row, int column, int n) {
        for (int i = 0; i < row; ++i) {
            if (board[i][column] == 'Q')
                return false;
        }
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; --i, --j){
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = column + 1; i >= 0 && j < n; --i, ++j){
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void dfs(vector<string> &board, int row, int n, int &result) {
        if (row == n) {
            result++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(board, row, i, n)) {
                board[row][i] = 'Q';
                dfs(board, row + 1, n, result);
                board[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int result = 0;
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n, result);   
        return result;
    }
};


// Solution 1 : bitmask, use bit to represent board, maybe the fastest solution!
// http://blog.csdn.net/xadillax/article/details/6512318
class Solution_1 {
public:
    int totalNQueens(int n) {
        int board = (1 << n) - 1, res = 0;
        dfs(0, 0, 0, board, res);
        return res;
    }
    void dfs(int row, int ld, int rd, int& board, int& res) {
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


// Solution 2 : brute-force enumerate, much slower
class Solution_2 {
public:
    int totalNQueens(int n){
        int *pos = new int[n], ans = 0;
        iota(pos, pos+n, 0);
        while(next_permutation(pos,pos+n)) {
            bool ok = true;
            for(int* p = pos; p < pos+n; p++) // only need to check two diagonals
                if (count_if(pos, p, [=](int& i) {return p-&i == *p-i || p-&i == i-*p;} )) { ok = false; break; }
            ans += ok;
        }
        return n == 1 ? 1 : ans;
    }
};

int main() {
    Solution_1 s;
    cout << s.totalNQueens(6) << endl;
}
