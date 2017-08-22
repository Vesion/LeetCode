#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m, n;
    int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<char> > &board, string& word, int x, int y, int cur, vector<vector<int>>& visited) {
        if (cur == (int)word.size()) return true;
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[cur]) return false;
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + go[i][0], ny = y + go[i][1];
            if (dfs(board, word, nx, ny, cur+1, visited)) return true;
        }
        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty()) return word.empty();
        m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << s.exist(board, "ABAB") <<endl;
    return 0;
}
