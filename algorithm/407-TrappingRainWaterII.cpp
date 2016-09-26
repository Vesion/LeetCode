#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;


// Solution 0 : dfs (flood fill), TLE
class Solution_dfs {
public:
    int area;
    int m, n;
    bool out;
    bool visited[111][111];
    int h;

    void dfs(int x, int y, vector<vector<int>>& height) {
        if (visited[x][y] || height[x][y] > h) return;
        if (x == 0 || x == m-1 || y == 0 || y == n-1) {
            out = true;
            return;
        }
        visited[x][y] = true;
        ++area;
        dfs(x-1, y, height);
        dfs(x, y-1, height);
        dfs(x+1, y, height);
        dfs(x, y+1, height);
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        m = heightMap.size(), n = heightMap[0].size();    
        int result = 0;
        for (h = 1; h <= 20000; ++h) {
            memset(visited, false, sizeof visited);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (heightMap[i][j] <= h) {
                        out = false;
                        area = 0;
                        dfs(i, j, heightMap);
                        if (!out) result += area;
                    }
                }
            }
        }
        return result;
    }
};


// Solution 1 : bfs + heap
class Solution {
private:
    struct Cell {
        int r, c, height;
        Cell(int r, int c, int h) : r(r), c(c), height(h) {}
        bool operator<(const Cell& other) const { return this->height > other.height; } // we need a min-queue
    };

    int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;    
        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<Cell> pq;
        vector<vector<int>> visited(m, vector<int>(n, false));

        // enqueue 4 border
        for (int i = 0; i < m; ++i) {
            pq.push(Cell(i, 0, heightMap[i][0]));
            pq.push(Cell(i, n-1, heightMap[i][n-1]));
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; ++j) {
            pq.push(Cell(0, j, heightMap[0][j]));
            pq.push(Cell(m-1, j, heightMap[m-1][j]));
            visited[0][j] = visited[m-1][j] = true;
        }

        int result = 0;
        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            for (int i = 0; i < 4; ++i) {
                int r = cell.r + go[i][0];
                int c = cell.c + go[i][1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) continue;
                visited[r][c] = true;
                result += max(0, cell.height - heightMap[r][c]);
                pq.push(Cell(r, c, max(cell.height, heightMap[r][c]))); // push the cell with water contained if it has
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<vector<int>> h = {
        {4, 4, 4}, 
        {4, 3, 4}, 
        {4, 1, 4}, 
    };
    cout << s.trapRainWater(h);
    return 0;
}
