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
        
        int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int step = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int i = q.front().first, j = q.front().second; q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d][0], nj = j+go[d][1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || rooms[ni][nj] != INT_MAX) continue;
                    rooms[ni][nj] = step;
                    q.push({ni, nj});
                }
            }
            ++step;
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> r = { { 2147483647,-1,0,2147483647 },{ 2147483647,2147483647,2147483647,-1 },{ 2147483647,-1,2147483647,-1 },{ 0,-1,2147483647,2147483647 } };
    s.wallsAndGates(r);
    return 0;
}
