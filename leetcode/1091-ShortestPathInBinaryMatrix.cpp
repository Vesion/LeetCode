#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        constexpr int go[8][2] = {
            {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int res = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i,j] = q.front(); q.pop();
                if (i == n-1 && j == n-1) return res;
                for (int d = 0; d < 8; ++d) {
                    int ni = i+go[d][0], nj = j+go[d][1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                    if (grid[ni][nj]) continue;
                    q.push({ni,nj});
                    // mark the cell visited right after pushing to queue,
                    // this will avoid pushing duplicated cells into queue,
                    // which means every cell can only be pushed into queue at most once.
                    grid[ni][nj] = 1;
                }
            }
            ++res;
        }
        return -1;
    }
};

int main() {

}
