#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Just straight-forward bfs, O(n^4)
// https://discuss.leetcode.com/topic/31702/36-ms-c-solution
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> total(m, vector<int>(n, 0));
        int res;
        int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        // we only need to go to cells that were reachable from all previous buildings,
        // so no need fresh 'visited' for each bfs turn
        int flag = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    int dist = 1;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while (!q.empty()) {
                        int len = q.size();
                        while (len--) {
                            auto t = q.front(); q.pop();
                            for (int d = 0; d < 4; ++d) {
                                int ni = t.first+go[d][0], nj = t.second+go[d][1];
                                if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != flag) continue;
                                q.push({ni,nj});
                                grid[ni][nj]--;
                                total[ni][nj] += dist;
                                res = min(res, total[ni][nj]);
                            }
                        }
                        dist++;
                    }
                    flag--;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> g = {
        {1,0,2,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0},
    };
    cout << s.shortestDistance(g) << endl;
    return 0;
}
