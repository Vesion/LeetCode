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
    int maximumMinimumPath(vector<vector<int>>& A) {
        constexpr int go[5] = {1, 0, -1, 0, 1};
        int m = A.size(), n = A[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        using S = tuple<int,int,int>;
        priority_queue<S> pq;
        pq.push({A[0][0], 0, 0});
        while (!pq.empty()) {
            auto [s, i, j] = pq.top(); pq.pop();
            if (vis[i][j]) continue;
            vis[i][j] = true;
            if (i == m-1 && j == n-1) return s;
            for (int d = 0; d < 4; ++d) {
                int ni = i + go[d], nj = j + go[d+1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (vis[ni][nj]) continue;
                int ns = min(s, A[ni][nj]);
                pq.push({ns, ni, nj});
            }
        }
        return -1;
    }
};

// Binary search
class Solution1 {
public:
    int m, n;
    vector<vector<bool>> vis;
    const int go[5] = {1, 0, -1, 0, 1};

    bool dfs(vector<vector<int>>& A, int i, int j, int threshold) {
        if (A[i][j] < threshold) return false;
        vis[i][j] = true;
        if (i == m-1 && j == n-1) return true;
        for (int d = 0; d < 4; ++d) {
            int ni = i + go[d], nj = j + go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (vis[ni][nj]) continue;
            if (A[ni][nj] < threshold) continue;
            if (dfs(A, ni, nj, threshold)) return true;
        }
        return false;
    }

    int maximumMinimumPath(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        int l = 0, r = 1e9+1;
        while (l < r) {
            int mid = l + (r-l)/2;
            vis = vector<vector<bool>>(m, vector<bool>(n, false));
            if (dfs(A, 0, 0, mid)) l = mid+1;
            else r = mid;
        }
        // return r-1 not l, different with 1631
        return r-1;
    }
};

int main() {

}