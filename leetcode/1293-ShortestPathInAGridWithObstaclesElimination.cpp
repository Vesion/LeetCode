#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    struct State {
        int x = 0, y = 0, k = 0;
    };
    int go[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        if (grid.empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        // The minimum obstacles need to remove to reach a position
        vector<vector<int>> v(m, vector<int>(n, k+1));

        vector<State> s;
        s.push_back({0, 0, 0});
        v[0][0] = 0;
        int res = 0;
        while (!s.empty()) {
            vector<State> ns;
            for (const State& a : s) {
                if (a.x == m-1 && a.y == n-1) return res;
                for (int d = 0; d < 4; ++d) {
                    const int nx = a.x + go[d][0];
                    const int ny = a.y + go[d][1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    const int nk = a.k + grid[nx][ny];
                    if (nk > k || nk >= v[nx][ny]) continue;
                    ns.push_back({nx, ny, nk});
                    v[nx][ny] = nk;
                }
            }
            s.swap(ns);
            ++res;
        }
        return -1;
    }
};

int main() {
    return 0;
}
