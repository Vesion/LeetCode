#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    int N;

    bool check(int x, int y) {
        for (int i = 0; i < x; ++i) { // check column
            if (board[i][y] == 'Q')
                return false;
        }
        for (int i = x-1, j = y-1; i >= 0 && j >= 0; --i, --j) { // check main diagonal
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = x-1, j = y+1; i >= 0 && j < N; --i, ++j) { // check anti diagonal
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void dfs(int x) {
        if (x == N) {
            result.push_back(board);
            return;
        }
        for (int y = 0; y < N; ++y) {
            if (check(x, y)) { // check first
                board[x][y] = 'Q';
                dfs(x+1);
                board[x][y] = '.';
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        N = n;
        dfs(0);
        return result;
    }
};

int main() {
    Solution s;
    auto r = s.solveNQueens(3);
    for (auto i : r) {
        for (auto j : i)
            cout << j << endl;
        cout << endl;
    }
    return 0;
}
