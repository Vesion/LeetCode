#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int res = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;
                res++;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + go[d][0], ny = y + go[d][1];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0') continue;
                        grid[nx][ny] = '0'; // update before enque, in case repeat visit
                        q.push({nx, ny});
                    }
                }
            }
        }
        return res;
    }
};


// Solution 2 : DFS
class Solution_2 {
public:
    int m, n;
    int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;
                ++res;
                dfs(grid, i, j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') return;
        grid[x][y] = '0';
        for (int d = 0; d < 4; ++d)
            dfs(grid, x + go[d][0], y + go[d][1]);
    }
};


// Solution 3 : Union Find
class Solution_3 {
private:
    vector<int> root;
    int count;
    
    int findRoot(int i) {
        if (root[i] != i) root[i] = findRoot(root[i]);
        return root[i];
    }
    
    void unionSet(int i, int j) {
        int ri = findRoot(i), rj = findRoot(j);
        if (ri != rj) {
            root[ri] = rj;
            --count;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        root.resize(m*n, -1);
        count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    int id = i*n + j;
                    root[id] = id;
                    ++count;
                    if (i-1 >= 0) { // left one
                        int nid = (i-1)*n+j;
                        if (root[nid] != -1) unionSet(id, nid);
                    }
                    if (j-1 >= 0) { // upside one
                        int nid = i*n+(j-1);
                        if (root[nid] != -1) unionSet(id, nid);
                    }
                }
            }
        }
        return count;
    }
};


int main() {
    Solution_3 s;
    vector<vector<char>> g = {
        {'1', '0', '1', '1', '0', '1', '1'},
        //{'1', '1', '1', '0'},
        //{'0', '1', '1', '0'},
    };
    cout << s.numIslands(g) << endl;
    return 0;
}

