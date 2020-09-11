#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// dfs + memo, O(N)
class Solution {
public:
    vector<vector<int>> dp;
    int m, n;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            res = max(res, dfs(matrix, i, j));
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int si, int sj) {
        constexpr int go[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        if (dp[si][sj]) return dp[si][sj];
        int res = 1;
        for (int d = 0; d < 4; ++d) {
            const int i = si + go[d][0];
            const int j = sj + go[d][1];
            if (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] > matrix[si][sj]) {
                res = max(res, 1 + dfs(matrix, i, j));
            }
        }
        dp[si][sj] = res;
        return res;
    }
};

// convert to graph, find the longest path (diameter)
class Solution1 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        constexpr int go[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> in(m*n, 0);
        vector<vector<int>> graph(m*n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int d = 0; d < 4; ++d) {
                    const int ni = i + go[d][0];
                    const int nj = j + go[d][1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                        graph[i*n+j].push_back(ni*n+nj);
                        in[ni*n+nj]++;
                    }
                }
            }
        }

        vector<int> zero;
        for (int i = 0; i < m*n; ++i) if (in[i] == 0) zero.push_back(i);

        int res = 0;
        while (!zero.empty()) {
            vector<int> new_zero;
            for (int i : zero) {
                for (int j : graph[i]) {
                    if (--in[j] == 0) new_zero.push_back(j);
                }
            }
            zero.swap(new_zero);
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
