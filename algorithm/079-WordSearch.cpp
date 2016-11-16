#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                    if (dfs(i, j, board, m, n, 0, word)) return true;
        return false;
    }

    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(int x, int y, vector<vector<char>>& board, int m, int n, int cur, string& word) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '$' || board[x][y] != word[cur]) return false;
        if (cur == (int)word.size()-1) return true;
        char t = board[x][y];
        board[x][y] = '$'; // use '$' to mark visted position
        for (int d = 0; d < 4; ++d) {
            if (dfs(x+go[d][0], y+go[d][1], board, m, n, cur+1, word)) return true;
        }
        board[x][y] = t;
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'},
    };
    cout << s.exist(board, "ABCESEEEFS") << endl;
    return 0;
}


