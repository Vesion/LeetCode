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

int main() {
    cout << totalNQueens(6) << endl;
}
