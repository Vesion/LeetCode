#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vector<vector<char>>& grid, int m, int n, int i, int j) {
    if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '0') return;
    grid[i][j] = '0'; // change connecting '1' to '0'
    for (int k = 0; k < 4; ++k)
        dfs(grid, m, n, i+go[k][0], j+go[k][1]);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(); if (!m) return 0;
    int n = grid[0].size(); if (!n) return 0;
    int result = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '0') continue;
            ++result; // meet a new '1'
            dfs(grid, m, n, i, j); // search all '1' which connected to it directly or indirectly, and change it to '0'
        }
    }
    return result;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}
