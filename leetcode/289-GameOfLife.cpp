#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        int go[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i+go[d][0], nj = j+go[d][1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (board[ni][nj]&1) ++c;
                }
                if (((board[i][j]&1) == 1 && (c == 2 || c == 3)) 
                 || ((board[i][j]&1) == 0 && c == 3)) 
                    board[i][j] |= 0b10;
            }
        }
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) board[i][j] >>= 1;
    }
};


int main() {
    return 0;
}

