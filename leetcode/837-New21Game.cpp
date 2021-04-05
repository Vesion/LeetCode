#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// https://leetcode.com/problems/new-21-game/discuss/132334/One-Pass-DP-O(N)
// Nice probability/DP/sliding-window combo question!

// dp[i] = probability of get i points by some draws
//       = dp[i-1]/W + dp[i-2]/W + ... + dp[i-W]/W
//       = (dp[i-1] + dp[i-2] + ... + dp[i-W]) / W
// let wsum = dp[i] + dp[i-1] + ... + dp[i-W+1]
// use sliding window wsum to maintain the sum of dp[i-W+1...i]
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;

        vector<double> dp(N+1);
        dp[0] = 1;
        double wsum = 1, res = 0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = wsum / W;  // use last wsum to get new dp[i]
            if (i < K) wsum += dp[i];  // sliding window extend
            if (i >= W) wsum -= dp[i-W];  // sliding window shrink
            if (i >= K) res += dp[i];  // only care about i in [K, N]
        }
        return res;
    }
};

int main() {

}
