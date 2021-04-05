#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        n = workers.size(), m = bikes.size();
        dp = vector<vector<int>>(n, vector<int>(1<<m, -1));
        return dfs(workers, 0, bikes, 0);
    }

    int dfs(vector<vector<int>>& workers, int i, vector<vector<int>>& bikes, int bmask) {
        if (i == n) return 0;
        if (dp[i][bmask] != -1) return dp[i][bmask];
        int res = INT_MAX;
        for (int j = 0; j < m; ++j) {
            if (bmask & (1<<j)) continue;
            int nbmask = bmask | (1<<j);
            int d = abs(workers[i][0]-bikes[j][0]) +
                    abs(workers[i][1]-bikes[j][1]);
            res = min(res, dfs(workers, i+1, bikes, nbmask) + d);
        }
        return dp[i][bmask] = res;
    }
};

int main() {

}
