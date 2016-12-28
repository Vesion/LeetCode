#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

// DP, O(n^2)
// dp[i][d] means the number of arithmetic subsequences ending with A[i], diff is d
// note it includes subsequences whose length is 2
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<long long, int>> dp(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                long long d = (long long)A[i] - A[j];
                if (d > INT_MAX || d < INT_MIN) continue; // in case of TLE
                dp[i][d]++;
                if (dp[j].count(d)) { // in case of MLE
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};


int main() {
    return 0;
}

