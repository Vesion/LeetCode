#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Solution 1 : BFS
class Solution {
public:
    int m, n;
    vector<vector<int>> s;
    queue<pair<int,int>> q;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        s.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) s[i][0] += 1, q.push({i, 0});
        for (int j = 1; j < n; ++j) s[0][j] += 1, q.push({0, j});
        bfs(heights, 1);

        for (int i = 0; i < m; ++i) s[i][n-1] += 2, q.push({i, n-1});
        for (int j = 0; j < n-1; ++j) s[m-1][j] += 2, q.push({m-1, j});
        bfs(heights, 2);

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
            if (s[i][j] == 3) res.push_back({i, j});
        return res;
    }

    void bfs(const vector<vector<int>>& h, int k) {
        constexpr int go[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i+go[d], nj = j+go[d+1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (h[ni][nj] < h[i][j]) continue;
                if (s[ni][nj] >= k) continue;
                q.push({ni, nj});
                s[ni][nj] += k;
            }
        }
    }
};


// Solution 2 : DFS
class Solution2 {
public:
    int m, n;
    int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> state;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        m = matrix.size(), n = matrix[0].size();
        state.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) dfs(matrix, i, 0, 1);
        for (int j = 1; j < n; ++j) dfs(matrix, 0, j, 1);

        for (int i = 0; i < m; ++i) dfs(matrix, i, n-1, 2);
        for (int j = 0; j < n-1; ++j) dfs(matrix, m-1, j, 2);

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
                if (state[i][j] == 3) res.push_back({i, j});
        return res;
    }

    void dfs(vector<vector<int>>& matrix, int i, int j, int s) {
        state[i][j] |= s;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || matrix[ni][nj] < matrix[i][j] || (state[ni][nj]&s) == s) continue;
            dfs(matrix, ni, nj, s);
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4 ,4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    auto r = s.pacificAtlantic(matrix);
    for (auto& e : r) cout << e.first << " " <<e.second << endl;; cout << endl;
    return 0;
}
