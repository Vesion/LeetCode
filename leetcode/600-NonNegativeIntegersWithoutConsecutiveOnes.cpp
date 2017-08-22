#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Solution 1 : digit dp, top down
class Solution_1 {
public:
    int dp[40][2];
    int n;

    int dfs(int pos, int pre, bool limit) {
        if (pos == -1) return 1;
        if (!limit && dp[pos][pre] != -1) return dp[pos][pre];
        int upper = limit ? ((n>>pos)&1) : 1;
        int res = 0;
        for (int i = 0; i <= upper; ++i) {
            if (pre == 1 && i == 1) continue;
            res += dfs(pos-1, i, limit && i == ((n>>pos)&1));
        }
        if (!limit) dp[pos][pre] = res;
        return res;
    }

    int findIntegers(int num) {
        n = num;
        memset(dp, -1, sizeof dp);
        return dfs(log2(n), -1, true);
    }
};


// Solution 2 : dp, bottom up
class Solution {
public:
    int findIntegers(int num) {
        int n = (int)log2(num);
        int dp[32][2] = {{0}};

        // first count valid numbers without considering num
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][0];
        }

        // then substract numbers greater than num
        int res = dp[n][0] + dp[n][1];
        for (int i = n-1; i >= 0; --i) {
            if (((num>>i)&1) == 1 && ((num>>(i+1))&1) == 1) break; // why stop here?
            if (((num>>i)&1) == 0 && ((num>>(i+1))&1) == 0) res -= dp[i][1];
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.findIntegers(5) << endl;
    return 0;
}
