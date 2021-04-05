#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int waysToDistribute(int n, int k) {
        constexpr int kMod = 1e9+7;
        using ll = long long;
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(k, i); j >= 1; --j) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]*j) % kMod;
            }
        }
        return dp[n][k];
    }
};

int main() {
}
