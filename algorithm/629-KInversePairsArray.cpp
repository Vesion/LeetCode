#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, dp[i+1][j] = sum{ dp[i][j-k], k = 0...i }
class Solution {
public:
    using ll = long long;
    const int MOD = 1e9+7;

    void add(ll& a, ll b) {
        a += b;
        if (a > MOD) a -= MOD;
    }

    void sub(ll& a, ll b) {
        a -= b;
        if (a < 0) a += MOD;
    }

    int kInversePairs(int n, int k) {
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));       
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            ll sum = 0, pre = 0;
            for (int j = 0; j <= k; ++j) {
                add(sum, dp[i][j]);
                if (j-i-1 >= 0) add(pre, dp[i][j-i-1]);
                add(dp[i+1][j], sum);
                sub(dp[i+1][j], pre);
            }
        }
        return dp[n][k];
    }
};


int main() {
    return 0;
}
