#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m, n;
    int go[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0)) return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int start) {
        if (start == (int)word.size()-1) return true;
        char c = board[i][j];
        board[i][j] = '#';
        bool res = false;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] != word[start+1]) continue;
            if (dfs(board, ni, nj, word, start+1)) { res = true; break; } // do not return here, we need to recover board
        }
        board[i][j] = c;
        return res;
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
    for (auto& i : board) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
