#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Min-max

// top-down DP
class Solution0 {
public:
    vector<int> dp;

    string stoneGameIII(vector<int>& stoneValue) {
        dp = vector<int>(stoneValue.size(), INT_MIN);
        int over = winover(stoneValue, 0);
        if (over > 0) return "Alice";
        if (over < 0) return "Bob";
        return "Tie";
    }

    // return the max score the player can win over the opponent if start from i
    int dfs(vector<int>& s, int i) {
        if (i >= s.size()) return 0;
        if (dp[i] != INT_MIN) return dp[i];
        int take = 0;
        for (int k = 0; k < 3 && i+k < s.size(); ++k) {
            take += s[i+k];
            dp[i] = max(dp[i], take - dfs(s, i+k+1));
        }
        return dp[i];
    }
};

// bottom-up DP
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] = the max score the current player can win over the opponent for stoneValue[i...n-1]
        vector<int> dp(n, INT_MIN);
        for (int i = n-1; i >= 0; --i) {
            int take = 0;
            for (int k = 0; k < 3 && i+k < n; ++k) {
                take += stoneValue[i+k];
                dp[i] = max(dp[i], take - (i+k+1 < n ? dp[i+k+1] : 0));
            }
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};

int main() {

}