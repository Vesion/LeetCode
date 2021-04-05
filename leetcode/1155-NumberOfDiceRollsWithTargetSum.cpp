#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        using ll = long long;
        vector<ll> dp(target+1, 0);
        constexpr int kMod = 1e9+7;
        dp[0] = 1;
        for (int i = 0; i < d; ++i) {
            for (int j = target; j >= 0; --j) {  // j must end at 0
                dp[j] = 0;  // reset dp[j] for a new dice, think why?
                for (int k = 1; k <= f; ++k) {
                    if (j-k >= 0) dp[j] = (dp[j-k] + dp[j]) % kMod;
                }
            }
        }
        return dp[target];
    }
};

int main() {
}
