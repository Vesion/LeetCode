#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// dfs + memo, O(N)
class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
            res = max(res, dfs(matrix, i, j));
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        constexpr int go[5] = {1, 0, -1, 0, 1};
        if (dp[i][j]) return dp[i][j];
        int res = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d], nj = j+go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (matrix[i][j] <= matrix[ni][nj]) continue;
            res = max(res, dfs(matrix, ni, nj) + 1);
        }
        dp[i][j] = res;
        return res;
    }
};

// convert to graph, find the longest path (diameter), O(N)
class Solution1 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> g(m*n);
        vector<int> in(m*n, 0);
        constexpr int go[5] = {1, 0, -1, 0, 1};
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            int x = i*n + j;
            for (int d = 0; d < 4; ++d) {
                int ni = i + go[d], nj = j + go[d+1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (matrix[i][j] >= matrix[ni][nj]) continue;
                int y = ni*n + nj;
                g[x].push_back(y);
                ++in[y];
            }
        }

        int res = 0;
        queue<int> q;
        for (int i = 0; i < m*n; ++i) if (in[i] == 0) q.push(i);
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int i = q.front(); q.pop();
                for (int j : g[i]) {
                    if (--in[j] == 0) q.push(j);
                }
            }
            ++res;
        }
        return res;
    }
};

// sort, O(N*logN)
class Solution2 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<pair<int, vector<int>>> p;
        p.reserve(m*n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                p.push_back({matrix[i][j], {i, j}});
            }
        }
        sort(p.begin(), p.end());

        vector<vector<int>> l(m, vector<int>(n, 1));
        constexpr int go[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int res = 1;
        for (auto& cell : p) {
            const int i = cell.second[0];
            const int j = cell.second[1];
            for (int d = 0; d < 4; ++d) {
                const int ni = i + go[d][0];
                const int nj = j + go[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] < cell.first) {
                    l[i][j] = max(l[i][j], l[ni][nj] + 1);
                }
            }
            res = max(res, l[i][j]);
        }
        return res;
    }
};


int main() {
    return 0;
}
