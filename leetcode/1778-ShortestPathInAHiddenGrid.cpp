#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */


// First DFS to discover the map, then BFS to find the shortest path
class Solution {
public:
    char dir[4] = {'U', 'R', 'D', 'L'};
    int go[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    static const int kMax = 1e3+5;
    int g[kMax][kMax] = {};

    int findShortestPath(GridMaster &master) {
        int i0 = 500, j0 = 500;
        dfs(master, i0, j0);
        int res = 0;
        queue<pair<int,int>> q;
        q.push({i0, j0});
        g[i0][j0] = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i, j] = q.front(); q.pop();
                if (g[i][j] == 2) return res;
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d][0], nj = j+go[d][1];
                    if (ni < 0 || ni >= kMax || nj < 0 || nj >= kMax) continue;
                    if (g[ni][nj] != 0) {
                        q.push({ni, nj});
                        if (g[ni][nj] == 1) g[ni][nj] = 0;
                    }
                }
            }
            ++res;
        }
        return -1;
    }

    void dfs(GridMaster &ma, int i, int j) {
        g[i][j] = ma.isTarget() ? 2 : 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni < 0 || ni >= kMax || nj < 0 || nj >= kMax) continue;
            if (g[ni][nj] != 0) continue;
            if (!ma.canMove(dir[d])) continue;
            ma.move(dir[d]);
            dfs(ma, ni, nj);
            ma.move(dir[(d+2)%4]);
        }
    }
};

int main() {

}
