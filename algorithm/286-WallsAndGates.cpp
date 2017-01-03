#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// The naive BFS is O(n^4) time, get TLE!
// So we should use Multi End BFS, O(n^2)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rooms[i][j] == 0) q.push({i, j});

        int dist = 0;
        int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!q.empty()) {
            ++dist;
            int len = q.size();
            while (len--) {
                int x = q.front().first, y = q.front().second; q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x+go[d][0], ny = y+go[d][1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || rooms[nx][ny] != INT_MAX) continue;
                    rooms[nx][ny] = dist;
                    q.push({nx, ny});
                }
            }
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> r = { { 2147483647,-1,0,2147483647 },{ 2147483647,2147483647,2147483647,-1 },{ 2147483647,-1,2147483647,-1 },{ 0,-1,2147483647,2147483647 } };
    s.wallsAndGates(r);
    return 0;
}
