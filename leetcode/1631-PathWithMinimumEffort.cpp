#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
using namespace std;

// 1102-PathWithMaximumMinimumValue
// 1368-MinimumCostToMakeAtLeastOneValidPathInAGrid
// 1631-PathWithMinimumEffort

// Dijkstra, max-heap bfs, O(NlogN)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        constexpr int go[5] = {-1, 0, 1, 0, -1};
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        using S = tuple<int,int,int>;
        priority_queue<S, vector<S>, greater<S>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [e, i, j] = pq.top(); pq.pop();
            if (vis[i][j]) continue;
            vis[i][j] = true;
            if (i == m-1 && j == n-1) return e;
            for (int d = 0; d < 4; ++d) {
                int ni = i + go[d], nj = j + go[d+1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (vis[ni][nj]) continue;
                int ne = max(e, abs(heights[i][j] - heights[ni][nj]));
                pq.push({ne, ni, nj});
            }
        }
        return -1;
    }
};

// binary search solution space
class Solution1 {
public:
    int m, n;
    vector<vector<bool>> vis;
    const int go[5] = {1, 0, -1, 0, 1};

    bool dfs(vector<vector<int>>& heights, int i, int j, int threshold) {
        if (i == m-1 && j == n-1) return true;
        for (int d = 0; d < 4; ++d) {
            int ni = i + go[d], nj = j + go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (vis[ni][nj]) continue;
            int diff = abs(heights[i][j] - heights[ni][nj]);
            if (diff > threshold) continue;
            vis[ni][nj] = true;
            if (dfs(heights, ni, nj, threshold)) return true;
            // backtracking will have it TLE, we do not need it!
            // because we only need to find just one valid path
            // vis[ni][nj] = false;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        int l = 0, r = 1000001;
        while (l < r) {
            int mid = l + (r-l)/2;
            vis = vector<vector<bool>>(m, vector<bool>(n, false));
            vis[0][0] = true;
            if (dfs(heights, 0, 0, mid)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};

// Brute-force, TLE
class Solution_bf {
public:
    int m, n;
    vector<vector<bool>> vis;
    int effort = INT_MAX;
    static constexpr int go[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        vis[0][0] = true;
        dfs(heights, 0, 0, 0);
        return effort;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, int max_diff) {
        if (i == m-1 && j == n-1) {
            effort = min(effort, max_diff);
            return;
        }
        for (int d = 0; d < 4; ++d) {
            int ni = i + go[d][0], nj = j + go[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (vis[ni][nj]) continue;
            vis[ni][nj] = true;
            dfs(heights, ni, nj, max(max_diff, abs(heights[i][j]-heights[ni][nj])));
            vis[ni][nj] = false;
        }
    }
};

// Dijkstra, no-heap, O(N^2), TLE
class Solution_d {
public:
    int m, n;
    vector<vector<int>> effort;
    vector<vector<bool>> has;
    const int go[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        effort = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        has = vector<vector<bool>>(m, vector<bool>(n, false));
        effort[0][0] = 0;
        for (int t = 0; t < m*n; ++t) {
            int si, sj, se = INT_MAX;
            for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
                if (!has[i][j] && effort[i][j] < se) {
                    si = i, sj = j, se = effort[i][j];
                }
            }
            has[si][sj] = true;
            for (int d = 0; d < 4; ++d) {
                int ni = si + go[d][0], nj = sj + go[d][1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (has[ni][nj]) continue;
                effort[ni][nj] = min(effort[ni][nj],
                                     abs(heights[si][sj]-heights[ni][nj]));
            }
        }
        return effort[m-1][n-1];
    }
};


int main() {
    Solution s;
    vector<vector<int>> h = {
        {4,3,4,10,5,5,9,2},
        {10,8,2,10,9,7,5,6},
        {5,8,10,10,10,7,4,2},
        {5,1,3,1,1,3,1,9},
        {6,4,10,6,10,9,4,6}};
    cout << s.minimumEffortPath(h) << endl;

    vector<vector<int>> h2 = {{1,10,6,7,9,10,4,9}};
    cout << s.minimumEffortPath(h2) << endl;
}