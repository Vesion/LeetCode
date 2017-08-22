#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; ++j) 
            if (ring[j] == key[0]) dp[0][j] = min(j, n-j) + 1;

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ring[j] == key[i]) {
                    for (int k = 0; k < n; ++k) {
                        if (ring[k] == key[i-1]) {
                            dp[i][j] = min(dp[i][j], dp[i-1][k] + min(abs(k-j), n-abs(k-j)) + 1);
                        }
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < n; ++j) res = min(res, dp[m-1][j]);
        return res;
    }
};


int main() {
    return 0;
}
