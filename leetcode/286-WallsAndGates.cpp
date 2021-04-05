#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) for (int j =  0; j < n; ++j) {
            if (rooms[i][j] == 0) q.push({i, j});
        }

        int level = 1;
        constexpr int go[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i,j] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d], nj = j+go[d+1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (rooms[ni][nj] == INT_MAX) {
                        rooms[ni][nj] = level;
                        q.push({ni, nj});
                    }
                }
            }
            ++level;
        }
    }
};


int main() {
    return 0;
}
