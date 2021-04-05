#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// A naive solution is iterate height from 1 to 20000, accumulate water level by level using dfs, TLE
// So we need a better search strategy.

// heap + bfs
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // minimum heap, {height, pos = i*n+j}
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // enqueue 4 borders
        for (int i = 0; i < m; ++i) {
            q.push({heightMap[i][0], i*n+0}); visited[i][0] = true;
            q.push({heightMap[i][n-1], i*n+n-1}); visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; ++j) {
            q.push({heightMap[0][j], 0*n+j}); visited[0][j] = true;
            q.push({heightMap[m-1][j], (m-1)*n+j}); visited[m-1][j] = true;
        }

        int res = 0;
        int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            int height = t.first;
            int x = t.second/n, y = t.second%n;
            for (int d = 0; d < 4; ++d) {
                int nx = x+go[d][0], ny = y+go[d][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                res += max(0, height-heightMap[nx][ny]);
                q.push({max(height, heightMap[nx][ny]), nx*n+ny}); // fill the new cell with water if it is lower
            }
        }
        return res;
    }
};

// A big optimization:
// Used DFS for the cells that are shorter or equal,
// because you know they are going to be switched to the root of the queue,
// why bother putting them back wasting logN time.


int main() {
    Solution s;
    vector<vector<int>> h = { { 1,4,3,1,3,2 },{ 3,2,1,3,2,4 },{ 2,3,3,2,3,1 } };
    cout << s.trapRainWater(h) << endl;
    return 0;
}

