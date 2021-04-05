#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// bfs with bitmap
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int vis[35][35][1<<6] = {};  // i, j, key_bitmap
        queue<tuple<int,int,int>> q;
        int keys = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (iskey(grid[i][j])) ++keys;
            else if (grid[i][j] == '@') {
                q.push({i, j, 0});
                vis[i][j][0] = true;
            }
        }

        constexpr int go[5] = {1, 0, -1, 0, 1};
        int res = 0;
        int target = (1<<keys)-1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i, j, k] = q.front(); q.pop();
                if (k == target) return res;
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d], nj = j+go[d+1], nk = k;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (grid[ni][nj] == '#') continue;
                    if (iskey(grid[ni][nj])) {
                        nk |= (1 << (grid[ni][nj]-'a'));
                    } else if (islock(grid[ni][nj])) {
                        if ((k & (1 << (grid[ni][nj]-'A'))) == 0) continue;
                    }
                    if (vis[ni][nj][nk]) continue;
                    q.push({ni, nj, nk});
                    vis[ni][nj][nk] = true;
                }
            }
            ++res;
        }
        return -1;
    }

    bool iskey(char c) {
        return c >= 'a' && c <= 'f';
    }

    bool islock(char c) {
        return c >= 'A' && c <= 'F';
    }
};

int main() {
}