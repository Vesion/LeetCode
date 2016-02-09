#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        bool dfs(vector<vector<char>>& board, vector<vector<bool>>& flag, int m, int n, string& word, int row, int col, int index) {
            cout << row << " " << col << endl;
            if (index == word.size())
                return true;
            for (int i = 0; i < 4; ++i) {
                int newRow = row + direct[i][0]; 
                int newCol = col + direct[i][1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n  && !flag[newRow][newCol] && board[newRow][newCol] == word[index]) {
                    flag[newRow][newCol] = true;
                    if (dfs(board, flag, m, n, word, newRow, newCol, index+1))
                        return true;
                    flag[newRow][newCol] = false;
                }
            }
            return false;
        }

        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size(), n = board[0].size();
            vector<vector<bool>> flag(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == word[0]) {
                        flag[i][j] = true;
                        if (dfs(board, flag, m, n, word, i, j, 1))
                            return true;
                        flag[i][j] = false;
                    }
                }
            }
            return false;
        }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        { 'A','B','C','E' },
        { 'S','F','C','S' },
        { 'A','D','E','E' }};
    cout << s.exist(board, "ABCCSES") << endl;
    return 0;
}
