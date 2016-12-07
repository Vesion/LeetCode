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
        int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int walk = 0;
        auto total = grid;
        int res;
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
                                if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != walk) continue;
                                grid[ni][nj]--;
                                total[ni][nj] += dist;
                                q.push({ni,nj});
                                res = min(res, total[ni][nj]);
                            }
                        }
                        dist++;
                    }
                    walk--;
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
