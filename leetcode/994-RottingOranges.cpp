#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        bool f = false;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1 && !f) f = true;
        }
        if (!f) return 0;

        int res = -1;
        constexpr int go[5] = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i, j] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d], nj = j+go[d+1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (grid[ni][nj] != 1) continue;
                    q.push({ni, nj});
                    grid[ni][nj] = 2;
                }
            }
            ++res;
        }
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) return -1;
        }
        return res;
    }
};

int main() {

}