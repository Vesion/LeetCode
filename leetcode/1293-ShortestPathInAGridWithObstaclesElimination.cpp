#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, k+1));
        constexpr int go[5] = {-1, 0, 1, 0, -1};
        using S = tuple<int,int,int>;
        queue<S> q;
        q.push({0,0,0});
        int res = 0;
        while (!q.empty()) {
            int l = q.size();
            while (l--) {
                auto [i, j, t] = q.front(); q.pop();
                if (i == m-1 && j == n-1) return res;
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d], nj = j+go[d+1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    int nt = t + grid[ni][nj];
                    if (nt > k || nt >= cost[ni][nj]) continue;
                    q.push({ni, nj, nt});
                    cost[ni][nj] = nt;
                }
            }
            ++res;
        }
        return -1;
    }
};

int main() {
    return 0;
}
