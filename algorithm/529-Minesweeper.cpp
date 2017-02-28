#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m, n;
    int go[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty()) return board;    
        m = board.size(), n = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return;
        }
        int c = 0; 
        for (int d = 0; d < 8; ++d) { 
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni >= 0 && ni < m  && nj >= 0 && nj < n && board[ni][nj] == 'M') ++c;
        }
        if (c) {
            board[i][j] = '0'+c;
            return;
        }
        board[i][j] = 'B';
        for (int d = 0; d < 8; ++d) { 
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni >= 0 && ni < m  && nj >= 0 && nj < n && board[ni][nj] == 'E') dfs(board, ni, nj);
        }
    }
};


int main() {
    Solution s;
    vector<vector<char>> board = {
    { 'E', 'E', 'E', 'E', 'E' },
    { 'E', 'E', 'M', 'E', 'E' },
    { 'E', 'E', 'E', 'E', 'E' },
    { 'E', 'E', 'E', 'E', 'E' } } ;
    vector<int> c = {0, 4};
    auto r = s.updateBoard(board, c);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
