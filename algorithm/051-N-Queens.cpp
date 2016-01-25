#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    dfs(result, board, 0, n);   
    return result;
}

int main() {
    auto result = solveNQueens(4);
    for (auto v : result) {
        for (auto s : v) {
            cout << s << endl;
        }
        cout << endl;
    }
}
