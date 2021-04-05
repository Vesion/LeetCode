#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dfs
class Solution0 {
public:
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size(), n = grid[0].size();
        int s = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) s = max(s, dfs(grid, i, j));
        return s;
    }

    int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;
        int s = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i + go[d][0], nj = j + go[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (grid[ni][nj]) s += dfs(grid, ni, nj);
        }
        return s;
    }
};

// bfs
class Solution1 {
public:
    int m, n;
    static constexpr int go[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    struct Pos { int i, j; };

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size(), n = grid[0].size();
        int s = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) s = max(s, bfs(grid, i, j));
        return s;
    }

    int bfs(vector<vector<int>>& grid, int i, int j) {
        queue<Pos> q;
        q.push({i, j});
        grid[i][j] = 0;
        int s = 0;
        while (!q.empty()) {
            Pos pos = q.front(); q.pop();
            ++s;
            for (int d = 0; d < 4; ++d) {
                int ni = pos.i + go[d][0];
                int nj = pos.j + go[d][1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid[ni][nj]) {
                    q.push({ni, nj});
                    grid[ni][nj] = 0;
                }
            }
        }
        return s;
    }
};

// union find
class Solution {
public:
    int m, n;
    vector<int> root, area;
    int find(int x) {
        if (x != root[x]) root[x] = find(root[x]);
        return root[x];
    }
    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            root[rx] = ry;
            area[ry] += area[rx];
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size(), n = grid[0].size();
        root.resize(m*n, 0), area.resize(m*n, 0);
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            int x = i * n + j;
            if (grid[i][j]) root[x] = x, area[x] = 1;
        }
        int s = 0;
        constexpr int go[2][2] = {{0, -1}, {-1, 0}};
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (!grid[i][j]) continue;
            int x = i*n + j;
            for (int d = 0; d < 2; ++d) {
                int ni = i + go[d][0], nj = j + go[d][1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid[ni][nj]) link(x, ni*n + nj);
            }
            s = max(s, area[find(x)]);
        }
        return s;
    }
};

int main() {
  return 0;
}
