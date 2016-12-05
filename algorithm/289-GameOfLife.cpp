#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int go[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i+go[d][0], nj = j+go[d][1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && (board[ni][nj]&1) == 1) ++c;
                }
                if ((board[i][j]&1) == 1) board[i][j] |= (c == 2 || c == 3) << 1;
                else board[i][j] |= (c == 3) << 1;
            }
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};

int main() {
    Solution s;
    return 0;
}

