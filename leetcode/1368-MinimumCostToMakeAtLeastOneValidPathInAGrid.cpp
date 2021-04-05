#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 1102-PathWithMaximumMinimumValue
// 1368-MinimumCostToMakeAtLeastOneValidPathInAGrid
// 1631-PathWithMinimumEffort

// Dijkstra, max-heap, O(NlogN)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        constexpr int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        using S = tuple<int,int,int>;
        priority_queue<S, vector<S>, greater<S>> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            auto [c, i, j] = q.top(); q.pop();
            if (vis[i][j]) continue;
            vis[i][j] = true;
            if (i == m-1 && j == n-1) return c;
            for (int d = 0; d < 4; ++d) {
                int ni = i+go[d][0], nj = j+go[d][1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (vis[ni][nj]) continue;
                int nc = c;
                if (grid[i][j] != d+1) ++nc;
                q.push({nc, ni, nj});
            }
        }
        return -1;
    }
};

int main() {

}