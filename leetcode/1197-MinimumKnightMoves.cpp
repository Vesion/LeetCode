#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Naive BFS
class Solution {
public:
    const int go[8][2] = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };
    const int kMax = 608;
    int minKnightMoves(int x, int y) {
        vector<vector<bool>> vis(kMax, vector<bool>(kMax, false));
        const int w = kMax/2;
        x += w, y += w;
        queue<pair<int,int>> q;
        q.push({w, w}); vis[w][w] = true;
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i, j] = q.front(); q.pop();
                if (i == x && j == y) return res;
                for (int d = 0; d < 8; ++d) {
                    int ni = i+go[d][0], nj = j+go[d][1];
                    if (ni < 0 || ni >= kMax || nj < 0 || nj >= kMax) continue;
                    if (vis[ni][nj]) continue;
                    q.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }
            ++res;
        }
        return -1;
    }
};


// DP
class Solution {
public:
    vector<vector<int>> dp;
    const int kMax = 305;

    int minKnightMoves(int x, int y) {
        dp.resize(kMax, vector<int>(kMax, -1));
        return dfs(abs(x), abs(y));
    }

    int dfs(int x, int y) {
        if (x == 0 && y == 0) return 0;
        if (x+y == 2) return 2;  // termination
        if (dp[x][y] != -1) return dp[x][y];
        int res = min(dfs(abs(x-1), abs(y-2)), dfs(abs(x-2), abs(y-1))) + 1;
        return dp[x][y] = res;
    }
};


// math
// https://leetcode.com/problems/minimum-knight-moves/discuss/392053/Here-is-how-I-get-the-formula-(with-graphs)

int main() {

}
