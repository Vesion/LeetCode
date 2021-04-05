#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// dp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366, 0);
        for (int d : days) dp[d] = costs[0];
        for (int d = 1; d <= days.back(); ++d) {
            if (dp[d] == 0) dp[d] = dp[d-1];
            else {
                dp[d] = dp[d-1] + costs[0];
                dp[d] = min(dp[d], dp[max(0, d-7)] + costs[1]);
                dp[d] = min(dp[d], dp[max(0, d-30)] + costs[2]);
            }
        }
        return dp[days.back()];
    }
};

// dp, generate
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int d = days[i-1];
            for (int j = i; j <= n && days[j-1]-d < 1; ++j)
                dp[j] = min(dp[j], dp[i-1] + costs[0]);
            for (int j = i; j <= n && days[j-1]-d < 7; ++j)
                dp[j] = min(dp[j], dp[i-1] + costs[1]);
            for (int j = i; j <= n && days[j-1]-d < 30; ++j)
                dp[j] = min(dp[j], dp[i-1] + costs[2]);

        }
        return dp[n];
    }
};



int main() {
}