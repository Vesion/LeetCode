#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : BFS
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> state(m, vector<int>(n ,0));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; ++i) { state[i][0] += 1; q.push({i, 0}); }
        for (int j = 1; j < n; ++j) { state[0][j] += 1; q.push({0, j}); }
        bfs(matrix, m, n, 1, state, q);

        for (int i = 0; i < m; ++i) { state[i][n-1] += 2; q.push({i, n-1}); }
        for (int j = 0; j < n-1; ++j) { state[m-1][j] += 2; q.push({m-1, j}); }
        bfs(matrix, m, n, 2, state, q);

        vector<pair<int,int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (state[i][j] == 3) res.push_back({i, j});
        return res;
    } 

    int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void bfs(vector<vector<int>>& matrix, int m, int n, int ocean, vector<vector<int>>& state, queue<pair<int,int>>& q) {
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            int x = t.first, y = t.second;
            for (int d = 0; d < 4; ++d) {
                int nx = x+go[d][0], ny = y+go[d][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || state[nx][ny] >= ocean || matrix[nx][ny] < matrix[x][y]) continue;
                state[nx][ny] += ocean;
                q.push({nx, ny});
            }
        }
    }
};


// Solution 2 : DFS
class Solution_2 {
public:
    int m, n;
    int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> state;
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        m = matrix.size(), n = matrix[0].size();
        state.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) dfs(matrix, i, 0, 1);
        for (int j = 1; j < n; ++j) dfs(matrix, 0, j, 1);

        for (int i = 0; i < m; ++i) dfs(matrix, i, n-1, 2);
        for (int j = 0; j < n-1; ++j) dfs(matrix, m-1, j, 2);
        
        vector<pair<int,int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
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
